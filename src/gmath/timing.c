#include "timing.h"

#include <time.h>

struct Timer {
    time_t frameStart, frameEnd;
    time_t programEpoch;
    double deltaTime;
};

void TimeStart(struct Timer* t) {
    t->frameStart = clock();
}

void TimeEnd(struct Timer* t) {
    t->frameEnd = clock();
}

void CalculateDelta(struct Timer* t) {
    t->deltaTime = t->frameEnd - t->frameStart;
}

uint64_t TimeGetEpoch(struct Timer* t) {
    return (uint64_t) t->programEpoch;
}

double TimeGetDelta(struct Timer* t) {
    return t->deltaTime;
}