#include <voidworks/target.h>

const void* TargetTrackerHookReturn = (const void*)TARGET_TRACKER_HOOK_RETURN;

__asm__(
  ".global TargetTrackerHook\n\t"
  "TargetTrackerHook:\n\t"
  "movabs %rax, _ZN13TargetTracker18target_entity_ptr_E\n\t"
  "mov    0x0000(%rax), %rax\n\t"
  "jmp    *TargetTrackerHookReturn(%rip)"
);

TargetTracker* TargetTracker::instance_ = 0;

void* TargetTracker::target_entity_ptr_ = NULL;

TargetTracker::TargetTracker()
{
  ds3_ = ProcessInterface::GetInstance();
  hook_ = new BasicHook(
      0x00,
      TARGET_TRACKER_HOOK_SIZE,
      (void*)TARGET_TRACKER_HOOK_ADDRESS,
      (void*)TargetTrackerHook
    );
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "TargetTracker initialized\n" ANSI_RESET);
#endif
}

TargetTracker* TargetTracker::GetInstance()
{
  if (!instance_)
  {
    instance_ = new TargetTracker();
  }
  return instance_;
}

TargetTracker::~TargetTracker()
{
  RestoreLockOnRange();
  delete hook_;
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "TargetTracker terminated\n" ANSI_RESET);
#endif
}

void* TargetTracker::GetTarget()
{
  return target_entity_ptr_;
}

bool TargetTracker::IsLockedOn()
{
  return (bool)ds3_->ReadByte(ds3_->GetDynamicAddress({SPRJ_LOCKON_MANAGER, 0x0000}));
}

void TargetTracker::SetLockOnRange(float range)
{
  ds3_->WriteFloat(ds3_->GetDynamicAddress({SPRJ_LOCKON_MANAGER, 0x0000}), range);
  ds3_->WriteFloat(ds3_->GetDynamicAddress({SPRJ_LOCKON_MANAGER, 0x0000}), range);
#if (DEBUG >= LOG_WARNING)
  printf("Setting lock on range to %.2f\n", range);
#endif
}

void TargetTracker::RestoreLockOnRange()
{
  SetLockOnRange(2.0f);
}
