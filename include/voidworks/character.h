#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/param_classes.h>
#include <voidworks/process.h>

#define UNLOCK_BONFIRES_HOOK_ADDRESS 0x000000000000
#define UNLOCK_BONFIRES_HOOK_SIZE    6
#define UNLOCK_BONFIRES_HOOK_RETURN  (UNLOCK_BONFIRES_HOOK_ADDRESS+UNLOCK_BONFIRES_HOOK_SIZE)
#define UNLOCKED_GESTURE_DATA_SIZE   132

extern "C"
{
  void UnlockBonfiresHook(void);
}

void UnlockAllGestures();
void UnlockAllBonfires();
enum class SheatState : uint8_t;
void SetSheatState();

#endif
