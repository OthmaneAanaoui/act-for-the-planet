#include "header/IntervalManager.h"

IntervalManager::IntervalManager(){
    milliSeconds = 1000;
}

void IntervalManager::setInterval(long _milliSeconds) {
    milliSeconds = _milliSeconds;
}

long IntervalManager::getInterval() {
    return milliSeconds;
}