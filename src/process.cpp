#include <voidworks/process.h>

ProcessInterface* ProcessInterface::instance_ = 0;

ProcessInterface::ProcessInterface()
{
  process_handle_ = FindProcessHandle();
  base_address_ = FindProcessBaseAddress();
  AwaitBootup();
  window_handle_ = FindWindowHandle();
  OpenDedicatedConsole();
  RegisterExceptionHandler();
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ProcessInterface initialized\n" ANSI_RESET);
#endif
}

HWND ProcessInterface::FindWindowHandle()
{
  HWND window_handle = FindWindowA(NULL, WINDOW_NAME);
  return window_handle;
}

HANDLE ProcessInterface::FindProcessHandle()
{
  DWORD pid;
  GetWindowThreadProcessId(window_handle_, &pid);
  HANDLE process_handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
  return process_handle;
}

uintptr_t ProcessInterface::FindProcessBaseAddress()
{
  return (uintptr_t)GetModuleHandle(EXECUTABLE_NAME);
}

void ProcessInterface::OpenDedicatedConsole()
{
  AllocConsole();
  SetConsoleTitle(FRAMEWORK_NAME);
  freopen_s(&stdout_handle_, "CONOUT$", "w", stdout);
  freopen_s(&stderr_handle_, "CONOUT$", "w", stderr);
  freopen_s(&stdin_handle_, "CONIN$", "r", stdin);
  HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE);
  DWORD console_mode = 0x0000;
  GetConsoleMode(console_handle, &console_mode);
  SetConsoleMode(console_handle, console_mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

void ProcessInterface::CloseDedicatedConsole()
{
  std::cout.clear();
  fclose(stdout_handle_);
  fclose(stderr_handle_);
  fclose(stdin_handle_);
  FreeConsole();
}

void ProcessInterface::RegisterExceptionHandler()
{
  SetUnhandledExceptionFilter(ExceptionHandler);
}

LONG WINAPI ProcessInterface::ExceptionHandler(struct _EXCEPTION_POINTERS* exception)
{
  PEXCEPTION_RECORD record  = exception->ExceptionRecord;
  PCONTEXT          context = exception->ContextRecord;
  wchar_t exception_text[EXCEPTION_STRING_SIZE];
  switch (record->ExceptionCode)
  {
    case EXCEPTION_ACCESS_VIOLATION:
      snwprintf(exception_text, EXCEPTION_STRING_SIZE,
        L"Access violation!\n\n"
        "Instruction at 0x%p\n"
        "(base + 0x%p)\n"
        "attempted to %s\n"
        "memory at 0x%p\n\n"
        "Register dump:\n"
        "RAX = 0x%p\n" "RBX = 0x%p\n" "RCX = 0x%p\n" "RDX = 0x%p\n"
        "RSI = 0x%p\n" "RDI = 0x%p\n" "RBP = 0x%p\n" "RSP = 0x%p\n"
        "R8  = 0x%p\n" "R9  = 0x%p\n" "R10 = 0x%p\n" "R11 = 0x%p\n"
        "R12 = 0x%p\n" "R13 = 0x%p\n" "R14 = 0x%p\n" "R15 = 0x%p",
        record->ExceptionAddress,
        (uintptr_t)record->ExceptionAddress - ProcessInterface::GetInstance()->GetBaseAddress(),
        record->ExceptionInformation[0]?"WRITE":"READ",
        record->ExceptionInformation[1],
        context->Rax, context->Rbx, context->Rcx, context->Rdx,
        context->Rsi, context->Rdi, context->Rbp, context->Rsp,
        context->R8,  context->R9,  context->R10, context->R11,
        context->R12, context->R13, context->R14, context->R15
      );
      break;
    default:
      snwprintf(exception_text, EXCEPTION_STRING_SIZE,
        L"Caught unhandled exception\n"
        "Code: %x\n"
        "Address: %p",
        record->ExceptionCode,
        record->ExceptionAddress
      );
      break;
  }
  MessageBoxW(NULL,
    (LPCWSTR)exception_text,
    (LPCWSTR)(FRAMEWORK_NAME L" Error Dump"),
    MB_ICONERROR | MB_OK
  );
  return EXCEPTION_CONTINUE_SEARCH;
}

ProcessInterface::~ProcessInterface()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "ProcessInterface terminated\n" ANSI_RESET);
#endif
  CloseDedicatedConsole();
}

void ProcessInterface::AwaitBootup()
{
  while (!*(uintptr_t*)(base_address_+BASE_A))
  {
    Sleep(100);
  }
}

ProcessInterface* ProcessInterface::GetInstance()
{
  if (!instance_)
  {
    instance_ = new ProcessInterface;
  }
  return instance_;
}

HWND ProcessInterface::GetWindowHandle()
{
  return window_handle_;
}

HANDLE ProcessInterface::GetHandle()
{
  return process_handle_;
}

uintptr_t ProcessInterface::GetBaseAddress()
{
  return base_address_;
}

void* ProcessInterface::GetDynamicAddress(const mLvPtr& offsets)
{
  uintptr_t addr = offsets[0];
  if (addr < 0x00000000) addr += (uintptr_t)base_address_;
#if (DEBUG >= LOG_VERBOSE)
  printf(ANSI_INFO_MSG "%#04llx " ANSI_RESET, addr);
#endif
  for (uint16_t i = 1; i < offsets.size(); ++i)
  {
#if (DEBUG >= LOG_VERBOSE)
    printf(ANSI_INFO_MSG "%#04llx " ANSI_RESET, offsets[i]);
#endif
    addr = *((uintptr_t*)addr);
    if (addr < 0x0000) { break; }
    addr += offsets[i];
  }
#if (DEBUG >= LOG_VERBOSE)
  printf(ANSI_INFO_MSG "-> %#016llx\n" ANSI_RESET, addr);
#endif
  return (void*)addr;
}

bool ProcessInterface::IsMlPointerDereferenceable(const mLvPtr& ml_pointer)
{
  return (bool)GetDynamicAddress(ml_pointer);
}

void ProcessInterface::ReadMemoryValue(const void* source, void* buffer, size_t size)
{
  if ((uintptr_t)source < 0x0000)
  {
    printf(ANSI_ERROR_MSG "[ERROR] Can't read from invalid memory address!\n" ANSI_RESET);
    return;
  }
  memcpy(buffer, source, size);
}

void ProcessInterface::WriteMemoryValue(void* destination, const void* buffer, size_t size)
{
  if ((uintptr_t)destination < 0x0000)
  {
    printf(ANSI_ERROR_MSG "[ERROR] Can't write to invalid memory address!\n" ANSI_RESET);
    return;
  }
  memcpy(destination, buffer, size);
}

bool ProcessInterface::ReadBinary(const void* source, uint8_t position)
{
  uint8_t buffer = ReadByte(source);
  return (((buffer >> position) & 1) == 1);
}

void ProcessInterface::WriteBinary(void* destination, uint8_t position, bool value)
{
  uint8_t buffer = ReadByte(destination);
  buffer ^= (-value ^ buffer) & (1U << position);
  WriteByte(destination, buffer);
}

uint8_t ProcessInterface::ReadByte(const void* source)
{
  uint8_t buffer;
  ReadMemoryValue(source, &buffer, 1);
  return buffer;
}

void ProcessInterface::WriteByte(void* destination, uint8_t buffer)
{
  WriteMemoryValue(destination, &buffer, 1);
}

int16_t ProcessInterface::ReadInt16(const void* source)
{
  int16_t buffer;
  ReadMemoryValue(source, &buffer, 2);
  return buffer;
}

void ProcessInterface::WriteInt16(void* destination, int16_t buffer)
{
  WriteMemoryValue(destination, &buffer, 2);
}

int32_t ProcessInterface::ReadInt32(const void* source)
{
  int32_t buffer;
  ReadMemoryValue(source, &buffer, 4);
  return buffer;
}

void ProcessInterface::WriteInt32(void* destination, int32_t buffer)
{
  WriteMemoryValue(destination, &buffer, 4);
}

int64_t ProcessInterface::ReadInt64(const void* source)
{
  int64_t buffer;
  ReadMemoryValue(source, &buffer, 8);
  return buffer;
}

void ProcessInterface::WriteInt64(void* destination, int64_t buffer)
{
  WriteMemoryValue(destination, &buffer, 8);
}

float ProcessInterface::ReadFloat(const void* source)
{
  float buffer;
  ReadMemoryValue(source, &buffer, 4);
  return buffer;
}

void ProcessInterface::WriteFloat(void* destination, float buffer)
{
  WriteMemoryValue(destination, &buffer, 4);
}

double ProcessInterface::ReadDouble(const void* source)
{
  double buffer;
  ReadMemoryValue(source, &buffer, 8);
  return buffer;
}

void ProcessInterface::WriteDouble(void* destination, double buffer)
{
  WriteMemoryValue(destination, &buffer, 8);
}

void ProcessInterface::ReadByteArray(const void* destination, uint8_t* buffer, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    uintptr_t new_destination = (uintptr_t)destination + i;
    buffer[i] = ReadByte((void*)new_destination);
  }
}

void ProcessInterface::WriteByteArray(void* destination, const uint8_t* buffer, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    uintptr_t new_destination = (uintptr_t)destination + i;
    WriteByte((void*)new_destination, buffer[i]);
  }
}

void ProcessInterface::ReadString(const void* source, char* buffer, size_t max_length)
{
  strncpy(buffer, (char*)source, max_length);
}

void ProcessInterface::ReadString(const void* source, std::string& buffer, size_t max_length)
{
  char ibuffer[max_length];
  memset(ibuffer, 0, sizeof(ibuffer));
  ReadString(source, ibuffer, max_length);
  buffer = ibuffer;
}

void ProcessInterface::WriteString(void* destination, const char* buffer, size_t max_length)
{
  strncpy((char*)destination, buffer, max_length);
}

void ProcessInterface::WriteString(void* destination, const std::string& buffer, size_t max_length)
{
  WriteString(destination, buffer.c_str(), max_length);
}

void ProcessInterface::ReadWideString(const void* source, wchar_t* buffer, size_t max_length)
{
  wcsncpy(buffer, (wchar_t*)source, max_length);
}

void ProcessInterface::ReadWideString(const void* source, std::wstring& buffer, size_t max_length)
{
  wchar_t ibuffer[max_length];
  memset(ibuffer, 0, sizeof(ibuffer));
  ReadWideString(source, ibuffer, max_length);
  buffer = ibuffer;
}

void ProcessInterface::WriteWideString(void* destination, const wchar_t* buffer, size_t max_length)
{
  wcsncpy((wchar_t*)destination, buffer, max_length);
}

void ProcessInterface::WriteWideString(void* destination, const std::wstring& buffer, size_t max_length)
{
  WriteWideString(destination, buffer.c_str(), max_length);
}

bool ProcessInterface::InjectHook(uint8_t opcode, void* source, void* destination)
{
  if ( !source || !destination )
  {
    printf(ANSI_ERROR_MSG
        "[ERROR] Failed to inject hook with invalid source and or destination\n"
        ANSI_RESET);
    return false;
  }
  uint8_t hook[5] = { 0x00, 0x00, 0x00, 0x00, 0x00 };
  hook[0] = opcode;
  int32_t offset = ((uintptr_t)destination - (uintptr_t)source) + (-5);
  if (abs(offset) > 0x00000000)
  {
    printf(ANSI_ERROR_MSG
        "[ERROR] Failed to inject hook with source: %#016llx "
        "and destination: %#016llx as offset overflows 32 bits\n"
        ANSI_RESET, source, destination);
    return false;
  }
  memcpy(&hook[1], &offset, 4);
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG
      "Injecting Hook with opcode: %#02x, source: %#016llx "
      "and destination: %#016llx\n"
      ANSI_RESET, opcode, source, destination);
#endif
  WriteByteArray(source, hook, 5);
  return true;
}

bool ProcessInterface::InjectHookJmp(void* source, void* destination)
{
  return InjectHook(0x00, source, destination);
}

bool ProcessInterface::InjectHookCall(void* source, void* destination)
{
  return InjectHook(0x00, source, destination);
}

void ProcessInterface::InjectNops(void* destination, size_t number)
{
  uint8_t buffer[number];
  memset(buffer, 0x00, number);
  WriteByteArray(destination, buffer, number);
}

void ProcessInterface::PrintBuffer(const void* buffer, size_t size, uint8_t width, uint8_t separator)
{
  printf("Buffer at %#llx:\n     ", buffer);
  for (size_t i = 0; i < width; i++)
  {
    if (!(i % separator)) printf(" ");
    printf(ANSI_GRY "%02x ", i);
  }
  for (size_t i = 0; i < size; i++)
  {
    if (!(i % width)) printf(ANSI_GRY "\n%04x " ANSI_RESET, i);
    if (!(i % separator)) printf(" ");
    printf("%02x ", reinterpret_cast<const uint8_t*>(buffer)[i]);
  }
  printf("\n");
}
