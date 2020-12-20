#ifndef EFFECT_H_
#define EFFECT_H_

#include <voidworks/common.h>
#include <voidworks/packet.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

enum class EffectId : uint32_t;
void EffectToDataBlock(uint8_t*, uint32_t, uint32_t, float);
void ApplyEffectEntity(const void*, uint32_t);
void ApplyEffectSelf(uint32_t);
void ApplyEffectSelf(EffectId);
void ApplyEffectPlayer(uint8_t, uint32_t, bool=true, float=1);
void ApplyEffectPlayer(uint8_t, EffectId, bool=true, float=1);

enum class EffectId : uint32_t
{
  ActionEventInfo      = 112022000,
  AddSoul              = 3289,
  ArenaBurst           = 1420000,
  ArenaCrownGold       = 1420040,
  ArenaCrownSilver     = 1420050,
  ArmorBreak           = 12630,
  Bleed                = 3115,
  Bonfire              = 110,
  Chameleon            = 3870,
  CrystalCurse         = 34,
  CrystalLizardShimmer = 12170,
  Curse                = 33,
  CurseBuildup         = 23100,
  DS1HumanityRestored  = 3230,
  DarkFog              = 16190,
  DivineBlessing       = 3080,
  DotInFrontOfPlayer   = 12070,
  DragonBody           = 3610,
  DragonChange         = 1520,
  DragonChange2        = 1521,
  DragonTorsoBuff      = 3650,
  Dragonbody           = 3610,
  Dragonhead           = 3600,
  Drain                = 1600,
  Drain2               = 1610,
  Drain3               = 1620,
  Drain4               = 1630,
  DriedFinger          = 28,
  Ember                = 3290,
  FreezeSelf           = 4902,
  FrostCurse           = 45,
  Glow                 = 10932,
  HeraldHumanityHead   = 140000000,
  HitPlayerVisible     = 12150,
  HitPlayerVisible2    = 12153,
  HollowingReversed    = 3090,
  HumanityHead         = 16323,
  HumanityHead2        = 16325,
  HumanityStolen       = 13,
  Instadeath           = 11013,
  InvTriggerAldriches  = 9010,
  InvTriggerSpears     = 9020,
  InvTriggerWatchdogs  = 9000,
  Kill                 = 11013,
  LightCircles         = 12000,
  MoundBurst           = 9400,
  NoPhantomToSendHome  = 6,
  Overemcumbered       = 500,
  RemoveCurse          = 3094,
  RimeBlueMoss         = 3092,
  RimeBlueMossDivine   = 3091,
  SilverCrown          = 1420050,
  SlowWalk             = 12050,
  StunDeath            = 103750410,
  TearsOfDenial        = 103520000,
  TwinklingDragonHead  = 3640,
  VowOfSilence         = 600,
  VowOfSilence2        = 610,
  VowOfSilence3        = 611,
};

static auto& GetMaliciousEffectsList()
{
  static const std::vector<EffectId> MaliciousEffectsList
  {
    EffectId::ArmorBreak,
    EffectId::CrystalCurse,
    EffectId::Curse,
    EffectId::DS1HumanityRestored,
    EffectId::DarkFog,
    EffectId::Drain,
    EffectId::Drain2,
    EffectId::Drain3,
    EffectId::Drain4,
    EffectId::FreezeSelf,
    EffectId::FrostCurse,
    EffectId::FrostCurse,
    EffectId::HitPlayerVisible,
    EffectId::HitPlayerVisible2,
    EffectId::HumanityStolen,
    EffectId::Instadeath,
    EffectId::LightCircles,
    EffectId::Overemcumbered,
    EffectId::SlowWalk,
    EffectId::StunDeath,
  };
  return MaliciousEffectsList;
}

#endif
