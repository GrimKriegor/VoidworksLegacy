#ifndef POSITION_H_
#define POSITION_H_

#include <math.h>
#include <vector>
#include <voidworks/common.h>
#include <voidworks/process.h>
#include <voidworks/session.h>

Pos GetSetPositionPlayer(uint8_t, const Pos&, bool);
Pos GetPositionPlayer(uint8_t);
Pos GetPositionSelf();
void SetPositionSelf(const Pos&);
void PrintPosition(const Pos&);
void RelativeMove(float, float, float);
void RelativeMove(const Pos&);
float MeasureDistance(const Pos&, const Pos&);
void TeleportToPlayer(uint8_t);

#endif
