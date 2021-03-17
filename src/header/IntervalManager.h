#ifndef INTERVAL_MANAGER
#define INTERVAL_MANAGER

#include "Time.h"

class IntervalManager {
    private:
        long milliSeconds;
    public:
        IntervalManager();
        void setInterval(long _milliSeconds);
        long getInterval();
};

#endif