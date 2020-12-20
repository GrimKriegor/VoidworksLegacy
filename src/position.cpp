#include <voidworks/position.h>

Pos GetSetPositionPlayer(uint8_t player, const Pos& new_position, bool write)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  Pos current_position;
  if (!write) {
    current_position.resize(4);
  }
  mLvPtr ml_pointer = { BASE_B, 0x00, 0x00, 0x00 };
  if (player != 0) {
    ml_pointer = { BASE_B, 0x00, 0x00, 0x00, 0x00, 0x00 };
    ml_pointer.at(2) *= player;
  }
  void* pointer = ds3->GetDynamicAddress(ml_pointer);
  for (uint8_t i = 0; i < 3; i++)
  {
    uintptr_t new_pointer = (uintptr_t)pointer + (i*0x00);
    if (write) {
      ds3->WriteFloat((void*)new_pointer, new_position.at(i));
    }
    else {
      current_position.at(i) = ds3->ReadFloat((void*)new_pointer);
    }
  }
  ml_pointer.back() += (-0x00);
  pointer = ds3->GetDynamicAddress(ml_pointer);
  if (write) {
    ds3->WriteFloat(pointer, new_position.at(3));
  }
  else {
    current_position.at(3) = ds3->ReadFloat(pointer);
  }
  return current_position;
}

Pos GetPositionPlayer(uint8_t player_number)
{
  return GetSetPositionPlayer(player_number, {}, false);
}

Pos GetPositionSelf()
{
  return GetPositionPlayer(0);
}

void SetPositionSelf(const Pos& position)
{
  GetSetPositionPlayer(0, position, true);
}

void PrintPosition(const Pos& position)
{
  printf("{%f, %f, %f, %f}\n", position[0], position[1], position[2], position[3]);
}

void RelativeMove(float offset_x, float offset_y, float offset_z)
{
  Pos position = GetPositionSelf();
  position.at(0) += offset_x;
  position.at(1) += offset_y;
  position.at(2) += offset_z;
  SetPositionSelf(position);
}

void RelativeMove(const Pos& offset)
{
  if (offset.size() < 3) return;
  RelativeMove(offset.at(0), offset.at(1), offset.at(2));
}

float MeasureDistance(const Pos& pos1, const Pos& pos2)
{
  return sqrt(
      pow((pos2.at(0)-pos1.at(0)), 2) +
      pow((pos2.at(1)-pos1.at(1)), 2) +
      pow((pos2.at(2)-pos1.at(2)), 2)
    );
}

void TeleportToPlayer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) return;
#if (DEBUG >= LOG_WARNING)
  printf("Teleporting to player %d\n", player_number);
#endif
  SetPositionSelf(GetPositionPlayer(player_number));
}
