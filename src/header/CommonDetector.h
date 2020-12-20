#ifndef COMMON_DETECTOR
#define COMMON_DETECTOR

#include <Arduino.h>

enum PresenceState {
    startDetecting,
    endDetecting,
    betweenDetecting
};

class CommonDetector {
    protected:
        int inputPin;
        int pirState;
        PresenceState state;
    public:
        CommonDetector();
        void init(byte inputPin);
        PresenceState getIsDetect();
};

#endif