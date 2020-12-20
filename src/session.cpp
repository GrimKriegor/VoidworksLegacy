#include <voidworks/session.h>

const void* UnlimitedSummonHookReturn = (const void*)UNLOCKED_SUMMON_HOOK_RETURN;

__asm__(
  ".section .text\n\t"
  ".global UnlimitedSummonHook\n\t"
  "UnlimitedSummonHook:\n\t"
  "movl  $0x00, 0x00(%rbx)\n\t"
  "add   $0x00, %rsi\n\t"
  "add   $0x00, %rdi\n\t"
  "jmp   *UnlimitedSummonHookReturn(%rip)\n\t"
);

SessionState GetSessionState()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return (SessionState)ds3->ReadByte(ds3->GetDynamicAddress({SPRJ_SESSION_MANAGER, 0x0000}));
}

uint8_t GetPlayerCount()
{
  uint8_t player_count = 0;
  for (uint8_t player_number = 1; player_number <= 5; player_number++)
  {
    if (IsPlayerConnected(player_number))
    {
      player_count++;
    }
  }
  return player_count;
}

uint8_t GetPlayerNumberAbsolute(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return 0; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadByte(ds3->GetDynamicAddress(
        {BASE_B, 0x00, (uintptr_t)(player_number*0x00), XB, 0x00}));
}

void* GetPlayerNetworkPointer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return nullptr; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->GetDynamicAddress(
      {BASE_B, 0x00, (uintptr_t)(player_number*0x00), 0x0000, 0x00, 0x00});
}

uint8_t GetPlayerNumberByPacketPointer(const void* pointer)
{
  pointer = (void*)(*(uintptr_t*)pointer);
  for (uint8_t player_number = 1; player_number <= 5; player_number++)
  {
    if (GetPlayerNetworkPointer(player_number) == pointer)
    {
      return player_number;
    }
  }
  return 0;
}

wchar_t* GetPlayerNameByNumber(uint8_t player_number, wchar_t* name)
{
  if (!IsPlayerConnected(player_number)) { return name; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  ds3->ReadWideString(
      ds3->GetDynamicAddress({BASE_B, 0x00, (uintptr_t)(0x00*player_number), XB, 0x00}),
      name,
      16
    );
  return name;
}

bool IsCharacterLoaded()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->IsMlPointerDereferenceable({BASE_B, 0x00, 0x00});
}

bool IsPlayerConnected(uint8_t player_number)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t player_offset = (0x00 * (uintptr_t)player_number);
  return ds3->IsMlPointerDereferenceable({BASE_B, 0x00, player_offset, 0x00});
}

bool IsMyWorld()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadByte(ds3->GetDynamicAddress({BASE_C, 0x0000}));
}

bool IsBossRoomActive()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadByte(ds3->GetDynamicAddress({BASE_A, 0x00}));
}

uint32_t GetOnlineAreaId()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  return ds3->ReadInt32(ds3->GetDynamicAddress({BASE_B, 0x00, 0x0000}));
}

void SessionDisconnect()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t process_base_address = ds3->GetBaseAddress();
  void (*sprjSessionDisconnect)(...);
  *(uintptr_t*)&sprjSessionDisconnect = process_base_address + FUNC_SESSION_DISCONNECT;
  uintptr_t sprjSessionManager = *(uintptr_t*)(process_base_address + SPRJ_SESSION_MANAGER);
#if (DEBUG >= LOG_WARNING)
  printf("Disconnecting from session.\n");
#endif
  sprjSessionDisconnect(sprjSessionManager);
}

void P2PDisconnect(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t process_base_address = ds3->GetBaseAddress();
  void (*sprjP2PDisconnect)(...);
  *(uintptr_t*)&sprjP2PDisconnect = process_base_address + FUNC_P2P_DISCONNECT;
  void* sprjP2PDisconnectSocket = ds3->GetDynamicAddress({BASE_C, 0x0000, 0x00});
  uint32_t player_handle = (player_number + 0x00000000);
  sprjP2PDisconnect(sprjP2PDisconnectSocket, player_handle, 0x00);
}

void KickPlayer(uint8_t player_number)
{
  if (!IsMyWorld() || !IsPlayerConnected(player_number)) { return; }
#if (DEBUG >= LOG_WARNING)
  printf("Kicking player %d\n", player_number);
#endif
  P2PDisconnect(player_number);
}

PhantomType GetPhantomType(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return phantom_type_host; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  PhantomType type;
  type.character = ds3->ReadInt32(ds3->GetDynamicAddress(
        {BASE_B, 0x00, (uintptr_t)(0x00*player_number), 0x00}));
  type.team      = ds3->ReadInt32(ds3->GetDynamicAddress(
        {BASE_B, 0x00, (uintptr_t)(0x00*player_number), 0x00}));
  return type;
}

void SetPhantomType(uint32_t character, uint32_t team)
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
#if (DEBUG >= LOG_WARNING)
  printf("Setting phantom type to character: %d, team: %d\n", character, team);
#endif
  ds3->WriteInt32(ds3->GetDynamicAddress({BASE_B, 0x00, 0x00}), character);
  ds3->WriteInt32(ds3->GetDynamicAddress({BASE_B, 0x00, 0x00}), team);
}

void SetPhantomType(PhantomType phantom_type)
{
  SetPhantomType(phantom_type.character, phantom_type.team);
}

void SendSOS(uint32_t flag)
{
  if (!IsMyWorld()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t process_base_address = ds3->GetBaseAddress();
  void (*sprjSendSOS)(...);
  *(uintptr_t*)&sprjSendSOS = process_base_address + FUNC_SOS_SEND;
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG "Sending SOS with id: %d\n" ANSI_RESET, flag);
#endif
  sprjSendSOS(ds3->GetDynamicAddress({BASE_B, 0x00, 0x00}), flag);
}

void SendSOS(SOSFlag flag)
{
  SendSOS((uint32_t)flag);
}

void PrintPlayerList()
{
  if (!GetPlayerCount())
  {
    printf(ANSI_BHYEL "No players connected.\n" ANSI_RESET);
    return;
  }
  for (uint8_t player_number = 1; player_number <= 5; player_number++)
  {
    if (!IsPlayerConnected(player_number)) { continue; }
    wchar_t player_name[16] = {0};
    GetPlayerNameByNumber(player_number, player_name);
    printf(ANSI_BHYEL "%d) %S\n" ANSI_RESET, player_number, player_name);
  }
}
