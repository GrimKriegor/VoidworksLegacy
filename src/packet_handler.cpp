#include <voidworks/packet_handler.h>

const void* HandlePacketInboundHookReturn = (const void*)HANDLE_PACKET_INBOUND_HOOK_RETURN;
const void* HandlePacketOutboundHookReturn = (const void*)HANDLE_PACKET_OUTBOUND_HOOK_RETURN;

__asm__(
  ".global sprjHandlePacketInbound\n\t"
  "sprjHandlePacketInbound:\n\t"
  "mov %rbx, 0x00(%rsp)\n\t"
  "jmp *HandlePacketInboundHookReturn(%rip)"
);

__asm__(
  ".global sprjHandlePacketOutbound\n\t"
  "sprjHandlePacketOutbound:\n\t"
  "mov %rsp, %rax\n\t"
  "mov %r9, 0x00(%rax)\n\t"
  "jmp *HandlePacketOutboundHookReturn(%rip)"
);

uint32_t HandlePacketInbound(void* session, void* sender, uint32_t id, uint8_t* buffer, uint32_t max_length)
{
  uint32_t length = sprjHandlePacketInbound(session, sender, id, buffer, max_length);
  if (!length) { return 0; }
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "Packet received: id %#x, length %d, max_length %d\n"
      ANSI_RESET,
      id, length, max_length
    );
#endif
  PacketHandlerRegistry* registry = PacketHandlerRegistry::GetInstance();
  for (auto handler : *registry->GetInboundHandlerList())
  {
    length = handler.second(session, sender, id, buffer, length);
    if (!length) { return 0; }
  }
  return length;
}

uint32_t HandlePacketOutbound(void* session, void* sender, uint32_t id, uint8_t* buffer, uint32_t max_length)
{
  uint32_t length = max_length;
  PacketHandlerRegistry* registry = PacketHandlerRegistry::GetInstance();
  for (auto handler : *registry->GetOutboundHandlerList())
  {
    length = handler.second(session, sender, id, buffer, max_length);
    if (!length) { return 0; }
  }
#if (DEBUG >= LOG_DEBUG)
  printf(ANSI_INFO_MSG
      "Packet sent: id %#x, length %d, max_length %d\n"
      ANSI_RESET,
      id, length, max_length
    );
#endif
  return sprjHandlePacketOutbound(session, sender, id, buffer, length);
}

PacketManager* PacketManager::instance_ = nullptr;

PacketManager::PacketManager()
{
  InstallHooks();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PacketManager initialized\n" ANSI_RESET);
#endif
}

PacketManager::~PacketManager()
{
  UninstallHooks();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PacketManager terminated\n" ANSI_RESET);
#endif
}

void PacketManager::InstallHooks()
{
  if (packet_hook_installed_) { return; }
  packet_hook_inbound_ = new BasicHook(
    0x00,
    HANDLE_PACKET_INBOUND_HOOK_SIZE,
    (void*)HANDLE_PACKET_INBOUND_HOOK_ADDRESS,
    (void*)HandlePacketInbound
  );
  packet_hook_outbound_ = new BasicHook(
    0x00,
    HANDLE_PACKET_OUTBOUND_HOOK_SIZE,
    (void*)HANDLE_PACKET_OUTBOUND_HOOK_ADDRESS,
    (void*)HandlePacketOutbound
  );
  packet_hook_installed_ = true;
}

void PacketManager::UninstallHooks()
{
  if (!packet_hook_installed_) { return; }
  delete packet_hook_inbound_;
  delete packet_hook_outbound_;
  packet_hook_installed_ = false;
}

PacketManager* PacketManager::GetInstance()
{
  if (!instance_)
  {
    instance_ = new PacketManager();
  }
  return instance_;
}

PacketHandlerRegistry* PacketHandlerRegistry::instance_ = nullptr;

PacketHandlerRegistry::PacketHandlerRegistry()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PacketHandlerRegistry initialized\n" ANSI_RESET);
#endif
}

PacketHandlerRegistry::~PacketHandlerRegistry()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "PacketHandlerRegistry terminated\n" ANSI_RESET);
#endif
}

PacketHandlerRegistry* PacketHandlerRegistry::GetInstance()
{
  if (!instance_)
  {
    instance_ = new PacketHandlerRegistry();
  }
  return instance_;
}

const PacketHandlerList* PacketHandlerRegistry::GetInboundHandlerList()
{
  return &InboundHandlerList;
}

const PacketHandlerList* PacketHandlerRegistry::GetOutboundHandlerList()
{
  return &OutboundHandlerList;
}

void PacketHandlerRegistry::RegisterUnregisterHandler(bool reg, bool outbound, const std::string& name, PacketHandlerFunction function)
{
  PacketHandlerList* packet_handler_list = nullptr;
  if (outbound) {
    packet_handler_list = &OutboundHandlerList;
  } else {
    packet_handler_list = &InboundHandlerList;
  }
  if (reg) {
    auto handler = PacketHandlerEntry(name, function);
    packet_handler_list->insert(handler);
  } else {
    packet_handler_list->erase(name);
  }
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG
      "%s %s packet handler \"%s\"\n"
      ANSI_RESET,
      reg?"Registered":"Unregistered",
      outbound?"outbound":"inbound",
      name.c_str()
    );
#endif
}

void PacketHandlerRegistry::RegisterInboundHandler(const std::string& name, PacketHandlerFunction function)
{
  RegisterUnregisterHandler(true, false, name, function);
}

void PacketHandlerRegistry::RegisterOutboundHandler(const std::string& name, PacketHandlerFunction function)
{
  RegisterUnregisterHandler(true, true, name, function);
}

void PacketHandlerRegistry::UnregisterInboundHandler(const std::string& name)
{
  RegisterUnregisterHandler(false, false, name, nullptr);
}

void PacketHandlerRegistry::UnregisterOutboundHandler(const std::string& name)
{
  RegisterUnregisterHandler(false, true, name, nullptr);
}
