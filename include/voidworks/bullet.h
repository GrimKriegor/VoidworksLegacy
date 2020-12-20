#ifndef BULLET_H_
#define BULLET_H_

#include <cstring>
#include <vector>
#include <math.h>
#include <voidworks/common.h>
#include <voidworks/process.h>

#define BULLET_DATA_SIZE 256

enum class BulletId : uint32_t;

class BulletInstance
{
  private:
    void (*sprjSpawnBullet)(...);
    uintptr_t sprjBulletManager = 0;
    uint8_t bullet_data_[BULLET_DATA_SIZE] = {0};
    void WriteBulletData(uint64_t, void*, size_t);

  public:
    BulletInstance();
    void SetPlayerHandle(uint64_t);
    void SetId(uint64_t);
    void SetId(BulletId);
    void SetCoord(const Pos&);
    void SetAngle(const Pos&);
    void SetCoordAngleFromPlayerPos(const Pos&);
    void Spawn();
    void Spawn(uint64_t);
    void Spawn(BulletId);
    void SpawnAt(const Pos&);
    void SpawnAt(uint64_t, const Pos&);
    void SpawnAt(BulletId, const Pos&);
};

enum class BulletId : uint32_t
{
  AcidSurge       = 12422000,
  ArrowExplosion  = 704,
  BoulderHeave    = 12630000,
  CaressingTears  = 13508000,
  DragonFumeBurst = 246,
  EarthPillar     = 6100705,
  FireExplosion   = 12455200,
  Force           = 13532000,
  PillarOfLight   = 13720100,
  RestoreHP       = 226,
  SeethingChaos   = 12660000,
  Shockwave       = 5190710,
  SlayerExplosion = 2150020,
  SoulStream      = 11620000,
  StormRulerShock = 100063730,
  Warmth          = 12470000,
  WrathOfTheGods  = 30,
};

#endif
