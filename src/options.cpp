#include <voidworks/options.h>

void Options::SoundAndDisplay::HUD(uint8_t value)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteByte(ds3->GetDynamicAddress({BASE_A, 0x00, 0x00}), value);
}
