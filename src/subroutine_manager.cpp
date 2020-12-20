#include <voidworks/subroutine_manager.h>

// Please migrate these to runnables, so bad

void FightClubMode(bool state)
{
  if (!IsCharacterLoaded()) { return; }
  DebugFlag::NoConsumeGoods(state);
  DebugFlag::NoConsumeArrows(state);
  SubroutineManager::GetInstance()->SetAutoreviveWithTears(state);
#if (DEBUG >= LOG_WARNING)
  printf("Fight Club mode: %s\n", state?"enabled":"disabled");
#endif
}

void FightClubModeToggle()
{
  static bool state = false;
  state = !state;
  FightClubMode(state);
}

SubroutineManager* SubroutineManager::instance_ = 0;

SubroutineManager::SubroutineManager()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "SubroutineManager initialized\n" ANSI_RESET);
#endif
}

SubroutineManager* SubroutineManager::GetInstance()
{
  if (!instance_)
  {
    instance_ = new SubroutineManager();
  }
  return instance_;
}

SubroutineManager::~SubroutineManager()
{
  DisableSubroutines();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "SubroutineManager terminated\n" ANSI_RESET);
#endif
}

void SubroutineManager::DisableSubroutines()
{
  SetAutosave(true);
  SetAutorevive(false);
  SetAutosign(false);
  SetAutosummon(false);
  SetUnlimitedsummon(false);
  SetBlockEvents(false);
}

void SubroutineManager::SpawnNotificationBullet(BulletId id)
{
  if (!IsCharacterLoaded()) { return; }
  notification_bullet.SetId(id);
  notification_bullet.SetCoordAngleFromPlayerPos(GetPositionSelf());
  notification_bullet.Spawn();
}

void SubroutineManager::SetAutosave(bool state)
{
  if (state == auto_save_state_) { return; }
  auto_save_state_ = state;
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->WriteByte(ds3->GetDynamicAddress({BASE_C, 0x0000}), state);
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Auto Save: %s\n",
      auto_save_state_?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleAutosave()
{
  SetAutosave(!auto_save_state_);
}

void SubroutineManager::AutoreviveLoop()
{
  while (auto_revive_state_)
  {
    if (IsCharacterLoaded() && !GetHealthSelf())
    {
      ReviveSelf();
      if (auto_revive_tears_) { ApplyTears(); }
    }
    Sleep(1000);
  }
}

void SubroutineManager::SetAutorevive(bool state)
{
  if (state == auto_revive_state_) { return; }
  if (state)
  {
    auto_revive_state_ = true;
    auto_revive_thread_ = new std::thread(&SubroutineManager::AutoreviveLoop, this);
    if (auto_revive_tears_) { ApplyTears(); }
    ApplyEffectSelf(EffectId::ArenaBurst);
  }
  else
  {
    auto_revive_state_ = false;
    auto_revive_tears_ = false;
    auto_revive_thread_->join();
    auto_revive_thread_ = NULL;
  }
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Auto Revive: %s, tears: %s\n",
      state?"enabled":"disabled",
      auto_revive_tears_?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleAutorevive()
{
  SetAutorevive(!auto_revive_state_);
}

void SubroutineManager::SetAutoreviveWithTears(bool state)
{
  auto_revive_tears_ = state;
  SetAutorevive(state);
}

void SubroutineManager::ToggleAutoreviveWithTears()
{
  SetAutoreviveWithTears(!auto_revive_state_);
}

void SubroutineManager::AutosignLoop()
{
  while (auto_sign_state_)
  {
    if (IsCharacterLoaded() && IsMyWorld() && !auto_sign_placed_)
    {
      Sleep(10000);
      SendSOS(auto_sign_flag_);
      auto_sign_placed_ = true;
    }
    if (!IsMyWorld() && auto_sign_placed_)
    {
      auto_sign_placed_ = false;
    }
    Sleep(1000);
  }
}

void SubroutineManager::SetAutosign(bool state, SOSFlag flag)
{
  if (state == auto_sign_state_) { return; }
  if (state)
  {
    auto_sign_flag_ = flag;
    auto_sign_state_ = true;
    auto_sign_thread_ = new std::thread(&SubroutineManager::AutosignLoop, this);
    SpawnNotificationBullet(BulletId::Shockwave);
  }
  else
  {
    auto_sign_state_ = false;
    auto_sign_thread_->join();
    auto_sign_thread_ = NULL;
    auto_sign_placed_ = false;
  }
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Auto Sign: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleAutosign(SOSFlag flag)
{
  SetAutosign(!auto_sign_state_, flag);
}


void SubroutineManager::SetAutosummon(bool state)
{
  if (state == auto_summon_state_) { return; }
  if (state)
  {
    auto_summon_hook_ = new BasicHook(
        0x00,
        AUTO_SUMMON_HOOK_SIZE,
        (void*)AUTO_SUMMON_HOOK_ADDRESS
      );
    auto_summon_state_ = true;
  }
  else
  {
    auto_summon_state_ = false;
    delete auto_summon_hook_;
    auto_summon_hook_ = NULL;
  }
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Auto Summon: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleAutosummon()
{
  SetAutosummon(!auto_summon_state_);
}

void SubroutineManager::SetUnlimitedsummon(bool state)
{
  if (state == unlimited_summon_state_) { return; }
  if (state)
  {
    ProcessInterface* ds3 = ProcessInterface::GetInstance();
    ds3->WriteInt32(ds3->GetDynamicAddress({BASE_C, 0x0000}), 0x00);
    unlimited_summon_hook_ = new BasicHook(
        0x00,
        UNLOCKED_SUMMON_HOOK_SIZE,
        (void*)UNLOCKED_SUMMON_HOOK_ADDRESS,
        (void*)UnlimitedSummonHook,
        3
      );
    unlimited_summon_state_ = true;
  }
  else
  {
    unlimited_summon_state_ = false;
    delete unlimited_summon_hook_;
    unlimited_summon_hook_ = NULL;
  }
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Unlimited Summon: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleUnlimitedsummon()
{
  SetUnlimitedsummon(!unlimited_summon_state_);
}

void SubroutineManager::SetTriggerCovenants(bool state)
{
  if (state == trigger_covenants_state_) { return; }
  if (state)
  {
    trigger_covenants_aldrich_ = new SpEffectParam((uint32_t)EffectId::InvTriggerAldriches);
    trigger_covenants_watchdog_ = new SpEffectParam((uint32_t)EffectId::InvTriggerWatchdogs);
    trigger_covenants_aldrich_->EffectEndurance(-1.0f);
    trigger_covenants_watchdog_->EffectEndurance(-1.0f);
    ApplyEffectSelf(EffectId::InvTriggerAldriches);
    ApplyEffectSelf(EffectId::InvTriggerWatchdogs);
  }
  else
  {
    delete trigger_covenants_aldrich_;
    delete trigger_covenants_watchdog_;
    trigger_covenants_aldrich_ = nullptr;
    trigger_covenants_watchdog_ = nullptr;
  }
  trigger_covenants_state_ = state;
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Trigger Covenants: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleTriggerCovenants()
{
  SetTriggerCovenants(!trigger_covenants_state_);
}

void SubroutineManager::SetBlockEvents(bool state)
{
  if (state == block_events_state_) { return; }
  if (state)
  {
    block_events_hook_ = new BasicHook(
        0x00,
        BLOCK_EVENTS_HOOK_SIZE,
        (void*)BLOCK_EVENTS_HOOK_ADDRESS
      );
    block_events_state_ = true;
  }
  else
  {
    block_events_state_ = false;
    delete block_events_hook_;
    block_events_hook_ = NULL;
  }
#if (DEBUG >= LOG_WARNING)
  printf("SubroutineManager Block Events: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::ToggleBlockEvents()
{
  SetBlockEvents(!block_events_state_);
}

void SubroutineManager::SetPotatoPcMode(bool state)
{
  if (state == potato_pc_mode_state_) { return; }
  if (state)
  {
    const std::vector<int32_t> ids = {19, 22, 26, 50, 54, 61};
    for (auto id : ids)
    {
      auto param = new LodParam(id);
      param->Lv01_BorderDist(5);
      param->Lv01_PlayDist(1);
      param->Lv12_BorderDist(15);
      param->Lv12_PlayDist(2);
      param->TextureLod(0);
      param->Lv23_BorderDist(15);
      param->Lv23_PlayDist(1);
      param->Lv34_BorderDist(15);
      param->Lv34_PlayDist(1);
      param->Lv45_BorderDist(15);
      param->Lv45_PlayDist(1);
      param->DistanceScaleId(1);
      potato_pc_mode_params_.push_back(param);
    }
    potato_pc_mode_state_ = true;
  }
  else
  {
    for (auto param : potato_pc_mode_params_)
    {
      delete param;
    }
    potato_pc_mode_params_.clear();
    potato_pc_mode_state_ = false;
  }
#if (DEBUG >= LOG_WARNING)
  printf("Potato PC Mode: %s\n", state?"enabled":"disabled");
#endif
}

void SubroutineManager::TogglePotatoPcMode()
{
  SetPotatoPcMode(!potato_pc_mode_state_);
}
