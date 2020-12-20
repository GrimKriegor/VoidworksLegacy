#include <voidworks/session_watcher.h>

SessionWatcher* SessionWatcher::instance_ = 0;

SessionWatcher::SessionWatcher()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "SessionWatcher initialized\n" ANSI_RESET);
#endif
}

SessionWatcher* SessionWatcher::GetInstance()
{
  if (!instance_)
  {
    instance_ = new SessionWatcher();
  }
  return instance_;
}

SessionWatcher::~SessionWatcher()
{
#if (DEBUG >= LOG_INFO)
  printf(ANSI_INFO_MSG "SessionWatcher terminated\n" ANSI_RESET);
#endif
}
