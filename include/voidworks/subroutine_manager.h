#ifndef SUBROUTINE_MANAGER_H_
#define SUBROUTINE_MANAGER_H_

#include <atomic>
#include <thread>
#include <voidworks/bullet.h>
#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/param_classes.h>
#include <voidworks/player.h>
#include <voidworks/position.h>
#include <voidworks/session.h>
#include <voidworks/subroutine.h>

void FightClubMode(bool);
void FightClubModeToggle();

class SubroutineManager
{
  private:
    static SubroutineManager* instance_;
    SubroutineManager();
    void DisableSubroutines();
    BulletInstance notification_bullet;
    void SpawnNotificationBullet(BulletId);

    bool auto_save_state_ = true;

    std::atomic<bool> auto_revive_state_{false};
    bool auto_revive_tears_ = false;
    std::thread* auto_revive_thread_ = NULL;
    void AutoreviveLoop();

    std::atomic<bool> auto_sign_state_{false};
    bool auto_sign_placed_ = false;
    std::thread* auto_sign_thread_ = NULL;
    SOSFlag auto_sign_flag_ = SOSFlag::RedSign;
    void AutosignLoop();

    bool auto_summon_state_ = false;
    BasicHook* auto_summon_hook_ = NULL;

    bool unlimited_summon_state_ = false;
    BasicHook* unlimited_summon_hook_ = NULL;

    bool trigger_covenants_state_ = false;
    SpEffectParam* trigger_covenants_aldrich_ = nullptr;
    SpEffectParam* trigger_covenants_watchdog_ = nullptr;

    bool block_events_state_ = false;
    BasicHook* block_events_hook_ = NULL;

    bool potato_pc_mode_state_ = false;
    std::vector<LodParam*> potato_pc_mode_params_;

  public:
    ~SubroutineManager();
    static SubroutineManager* GetInstance();

    void SetAutosave(bool);
    void ToggleAutosave();

    void SetAutorevive(bool);
    void ToggleAutorevive();
    void SetAutoreviveWithTears(bool);
    void ToggleAutoreviveWithTears();

    void SetAutosign(bool, SOSFlag = SOSFlag::RedSign);
    void ToggleAutosign(SOSFlag = SOSFlag::RedSign);

    void SetAutosummon(bool);
    void ToggleAutosummon();

    void SetUnlimitedsummon(bool);
    void ToggleUnlimitedsummon();

    void SetTriggerCovenants(bool);
    void ToggleTriggerCovenants();

    void SetBlockEvents(bool);
    void ToggleBlockEvents();

    void SetPotatoPcMode(bool);
    void TogglePotatoPcMode();
};

#endif
