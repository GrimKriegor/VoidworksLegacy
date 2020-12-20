#include <voidworks/param.h>

ParamRegistry* ParamRegistry::instance_ = 0;

ParamRegistry::ParamRegistry()
{
  ds3_ = ProcessInterface::GetInstance();
  AwaitParamLoading();
  IndexParams();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ParamRegistry initialized\n" ANSI_RESET);
#endif
}

ParamRegistry* ParamRegistry::GetInstance()
{
  if (!instance_)
  {
    instance_ = new ParamRegistry();
  }
  return instance_;
}

ParamRegistry::~ParamRegistry()
{
  RestoreRegisteredParams();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ParamRegistry terminated\n" ANSI_RESET);
#endif
}

void ParamRegistry::AwaitParamLoading()
{
  while (!ds3_->IsMlPointerDereferenceable({CS_REG_MANAGER, 0x00, 0x00}))
  {
    Sleep(200);
  }
}

void ParamRegistry::IndexParams()
{
  uintptr_t base  = (uintptr_t)ds3_->GetDynamicAddress({CS_REG_MANAGER, 0x00});
  uintptr_t start = (uintptr_t)ds3_->GetDynamicAddress({base, 0x00});
  uintptr_t end   = (uintptr_t)ds3_->GetDynamicAddress({base+0x00, 0x00});
  size_t    count = ((end - start) / 8);
  for (size_t i = 0; i < count; i++)
  {
    std::wstring string = L"Unknown";
    uintptr_t    offset = (uintptr_t)ds3_->GetDynamicAddress({start+(i*8)});
    mLvPtr param_string_mlp = {offset, 0x00};
    if (ds3_->ReadInt32(ds3_->GetDynamicAddress({offset, 0x00})) > 7)
    {
      param_string_mlp.push_back(0x00);
    }
    ds3_->ReadWideString(ds3_->GetDynamicAddress(param_string_mlp), string, 90);
    master_param_table_.insert_or_assign(string, offset);
  }
}

void ParamRegistry::RestoreRegisteredParams()
{
  for (auto& param : param_registry_)
  {
    if (param.second == nullptr) { continue; }
    delete param.second;
  }
}

std::map<uint32_t, uintptr_t> ParamRegistry::GetParamIdTable(const std::wstring& param)
{
  std::map<uint32_t, uintptr_t> table;
  uintptr_t base    = master_param_table_[param];
  uintptr_t address = (uintptr_t)ds3_->GetDynamicAddress({base, 0x00, 0x00});
  uintptr_t idosum  = (uintptr_t)ds3_->GetDynamicAddress({address, 0x00}); //holup...
  size_t    count   = ds3_->ReadInt16(ds3_->GetDynamicAddress({address, 0x00}));
  for (size_t i = 0; i < count; i++)
  {
    uint32_t pid =
      ds3_->ReadInt32(ds3_->GetDynamicAddress({address, 0x00 + (0x00 * i)}));
    uint32_t ido =
      ds3_->ReadInt32(ds3_->GetDynamicAddress({address, 0x00 + (0x00 * i)}));
    table.insert_or_assign(pid, (idosum+ido));
  }
  return table;
}

void ParamRegistry::PrintIndexedParams()
{
  printf("ParamRegistry MasterParamTable:\n");
  for (auto& param : master_param_table_)
  {
    printf("[%S] %#016llx\n", param.first.c_str(), param.second);
  }
}

void ParamRegistry::PrintParamIdTable(const std::map<uint32_t, uintptr_t>& id_table)
{
  printf("IdTable:\n");
  for (auto& id : id_table)
  {
    printf("[%#llx] %#016llx\n", id.first, id.second);
  }
}

uintptr_t ParamRegistry::GetParamAddress(const std::wstring& param)
{
  return master_param_table_[param];
}

void ParamRegistry::RegisterParam(const std::wstring& name, BaseParam* param)
{
  param_registry_.insert_or_assign(name, param);
}

void ParamRegistry::UnregisterParam(const std::wstring& name)
{
  param_registry_.erase(name);
}

BaseParam* ParamRegistry::GetRegisteredParam(const std::wstring& name)
{
  return param_registry_[name];
}

PatchInfo::PatchInfo(void* address, void* buffer, PatchValueType type, uint8_t binary_offset)
{
  address_ = address;
  type_ = type;
  binary_offset_ = binary_offset;
  switch (type)
  {
    case PatchValueType::Binary:    { size_ = 1; break; }
    case PatchValueType::Byte:      { size_ = 1; break; }
    case PatchValueType::TwoByte:   { size_ = 2; break; }
    case PatchValueType::FourByte:  { size_ = 4; break; }
    case PatchValueType::EightByte: { size_ = 8; break; }
    case PatchValueType::Float:     { size_ = 4; break; }
  }
  memcpy(value_, buffer, size_);
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "New patch of type %d at %#016llx\n"
      ANSI_RESET,
      type_,
      address_
    );
#endif
}

BaseParam::BaseParam(std::wstring param, uint32_t id, uintptr_t address)
{
  param_ = param;
  id_ = id;
  id_ %= 0x00000000;
  address_ = address;
  if (!address_) {
    address_ = ParamRegistry::GetInstance()->
      GetParamIdTable(param_)[id_];
  }
  registry_key_ = param_ + L"_" + std::to_wstring(id);
  ParamRegistry::GetInstance()->RegisterParam(registry_key_, this);
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "Created param instance %S, id %#x, address %#016llx\n"
      ANSI_RESET,
      param_.c_str(), id_, address_
    );
#endif
}

BaseParam::~BaseParam()
{
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "Destroyed param instance %S, id %#x with %d patches\n"
      ANSI_RESET,
      param_.c_str(), id_, patch_store_.size()
    );
#endif
  for (auto& patch : patch_store_)
  {
    RestorePatch(patch);
  }
  ParamRegistry::GetInstance()->UnregisterParam(registry_key_);
}

void BaseParam::ReadWritePatch(PatchInfo& patch, bool write, bool backup)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uint8_t* value = patch.value_;
  if (backup) { value = patch.backup_; }
  switch (patch.type_)
  {
    case PatchValueType::Binary:
      if (write) {
        ds3->WriteBinary(
            patch.address_, patch.binary_offset_, *reinterpret_cast<bool*>(value));
      } else {
        *reinterpret_cast<bool*>(value) = ds3->ReadBinary(
            patch.address_, patch.binary_offset_);
      }
      break;
    case PatchValueType::Byte:
      if (write) {
        ds3->WriteByte(patch.address_, *reinterpret_cast<uint8_t*>(value));
      } else {
        *reinterpret_cast<uint8_t*>(value) = ds3->ReadByte(patch.address_);
      }
      break;
    case PatchValueType::TwoByte:
      if (write) {
        ds3->WriteInt16(patch.address_, *reinterpret_cast<int16_t*>(value));
      } else {
        *reinterpret_cast<int16_t*>(value) = ds3->ReadInt16(patch.address_);
      }
      break;
    case PatchValueType::FourByte:
      if (write) {
        ds3->WriteInt32(patch.address_, *reinterpret_cast<int32_t*>(value));
      } else {
        *reinterpret_cast<int32_t*>(value) = ds3->ReadInt32(patch.address_);
      }
      break;
    case PatchValueType::EightByte:
      if (write) {
        ds3->WriteInt64(patch.address_, *reinterpret_cast<int64_t*>(value));
      } else {
        *reinterpret_cast<int64_t*>(value) = ds3->ReadInt64(patch.address_);
      }
      break;
    case PatchValueType::Float:
      if (write) {
        ds3->WriteFloat(patch.address_, *reinterpret_cast<float*>(value));
      } else {
        *reinterpret_cast<float*>(value) = ds3->ReadFloat(patch.address_);
      }
      break;
    default:
      printf(ANSI_ERROR_MSG
          "[ERROR] Patch %#016llx has unhandled type!\n"
          ANSI_RESET,
          patch.address_
        );
      break;
  }
}

void BaseParam::RestorePatch(PatchInfo& patch)
{
  ReadWritePatch(patch, true, true);
}

void BaseParam::ApplyPatch(PatchInfo& patch)
{
  if (!patch.initialized_)
  {
    ReadWritePatch(patch, false, true);
  }
  ReadWritePatch(patch, true);
  patch.initialized_ = true;
}

void BaseParam::PatchValue(uintptr_t offset, void* buffer, PatchValueType type, uint8_t binary_offset)
{
  uintptr_t full_address = (offset < address_) ? (offset + address_) : offset;
  PatchInfo patch_info = PatchInfo(
      (void*)(full_address),
      buffer,
      type,
      binary_offset
    );
  patch_store_.push_back(patch_info);
  ApplyPatch(patch_store_.back());
}

void BaseParam::PatchAll(uintptr_t offset, void* buffer, PatchValueType type, uint8_t binary_offset)
{
  for (auto& entry : ParamRegistry::GetInstance()->GetParamIdTable(param_))
  {
    PatchValue((entry.second + offset), buffer, type, binary_offset);
  }
}

void BaseParam::PatchBinary(uintptr_t offset, uint8_t value, uint8_t binary_offset)
{
  PatchValue(offset, &value, PatchValueType::Binary, binary_offset);
}

void BaseParam::PatchByte(uintptr_t offset, uint8_t value)
{
  PatchValue(offset, &value, PatchValueType::Byte);
}

void BaseParam::Patch2Byte(uintptr_t offset, int16_t value)
{
  PatchValue(offset, &value, PatchValueType::TwoByte);
}

void BaseParam::Patch4Byte(uintptr_t offset, int32_t value)
{
  PatchValue(offset, &value, PatchValueType::FourByte);
}

void BaseParam::Patch8Byte(uintptr_t offset, int64_t value)
{
  PatchValue(offset, &value, PatchValueType::EightByte);
}

void BaseParam::PatchFloat(uintptr_t offset, float value)
{
  PatchValue(offset, &value, PatchValueType::Float);
}

void BaseParam::PatchAllBinary(uintptr_t offset, uint8_t value, uint8_t binary_offset)
{
  PatchAll(offset, &value, PatchValueType::Binary, binary_offset);
}

void BaseParam::PatchAllByte(uintptr_t offset, uint8_t value)
{
  PatchAll(offset, &value, PatchValueType::Byte);
}

void BaseParam::PatchAll2Byte(uintptr_t offset, int16_t value)
{
  PatchAll(offset, &value, PatchValueType::TwoByte);
}

void BaseParam::PatchAll4Byte(uintptr_t offset, int32_t value)
{
  PatchAll(offset, &value, PatchValueType::FourByte);
}

void BaseParam::PatchAll8Byte(uintptr_t offset, int64_t value)
{
  PatchAll(offset, &value, PatchValueType::EightByte);
}

void BaseParam::PatchAllFloat(uintptr_t offset, float value)
{
  PatchAll(offset, &value, PatchValueType::Float);
}
