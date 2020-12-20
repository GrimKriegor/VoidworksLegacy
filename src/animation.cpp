#include <voidworks/animation.h>

AnimCategory GetAnimCategoryById(uint32_t id)
{
  switch(id)
  {
    case 17000 ... 18000:
      return AnimCategory::Death;
    default:
      return AnimCategory::Unhandled;
  }
}

uint32_t GetAnimationPlayer(uint8_t player_number, bool lingering)
{
  if (!player_number && !IsCharacterLoaded()) return 0;
  else if (!IsPlayerConnected(player_number)) return 0;
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t player_offset = 0x00 * player_number;
  mLvPtr ml_ptr = {BASE_B, 0x00, player_offset, XA};
  if (lingering) ml_ptr.insert(ml_ptr.end(), {0x00, 0x00});
  else           ml_ptr.insert(ml_ptr.end(), {0x00, 0x00});
  return ds3->ReadInt32(ds3->GetDynamicAddress(ml_ptr));
}

uint32_t GetAnimationSelf(bool lingering)
{
  return GetAnimationPlayer(0, lingering);
}

void SetAnimationSpeed(float speed)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteFloat(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x0000}), speed);
}

void FreezeAnimation()
{
  SetAnimationSpeed(0.0f);
}

void RestoreAnimationSpeed()
{
  SetAnimationSpeed(1.0f);
}

void SetAnimation(const void* target, uint32_t id)
{
  if (!target) { return; }
  int(*sprjAnimFunction)(...);
  *(uintptr_t*)&sprjAnimFunction =
    ProcessInterface::GetInstance()->GetBaseAddress() + FUNC_ANIM_PLAY;
  char anim_data[24] = {0};
  memcpy(anim_data, &id, 4);
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG
      "Playing animation id %u on %#016llx\n"
      ANSI_RESET,
      id, target);
#endif
  sprjAnimFunction(target, anim_data);
}

void SetAnimationSelf(uint32_t id)
{
  if (!IsCharacterLoaded()) return;
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  void* player_ptr = ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00, XA, 0x00, 0x00, 0x00, 0x00, 0x00});
  SetAnimation(player_ptr, id);
}

void SetAnimationSelf(PlayerAnimation id)
{
  SetAnimationSelf((uint32_t)id);
}

void SetAnimationTarget(uint32_t id)
{
  if (!IsCharacterLoaded()) return;
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  TargetTracker* target_tracker = TargetTracker::GetInstance();
  if (!target_tracker->IsLockedOn()) { return; }
  void* target_base_ptr = target_tracker->GetTarget();
  void* target_ptr = ds3->GetDynamicAddress({(uintptr_t)target_base_ptr, XA, 0x00, 0x00, XA, 0x00, 0x00, 0x00, 0x00, 0x00});
  SetAnimation(target_ptr, id);
}

void SetAnimationTarget(PlayerAnimation id)
{
  SetAnimationTarget((uint32_t)id);
}

void SetAnimationIdle(uint32_t id)
{
  if (!IsCharacterLoaded()) return;
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG
      "Playing idle animation id %d\n"
      ANSI_RESET,
      id);
#endif
  ds3->WriteInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}), id);
}

void SetAnimationIdle(IdleAnimation id)
{
  SetAnimationIdle((uint32_t)id);
}

void SetAnimationPlayer(uint8_t player_number, uint32_t id)
{
  if (!IsPlayerConnected(player_number)) return;
  PacketStruct::MsgMap buffer;
  buffer.msg_id   = 0x0000;
  buffer.event_id = 0x0000;
  buffer.param_1  = 0x0000;
  buffer.param_2  = id;
  buffer.player_number_abs = GetPlayerNumberAbsolute(player_number);
#if (DEBUG >= LOG_WARNING)
  printf("Playing animation id %u on player %d\n", id, player_number);
#endif
  SendPacketSession(PacketId::MsgMap, &buffer, sizeof(buffer));
}

void SetAnimationPlayer(uint8_t player_number, IdleAnimation id)
{
  SetAnimationPlayer(player_number, (uint32_t)id);
}

bool IsAnimationBeingPerformedInSession(uint32_t id)
{
  if (GetAnimationSelf(true) == id) return true;
  for (uint8_t i = 1; i <= 5; i++)
  {
    if (GetAnimationPlayer(i, true) == id) return true;
  }
  return false;
}

bool IsAnimationBeingPerformedInSession(PlayerAnimation id)
{
  return IsAnimationBeingPerformedInSession((uint32_t)id);
}
