#include <Arduino.h>

class UltraSonic {

private:
    byte trigger;
    byte echo;

public:
    /* Constantes pour le timeout */
    static const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s
    /* Vitesse du son dans l'air en mm/us */
    static constexpr float SOUND_SPEED = (340.0 / 1000.0); 

     UltraSonic();
     byte getTriggerPin();
     byte getEchoPin();
     void setTriggerPin(byte pin);
     void setEchoPin(byte pin);
     void init(byte trigger, byte echo);
     float getDistance();
};