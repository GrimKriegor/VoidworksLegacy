#include <voidworks/boss.h>

Boss::Boss()
{
  player_original->CopySelf();
  equipment_original->CopySelf();
  player->CopySelf();
  equipment->CopySelf();
}

Boss::~Boss()
{
  player_original->ApplyToSelf();
  player_original->SendAsPacket();
  equipment_original->SetCharAsm();
  equipment_original->SendAsPacket();
}

void Boss::Init()
{
  Transform();
  Loop();
}

void Boss::Transform()
{
  player->SetName(name);
  player->ApplyToSelf();
  player->SendAsPacket();
  equipment->SetCharAsm();
  equipment->SendAsPacket();
}
