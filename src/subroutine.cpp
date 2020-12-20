#include <voidworks/subroutine.h>

uint8_t PlayerNumberKeyboardPrompt()
{
  PrintPlayerList();
  if (!GetPlayerCount()) { return 0; }
  bool key_pressed_in_loop;
  while (true)
  {
    key_pressed_in_loop = false;
    if      (IsKeyDown(VirtualKey::Number_0)) { return 0; }
    else if (IsKeyDown(VirtualKey::Number_1)) { return 1; }
    else if (IsKeyDown(VirtualKey::Number_2)) { return 2; }
    else if (IsKeyDown(VirtualKey::Number_3)) { return 3; }
    else if (IsKeyDown(VirtualKey::Number_4)) { return 4; }
    else if (IsKeyDown(VirtualKey::Number_5)) { return 5; }
    else if (IsKeyDown(VirtualKey::Escape))   { break; }
    else { key_pressed_in_loop = false; }
    if (key_pressed_in_loop) { Sleep(250); }
  }
  return 0;
}

void ReviveSelf()
{
  if (!IsCharacterLoaded()) { return; }
  ThrowSelf(PlayerThrows::LycanthropeBite);
  SetHealthSelfFull();
  SetFocusSelfFull();
}

void RevivePlayer(uint8_t player_number)
{
  if (!IsCharacterLoaded() || !IsPlayerConnected(player_number)) return;
  ThrowPlayer(player_number, player_number, PlayerThrows::LycanthropeBite);
  ApplyEffectPlayer(player_number, EffectId::Bonfire);
}

void ToggleEmber()
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  void* ptr = ds3->GetDynamicAddress({BASE_A, 0x00, 0x0000});
  ds3->WriteByte(ptr, !ds3->ReadByte(ptr));
}

void ApplyDriedFinger()
{
  ApplyEffectSelf(EffectId::DriedFinger);
}

void ApplyTears()
{
  ApplyEffectSelf(EffectId::TearsOfDenial);
}

void ApplyTearsPlayer(uint8_t player_number)
{
  ApplyEffectPlayer(player_number, EffectId::TearsOfDenial);
}

void HealPlayer(uint8_t player_number)
{
  ApplyEffectPlayer(player_number, EffectId::Bonfire);
}

void KillPlayer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  BulletInstance bullet;
#if (DEBUG >= LOG_WARNING)
  printf("Killing player %d\n", player_number);
#endif
  bullet.SpawnAt(BulletId::ArrowExplosion, GetPositionPlayer(player_number));
  SetAnimationPlayer(player_number, IdleAnimation::Death);
}

void KillPlayerPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "KillPlayer keyboard prompt\n" ANSI_RESET);
#endif
  uint8_t player_number = PlayerNumberKeyboardPrompt();
  if (!player_number) { return; }
  KillPlayer(player_number);
}

void KickPlayerPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "KickPlayer keyboard prompt\n" ANSI_RESET);
#endif
  uint8_t player_number = PlayerNumberKeyboardPrompt();
  if (!player_number) { return; }
  KickPlayer(player_number);
}

void SetPhantomTypePrompt()
{
  if (!IsCharacterLoaded()) { return; }
  PhantomType phantom_type;
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "SetPhantomType keyboard prompt\n" ANSI_RESET);
#endif
  printf(ANSI_BHYEL "H) Host\nP) Phantom\nI) Invader\n" ANSI_RESET);
  while (true)
  {
    if      (IsKeyDown(VirtualKey::H))      { phantom_type = phantom_type_host; break; }
    else if (IsKeyDown(VirtualKey::F))      { phantom_type = phantom_type_phantom; break; }
    else if (IsKeyDown(VirtualKey::I))      { phantom_type = phantom_type_invader; break; }
    else if (IsKeyDown(VirtualKey::Escape)) { return; }
  }
  SetPhantomType(phantom_type);
}

void ChangeNameSelfTemporary(const wchar_t* name)
{
  PlayerStruct player;
  player.CopyPlayer(0);
  player.SetName(name);
  player.SendAsPacket();
  printf("Sending this name to all session participants: " ANSI_YEL "%S\n" ANSI_RESET, name);
}

void ChangeNameSelfPersistent(const wchar_t* name)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteWideString(
    ds3->GetDynamicAddress({BASE_A, 0x00, 0x00}),
    name,
    16
  );
  printf("Changing character name to: " ANSI_YEL "%S\n" ANSI_RESET, name);
  ChangeNameSelfTemporary(name);
}

void ChangeNamePrompt()
{
  if (!IsCharacterLoaded()) { return; }
  wchar_t new_name[17];
  Sleep(100);
  printf("Insert new character name:\n");
  fgetws(new_name, 17, stdin);
  new_name[wcscspn(new_name, L"\n")] = 0;
  if (!new_name[0])
  {
    printf("Empty name, aborting...\n");
    return;
  }
  ChangeNameSelfPersistent(new_name);
}

void TeleportPlayerTo(uint8_t player_number, Pos position)
{
  ThrowPlayerTeleport(player_number, player_number, PlayerThrows::LycanthropeBite, position);
}

void TeleportPlayerToMultipleAttempts(uint8_t player_number, Pos position, uint8_t attempts)
{
  for (uint8_t i = 0; i < attempts; i++)
  {
    TeleportPlayerTo(player_number, position);
    Sleep(500);
    float current_distance = MeasureDistance(GetPositionPlayer(player_number), position);
    if (current_distance < 5.0) break;
  }
}

void TeleportToPlayerPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "TeleportToPlayer keyboard prompt\n" ANSI_RESET);
#endif
  uint8_t player_number = PlayerNumberKeyboardPrompt();
  if (!player_number) { return; }
  TeleportToPlayer(player_number);
}

void TeleportPlayerToPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "TeleportPlayerTo keyboard prompt\n" ANSI_RESET);
#endif
  uint8_t player_number = PlayerNumberKeyboardPrompt();
  if (!player_number) { return; }
  TeleportPlayerToMultipleAttempts(player_number, GetPositionSelf());
}

IdleAnimation IdleAnimationSelectorPrompt()
{
  IdleAnimation id = IdleAnimation::Idle;
  while (true)
  {
    if      (IsKeyDown(VirtualKey::Number_0)) { id = IdleAnimation::GoInvisible; break; }
    else if (IsKeyDown(VirtualKey::Number_1)) { id = IdleAnimation::Idle; break; }
    else if (IsKeyDown(VirtualKey::Number_2)) { id = IdleAnimation::CrossArmsSlow; break; }
    else if (IsKeyDown(VirtualKey::Number_3)) { id = IdleAnimation::BadassSit; break;}
    else if (IsKeyDown(VirtualKey::Number_4)) { id = IdleAnimation::BadassStand; break;}
    else if (IsKeyDown(VirtualKey::Number_5)) { id = IdleAnimation::Flex; break; }
    else if (IsKeyDown(VirtualKey::Number_6)) { id = IdleAnimation::KneelTouch; break; }
    else if (IsKeyDown(VirtualKey::Number_7)) { id = IdleAnimation::StandUp; break; }
    else if (IsKeyDown(VirtualKey::Number_8)) { id = IdleAnimation::Faceup; break;}
    else if (IsKeyDown(VirtualKey::Number_9)) { id = IdleAnimation::Facedown; break;}
    else if (IsKeyDown(VirtualKey::F1))       { id = IdleAnimation::FogwallCross; break;}
    else if (IsKeyDown(VirtualKey::F2))       { id = IdleAnimation::Summon; break;}
    else if (IsKeyDown(VirtualKey::F7))       { id = IdleAnimation::TimeoutOver; break;}
    else if (IsKeyDown(VirtualKey::F8))       { id = IdleAnimation::Timeout; break;}
    else if (IsKeyDown(VirtualKey::F9))       { id = IdleAnimation::Shadowrealm; break;}
    else if (IsKeyDown(VirtualKey::Escape))   { break; }
  }
  return id;
}

void IdleAnimationPrompt(bool on_self)
{
  if (!IsCharacterLoaded()) { return; }
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "IdleAnimation keyboard prompt\n" ANSI_RESET);
#endif
  IdleAnimation id = IdleAnimationSelectorPrompt();
  if (on_self)
  {
    SetAnimationIdle(id);
  }
  else
  {
    uint8_t player_number = PlayerNumberKeyboardPrompt();
    SetAnimationPlayer(player_number, id);
  }
}

void IdleAnimationSelfPrompt()
{
  IdleAnimationPrompt(true);
}

PlayerAnimation PlayerAnimationSelectorPrompt()
{
  PlayerAnimation id = PlayerAnimation::Idle;
  while (true)
  {
    if      (IsKeyDown(VirtualKey::Number_0)) { id = PlayerAnimation::CeremonyPush; break; }
    else if (IsKeyDown(VirtualKey::Number_1)) { id = PlayerAnimation::Idle; break; }
    else if (IsKeyDown(VirtualKey::Number_2)) { id = PlayerAnimation::AutisticJump; break; }
    else if (IsKeyDown(VirtualKey::Number_3)) { id = PlayerAnimation::BossKnockback; break;}
    else if (IsKeyDown(VirtualKey::Number_4)) { id = PlayerAnimation::Backflip; break;}
    else if (IsKeyDown(VirtualKey::Number_5)) { id = PlayerAnimation::DragonHands; break;}
    else if (IsKeyDown(VirtualKey::Number_6)) { id = PlayerAnimation::Guardbreak; break; }
    else if (IsKeyDown(VirtualKey::Number_7)) { id = PlayerAnimation::Burgerflip; break; }
    else if (IsKeyDown(VirtualKey::Number_8)) { id = PlayerAnimation::Parried; break; }
    else if (IsKeyDown(VirtualKey::Number_9)) { id = PlayerAnimation::Knockback; break;}
    else if (IsKeyDown(VirtualKey::F1))       { id = PlayerAnimation::AxeWA; break;}
    else if (IsKeyDown(VirtualKey::F2))       { id = PlayerAnimation::BeybladeWeapon; break;}
    else if (IsKeyDown(VirtualKey::F3))       { id = PlayerAnimation::MagicSwordVestige; break;}
    else if (IsKeyDown(VirtualKey::F4))       { id = PlayerAnimation::ShotarrowWA; break;}
    else if (IsKeyDown(VirtualKey::F5))       { id = PlayerAnimation::BrokenSpine; break;}
    else if (IsKeyDown(VirtualKey::Escape))   { break; }
  }
  return id;
}

void PlayerAnimationPrompt(bool on_self)
{
  if (!IsCharacterLoaded()) { return; }
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PlayerAnimation keyboard prompt\n" ANSI_RESET);
#endif
  PlayerAnimation id = PlayerAnimationSelectorPrompt();
  if (on_self)
  {
    SetAnimationSelf(id);
  }
  else
  {
    SetAnimationTarget(id);
  }
}

void PlayerAnimationSelfPrompt()
{
  if (!IsCharacterLoaded()) { return; }
  PlayerAnimationPrompt(true);
}

void ReverseCast(bool state)
{
  if (!IsCharacterLoaded()) { return; }
  DebugFlag::NoConsumeGoods(state);
  DebugFlag::NoConsumeArrows(state);
  DebugFlag::NoFocusDrain(state);
  DebugFlag::NoStaminaDrain(state);
  if (state) { SetAnimationSpeed(-0.0001f); }
  else       { SetAnimationSpeed(+1.0000f); }
}

void ReverseCastToggle()
{
  static bool state = false;
  state = !state;
  ReverseCast(state);
}

void PrepareSurvivalMode()
{
  if (!IsCharacterLoaded() || !IsMyWorld()) { return; }
  OnlineAreaId area = (OnlineAreaId)GetOnlineAreaId();
  switch(area)
  {
    case OnlineAreaId::Irithyll_Pontiff_Sullyvahn:
    case OnlineAreaId::Irithyll_Pontiff_Hotspot:
    case OnlineAreaId::Irithyll_Darkmoon_Tomb:
    {
      SetPositionSelf({526.3994751f, -220.7500763f, -1188.285522f, -1.645373821f});
      Sleep(1000);
      SetPositionSelf({557.9239502f, -183.170639f, -1111.819824f, -0.02520561218f});
      break;
    }
    case OnlineAreaId::Crucifixion_Woods_Halfway_fortress:
    case OnlineAreaId::Crucifixion_Woods_Road_of_Sacrifices:
    case OnlineAreaId::Crucifixion_Woods_Crystal_Sage:
    {
      SetPositionSelf({-68.996849, -256.863525, -490.433746, -2.771509});
      Sleep(1000);
      SetPositionSelf({-47.882851, -258.338043, -419.670746, 0.628225});
      break;
    }
    default: break;
  }
  ApplyEffectSelf(EffectId::Ember);
  ApplyEffectSelf(EffectId::TearsOfDenial);
  KillMobs();
}

void PlayerSnatcher(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  bool snatched = false;
  Pos position_self = GetPositionSelf();
  Pos position_player = GetPositionPlayer(player_number);
  for (uint8_t attempt; attempt < 10; attempt++)
  {
    TeleportPlayerTo(player_number, position_self);
    Sleep(1000);
    if (MeasureDistance(GetPositionPlayer(player_number), position_self) < 5.0)
    {
      snatched = true;
      break;
    }
  }
  if (!snatched)
  {
    printf(ANSI_ERROR_MSG "Failed to snatch player %d\n" ANSI_RESET, player_number);
    return;
  }
  SetPhantomType(GetPhantomType(player_number));
  PlayerShapeshifter::GetInstance()->CopyPlayer(player_number);
  SetPositionSelf(position_player);
#if (DEBUG >= LOG_WARNING)
  printf("Successfully snatched player %d\n", player_number);
#endif
}

void RepeatingRedOrb(uint8_t attempts)
{
  SendSOS(SOSFlag::WhiteSign);
  for (uint8_t attempt = 0; attempt < attempts; attempt++)
  {
#if (DEBUG >= LOG_INFO)
    printf(ANSI_INFO_MSG "Invasion attempt %d of %d\n" ANSI_RESET, attempt+1, attempts);
#endif
    SendSOS(SOSFlag::RedOrb);
    Sleep(2000);
    while (GetSessionState() >= SessionState::TryingToJoin)
    {
      Sleep(500);
      if (GetSessionState() == SessionState::Client || !IsMyWorld()) {
#if (DEBUG >= LOG_INFO)
        printf(ANSI_INFO_MSG "Invading now!\n" ANSI_RESET);
#endif
        return;
      }
    }
    SendSOS(SOSFlag::RedOrb);
  }
}

void StoreRestorePosition(Pos& position, bool write)
{
  if (!IsCharacterLoaded()) { return; }
  if (position.size() != 4)
  {
    position.resize(4);
  }
  if (write)
  {
    position = GetPositionSelf();
    return;
  }
  SetPositionSelf(position);
}

void BuildCreationPrompt()
{
  if (!IsCharacterLoaded()) { return; }
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "BuildCreation keyboard prompt\n" ANSI_RESET);
#endif
  printf(ANSI_BHYEL
      "I) Spawn item\n"
      "N) Change name\n"
      "G) Unlock all gestures\n"
      "B) Unlock bonfires\n"
      "K) No cost upgrades\n"
      "M) Open menus\n"
      ANSI_RESET
    );
  while (true)
  {
    if      (IsKeyDown(VirtualKey::I))      { ItemSpawnPrompt(); break; }
    else if (IsKeyDown(VirtualKey::N))      { ChangeNamePrompt(); break; }
    else if (IsKeyDown(VirtualKey::G))      { UnlockAllGestures(); break; }
    else if (IsKeyDown(VirtualKey::B))      { UnlockAllBonfires(); break; }
    else if (IsKeyDown(VirtualKey::K))      { DisableItemUpgradeCost(); break; }
    else if (IsKeyDown(VirtualKey::M))      { OpenMenuPrompt(); break; }
    else if (IsKeyDown(VirtualKey::Escape)) { break; }
  }
}

void ItemSpawnPrompt()
{
  ItemCategory category = ItemCategory::Invalid;
  int32_t id = 0;
  int32_t infusion = 0;
  int32_t level = 0;
  int32_t quantity = 1;
  int32_t durability = -1;
  std::vector<std::string> item_search_results;
  std::vector<std::string> infusion_list;
  char search_term[32] = {0};
  int32_t index = -1;
  printf("Search item by name:\n");
  GetUserInputString(search_term, sizeof(search_term));
  for (auto item : GetItemList())
  {
    if (FindInString(item.first, search_term) != std::string::npos)
    {
      item_search_results.push_back(item.first);
    }
  }
  for (auto infusion : GetInfusionList())
  {
    infusion_list.push_back(infusion.first);
  }
  if (item_search_results.size())
  {
    PrintOrderedStringVector(item_search_results);
  }
  else
  {
    printf("No items have been found...\n");
    return;
  }
  printf("Pick by index (leave empty to abort): ");
  index = GetUserInputIntenger();
  if (index < 0)
  {
    printf("No item has been picked. Aborting...\n");
    return;
  }
  id = GetItemList().at(item_search_results[index]);
  category = GetItemCategoryById(id);
  if (category == ItemCategory::Weapon)
  {
    PrintOrderedStringVector(infusion_list);
    printf("Infusion: ");
    infusion = GetUserInputIntenger();
    if (infusion < 0 || infusion > infusion_list.size())
    {
      infusion = 0;
    }
    else
    {
      infusion = GetInfusionList().at(infusion_list[infusion]);
    }
    printf("Level: ");
    level = GetUserInputIntenger();
    level = (level >= 0) ? level : 0;
    level %= 11;
  }
  printf("Quantity: ");
  quantity = GetUserInputIntenger();
  quantity = (quantity > 0) ? quantity : 1;
  if (category == ItemCategory::Weapon || category == ItemCategory::Armor)
  {
    printf("Durability: ");
    durability = GetUserInputIntenger();
  }
  ItemSpawn(id, infusion, level, quantity, durability);
}

PlayerShapeshifter::PlayerShapeshifter()
{
  TryInit();
}

PlayerShapeshifter::~PlayerShapeshifter()
{
  Restore();
}

PlayerShapeshifter* PlayerShapeshifter::instance = 0;

PlayerShapeshifter* PlayerShapeshifter::GetInstance()
{
  if (!instance)
  {
    instance = new PlayerShapeshifter();
  }
  return instance;
}

void PlayerShapeshifter::Init()
{
  player_original.CopyPlayer(0);
  equipment_original.CopyPlayer(0);
  player_current.CopyPlayer(0);
  equipment_current.CopyPlayer(0);
  initialized = true;
}

void PlayerShapeshifter::TryInit()
{
  if (initialized || !IsCharacterLoaded()) { return; }
  Init();
}

void PlayerShapeshifter::TransitionEffect()
{
  BulletInstance bullet;
  bullet.SpawnAt(BulletId::SlayerExplosion, GetPositionSelf());
  SetAnimationSelf(PlayerAnimation::Backflip);
}

void PlayerShapeshifter::Restore()
{
  if (!restorable || !IsCharacterLoaded()) { return; }
  TryInit();
  player_original.ApplyToSelf();
  player_original.SendAsPacket();
  equipment_original.SetCharAsm();
  equipment_original.SendAsPacket();
  TransitionEffect();
#if (DEBUG >= LOG_WARNING)
  printf("Restoring original character\n");
#endif
}

void PlayerShapeshifter::CopyPlayer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  TryInit();
  player_current.CopyPlayer(player_number);
  player_current.ApplyToSelf();
  player_current.SendAsPacket();
  equipment_current.CopyPlayer(player_number);
  equipment_current.ring_1 = 20560;
  equipment_current.SetCharAsm();
  equipment_current.SendAsPacket();
  TransitionEffect();
  restorable = true;
#if (DEBUG >= LOG_WARNING)
  printf("Shapeshifting into player %d\n", player_number);
#endif
#if (DEBUG >= LOG_INFO)
  Print();
#endif
}

void PlayerShapeshifter::ChangeName(const wchar_t* newname)
{
  TryInit();
  player_current.SetName(newname);
  player_current.SendAsPacket();
}

void PlayerShapeshifter::Print()
{
  TryInit();
  player_current.Print();
  equipment_current.Print();
}

void PlayerShapeshifter::KeyboardPrompt()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PlayerShapeshifter keyboard prompt\n" ANSI_RESET);
#endif
  PrintPlayerList();
  uint8_t player_num = 0;
  while (true)
  {
    if      (IsKeyDown(VirtualKey::Escape))   { return; }
    else if (IsKeyDown(VirtualKey::Number_9)) { Init(); return; }
    else if (IsKeyDown(VirtualKey::Number_0)) { Restore(); return; }
    else if (IsKeyDown(VirtualKey::Number_1)) { player_num = 1; break; }
    else if (IsKeyDown(VirtualKey::Number_2)) { player_num = 2; break; }
    else if (IsKeyDown(VirtualKey::Number_3)) { player_num = 3; break; }
    else if (IsKeyDown(VirtualKey::Number_4)) { player_num = 5; break; }
    else if (IsKeyDown(VirtualKey::Number_5)) { player_num = 5; break; }
  }
  CopyPlayer(player_num);
}
