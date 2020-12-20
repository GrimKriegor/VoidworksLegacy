#ifndef DEBUG_H_
#define DEBUG_H_

#include <voidworks/common.h>
#include <voidworks/process.h>

class DebugFlag
{
  public:
    static void WriteDebugFlagBinary(mLvPtr, uint8_t, bool);
    static void WriteDebugFlagByte(mLvPtr, bool);
    static void NoGravity(bool);
    static void NoDeath(bool);
    static void NoDamage(bool);
    static void NoStaminaDrain(bool);
    static void NoFocusDrain(bool);
    static void NoConsumeGoods(bool);
    static void NoConsumeArrows(bool);
    static void NoHit(bool);
    static void InfinitePoise(bool);
    static void NoAI(bool);
    static void Collision(bool);
};

#endif
