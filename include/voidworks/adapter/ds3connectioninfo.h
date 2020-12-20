#ifndef ADAPTER_DS3CONNECTIONINFO_H_
#define ADAPTER_DS3CONNECTIONINFO_H_

#include <voidworks/common.h>

class DS3ConnectionInfoAdapter
{
  private:
    static DS3ConnectionInfoAdapter* instance_;
    DS3ConnectionInfoAdapter();
  public:
    ~DS3ConnectionInfoAdapter();
    static DS3ConnectionInfoAdapter* GetInstance();
};

#endif
