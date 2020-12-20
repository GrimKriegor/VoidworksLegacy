#ifndef SESSION_H_
#define SESSION_H_

#include <voidworks/common.h>
#include <voidworks/effect.h>
#include <voidworks/packet.h>
#include <voidworks/process.h>

#define AUTO_SUMMON_HOOK_ADDRESS     0x00000000
#define AUTO_SUMMON_HOOK_SIZE        5
#define BLOCK_EVENTS_HOOK_ADDRESS    0x000000000000
#define BLOCK_EVENTS_HOOK_SIZE       5
#define UNLOCKED_SUMMON_HOOK_ADDRESS 0x00000000
#define UNLOCKED_SUMMON_HOOK_SIZE    11
#define UNLOCKED_SUMMON_HOOK_RETURN  (UNLOCKED_SUMMON_HOOK_ADDRESS+UNLOCKED_SUMMON_HOOK_SIZE)

extern "C"
{
  void UnlimitedSummonHook(void);
}

enum class SessionState : uint8_t;
enum class SOSFlag : uint32_t;
enum class MsgMapEvent : uint32_t;
struct PhantomType;
SessionState GetSessionState();
uint8_t GetPlayerCount();
uint8_t GetPlayerNumberAbsolute(uint8_t);
void* GetPlayerNetworkPointer(uint8_t);
uint8_t GetPlayerNumberByPacketPointer(const void*);
wchar_t* GetPlayerNameByNumber(uint8_t, wchar_t*);
bool IsCharacterLoaded();
bool IsPlayerConnected(uint8_t);
bool IsMyWorld();
bool IsBossRoomActive();
uint32_t GetOnlineAreaId();
void SessionDisconnect();
void P2PDisconnect(uint8_t);
void KickPlayer(uint8_t);
PhantomType GetPhantomType(uint8_t);
void SetPhantomType(uint8_t, uint8_t);
void SetPhantomType(PhantomType);
void SendSOS(uint32_t);
void SendSOS(SOSFlag);
void PrintPlayerList();

enum class SessionState : uint8_t
{
  None,
  TryingToCreate,
  FailedToCreate,
  Host,
  TryingToJoin,
  FailedToJoin,
  Client,
  TryingToLeave,
  FailedToLeave,
};

enum class SOSFlag : uint32_t
{
  WhiteSign = 0x00,
  RedOrb    = 0x00,
  RedSign   = 0x00,
};

enum class MsgMapEvent : uint32_t
{
  ForceAnimation1 = 0x0000,
  ForceAnimation2 = 0x0000,
  ForceAnimation3 = 0x0000,
  DarkSpiritDead  = 0x0000,
  SendHostMenu    = 0x0000,
  OnKickOut       = 0x0000,
  FogwallKick     = 0x0000,
  FogwallKick2    = 0x0000,
};

struct PhantomType
{
  uint32_t character = 0;
  uint32_t team      = 1;
};

const PhantomType phantom_type_host    {0, 1};
const PhantomType phantom_type_phantom {1, 2};
const PhantomType phantom_type_invader {2, 16};

#endif
