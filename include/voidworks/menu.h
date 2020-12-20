#ifndef MENU_H_
#define MENU_H_

#include <voidworks/common.h>
#include <voidworks/input.h>
#include <voidworks/process.h>

enum class MenuId : uintptr_t;
uintptr_t GetMenuAddress(MenuId);
void OpenMenu(MenuId);
MenuId MenuIdSelectorPrompt();
void OpenMenuPrompt();

enum class MenuId : uintptr_t
{
  None        = NULL,
  Appearance  = FUNC_MENU_APPEARANCE,
  Arena       = FUNC_MENU_ARENA,
  Attunement  = FUNC_MENU_ATTUNEMENT,
  BonfireWarp = FUNC_MENU_BONFIREWARP,
  Rebirth     = FUNC_MENU_REBIRTH,
  StorageBox  = FUNC_MENU_STORAGEBOX,
};

#endif
