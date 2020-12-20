#include <voidworks/hook.h>

void BasicHook::CaptureOriginalCode()
{
  ds3_->ReadByteArray((void*)source_, original_code_, size_);
}

void BasicHook::Inject()
{
  ds3_->InjectNops((void*)source_, size_);
  if (opcode_ == 0x00) { return; }
  ds3_->InjectHook(opcode_, (void*)offset_source_, (void*)destination_);
}

void BasicHook::Restore()
{
  ds3_->WriteByteArray((void*)source_, original_code_, size_);
}

BasicHook::BasicHook(uint8_t opcode, size_t size, void* source, void* destination, size_t offset)
{
#ifdef SAFE_TO_HOOK
  opcode_ = opcode;
  size_ = size;
  source_ = (uintptr_t)source;
  destination_ = (uintptr_t)destination;
  offset_ = offset;
  return_ = source_ + size_;
  if (size_ - offset_ < 5)
  {
    printf(ANSI_ERROR_MSG
        "[ERROR] Offset %d for hook at %#016llx is too large!\n"
        ANSI_RESET,
        offset_, source_
      );
    return;
  }
  offset_source_ = source_ + offset_;
  ds3_ = ProcessInterface::GetInstance();
  CaptureOriginalCode();
  Inject();
#else
  printf(ANSI_ERROR_MSG
      "[ERROR] Hooks disabled until a new form of Anti-Tamper bypass is implemented\n"
      ANSI_RESET
    );
#endif
}

BasicHook::~BasicHook()
{
#ifdef SAFE_TO_HOOK
  Restore();
#endif
}
