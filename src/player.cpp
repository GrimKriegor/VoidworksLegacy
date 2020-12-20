#include <voidworks/player.h>

void PlayerStruct::Print()
{
  printf("---\n"
         "Name:	\t%S\n"
         "Player number:\t%d\n"
         "Soul level:\t%d\n"
         "Vigor:\t\t%d\n"
         "Attunement:\t%d\n"
         "Endurance:\t%d\n"
         "Vitality:\t%d\n"
         "Strength:\t%d\n"
         "Dexterity:\t%d\n"
         "Intelligence:\t%d\n"
         "Faith:\t\t%d\n"
         "Luck:\t\t%d\n"
         "---\n",
         name, number, level, vigor, attunement, endurance,
         vitality, strength, dexterity, intelligence, faith, luck
       );
}

PlayerStruct::PlayerStruct()
{
  ds3 = ProcessInterface::GetInstance();
}

void PlayerStruct::CopyPlayer(uint8_t player_number)
{
  mLvPtr ml_base_pointer;
  if (player_number == 0) {
    ml_base_pointer = {BASE_A, 0x00};
  }
  else {
    if (!IsPlayerConnected(player_number)) { return; }
    uintptr_t player_offset = 0x00 * player_number;
    ml_base_pointer = {BASE_B, 0x00, player_offset, XB};
  }
  uintptr_t base_pointer = (uintptr_t)ds3->GetDynamicAddress(ml_base_pointer);
  ds3->ReadByteArray(ds3->GetDynamicAddress({base_pointer, 0x00}), reinterpret_cast<uint8_t*>(name), 32);
  ds3->ReadByteArray(ds3->GetDynamicAddress({base_pointer, 0x0000}), facedata, 228);
  level        = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  vigor        = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  attunement   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  endurance    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  vitality     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  strength     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  dexterity    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  intelligence = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  faith        = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
  luck         = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x00}));
}

void PlayerStruct::CopySelf()
{
  CopyPlayer(0);
}

void PlayerStruct::ApplyToSelf()
{
  uint32_t attribute_difference = CheckInvalidAttributes();
  if (attribute_difference)
  {
    printf("Not applying %d invalid attributes from %S to self\n", attribute_difference, name);
    return;
  }
  uintptr_t base_pointer = (uintptr_t)ds3->GetDynamicAddress({BASE_A, 0x00});
  ds3->WriteByteArray(ds3->GetDynamicAddress({base_pointer, 0x0000}), facedata, 228);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), level);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), vigor);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), attunement);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), endurance);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), vitality);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), strength);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), dexterity);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), intelligence);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), faith);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x00}), luck);
}

void PlayerStruct::SendAsPacket()
{
  number = ds3->ReadInt32(ds3->GetDynamicAddress({BASE_A, 0x00, 0x0000}));
  uint8_t buffer[420] = {0};
  CopyToPacketData(buffer);
  SendPacketSession(PacketId::PlayerStruct, buffer, 0x0000);
}

void PlayerStruct::SetName(const wchar_t* newname)
{
  memset(name, 0, 32);
  memcpy(name, newname, 32);
}

uint32_t PlayerStruct::CheckInvalidAttributes()
{
  uint32_t attribute_sum = vigor + attunement + endurance + vitality + strength + dexterity + intelligence + faith + luck;
  return ((attribute_sum - 89) - level);
}

void PlayerStruct::CopyToPacketData(uint8_t* data)
{
  memcpy((data+0x00), name, 32);
  memcpy((data+0x00), facedata, 228);
  memcpy((data+0x00), &number, 4);
  memcpy((data+0x00), &level, 4);
  memcpy((data+0x00), &vigor, 4);
  memcpy((data+0x00), &attunement, 4);
  memcpy((data+0x00), &endurance, 4);
  memcpy((data+0x00), &vitality, 4);
  memcpy((data+0x00), &strength, 4);
  memcpy((data+0x00), &dexterity, 4);
  memcpy((data+0x00), &intelligence, 4);
  memcpy((data+0x00), &faith, 4);
  memcpy((data+0x00), &luck, 4);
}

uint32_t GetHealthSelf()
{
  if (!IsCharacterLoaded()) { return 0; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}));
}

uint32_t GetHealthSelfMax()
{
  if (!IsCharacterLoaded()) { return 0; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}));
}

void SetHealthSelf(uint32_t value)
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}), value);
}

void SetHealthSelfFull()
{
  SetHealthSelf(GetHealthSelfMax());
}

uint32_t GetFocusSelfMax()
{
  if (!IsCharacterLoaded()) { return 0; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}));
}

void SetFocusSelf(uint32_t value)
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteInt32(ds3->GetDynamicAddress({BASE_B, 0x00, XA, 0x00, 0x00}), value);
}

void SetFocusSelfFull()
{
  SetFocusSelf(GetFocusSelfMax());
}
