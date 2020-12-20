#ifndef PLAYER_H_
#define PLAYER_H_

#include <voidworks/common.h>
#include <voidworks/packet.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

class PlayerStruct
{
  protected:
    ProcessInterface* ds3 = NULL;
    void CopyToPacketData(uint8_t*);
  public:
    wchar_t name[16]      = {0};
    uint8_t facedata[228] = {0};
    uint32_t number       = 0;
    uint32_t level        = 1;
    uint32_t vigor        = 10;
    uint32_t attunement   = 10;
    uint32_t endurance    = 10;
    uint32_t vitality     = 10;
    uint32_t strength     = 10;
    uint32_t dexterity    = 10;
    uint32_t intelligence = 10;
    uint32_t faith        = 10;
    uint32_t luck         = 10;
    PlayerStruct();
    void Print();
    void CopyPlayer(uint8_t);
    void CopySelf();
    void ApplyToSelf();
    void SendAsPacket();
    void SetName(const wchar_t*);
    uint32_t CheckInvalidAttributes();
};

uint32_t GetHealthSelf();
uint32_t GetHealthSelfMax();
void SetHealthSelf(uint32_t);
void SetHealthSelfFull();
uint32_t GetFocusSelfMax();
void SetFocusSelf(uint32_t);
void SetFocusSelfFull();

#endif
