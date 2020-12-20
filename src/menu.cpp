#include <voidworks/menu.h>

void OpenMenu(MenuId id)
{
  uintptr_t menu_address = (uintptr_t)id;
  if (!menu_address) { return; }
  uint8_t buffer[48] = {0};
  void (*sprjMenuFunction)(...);
  uintptr_t process_base_address = ProcessInterface::GetInstance()->GetBaseAddress();
  *(uintptr_t*)&sprjMenuFunction = process_base_address + menu_address;
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "Opening menu at %#llx\n" ANSI_RESET, menu_address);
#endif
  sprjMenuFunction(buffer);
}

MenuId MenuIdSelectorPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "MenuIdSelector keyboard prompt\n" ANSI_RESET);
#endif
  printf(ANSI_BHYEL "1) Appearance\n2) Arena\n3) Attunement\n"
         "4) BonfireWarp\n5) Rebirth\n6) StorageBox\n" ANSI_RESET);
  while (true)
  {
    if      (IsKeyDown(VirtualKey::Number_1)) { return MenuId::Appearance; }
    else if (IsKeyDown(VirtualKey::Number_2)) { return MenuId::Arena; }
    else if (IsKeyDown(VirtualKey::Number_3)) { return MenuId::Attunement; }
    else if (IsKeyDown(VirtualKey::Number_4)) { return MenuId::BonfireWarp; }
    else if (IsKeyDown(VirtualKey::Number_5)) { return MenuId::Rebirth; }
    else if (IsKeyDown(VirtualKey::Number_6)) { return MenuId::StorageBox; }
    else if (IsKeyDown(VirtualKey::Escape))   { break; }
  }
  return MenuId::None;
}

void OpenMenuPrompt()
{
  OpenMenu(MenuIdSelectorPrompt());
}
