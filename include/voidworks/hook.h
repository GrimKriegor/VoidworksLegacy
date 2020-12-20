#ifndef HOOK_H_
#define HOOK_H_

#include <voidworks/common.h>
#include <voidworks/process.h>

class BasicHook
{
  private:
    ProcessInterface* ds3_;
    uint8_t opcode_             = 0x00;
    size_t size_                = 5;
    uintptr_t source_           = 0x00;
    uintptr_t destination_      = 0x00;
    size_t offset_              = 0;
    uintptr_t return_           = 0x00;
    uintptr_t offset_source_    = 0x00;
    uint8_t original_code_[256] = {0};
    void CaptureOriginalCode();
    void Inject();
    void Restore();
  public:
    BasicHook(uint8_t, size_t, void*, void* = 0x00, size_t = 0);
    ~BasicHook();
};

#endif
