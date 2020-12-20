#ifndef TARGET_H_
#define TARGET_H_

#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/process.h>

#define TARGET_TRACKER_HOOK_ADDRESS 0x000000000000
#define TARGET_TRACKER_HOOK_SIZE 7
#define TARGET_TRACKER_HOOK_RETURN (TARGET_TRACKER_HOOK_ADDRESS+TARGET_TRACKER_HOOK_SIZE)

extern "C"
{
  void TargetTrackerHook(void);
}

class TargetTracker
{
  private:
    static TargetTracker* instance_;
    static void* target_entity_ptr_;
    ProcessInterface* ds3_;
    BasicHook* hook_;
    TargetTracker();
  public:
    ~TargetTracker();
    static TargetTracker* GetInstance();
    void* GetTarget();
    bool IsLockedOn();
    void SetLockOnRange(float);
    void RestoreLockOnRange();
};

#endif
