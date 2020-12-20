#ifndef PROTECTION_HANDLER_H_
#define PROTECTION_HANDLER_H_

#include <voidworks/animation.h>
#include <voidworks/common.h>
#include <voidworks/effect.h>
#include <voidworks/hook.h>
#include <voidworks/item.h>
#include <voidworks/packet_handler.h>
#include <voidworks/param.h>
#include <voidworks/param_classes.h>
#include <voidworks/player.h>
#include <voidworks/process.h>
#include <voidworks/protection.h>
#include <voidworks/sound.h>
#include <voidworks/window.h>

enum class PacketHandlingPolicy
{
  Drop,
  Kick,
  Reflect,
};

class ProtectionHandler
{
  private:
    static ProtectionHandler* instance_;
    ProtectionHandler();
    void EnableSubroutines();
    void DisableSubroutines();
    bool enforcement_state_ = false;
    bool disable_malicious_effects_state_ = false;
    std::vector<SpEffectParam*> disable_malicious_effects_param_store_;
    bool packet_protections_state_ = false;
    PacketHandlingPolicy packet_handling_policy_ = PacketHandlingPolicy::Drop;
  public:
    ~ProtectionHandler();
    static ProtectionHandler* GetInstance();
    void SetEnforcement(bool);
    void ToggleEnforcement();
    void DisableMaliciousEffects(bool);
    void SetDefaultPacketHandlingPolicy(PacketHandlingPolicy);
    PacketHandlingPolicy GetDefaultPacketHandlingPolicy();
    void PacketProtections(bool);
};

uint32_t NeutralizeMaliciousPackets(void* session, void* sender, uint32_t id, uint8_t* buffer, uint32_t length);

#endif
