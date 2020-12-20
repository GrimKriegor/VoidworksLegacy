#include <voidworks/window.h>

const void* MessageBannerHookAbort = (const void*)MESSAGE_BANNER_HOOK_ABORT;
const void* MessageBannerHookReturn = (const void*)MESSAGE_BANNER_HOOK_RETURN;

wchar_t message_banner[MESSAGE_BANNER_SIZE] = {0};

__asm__(
  ".global MessageBannerHook\n\t"
  "MessageBannerHook:\n\t"
  "mov %ebx, %r9d\n\t"
  "xor %edx, %edx\n\t"
  "cmp $0x00000000, %r9d\n\t"
  "jne MessageBannerHookAbort\n\t"
  "lea message_banner(%rip), %rax\n\t"
  "jmp *MessageBannerHookReturn(%rip)"
);

void DisableStartupLogos()
{
  ProcessInterface* ds3 = ProcessInterface::GetInstance();
  uintptr_t location = ds3->GetBaseAddress() + HOOK_LOGOS_JUMP;
  ds3->InjectNops((void*)location, 2);
}

void SetWindowBorderless()
{
  RECT final;
  HWND hWnd = ProcessInterface::GetInstance()->GetWindowHandle();
  final.top = 0;
  final.left = 0;
  final.bottom = GetSystemMetrics(SM_CYSCREEN);
  final.right = GetSystemMetrics(SM_CXSCREEN);
  SetWindowLong(hWnd, GWL_STYLE, WS_POPUP | WS_VISIBLE);
  AdjustWindowRect(&final, GetWindowLong(hWnd, GWL_STYLE), FALSE);
  SetWindowLong(hWnd, GWL_EXSTYLE, (GetWindowLong(hWnd, GWL_EXSTYLE) | WS_EX_TOPMOST));
  MoveWindow(hWnd, final.left, final.top, final.right - final.left, final.bottom - final.top, TRUE);
}

void ShowMessageBanner(const wchar_t* message)
{
  wcsncpy(message_banner, message, MESSAGE_BANNER_SIZE);
  BasicHook hook = BasicHook(
      0x00,
      MESSAGE_BANNER_HOOK_SIZE,
      (void*)MESSAGE_BANNER_HOOK_ADDRESS,
      (void*)MessageBannerHook
    );
  void (*sprjShowMessageBanner)(...);
  *(uintptr_t*)&sprjShowMessageBanner = FUNC_MSGBANNER_SHOW;
  uintptr_t sprjLuaEventManager = *(uintptr_t*)SPRJ_LUA_EVENT_MANAGER;
  sprjShowMessageBanner(sprjLuaEventManager, 0x00, 0x00000000);
}
