#ifndef PROCESS_H_
#define PROCESS_H_

#include <iostream>
#include <vector>
#include <windows.h>
#include <dbghelp.h>
#include <winuser.h>
#include <voidworks/addresses.h>
#include <voidworks/common.h>

#define FRAMEWORK_NAME           "Voidworks"
#define EXECUTABLE_NAME          "DarkSoulsIII.exe"
#define WINDOW_NAME              "DARK SOULS III"
#define EXCEPTION_STRING_SIZE    1024

class ProcessInterface
{
  private:
    static ProcessInterface* instance_;
    ProcessInterface();
    void AwaitBootup();
    HWND window_handle_;
    HANDLE process_handle_;
    uintptr_t base_address_;
    FILE* stdout_handle_;
    FILE* stderr_handle_;
    FILE* stdin_handle_;
    HWND FindWindowHandle();
    HANDLE FindProcessHandle();
    uintptr_t FindProcessBaseAddress();
    void RegisterExceptionHandler();
    static LONG WINAPI ExceptionHandler(struct _EXCEPTION_POINTERS*);
  public:
    ~ProcessInterface();
    static ProcessInterface* GetInstance();
    HWND GetWindowHandle();
    HANDLE GetHandle();
    uintptr_t GetBaseAddress();
    void OpenDedicatedConsole();
    void CloseDedicatedConsole();
    void* GetDynamicAddress(const mLvPtr&);
    bool IsMlPointerDereferenceable(const mLvPtr&);
    void ReadMemoryValue(const void*, void*, size_t);
    void WriteMemoryValue(void*, const void*, size_t);
    bool ReadBinary(const void*, uint8_t);
    void WriteBinary(void*, uint8_t, bool);
    uint8_t ReadByte(const void*);
    void WriteByte(void*, uint8_t);
    int16_t ReadInt16(const void*);
    void WriteInt16(void*, int16_t);
    int32_t ReadInt32(const void*);
    void WriteInt32(void*, int32_t);
    int64_t ReadInt64(const void*);
    void WriteInt64(void*, int64_t);
    float ReadFloat(const void*);
    void WriteFloat(void*, float);
    double ReadDouble(const void*);
    void WriteDouble(void*, double);
    void ReadByteArray(const void*, uint8_t*, size_t);
    void WriteByteArray(void*, const uint8_t*, size_t);
    void ReadString(const void*, char*, size_t);
    void ReadString(const void*, std::string&, size_t);
    void WriteString(void*, const char*, size_t);
    void WriteString(void*, const std::string&, size_t);
    void ReadWideString(const void*, wchar_t*, size_t);
    void ReadWideString(const void*, std::wstring&, size_t);
    void WriteWideString(void*, const wchar_t*, size_t);
    void WriteWideString(void*, const std::wstring&, size_t);
    bool InjectHook(uint8_t, void*, void*);
    bool InjectHookJmp(void*, void*);
    bool InjectHookCall(void*, void*);
    void InjectNops(void*, size_t);
    void PrintBuffer(const void*, size_t, uint8_t=8, uint8_t=4);
};

#endif
