#ifndef THROW_H_
#define THROW_H_

#include <immintrin.h>
#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

#define THROW_POSITION_HOOK_ADDRESS 0x000000000000
#define THROW_POSITION_HOOK_SIZE 6
#define THROW_POSITION_HOOK_RETURN (THROW_POSITION_HOOK_ADDRESS+THROW_POSITION_HOOK_SIZE)

extern "C"
{
  void ThrowPositionHook(void);
}

enum class PlayerThrows : uint32_t;
void ThrowPlayer(uint8_t, uint8_t, uint32_t);
void ThrowPlayer(uint8_t, uint8_t, PlayerThrows);
void ThrowSelf(uint32_t);
void ThrowSelf(PlayerThrows);
void ThrowOther(uint8_t, uint32_t);
void ThrowOther(uint8_t, PlayerThrows);
void ThrowPlayerTeleport(uint8_t, uint8_t, uint32_t, const Pos&);
void ThrowPlayerTeleport(uint8_t, uint8_t, PlayerThrows, const Pos&);
void ThrowPlayerTeleportOther(uint8_t, uint32_t, const Pos&);
void ThrowPlayerTeleportOther(uint8_t, PlayerThrows, const Pos&);

enum class PlayerThrows : uint32_t
{
  Backstab             = 100,
  Bounce               = 552701,
  Knockdown            = 521311,
  LycanthropeBite      = 513601,
  MaggotsDog           = 520800,
  MimicHug             = 521200,
  Ressurection         = 512200,
  Riposte              = 101,
  StormKingLargeThrow  = 650300,
  Stumble              = 522301,
  StumbleAndFall       = 512000,
  Wiggles              = 521300,
  WolfThrow            = 520400,
  Wraith               = 531700,
};

#endif
