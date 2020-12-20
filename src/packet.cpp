#include <voidworks/packet.h>

void SendPacketSession(uint32_t id, const void* buffer, uint32_t length)
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t process_base_address = ds3->GetBaseAddress();
  void (*sprjSendPacketSession)(...);
  *(uintptr_t*)&sprjSendPacketSession = process_base_address + FUNC_PACKET_SEND_SESSION;
  uintptr_t sprjP2PSessionManager = *(uintptr_t*)(process_base_address + SPRJ_P2P_SESSION_MANAGER);
  sprjSendPacketSession(sprjP2PSessionManager, id, buffer, length);
}

void SendPacketSession(PacketId id, const void* buffer, uint32_t length)
{
  SendPacketSession((uint32_t)id, buffer, length);
}

void SendPacketPlayer(uint8_t player_number, uint32_t id, const void* buffer, uint32_t length)
{
  if (!IsPlayerConnected(player_number)) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t process_base_address = ds3->GetBaseAddress();
  void (*sprjSendPacketPlayerPlayer)(...);
  *(uintptr_t*)&sprjSendPacketPlayerPlayer = process_base_address + FUNC_PACKET_SEND_PLAYER;
  uintptr_t sprjP2PSessionManager = *(uintptr_t*)(process_base_address + SPRJ_P2P_SESSION_MANAGER);
  void* player_ptr = ds3->GetDynamicAddress(
      {BASE_B, 0x00, (uintptr_t)(0x00 * player_number), 0x0000, 0x00});
  sprjSendPacketPlayerPlayer(sprjP2PSessionManager, player_ptr, id, buffer, length);
}

void SendPacketPlayer(uint8_t player_number, PacketId id, const void* buffer, uint32_t length)
{
  SendPacketPlayer(player_number, (uint32_t)id, buffer, length);
}

void DamageInstance::WriteDamageDataBlock()
{
  memcpy((damage_data_+0x00), &physical, 4);
  memcpy((damage_data_+0x00), &magic, 4);
  memcpy((damage_data_+0x00), &fire, 4);
  memcpy((damage_data_+0x00), &lightning, 4);
  memcpy((damage_data_+0x00), &dark, 4);
  memcpy((damage_data_+0x00), &base, 2);
  memcpy((damage_data_+0x00), &base, 2);
  memcpy((damage_data_+0x00), &base, 2);
  memcpy((damage_data_+0x00), &base, 2);
  memcpy((damage_data_+0x00), &base, 2);
  memcpy((damage_data_+0x00), &id, 4);
}

void DamageInstance::SendToPlayer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  WriteDamageDataBlock();
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG "Sending dmg packet to %#016llx\n" ANSI_RESET, player_ptr);
  printf(ANSI_INFO_MSG
      "id: %d, base: %.2f, physical: %.2f, magic: %.2f, fire: %.2f, lightning: %.2f, dark: %.2f\n"
      ANSI_RESET, id, base, physical, magic, fire, lightning, dark);
#endif
  SendPacketPlayer(player_number, PacketId::Damage, damage_data_, 0x00);
}
