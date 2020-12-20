#ifndef WINDOW_H_
#define WINDOW_H_

#include <windows.h>
#include <voidworks/common.h>
#include <voidworks/hook.h>
#include <voidworks/process.h>

#define MESSAGE_BANNER_SIZE         64
#define MESSAGE_BANNER_HOOK_ADDRESS 0x000000000000
#define MESSAGE_BANNER_HOOK_SIZE    5
#define MESSAGE_BANNER_HOOK_ABORT   (MESSAGE_BANNER_HOOK_ADDRESS+MESSAGE_BANNER_HOOK_SIZE)
#define MESSAGE_BANNER_HOOK_RETURN  (MESSAGE_BANNER_HOOK_ADDRESS+0x00)

extern "C"
{
  void MessageBannerHook(void);
}

void DisableStartupLogos();
void SetWindowBorderless();
void ShowMessageBanner(const wchar_t*);

#endif
