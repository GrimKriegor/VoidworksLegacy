#ifndef BOSS_H_
#define BOSS_H_

#include <voidworks/animation.h>
#include <voidworks/common.h>
#include <voidworks/equipment.h>
#include <voidworks/player.h>
#include <voidworks/subroutine.h>

class Boss
{
  protected:
    wchar_t name[16] = L"BossTemplate";
    uint8_t phase = 0;
    uint32_t current_action = 0;
    PlayerStruct* player_original;
    EquipmentStruct* equipment_original;
    PlayerStruct* player;
    EquipmentStruct* equipment;
    virtual void Loop() = 0;
    void Transform();
  public:
    Boss();
    ~Boss();
    virtual void Init();
};

#endif
