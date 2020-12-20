#include <voidworks/protection_handler.h>

ProtectionHandler* ProtectionHandler::instance_ = 0;

ProtectionHandler::ProtectionHandler()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ProtectionHandler initialized\n" ANSI_RESET);
#endif
}

ProtectionHandler::~ProtectionHandler()
{
  SetEnforcement(false);
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ProtectionHandler terminated\n" ANSI_RESET);
#endif
}

ProtectionHandler* ProtectionHandler::GetInstance()
{
  if (!instance_)
  {
    instance_ = new ProtectionHandler();
  }
  return instance_;
}

void ProtectionHandler::EnableSubroutines()
{
  DisableMaliciousEffects(true);
  //PacketProtections(true);
}

void ProtectionHandler::DisableSubroutines()
{
  DisableMaliciousEffects(false);
  PacketProtections(false);
}

void ProtectionHandler::SetEnforcement(bool state)
{
  if (state == enforcement_state_) { return; }
  enforcement_state_ = state;
  if (state)
  {
    EnableSubroutines();
  }
  else
  {
    DisableSubroutines();
  }
#if (DEBUG >= LOG_WARNING)
  printf("ProtectionHandler Enforcement: %s\n",
      state?"enabled":"disabled");
#endif
}

void ProtectionHandler::ToggleEnforcement()
{
  SetEnforcement(!enforcement_state_);
}

void ProtectionHandler::DisableMaliciousEffects(bool state)
{
  if (state == disable_malicious_effects_state_) { return; }
  disable_malicious_effects_state_ = state;
  if (state)
  {
    for (auto effect_id : GetMaliciousEffectsList())
    {
      auto effect_param = new SpEffectParam((uint32_t)effect_id);
      effect_param->EffectEndurance(1);
      effect_param->Soul(0);
      effect_param->SpCategory(0);
      effect_param->CategoryPriority(0);
      effect_param->HeroPointDamage(0);
      effect_param->StateInfo(0);
      effect_param->ClearSoul(0);
      effect_param->RestrictFlags(4);
      effect_param->EffectSfx(0);
      effect_param->EffectSfx1(0);
      disable_malicious_effects_param_store_
        .push_back(effect_param);
    }
  }
  else
  {
    for (auto effect : disable_malicious_effects_param_store_)
    {
      delete effect;
    }
    disable_malicious_effects_param_store_.clear();
  }
#if (DEBUG >= LOG_WARNING)
  printf(ANSI_INFO_MSG
      "ProtectionHandler neutralize malicious effects: %s\n"
      ANSI_RESET,
      state?"enabled":"disabled"
    );
#endif
}

void ProtectionHandler::SetDefaultPacketHandlingPolicy(PacketHandlingPolicy policy)
{
  packet_handling_policy_ = policy;
}

PacketHandlingPolicy ProtectionHandler::GetDefaultPacketHandlingPolicy()
{
  return packet_handling_policy_;
}

void ProtectionHandler::PacketProtections(bool state)
{
  if (state == packet_protections_state_) { return; }
  auto packet_handler_reg = PacketHandlerRegistry::GetInstance();
  if (state)
  {
    packet_handler_reg->RegisterInboundHandler(
          "neutralize_malicious_packets", PacketHandlerFunction(NeutralizeMaliciousPackets));
    packet_protections_state_ = true;
  }
  else
  {
    packet_handler_reg->UnregisterInboundHandler("neutralize_malicious_packets");
    packet_protections_state_ = false;
  }
#if (DEBUG >= LOG_WARNING)
  printf(ANSI_INFO_MSG
      "ProtectionHandler packet protections: %s\n"
      ANSI_RESET,
      state?"enabled":"disabled"
    );
#endif
}

uint32_t NeutralizeMaliciousPackets(
    void* session, void* sender, uint32_t id, uint8_t* buffer, uint32_t length)
{
  PacketHandlingPolicy packet_handling_policy =
    ProtectionHandler::GetInstance()->GetDefaultPacketHandlingPolicy();
  bool notify = true;
  bool neutralize = false;
  bool blank_buffer = false;
  std::string threat_description = "Unnamed malicious packet";
  std::string policy_description = "ignoring";
  PacketId packet_id = (PacketId)id;
  switch(packet_id)
  {
    case PacketId::MsgMap:
    {
      auto data = (PacketStruct::MsgMap*)buffer;
      auto event = (MsgMapEvent)data->event_id;
      switch(event)
      {
        case MsgMapEvent::FogwallKick:
        case MsgMapEvent::FogwallKick2:
        {
          neutralize = true;
          notify = false;
          packet_handling_policy = PacketHandlingPolicy::Drop;
          ShowMessageBanner(L"Host has entered the boss arena");
          break;
        }
        case MsgMapEvent::SendHostMenu:
        case MsgMapEvent::OnKickOut:
        {
          if (!GetHealthSelf()) break;
          neutralize = true;
          threat_description = "Event kick";
          break;
        }
        default: break;
      }
      break;
    }
    case PacketId::CompleteEvent:
    {
      neutralize = true;
      blank_buffer = true;
      threat_description = "NG+ meme";
      break;
    }
    /*
    case PacketId::ItemDrop:
    {
      auto data = (PacketStruct::ItemDrop*)buffer;
      auto type = (ItemDropType)data->type;
      switch (type)
      {
        case ItemDropType::GuestInventoryAdd:
        case ItemDropType::HostInventoryAdd:
        {
          if (IsAnimationBeingPerformedInSession(PlayerAnimation::PickUp)) break;
          neutralize = true;
          threat_description = "Item injection";
          break;
        }
        default: break;
      }
      break;
    }
    */
    default: break;
  }
  if (neutralize)
  {
    uint8_t player_number = GetPlayerNumberByPacketPointer(sender);
    wchar_t player_name[16] = {0};
    GetPlayerNameByNumber(player_number, player_name);
    switch (packet_handling_policy)
    {
      case PacketHandlingPolicy::Kick:
      {
        if (!IsMyWorld()) { break; }
        policy_description = "kicking";
        KickPlayer(player_number);
        break;
      }
      case PacketHandlingPolicy::Reflect:
      {
        policy_description = "reflecting";
        SendPacketPlayer(player_number, id, buffer, length);
        break;
      }
      default: break;
    }
    if (blank_buffer)
    {
      memset(buffer, 0, length);
    }
    if (notify)
    {
      MusicPlayer::GetInstance()->PlayAsync("SystemHand");
      printf(ANSI_YEL
          "%s attempted by \"%S\" (%d), %s.\n"
          ANSI_RESET,
          threat_description.c_str(),
          player_name,
          player_number,
          policy_description.c_str()
        );
    }
    return 0;
  }
  return length;
}
