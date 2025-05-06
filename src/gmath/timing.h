#ifndef TIMING_H
#define TIMING_H

#include <stdint.h>

typedef struct Timer Timer;

void TimeStart(Timer* t);
void TimeEnd(Timer* t);
void CalculateDelta(Timer* t);
uint64_t TimeGetEpoch(Timer* t);
double TimeGetDelta(Timer* t);

#endif