#include <voidworks/bullet_tracker.h>

const void* BulletTrackerHookReturn = (const void*)BULLET_TRACKER_HOOK_RETURN;

__asm__(
  ".global BulletTrackerHook\n\t"
  "BulletTrackerHook:\n\t"
  "push  %rax\n\t"
  "mov   %rdi, _ZN13BulletTracker11target_ptr_E(%rip)\n\t"
  "mov   _ZN13BulletTracker10target_id_E(%rip), %eax\n\t"
  "test  %eax, %eax\n\t"
  "je    BulletTrackerHookSection1\n\t"
  "mov   0x0000(%rdi), %eax\n\t"
  "cmp   _ZN13BulletTracker10target_id_E(%rip), %eax\n\t"
  "jne   BulletTrackerHookOriginalCode\n\t"
  "BulletTrackerHookSection1:\n\t"
  "mov   _ZN13BulletTracker15target_shooter_E(%rip), %eax\n\t"
  "test  %eax, %eax\n\t"
  "je BulletTrackerHookSection2\n\t"
  "mov   0x0000(%rdi), %eax\n\t"
  "cmp   _ZN13BulletTracker15target_shooter_E(%rip), %eax\n\t"
  "jne   BulletTrackerHookOriginalCode\n\t"
  "BulletTrackerHookSection2:\n\t"
  //"mov   %rdi, SBulletAdr(%rip)\n\t"
  "BulletTrackerHookOriginalCode:\n\t"
  "pop   %rax\n\t"
  "movss 0x0000(%rdi), %xmm0\n\t"
  "jmp   *BulletTrackerHookReturn(%rip)"
);

BulletTracker* BulletTracker::instance_ = 0;
void* BulletTracker::target_ptr_ = 0;
uint32_t BulletTracker::target_id_ = 0;
uint32_t BulletTracker::target_shooter_ = 0;

BulletTracker::BulletTracker()
{
  ds3_ = ProcessInterface::GetInstance();
  hook_ = new BasicHook(
      0x00,
      BULLET_TRACKER_HOOK_SIZE,
      (void*)BULLET_TRACKER_HOOK_ADDRESS,
      (void*)BulletTrackerHook
    );
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "BulletTracker initialized\n" ANSI_RESET);
#endif
}

BulletTracker::~BulletTracker()
{
  delete hook_;
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "BulletTracker terminated\n" ANSI_RESET);
#endif
}

BulletTracker* BulletTracker::GetInstance()
{
  if (!instance_)
  {
    instance_ = new BulletTracker();
  }
  return instance_;
}

void BulletTracker::SetTargetId(uint32_t id)
{
  target_id_ = id;
}

void BulletTracker::SetTargetId(BulletId id)
{
  SetTargetId((uint32_t)id);
}

void BulletTracker::UnsetTargetId()
{
  target_id_ = 0;
}

void BulletTracker::SetTargetShooter(uint8_t player_number)
{
  target_shooter_ = (10068000 + player_number);
}

void BulletTracker::SetTargetShooterSelf()
{
  SetTargetShooter(0);
}

void BulletTracker::UnsetTargetShooter()
{
  target_shooter_ = 0;
}

void* BulletTracker::GetPointer()
{
  return target_ptr_;
}

Pos BulletTracker::GetPosition()
{
  Pos position = {0, 0, 0, 0};
  if (!target_ptr_) { return position; }
  for (uint8_t i = 0; i < 3; i++)
  {
    uintptr_t pointer = (uintptr_t)target_ptr_ + (0x00 + (i * 0x00));
    position.at(i) = ds3_->ReadFloat((void*)pointer);
  }
  position.at(3) = ds3_->ReadFloat((void*)((uintptr_t)target_ptr_ + 0x00));
  return position;
}
