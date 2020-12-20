#ifndef BULLET_TRACKER_H_
#define BULLET_TRACKER_H_

#include <voidworks/bullet.h>
#include <voidworks/common.h>
#include <voidworks/hook.h>

#define BULLET_TRACKER_HOOK_ADDRESS 0x000000000000
#define BULLET_TRACKER_HOOK_SIZE 8
#define BULLET_TRACKER_HOOK_RETURN (BULLET_TRACKER_HOOK_ADDRESS+BULLET_TRACKER_HOOK_SIZE)

extern "C"
{
  void BulletTrackerHook(void);
}

class BulletTracker
{
  private:
    BulletTracker();
    static BulletTracker* instance_;
    ProcessInterface* ds3_;
    BasicHook* hook_;
    static void* target_ptr_;
    static uint32_t target_id_;
    static uint32_t target_shooter_;
  public:
    ~BulletTracker();
    static BulletTracker* GetInstance();
    void SetTargetId(uint32_t);
    void SetTargetId(BulletId);
    void UnsetTargetId();
    void SetTargetShooter(uint8_t);
    void SetTargetShooterSelf();
    void UnsetTargetShooter();
    void* GetPointer();
    Pos GetPosition();
};

#endif
