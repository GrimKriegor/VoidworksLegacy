#include <voidworks/equipment.h>

void EquipmentStruct::Print()
{
  printf("---\n"
         "Head:\t\t%d\n"
         "Chest:\t\t%d\n"
         "Hands:\t\t%d\n"
         "Legs:\t\t%d\n"
         "Ring 1:\t\t%d\n"
         "Ring 2:\t\t%d\n"
         "Ring 3:\t\t%d\n"
         "Ring 4:\t\t%d\n"
         "Weapon L 1:\t%d\n"
         "Weapon L 2:\t%d\n"
         "Weapon L 3:\t%d\n"
         "Weapon R 1:\t%d\n"
         "Weapon R 2:\t%d\n"
         "Weapon R 3:\t%d\n"
         "Arrow 1:\t%d\n"
         "Arrow 2:\t%d\n"
         "Bolt 1:\t\t%d\n"
         "Bolt 2:\t\t%d\n"
         "Covenant:\t%d\n"
         "Number:\t\t%d\n"
         "Gender:\t\t%d\n"
         "---\n",
         head, chest, hands, legs, ring_1, ring_2, ring_3,
         ring_4, weapon_l_1, weapon_l_2, weapon_l_3, weapon_r_1,
         weapon_r_2, weapon_r_3, arrow_1, arrow_2, bolt_1, bolt_2,
         covenant, number, gender
       );
}

EquipmentStruct::EquipmentStruct()
{
  ds3 = ProcessInterface::GetInstance();
}

void EquipmentStruct::CopyPlayer(uint8_t player_number)
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
  gender     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  head       = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  chest      = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  hands      = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  legs       = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  ring_1     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  ring_2     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  ring_3     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  ring_4     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_l_1 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_l_2 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_l_3 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_r_1 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_r_2 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  weapon_r_3 = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  arrow_1    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  arrow_2    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  bolt_1     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  bolt_2     = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  //covenant   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
}

void EquipmentStruct::CopySelf()
{
  CopyPlayer(0);
}

void EquipmentStruct::SetCharAsm()
{
  uintptr_t base_pointer = (uintptr_t)ds3->GetDynamicAddress({BASE_A, 0x00});
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), gender);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), head);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), chest);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), hands);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), legs);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), ring_1);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), ring_2);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), ring_3);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), ring_4);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_l_1);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_l_2);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_l_3);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_r_1);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_r_2);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), weapon_r_3);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), arrow_1);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), arrow_2);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), bolt_1);
  ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), bolt_2);
  //ds3->WriteInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}), covenant);
}

void EquipmentStruct::SendAsPacket()
{
  number = ds3->ReadInt32(ds3->GetDynamicAddress({BASE_A, 0x00, 0x0000}));
  uint8_t buffer[144] = {0};
  CopyToPacketData(buffer);
  SendPacketSession(PacketId::Equipment, buffer, 0x00);
}

void EquipmentStruct::CopyToPacketData(uint8_t* data)
{
  memcpy((data+0x00), &number, 4);
  memcpy((data+0x00), &gender, 4);
  memcpy((data+0x00), &head, 4);
  memcpy((data+0x00), &chest, 4);
  memcpy((data+0x00), &hands, 4);
  memcpy((data+0x00), &legs, 4);
  memcpy((data+0x00), &ring_1, 4);
  memcpy((data+0x00), &ring_2, 4);
  memcpy((data+0x00), &ring_3, 4);
  memcpy((data+0x00), &ring_4, 4);
  memcpy((data+0x00), &weapon_l_1, 4);
  memcpy((data+0x00), &weapon_l_2, 4);
  memcpy((data+0x00), &weapon_l_3, 4);
  memcpy((data+0x00), &weapon_r_1, 4);
  memcpy((data+0x00), &weapon_r_2, 4);
  memcpy((data+0x00), &weapon_r_3, 4);
  //memcpy((data+0x00), &arrow_1, 4);
  //memcpy((data+0x00), &arrow_2, 4);
  //memcpy((data+0x00), &bolt_1, 4);
  //memcpy((data+0x00), &bolt_2, 4);
  //memcpy((data+0x00), &covenant, 4);
}

void EquipmentStructExtended::CopyPlayer(uint8_t player_number)
{
  EquipmentStruct::CopyPlayer(player_number);
  mLvPtr ml_base_pointer;
  if (player_number == 0) {
    ml_base_pointer = {BASE_A, 0x00, 0x0000};
  }
  else {
    uintptr_t player_offset = 0x00 * player_number;
    ml_base_pointer = {BASE_B, 0x00, player_offset, XB};
  }
  uintptr_t base_pointer = (uintptr_t)ds3->GetDynamicAddress(ml_base_pointer);
  spell_1    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_2    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_3    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_4    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_5    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_6    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_7    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_8    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_9    = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_10   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_11   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_12   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_13   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
  spell_14   = ds3->ReadInt32(ds3->GetDynamicAddress({base_pointer, 0x0000}));
}

void EquipmentStructExtended::CopySelf()
{
  CopyPlayer(0);
}

void EquipmentStructExtended::SetCharAsm()
{
  EquipmentStruct::SetCharAsm();
}
