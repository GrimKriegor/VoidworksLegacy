#ifndef PACKET_STRUCT_H_
#define PACKET_STRUCT_H_

#include <voidworks/common.h>

namespace PacketStruct
{

struct Player
{
  uint32_t number;
  const uint8_t padding0[40];
  uint32_t vigor;
  uint32_t attunement;
  uint32_t endurance;
  uint32_t strength;
  uint32_t dexterity;
  uint32_t intelligence;
  uint32_t faith;
  uint32_t luck;
  uint32_t vitality;
  uint32_t level;
  const uint8_t padding1[4];
  wchar_t name[16];
  const uint8_t padding2[64];
  uint8_t facedata[228];
  const uint8_t padding3[24];
}
__attribute__((__packed__));

struct Equipment
{
  uint32_t number;
  uint8_t gender;
  const uint8_t padding0[1];
  uint8_t voice;
  uint8_t covenant;
  const uint8_t padding1[4];
  uint32_t weapon_l_1;
  uint32_t weapon_r_1;
  uint32_t weapon_l_2;
  uint32_t weapon_r_2;
  uint32_t weapon_l_3;
  uint32_t weapon_r_3;
  uint32_t arrow_1;
  uint32_t bolt_1;
  uint32_t arrow_2;
  uint32_t bolt_2;
  uint32_t arrow_3;
  uint32_t bolt_3;
  const uint8_t padding2[8];
  uint32_t head;
  uint32_t chest;
  uint32_t hands;
  uint32_t legs;
  const uint8_t padding4[4];
  uint32_t ring_1;
  uint32_t ring_2;
  uint32_t ring_3;
  uint32_t ring_4;
  uint32_t covenant_item;
  const uint8_t padding5[40];
}
__attribute__((__packed__));

struct MsgMap
{
  uint32_t msg_id;
  uint32_t event_id;
  uint32_t param_1;
  uint32_t param_2;
  uint32_t player_number_abs;
}
__attribute__((__packed__));

struct CompleteEvent
{
  uint32_t id;
}
__attribute__((__packed__));

struct Damage
{
  uint32_t physical;
  uint32_t magic;
  uint32_t fire;
  uint32_t lightning;
  uint32_t dark;
  const uint8_t padding0[28];
  uint16_t base0;
  uint16_t base1;
  uint16_t base2;
  uint16_t base3;
  uint16_t base4;
  const uint8_t padding1[2];
  uint32_t guard_damage;
  const uint8_t padding2[4];
  uint32_t id;
  uint32_t headshot;
  const uint8_t padding3[68];
  float pos_x;
  float pos_y;
  float pos_z;
}
__attribute__((__packed__));

struct Effect
{
  uint32_t player_id;
  uint32_t value;
  uint32_t id;
  uint32_t param;
}
__attribute__((__packed__));

struct ItemDrop
{
  uint32_t type;
  const uint8_t unmapped[156];
}
__attribute__((__packed__));

}

#endif
