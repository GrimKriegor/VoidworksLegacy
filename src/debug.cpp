#include <voidworks/debug.h>

void DebugFlag::WriteDebugFlagBinary(mLvPtr ml_pointer, uint8_t position, bool state)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteBinary(ds3->GetDynamicAddress(ml_pointer), position, state);
}

void DebugFlag::WriteDebugFlagByte(mLvPtr ml_pointer, bool state)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteByte(ds3->GetDynamicAddress(ml_pointer), state);
}

void DebugFlag::NoGravity(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, 0x0000}, 6, state);
}

void DebugFlag::NoDeath(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, XA, 0x00, 0x0000}, 2, state);
}

void DebugFlag::NoDamage(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, XA, 0x00, 0x0000}, 1, state);
}

void DebugFlag::NoStaminaDrain(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, XA, 0x00, 0x0000}, 4, state);
}

void DebugFlag::NoFocusDrain(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, XA, 0x00, 0x0000}, 5, state);
}

void DebugFlag::NoConsumeGoods(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, 0x0000}, 3, state);
}

void DebugFlag::NoConsumeArrows(bool state)
{
  WriteDebugFlagByte({DEBUG_FLAGS+0x00}, state);
}

void DebugFlag::NoHit(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, 0x0000}, 5, state);
}

void DebugFlag::InfinitePoise(bool state)
{
  WriteDebugFlagBinary({BASE_B, 0x00, XA, 0x00, 0x00}, 0, state);
}

void DebugFlag::NoAI(bool state)
{
  WriteDebugFlagByte({DEBUG_FLAGS+0x00+0x00}, state);
}

void DebugFlag::Collision(bool state)
{
  WriteDebugFlagBinary({BASE_D, 0x00, 0x00}, 0, state);
}
