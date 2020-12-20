#ifndef PACKET_HANDLER_H_
#define PACKET_HANDLER_H_

#include <functional>
#include <map>
#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/packet.h>
#include <voidworks/process.h>

#define HANDLE_PACKET_INBOUND_HOOK_ADDRESS 0x000000000000
#define HANDLE_PACKET_INBOUND_HOOK_SIZE    5
#define HANDLE_PACKET_INBOUND_HOOK_RETURN \
  (HANDLE_PACKET_INBOUND_HOOK_ADDRESS+HANDLE_PACKET_INBOUND_HOOK_SIZE)
#define HANDLE_PACKET_OUTBOUND_HOOK_ADDRESS 0x000000000000
#define HANDLE_PACKET_OUTBOUND_HOOK_SIZE    7
#define HANDLE_PACKET_OUTBOUND_HOOK_RETURN \
  (HANDLE_PACKET_OUTBOUND_HOOK_ADDRESS+HANDLE_PACKET_OUTBOUND_HOOK_SIZE)

typedef std::function<uint32_t(void*, void*, uint32_t, uint8_t*, uint32_t)> PacketHandlerFunction;
typedef std::pair<std::string, PacketHandlerFunction> PacketHandlerEntry;
typedef std::map<std::string, PacketHandlerFunction> PacketHandlerList;

extern "C"
{
  uint32_t sprjHandlePacketInbound(void*, void*, uint32_t, uint8_t*, uint32_t);
  uint32_t sprjHandlePacketOutbound(void*, void*, uint32_t, uint8_t*, uint32_t);
  uint32_t HandlePacketInbound(void*, void*, uint32_t, uint8_t*, uint32_t);
  uint32_t HandlePacketOutbound(void*, void*, uint32_t, uint8_t*, uint32_t);
}

class PacketManager
{
  private:
    static PacketManager* instance_;
    BasicHook* packet_hook_inbound_ = nullptr;
    BasicHook* packet_hook_outbound_ = nullptr;
    bool packet_hook_installed_ = false;
    PacketManager();
  public:
    ~PacketManager();
    static PacketManager* GetInstance();
    void InstallHooks();
    void UninstallHooks();
};

class PacketHandlerRegistry
{
  private:
    static PacketHandlerRegistry* instance_;
    PacketHandlerRegistry();
    PacketHandlerList InboundHandlerList;
    PacketHandlerList OutboundHandlerList;
    void RegisterUnregisterHandler(bool, bool, const std::string&, PacketHandlerFunction);
  public:
    ~PacketHandlerRegistry();
    static PacketHandlerRegistry* GetInstance();
    const PacketHandlerList* GetInboundHandlerList();
    const PacketHandlerList* GetOutboundHandlerList();
    void RegisterInboundHandler(const std::string&, PacketHandlerFunction);
    void RegisterOutboundHandler(const std::string&, PacketHandlerFunction);
    void UnregisterInboundHandler(const std::string&);
    void UnregisterOutboundHandler(const std::string&);
};

#endif
