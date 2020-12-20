#include <voidworks/input.h>

int16_t GetAsyncKeyState(VirtualKey key)
{
  return GetAsyncKeyState((uint32_t)key);
}

bool IsKeyDown(VirtualKey key)
{
  return (bool)(GetAsyncKeyState(key) & 0x0000);
}

bool IsKeyDown(VirtualKey key1, VirtualKey key2)
{
  return (IsKeyDown(key1) && IsKeyDown(key2));
}

void GetUserInputString(char* string, size_t size)
{
  memset(string, 0, size);
  fgets(string, size, stdin);
  string[strcspn(string, "\n")] = 0;
}

int64_t GetUserInputIntenger()
{
  const size_t size = 24;
  char string[size];
  GetUserInputString(string, size);
  try
  {
    return std::stoi(string, nullptr, 10);
  }
  catch (...)
  {
    return -1;
  }
}

