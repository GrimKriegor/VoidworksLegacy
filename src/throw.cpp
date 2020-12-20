#include <voidworks/throw.h>

const void* ThrowPositionHookReturn = (const void*)THROW_POSITION_HOOK_RETURN;

__m128 player_position_array = _mm_setr_ps(0.0f, 0.0f, 0.0f, 0.0f);

__asm__(
  ".global ThrowPositionHook\n\t"
  "ThrowPositionHook:\n\t"
  "movaps player_position_array(%rip), %xmm0\n\t"
  "movdqa %xmm0, 0x00(%rsp)\n\t"
  "jmp    *ThrowPositionHookReturn(%rip)"
);

void ThrowPlayer(uint8_t thrower, uint8_t throwee, uint32_t id) {
  if (!IsPlayerConnected(thrower) || !IsPlayerConnected(throwee))
  {
    printf(ANSI_ERROR_MSG "[ERROR] Attempting throw on a disconnected player!\n" ANSI_RESET);
    return;
  }
  void (*sprjThrowFunction)(...);
  uintptr_t process_base_address_ = ProcessInterface::GetInstance()->GetBaseAddress();
  *(uintptr_t*)&sprjThrowFunction = process_base_address_ + FUNC_THROW_PLAY;
  uintptr_t sprjThrowManager = *(uintptr_t*)(process_base_address_ + SPRJ_THROW_MAN);
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  void* thrower_ptr =
    ds3->GetDynamicAddress({BASE_B, 0x00, (uintptr_t)(thrower * 0x00), XA, 0x00, 0x00, 0x00});
  void* throwee_ptr =
    ds3->GetDynamicAddress({BASE_B, 0x00, (uintptr_t)(throwee * 0x00), XA, 0x00, 0x00, 0x00});
#if (DEBUG >= LOG_INFO)
    printf(ANSI_INFO_MSG
        "Throwing id %lu from player %u (%#016llx) on %u (%#016llx)\n"
        ANSI_RESET, id, thrower, thrower_ptr, throwee, throwee_ptr);
#endif
  sprjThrowFunction(sprjThrowManager, thrower_ptr, throwee_ptr, id);
}

void ThrowPlayer(uint8_t thrower, uint8_t throwee, PlayerThrows id)
{
  ThrowPlayer(thrower, throwee, (uint32_t)id);
}

void ThrowSelf(uint32_t id)
{
  ThrowPlayer(0, 0, id);
}

void ThrowSelf(PlayerThrows id)
{
  ThrowSelf((uint32_t)id);
}

void ThrowOther(uint8_t throwee, uint32_t id)
{
  ThrowPlayer(0, throwee, id);
}

void ThrowOther(uint8_t throwee, PlayerThrows id)
{
  ThrowOther(throwee, (uint32_t)id);
}

void ThrowPlayerTeleport(uint8_t thrower, uint8_t throwee, uint32_t id, const Pos& position)
{
  player_position_array = _mm_setr_ps(position.at(0), position.at(1), position.at(2), position.at(3));
  BasicHook hook = BasicHook(
      0x00,
      THROW_POSITION_HOOK_SIZE,
      (void*)THROW_POSITION_HOOK_ADDRESS,
      (void*)ThrowPositionHook
    );
  ThrowPlayer(thrower, throwee, id);
  Sleep(50);
}

void ThrowPlayerTeleport(uint8_t thrower, uint8_t throwee, PlayerThrows id, const Pos& position)
{
  ThrowPlayerTeleport(thrower, throwee, (uint32_t)id, position);
}

void ThrowPlayerTeleportOther(uint8_t throwee, uint32_t id, const Pos& position)
{
  ThrowPlayerTeleport(0, throwee, id, position);
}

void ThrowPlayerTeleportOther(uint8_t throwee, PlayerThrows id, const Pos& position)
{
  ThrowPlayerTeleportOther(throwee, (uint32_t)id, position);
}
