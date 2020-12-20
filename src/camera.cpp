#include <voidworks/camera.h>

CameraController* CameraController::instance_ = 0;

void CameraController::SetAttachState(bool state)
{
  ds3_->WriteByte(ds3_->GetDynamicAddress({BASE_D, 0x00, 0x00}), !state);
}

CameraController::CameraController()
{
  ds3_ = ProcessInterface::GetInstance();
}

CameraController::~CameraController()
{
  UnfollowPlayer();
  Attach();
}

CameraController* CameraController::GetInstance()
{
  if (!instance_)
  {
    instance_ = new CameraController();
  }
  return instance_;
}

void CameraController::Attach()
{
  UnfollowPlayer();
  SetAttachState(true);
  Options::SoundAndDisplay::HUD(true);
#if (DEBUG >= LOG_WARNING)
  printf("Camera attached\n");
#endif
}

void CameraController::Detach()
{
  UnfollowPlayer();
  SetAttachState(false);
  Options::SoundAndDisplay::HUD(false);
#if (DEBUG >= LOG_WARNING)
  printf("Camera detached\n");
#endif
}

void CameraController::FollowPlayer(uint8_t player_number)
{
  if (!IsPlayerConnected(player_number)) { return; }
  Attach();
  uintptr_t player_offset = (player_number * 0x00);
  uintptr_t player_pointer = (uintptr_t)ds3_->GetDynamicAddress({BASE_B, 0x00, player_offset, 0x00});
  follow_player_hook_ = new BasicHook(
      0x00,
      CAMERA_ATTR_HOOK_SIZE,
      (void*)CAMERA_ATTR_HOOK_ADDRESS
    );
  ds3_->WriteInt64(ds3_->GetDynamicAddress({BASE_Z, 0x0000}), player_pointer);
  ds3_->WriteFloat(ds3_->GetDynamicAddress({BASE_Z, 0x00}), 9999.0f);
  following_player_ = true;
#if (DEBUG >= LOG_WARNING)
  printf("Camera following player %d\n", player_number);
#endif
}

void CameraController::UnfollowPlayer()
{
  if (!following_player_) { return; }
  ds3_->WriteInt64(ds3_->GetDynamicAddress({BASE_Z, 0x0000}), 0x00);
  ds3_->WriteFloat(ds3_->GetDynamicAddress({BASE_Z, 0x00}), 10.0f);
  delete follow_player_hook_;
  following_player_ = false;
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "Camera stopped following players\n" ANSI_RESET);
#endif
}

void CameraController::SetCameraPosition(const Pos& position)
{
  if (position.size() < 3)
  {
    printf(ANSI_ERROR_MSG "[ERROR] Attempting to move camera to invalid position\n" ANSI_RESET);
    return;
  }
  ds3_->WriteByteArray(
      ds3_->GetDynamicAddress({BASE_D, 0x00, 0x00, 0x00}),
      reinterpret_cast<const uint8_t*>(&position[0]),
      12
    );
}

void CameraController::KeyboardPrompt()
{
  if (!IsCharacterLoaded()) { return; }
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "CameraController keyboard prompt\n" ANSI_RESET);
#endif
  printf(ANSI_BHYEL
      "A) Attach\n"
      "D) Detach\n"
      "F) Detach (fixed position)\n"
      "P) Follow player\n"
      ANSI_RESET
    );
  while (true)
  {
    if      (IsKeyDown(VirtualKey::A)) { Attach(); break; }
    else if (IsKeyDown(VirtualKey::D)) { SetCameraPosition(GetPositionSelf()); Detach(); break; }
    else if (IsKeyDown(VirtualKey::F)) { Detach(); break; }
    else if (IsKeyDown(VirtualKey::P)) { FollowPlayer(PlayerNumberKeyboardPrompt()); break; }
    else if (IsKeyDown(VirtualKey::Escape)) { Attach(); break; }
  }
}
