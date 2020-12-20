#ifndef CAMERA_H_
#define CAMERA_H_

#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/input.h>
#include <voidworks/options.h>
#include <voidworks/position.h>
#include <voidworks/process.h>
#include <voidworks/subroutine.h>

#define CAMERA_ATTR_HOOK_ADDRESS 0x000000000000
#define CAMERA_ATTR_HOOK_SIZE 7
#define CAMERA_ATTR_HOOK_RETURN (CAMERA_ATTR_HOOK_ADDRESS+CAMERA_ATTR_HOOK_SIZE)

class CameraController
{
  private:
    static CameraController* instance_;
    ProcessInterface* ds3_;
    BasicHook* follow_player_hook_;
    bool following_player_ = false;
    CameraController();
    void SetAttachState(bool);
    void UnfollowPlayer();
  public:
    ~CameraController();
    static CameraController* GetInstance();
    void Attach();
    void Detach();
    void FollowPlayer(uint8_t);
    void SetCameraPosition(const Pos&);
    void KeyboardPrompt();
};

#endif
