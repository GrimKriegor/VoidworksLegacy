#include <voidworks/world.h>

const uint64_t mob_kill_list[MOB_KILL_LIST_SIZE] = {
  13511005043884081, 13511030813687857, 13511035108655153, 15199872084082737,
  13792497200529457, 13511013633622066, 13511035108589618, 13792510085300274,
  14073967882010673, 13511005043753009, 13792488610332722, 14918379927306289,
  13511039403556913, 14073989356978225, 13511022223687729, 13511005043818545,
  13511017928720433, 13511030813622321, 13511043698393139, 13511009338720306,
  13511039403556914, 13511022223818801, 13511026518655025, 13511022223753265,
  13511043698458674, 14073954997174321, 13511013633622067, 15199863494017077,
  15481338470727733, 14918388517306421, 13511043698589745, 13792518675300401,
  13511009338916913, 13511013633753139, 13511035108524081, 13511035108458545,
  13511039403491377, 13511017928654898, 13511017928589362, 13511026518720561,
  13511022223687733, 13511005043753010, 13511035108458547, 14073967882076210,
  13792484315496497, 13511009338851377, 13511017928720435, 13511022223622194,
  13511035108720689, 13511017928851505, 13511009338785842, 13511009338785841,
  13511035108524083, 14918397107372081, 14355438563885109, 13792514380267569,
  13511043698458673, 13511005043687478, 13511043698393142, 13511026518523958,
  13511030813491254, 13511005043753014, 13511039403425846, 13511022223556662,
  13511017928654902, 13792514380136502, 13511035108458550, 13511017928720438,
  13792492905431094, 13511013633818678, 13511026518655030, 14355464333688881,
  13511022223687734, 13792480020529201, 13792510085169201, 13511039403556918,
  13511030813622326, 13511035108458550, 13511043698524214, 13511017928785974,
  13792492905496630, 13511009338785843, 13511043698524210, 13511017928654897,
  13511013633687603, 13511026518589490, 13511005043753011, 13511013633753137,
  13792492905365554, 13511039403491378, 13511030813491250, 13511017928720434,
  13511035108458546, 13792497200398385, 13792518675169330, 13511022223556658,
  14073972177240113, 13511043698393137, 13792480020463665, 15199854904016945,
  13792497200332851, 13511039403622449, 13511039403425842, 13511035108589622
};

bool IsValidEntityPtr(mLvPtr ml_pointer)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t pointer = (uintptr_t)ds3->GetDynamicAddress(ml_pointer);
  if (pointer > 0x000000000000 || pointer < 0x000000000000)
  {
    return false;
  }
  return true;
}

void KillMobs()
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uint32_t mob_index = 0;
  uint32_t mob_kill_count = 0;
  while (true)
  {
#if (DEBUG >= LOG_DEBUG)
    printf(ANSI_INFO_MSG "Entity index %d\n" ANSI_RESET, mob_index);
#endif
    mLvPtr entity_mlptr = {BASE_B, 0x0000, 0x00, (mob_index*0x00), XA};
    if (!IsValidEntityPtr(entity_mlptr)) { break; }
    entity_mlptr.push_back(0x00);
    if (!IsValidEntityPtr(entity_mlptr)) { break; }
    mLvPtr entity_mlptr_id = entity_mlptr;
    entity_mlptr_id.push_back(0x0000);
    if (!IsValidEntityPtr(entity_mlptr_id)) { break; }
    mLvPtr entity_mlptr_hp = entity_mlptr;
    entity_mlptr_hp.push_back(0x00);
    if (!IsValidEntityPtr(entity_mlptr_hp)) { break; }
    uint64_t entity_id = ds3->ReadInt64(ds3->GetDynamicAddress(entity_mlptr_id));
    for (int16_t i = 0; i < MOB_KILL_LIST_SIZE; i++)
    {
      if (entity_id != mob_kill_list[i]) { continue; }
      ds3->WriteInt32(ds3->GetDynamicAddress(entity_mlptr_hp), 0);
      mob_kill_count++;
      Sleep(25);
    }
    mob_index++;
  }
#if (DEBUG >= LOG_WARNING)
  printf("All %d mobs are now dead!\n", mob_kill_count);
#endif
}

void* FindEntityPointer(uint16_t forward_id)
{
  if (!IsCharacterLoaded()) { return NULL; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  void* current_entity_ptr = NULL;
  uint16_t current_entity_id = 0;
  for (uint32_t i = 0; i < 0x00; i++)
  {
    for (uint32_t j = 0; j < 0x00; j++)
    {
      printf("i %d j %d\n", i, j);
      mLvPtr current_entity_mlptr = {BASE_B, (0x0000+j*8), 0x00, (0x00*i)};
      if (!IsValidEntityPtr(current_entity_mlptr)) { continue; }
      current_entity_ptr = ds3->GetDynamicAddress(current_entity_mlptr);
      printf("%llx\n", current_entity_ptr);
      current_entity_id = ds3->ReadInt16(
          ds3->GetDynamicAddress({(uintptr_t)current_entity_ptr, 0x00})
      );
      if (current_entity_id == forward_id) {
        return current_entity_ptr;
      }
    }
    printf("i %d\n", i);
    mLvPtr current_entity_mlptr = {BASE_B, 0x00, (0x00*i)};
    if (!IsValidEntityPtr(current_entity_mlptr)) { continue; }
    current_entity_ptr = ds3->GetDynamicAddress(current_entity_mlptr);
    current_entity_id = ds3->ReadInt16(
        ds3->GetDynamicAddress({(uintptr_t)current_entity_ptr, 0x00})
    );
    if (current_entity_id == forward_id) {
      return current_entity_ptr;
    }
  }
  return NULL;
}

void* FindEntityPointer(EntityId forward_id)
{
  return FindEntityPointer((uint16_t)forward_id);
}

EntityInterface::EntityInterface()
{
  ds3_ = ProcessInterface::GetInstance();
}

EntityInterface::EntityInterface(uint16_t forward_id)
{
  forward_id_ = forward_id;
  base_pointer_ = GetPointer();
  EntityInterface();
}

EntityInterface::EntityInterface(EntityId forward_id)
{
  EntityInterface((uint32_t)forward_id_);
}

EntityInterface::EntityInterface(void* base_pointer)
{
  base_pointer_ = base_pointer;
  forward_id_ = GetForwardId();
  EntityInterface();
}

EntityInterface::~EntityInterface()
{
  SetNoDead(false);
  SetGravity(true);
}

uint32_t EntityInterface::GetForwardId()
{
  if (!forward_id_)
  {
    forward_id_ = ds3_->ReadInt16(
        ds3_->GetDynamicAddress({(uintptr_t)base_pointer_, 0x00})
    );
  }
  return forward_id_;
}

void* EntityInterface::GetPointer()
{
  if (!base_pointer_)
  {
    base_pointer_ = FindEntityPointer(forward_id_);
  }
  return base_pointer_;
}

bool EntityInterface::IsLoaded()
{
  return ds3_->IsMlPointerDereferenceable({(uintptr_t)base_pointer_, 0x00});
}

void EntityInterface::SetHealth(uint32_t value)
{
  ds3_->WriteInt32(ds3_->GetDynamicAddress({(uintptr_t)base_pointer_, XA, 0x00, 0x00}), value);
}

void EntityInterface::SetPosition(Pos position)
{

}

void EntityInterface::SetNoDead(bool state)
{

}

void EntityInterface::SetGravity(bool state)
{

}
