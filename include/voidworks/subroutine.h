#ifndef SUBROUTINE_H_
#define SUBROUTINE_H_

#include <voidworks/animation.h>
#include <voidworks/bullet.h>
#include <voidworks/character.h>
#include <voidworks/common.h>
#include <voidworks/debug.h>
#include <voidworks/effect.h>
#include <voidworks/equipment.h>
#include <voidworks/input.h>
#include <voidworks/item.h>
#include <voidworks/menu.h>
#include <voidworks/player.h>
#include <voidworks/position.h>
#include <voidworks/process.h>
#include <voidworks/session.h>
#include <voidworks/throw.h>
#include <voidworks/world.h>

uint8_t PlayerNumberKeyboardPrompt();
void ReviveSelf();
void RevivePlayer(uint8_t);
void ToggleEmber();
void ApplyDriedFinger();
void ApplyTears();
void ApplyTearsPlayer(uint8_t);
void HealPlayer(uint8_t);
void KillPlayer();
void KillPlayerPrompt();
void KickPlayerPrompt();
void SetPhantomTypePrompt();
void ChangeNameSelfTemporary(const wchar_t*);
void ChangeNameSelfPersistent(const wchar_t*);
void ChangeNamePrompt();
void TeleportPlayerTo(uint8_t, Pos);
void TeleportPlayerToMultipleAttempts(uint8_t, Pos, uint8_t=20);
void TeleportToPlayerPrompt();
void TeleportPlayerToPrompt();
IdleAnimation IdleAnimationSelectorPrompt();
void IdleAnimationPrompt(bool=false);
void IdleAnimationSelfPrompt();
PlayerAnimation PlayerAnimationSelectorPrompt();
void PlayerAnimationPrompt(bool=false);
void PlayerAnimationSelfPrompt();
void ReverseCast(bool);
void ReverseCastToggle();
void PrepareSurvivalMode();
void PlayerSnatcher(uint8_t);
void RepeatingRedOrb(uint8_t);
void StoreRestorePosition(Pos&, bool=false);
void BuildCreationPrompt();
void ItemSpawnPrompt();

class PlayerShapeshifter
{
  private:
    static PlayerShapeshifter* instance;
    bool initialized = false;
    bool restorable = false;
    PlayerStruct player_original;
    EquipmentStruct equipment_original;
    void Init();
    void TryInit();
    void TransitionEffect();
    PlayerShapeshifter();
  public:
    PlayerStruct player_current;
    EquipmentStruct equipment_current;
    ~PlayerShapeshifter();
    static PlayerShapeshifter* GetInstance();
    void Restore();
    void CopyPlayer(uint8_t);
    void ChangeName(const wchar_t*);
    void Print();
    void KeyboardPrompt();
};

#endif
