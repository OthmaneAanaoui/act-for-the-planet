#include <Arduino.h>

#ifndef PRESENCE_ENUM
#define PRESENCE_ENUM
    enum PresenceState {
        startDetecting,
        endDetecting,
        betweenDetecting
    };
#endif
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