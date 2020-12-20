#include <voidworks.h>

#define PROJECT_NAME "Debug client"

void MainThread()
{
  // Documentation
  const char HELP_TEXT[] = ANSI_YEL
    "\nAvailable commands:\n"
      "Del) Toggle keybinds\n"
      "Shift+Del) Unload " PROJECT_NAME "\n"
    "\nSession:\n"
      "K) Kill player\n"
      "O) Toggle automatic red sign\n"
      "X) Block events\n"
      "Numpad 7) Activate red orb\n"
      "Numpad 8) Disconnect from session\n"
      "Numpad 9) Toggle covenants\n"
      "Shift+K) Kick player from session\n"
      "Shift+O) Toggle automatic summon\n"
      "Shift+P) Set phantom type\n"
      "Shift+Z) Toggle automatic red orb\n"
      "Shift+F8) Toggle unlimited summon\n"
    "\nModes:\n"
      "P) Shapeshift into a player\n"
      "Shift+F1) Toggle fight club mode\n"
      "Shift+F2) Start Pontiff survival\n"
    "\nAnimation:\n"
      "I) Idle animation on self\n"
      "U) Play animation on self\n"
      "V) Unfreeze animation\n"
      "Shift+I) Idle animation on player\n"
      "Shift+V) Freeze animation\n"
    "\nPosition:\n"
      "T) Teleport to player\n"
      "Shift+T) Teleport player to you\n"
      "Page Up) Move up\n"
      "Page Dn) Move down\n"
      "Numpad 4) Toggle collision\n"
      "Numpad 5) Store position\n"
      "Numpad 6) Restore position\n"
    "\nHelpers:\n"
      "C) Manipulate camera\n"
      "Numpad -) Toggle reverse cast\n"
      "Numpad .) Kill self\n"
      "Numpad 0) Kill mobs\n"
      "Numpad 1) Toggle ember\n"
      "Numpad 2) Heal or revive\n"
      "Numpad 3) Heal others\n"
      "Shift+L) Toggle Autorevive\n"
      "Shift+M) Open a menu\n"
      "Shift+F9) Toggle Autosave\n"
      "Shift+F10) Build creation prompt\n"
      "Shift+F12) Toggle protections\n"
      ANSI_RESET;

  // Bootup
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  SetWindowBorderless();
  //PacketManager::GetInstance()->InstallHooks();
  ProtectionHandler::GetInstance()->SetEnforcement(true);
  printf(PROJECT_NAME " powered by " FRAMEWORK_NAME "\n");
  printf("Built " __DATE__ " at " __TIME__ "\n");
  printf(">> Press H for a list of available commands\n");

  // Flags and storage
  bool super_speed = false;
  bool collision_state = true;
  Pos stored_position = {0.0, 0.0, 0.0, 0.0};

  // Param edits

  //// Untrue dark ring as covenant item
  auto untrue_covenant = new EquipParamAccessory(0x20005050);
  untrue_covenant->AccessoryCategory(1);
  untrue_covenant->Weight(0.0);
  untrue_covenant->SortId(8000);

  //// Overclocked invasions
  auto fast_invasions = new NetworkParam();
  fast_invasions->MaxBreakInTargetListCount(20);
  fast_invasions->BreakInRequestIntervalTimeSec(5);
  fast_invasions->BreakInRequestTimeOutSec(5);
  auto fast_redeye = new EquipParamGoods(102);
  fast_redeye->GoodsUseAnim(16);
  fast_redeye->OpmeMenuType(0);

  //// Host without restrictions
  for ( auto entry : ParamRegistry::GetInstance()->GetParamIdTable(L"PlayRegionParam") )
  {
    auto param = new PlayRegionParam(entry.first);
    param->MultiPlayStartLimitEventFlagId(0);
    param->MultiPlayHostLimitEventFlagId(0);
  }

  // Main Loop
  bool key_pressed_in_loop;
  while (true)
  {
    key_pressed_in_loop = true;
    if (IsKeyDown(VirtualKey::Shift))
    {
      if      (IsKeyDown(VirtualKey::Delete)) { break; }
      else if (IsKeyDown(VirtualKey::I)) { IdleAnimationPrompt(); }
      else if (IsKeyDown(VirtualKey::K)) { KickPlayerPrompt(); }
      else if (IsKeyDown(VirtualKey::L)) { SubroutineManager::GetInstance()->ToggleAutorevive(); }
      else if (IsKeyDown(VirtualKey::M)) { OpenMenuPrompt(); }
      //else if (IsKeyDown(VirtualKey::O)) { SubroutineManager::GetInstance()->ToggleAutosummon(); }
      else if (IsKeyDown(VirtualKey::P)) { SetPhantomTypePrompt(); }
      else if (IsKeyDown(VirtualKey::T)) { TeleportPlayerToPrompt(); }
      else if (IsKeyDown(VirtualKey::V)) { FreezeAnimation(); }
      else if (IsKeyDown(VirtualKey::Z)) { SubroutineManager::GetInstance()->ToggleAutosign(SOSFlag::RedOrb); }
      else if (IsKeyDown(VirtualKey::F1)) { FightClubModeToggle(); }
      else if (IsKeyDown(VirtualKey::F2)) { PrepareSurvivalMode(); }
      //else if (IsKeyDown(VirtualKey::F8)) { SubroutineManager::GetInstance()->ToggleUnlimitedsummon(); }
      else if (IsKeyDown(VirtualKey::F9)) { SubroutineManager::GetInstance()->ToggleAutosave(); }
      else if (IsKeyDown(VirtualKey::F10)) { BuildCreationPrompt(); }
      else if (IsKeyDown(VirtualKey::F12)) { ProtectionHandler::GetInstance()->ToggleEnforcement(); }
      else { key_pressed_in_loop = false; }
    }
    else
    {
      if (IsKeyDown(VirtualKey::Delete)) {
        printf("Keybinds disabled, press Delete to re-enable\n");
        Sleep(500);
        while (!IsKeyDown(VirtualKey::Delete)) { Sleep(10); }
        printf("Keybinds re-enabled\n");
      }
      else if (IsKeyDown(VirtualKey::H)) { printf(HELP_TEXT); }
      else if (IsKeyDown(VirtualKey::C)) { CameraController::GetInstance()->KeyboardPrompt(); }
      else if (IsKeyDown(VirtualKey::I)) { IdleAnimationSelfPrompt(); }
      else if (IsKeyDown(VirtualKey::K)) { KillPlayerPrompt(); }
      else if (IsKeyDown(VirtualKey::O)) { SubroutineManager::GetInstance()->ToggleAutosign(); }
      else if (IsKeyDown(VirtualKey::P)) { PlayerShapeshifter::GetInstance()->KeyboardPrompt(); }
      else if (IsKeyDown(VirtualKey::T)) { TeleportToPlayerPrompt(); }
      else if (IsKeyDown(VirtualKey::U)) { PlayerAnimationSelfPrompt(); }
      else if (IsKeyDown(VirtualKey::V)) { RestoreAnimationSpeed(); }
      //else if (IsKeyDown(VirtualKey::X)) { SubroutineManager::GetInstance()->ToggleBlockEvents(); }
      else if (IsKeyDown(VirtualKey::Decimal))  { SetHealthSelf(0); SetAnimationIdle(IdleAnimation::Death); }
      else if (IsKeyDown(VirtualKey::Subtract)) { ReverseCastToggle(); }
      else if (IsKeyDown(VirtualKey::Add)) {
        if (super_speed) SetAnimationSpeed(1.0f);
        else SetAnimationSpeed(5.0f);
        super_speed = !super_speed;
      }
      else if (IsKeyDown(VirtualKey::Numpad_0)) { KillMobs(); }
      else if (IsKeyDown(VirtualKey::Numpad_1)) { ToggleEmber(); }
      else if (IsKeyDown(VirtualKey::Numpad_2)) {
        if (GetHealthSelf()) {
          ApplyEffectSelf(EffectId::Bonfire);
          SetAnimationIdle(IdleAnimation::Idle);
        } else {
          ReviveSelf();
        }
      }
      else if (IsKeyDown(VirtualKey::Numpad_3)) { for (uint8_t i = 1; i < 5; i++) HealPlayer(i); }
      else if (IsKeyDown(VirtualKey::Numpad_4)) {
        DebugFlag::Collision(!collision_state);
        collision_state = !collision_state;
      }
      else if (IsKeyDown(VirtualKey::Numpad_5)) { StoreRestorePosition(stored_position, true); }
      else if (IsKeyDown(VirtualKey::Numpad_6)) {
        if (!stored_position[0]) continue;
        StoreRestorePosition(stored_position);
      }
      else if (IsKeyDown(VirtualKey::Numpad_7)) { SendSOS(SOSFlag::RedOrb);; }
      else if (IsKeyDown(VirtualKey::Numpad_8)) { SessionDisconnect(); }
      else if (IsKeyDown(VirtualKey::Numpad_9)) { SubroutineManager::GetInstance()->ToggleTriggerCovenants(); }
      else if (IsKeyDown(VirtualKey::Page_Up))  { if (!collision_state) RelativeMove(0.0,  1.0, 0.0); }
      else if (IsKeyDown(VirtualKey::Page_Down)){ if (!collision_state) RelativeMove(0.0, -1.0, 0.0); }
      else { key_pressed_in_loop = false; }
    }
    if (key_pressed_in_loop) { Sleep(250); }
  }

  // Shutdown
  //delete PacketManager::GetInstance();
  delete ProtectionHandler::GetInstance();
  delete SubroutineManager::GetInstance();
  //delete BulletTracker::GetInstance();
  //delete TargetTracker::GetInstance();
  delete CameraController::GetInstance();
  delete PlayerShapeshifter::GetInstance();
  delete ParamRegistry::GetInstance();
  delete ProcessInterface::GetInstance();
  UnloadDll();
}

BOOL WINAPI DllMain(HINSTANCE baseaddr, DWORD reason, BOOL isstatic) {
  switch (reason) {
    case DLL_PROCESS_ATTACH:
    {
      WrapGenuineDll(baseaddr);
      std::thread *entry = new std::thread(MainThread);
      break;
    }
  }
  return 1;
}
