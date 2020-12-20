#ifndef ANTICHEAT_H_
#define ANTICHEAT_H_

#include <voidworks/common.h>
#include <voidworks/process.h>

extern "C"
{
  void ACBypassHook(void);
}

void InjectSkipIntro(ProcessInterface*);
void InjectACBypassNops(ProcessInterface*);
void InjectACBypassHook(ProcessInterface*);
void ACBypass();

#endif
