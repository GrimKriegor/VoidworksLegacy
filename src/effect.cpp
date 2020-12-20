#include <voidworks/effect.h>

void EffectToDataBlock(uint8_t* data, uint32_t player_id, uint32_t id, float value)
{
  const uint32_t param = 0x00000000;
  memcpy((data+0x00), &player_id, 4);
  memcpy((data+0x00), &value, 4);
  memcpy((data+0x00), &id, 4);
  memcpy((data+0x00), &param, 4);
}

void ApplyEffectEntity(const void* entity, uint32_t id)
{
  if (!IsCharacterLoaded() || !entity) { return; }
  void (*sprjApplyEffect)(...);
  *(uintptr_t*)&sprjApplyEffect =
    ProcessInterface::GetInstance()->GetBaseAddress() + FUNC_EFFECT_APPLY;
  sprjApplyEffect(entity, id, entity);
}

void ApplyEffectSelf(uint32_t id)
{
  if (!IsCharacterLoaded()) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  void* player_pointer = ds3->GetDynamicAddress({BASE_B, 0x00, 0x00});
  ApplyEffectEntity(player_pointer, id);
}

void ApplyEffectSelf(EffectId id)
{
  ApplyEffectSelf((uint32_t)id);
}

void ApplyEffectPlayer(uint8_t player_number, uint32_t id, bool serverside, float value)
{
  if (!IsPlayerConnected(player_number)) { return; }
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  mLvPtr player_mlp = {BASE_B, 0x00, (uintptr_t)(player_number * 0x00)};
  mLvPtr player_entity_mlp = player_mlp;
  player_entity_mlp.push_back(0x00);
  void* player_pointer = ds3->GetDynamicAddress(player_entity_mlp);
  if (serverside)
  {
    mLvPtr player_id_mlp = player_mlp;
    player_id_mlp.push_back(0x00);
    uint32_t player_id = ds3->ReadInt32(ds3->GetDynamicAddress(player_id_mlp));
    uint8_t buffer[16] = {0};
    EffectToDataBlock(buffer, player_id, id, value);
    SendPacketSession(PacketId::Effect, buffer, 0x00);
  }
  ApplyEffectEntity(player_pointer, id);
}

void ApplyEffectPlayer(uint8_t player_number, EffectId id, bool serverside, float value)
{
  ApplyEffectPlayer(player_number, (uint32_t)id, serverside, value);
}
