#include <voidworks/bullet.h>

BulletInstance::BulletInstance()
{
  uintptr_t process_base_address_ = ProcessInterface::GetInstance()->GetBaseAddress();
  sprjBulletManager = *(uintptr_t*)(process_base_address_ + SPRJ_BULLET_MANAGER);
  *(uintptr_t*)&sprjSpawnBullet = process_base_address_ + FUNC_BULLET_SPAWN;
  uint64_t ServerSideFlag = 0x00;
  WriteBulletData(0x00, &ServerSideFlag, 4);
  uint64_t PlayerHandle = 0x00000000;
  WriteBulletData(0x00, &PlayerHandle, 4);
}

void BulletInstance::WriteBulletData(uint64_t offset, void* buffer, size_t size)
{
  memcpy((bullet_data_ + 0x00 + offset), buffer, size);
}

void BulletInstance::SetPlayerHandle(uint64_t handle)
{
  WriteBulletData(0x00, &handle, 4);
}

void BulletInstance::SetId(uint64_t id)
{
  WriteBulletData(0x00, &id, 4);
}

void BulletInstance::SetId(BulletId id)
{
  SetId((uint64_t)id);
}

void BulletInstance::SetCoord(const Pos& coords)
{
  WriteBulletData(0x00, (void*)&coords.at(0), 4);
  WriteBulletData(0x00, (void*)&coords.at(1), 4);
  WriteBulletData(0x00, (void*)&coords.at(2), 4);
}

void BulletInstance::SetAngle(const Pos& angles)
{
  WriteBulletData(0x00, (void*)&angles.at(0), 4);
  WriteBulletData(0x00, (void*)&angles.at(1), 4);
  WriteBulletData(0x00, (void*)&angles.at(2), 4);
}

void BulletInstance::SetCoordAngleFromPlayerPos(const Pos& pos)
{
  float angle = pos.at(3);
  Pos angle_vector = { -sin(angle), 0, -cos(angle) };
  SetCoord(pos);
  SetAngle(angle_vector);
}

void BulletInstance::Spawn()
{
  sprjSpawnBullet(sprjBulletManager, bullet_data_, (bullet_data_+0x00));
}

void BulletInstance::Spawn(uint64_t id)
{
  SetId(id);
  Spawn();
}

void BulletInstance::Spawn(BulletId id)
{
  Spawn((uint64_t)id);
}

void BulletInstance::SpawnAt(const Pos& position)
{
  SetCoordAngleFromPlayerPos(position);
  Spawn();
}

void BulletInstance::SpawnAt(uint64_t id, const Pos& position)
{
  SetCoordAngleFromPlayerPos(position);
  Spawn(id);
}

void BulletInstance::SpawnAt(BulletId id, const Pos& position)
{
  SpawnAt((uint64_t)id, position);
}
