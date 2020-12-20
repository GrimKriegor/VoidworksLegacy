#include <voidworks/adapter/ds3connectioninfo.h>

DS3ConnectionInfoAdapter* DS3ConnectionInfoAdapter::instance_ = nullptr;

DS3ConnectionInfoAdapter::DS3ConnectionInfoAdapter()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "DS3ConnectionInfoAdapter initialized\n" ANSI_RESET);
#endif
}

DS3ConnectionInfoAdapter* DS3ConnectionInfoAdapter::GetInstance()
{
  if (!instance_)
  {
    instance_ = new DS3ConnectionInfoAdapter();
  }
  return instance_;
}

DS3ConnectionInfoAdapter::~DS3ConnectionInfoAdapter()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "DS3ConnectionInfoAdapter terminated\n" ANSI_RESET);
#endif
}
