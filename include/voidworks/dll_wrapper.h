#ifndef DLL_WRAPPER_H_
#define DLL_WRAPPER_H_

#include <windows.h>
#include <voidworks/common.h>

#define importD3D(...) __VA_ARGS__;
#define IMPORT(a) a##_=GetProcAddress(BaseAddressGenuine,#a)
#define MATCH(s,n) strcmp(section, s) == 0 && strcmp(name, n) == 0

void WrapGenuineDll(HINSTANCE);
void UnloadDll();

extern "C"
{
  void LoadGenuineDll(void);
}

#endif
