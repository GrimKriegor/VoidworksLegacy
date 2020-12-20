#ifndef SESSION_WATCHER_H_
#define SESSION_WATCHER_H_

#include <voidworks/common.h>

class SessionWatcher
{
  private:
    static SessionWatcher* instance_;
    SessionWatcher();
  public:
    ~SessionWatcher();
    static SessionWatcher* GetInstance();
};
#endif
