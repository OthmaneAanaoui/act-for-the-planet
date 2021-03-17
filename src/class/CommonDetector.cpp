#include "header/CommonDetector.h"

CommonDetector::CommonDetector(){}

void CommonDetector::init(byte inputPin){
    this->inputPin = inputPin;
    pinMode(inputPin, INPUT);
    this->pirState = LOW;
    this->state = PresenceState::betweenDetecting;
}

PresenceState CommonDetector::getIsDetect(){
    int val = digitalRead(this->inputPin);
    this->state = PresenceState::betweenDetecting;
    if (val == HIGH)
    {
        if (pirState == LOW) {
            // mouvement détecter
            state = PresenceState::startDetecting;
            pirState = HIGH;
        }
    }
    else {
        if (pirState == HIGH)
        {
            // fin de détection
            state = PresenceState::endDetecting;
            pirState = LOW;
        }
    }
    return state;
}