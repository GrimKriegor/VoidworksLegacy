#ifndef EQUIPMENT_H_
#define EQUIPMENT_H_

#include <voidworks/common.h>
#include <voidworks/packet.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

class EquipmentStruct
{
  protected:
    ProcessInterface* ds3 = NULL;
    void CopyToPacketData(uint8_t*);
  public:
    int32_t number     = 0;
    int32_t gender     = 0;
    int32_t head       = 900000;
    int32_t chest      = 901000;
    int32_t hands      = 902000;
    int32_t legs       = 903000;
    int32_t ring_1     = -1;
    int32_t ring_2     = -1;
    int32_t ring_3     = -1;
    int32_t ring_4     = -1;
    int32_t weapon_l_1 = 110000;
    int32_t weapon_l_2 = 110000;
    int32_t weapon_l_3 = 110000;
    int32_t weapon_r_1 = 110000;
    int32_t weapon_r_2 = 110000;
    int32_t weapon_r_3 = 110000;
    int32_t arrow_1    = -1;
    int32_t arrow_2    = -1;
    int32_t bolt_1     = -1;
    int32_t bolt_2     = -1;
    int32_t covenant   = -1;
    EquipmentStruct();
    void Print();
    virtual void CopyPlayer(uint8_t);
    virtual void CopySelf();
    virtual void SetCharAsm();
    void SendAsPacket();
};

class EquipmentStructExtended : public EquipmentStruct
{
  int32_t spell_1  = -1;
  int32_t spell_2  = -1;
  int32_t spell_3  = -1;
  int32_t spell_4  = -1;
  int32_t spell_5  = -1;
  int32_t spell_6  = -1;
  int32_t spell_7  = -1;
  int32_t spell_8  = -1;
  int32_t spell_9  = -1;
  int32_t spell_10 = -1;
  int32_t spell_11 = -1;
  int32_t spell_12 = -1;
  int32_t spell_13 = -1;
  int32_t spell_14 = -1;
  void CopyPlayer(uint8_t) override;
  void CopySelf() override;
  void SetCharAsm() override;
};

#endif
