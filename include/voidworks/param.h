#ifndef PARAMS_H_
#define PARAMS_H_

#include <map>
#include <string>
#include <voidworks/common.h>
#include <voidworks/process.h>

class BaseParam;

class ParamRegistry
{
  private:
    static ParamRegistry* instance_;
    ProcessInterface* ds3_;
    std::map<std::wstring, uintptr_t> master_param_table_;
    std::map<std::wstring, BaseParam*> param_registry_;
    ParamRegistry();
    void AwaitParamLoading();
    void IndexParams();
    void RestoreRegisteredParams();
  public:
    ~ParamRegistry();
    static ParamRegistry* GetInstance();
    void PrintIndexedParams();
    void PrintParamIdTable(const std::map<uint32_t, uintptr_t>&);
    uintptr_t GetParamAddress(const std::wstring&);
    std::map<uint32_t, uintptr_t> GetParamIdTable(const std::wstring&);
    void RegisterParam(const std::wstring&, BaseParam*);
    void UnregisterParam(const std::wstring&);
    BaseParam* GetRegisteredParam(const std::wstring&);
};

enum class PatchValueType : uint8_t
{
  Binary,
  Byte,
  TwoByte,
  FourByte,
  EightByte,
  Float,
};

class PatchInfo
{
  public:
    bool initialized_ = false;
    void* address_ = nullptr;
    uint8_t value_[8] = {0};
    uint8_t backup_[8] = {0};
    PatchValueType type_ = PatchValueType::Byte;
    size_t size_ = 1;
    uint8_t binary_offset_ = 0;
    PatchInfo(void*, void*, PatchValueType, uint8_t = 0);
};

class BaseParam
{
  protected:
    uint32_t id_ = 0;
    uintptr_t address_ = 0;
    std::wstring param_;
    std::wstring registry_key_;
    std::vector<PatchInfo> patch_store_;
    void ReadWritePatch(PatchInfo&, bool = true, bool = false);
    void RestorePatch(PatchInfo&);
    void ApplyPatch(PatchInfo&);
    void PatchValue(uintptr_t, void*, PatchValueType, uint8_t = 0);
    void PatchAll(uintptr_t, void*, PatchValueType, uint8_t = 0);
  public:
    BaseParam(std::wstring, uint32_t, uintptr_t = 0);
    ~BaseParam();
    void PatchBinary(uintptr_t, uint8_t, uint8_t);
    void PatchByte(uintptr_t, uint8_t);
    void Patch2Byte(uintptr_t, int16_t);
    void Patch4Byte(uintptr_t, int32_t);
    void Patch8Byte(uintptr_t, int64_t);
    void PatchFloat(uintptr_t, float);
    void PatchAllBinary(uintptr_t, uint8_t, uint8_t);
    void PatchAllByte(uintptr_t, uint8_t);
    void PatchAll2Byte(uintptr_t, int16_t);
    void PatchAll4Byte(uintptr_t, int32_t);
    void PatchAll8Byte(uintptr_t, int64_t);
    void PatchAllFloat(uintptr_t, float);
};

#endif
