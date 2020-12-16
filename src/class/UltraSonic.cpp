#include "./header/UltraSonic.h"

UltraSonic::UltraSonic() {}

void UltraSonic::setTriggerPin(byte trigger) {
    this->trigger = trigger;
}

void UltraSonic::setEchoPin(byte echo) {
    this->echo = echo;
}

byte UltraSonic::getTriggerPin(){
    return trigger;
}

byte UltraSonic::getEchoPin(){
    return echo;
}

void UltraSonic::init(byte trigger, byte echo){
    this->trigger = trigger;
    this->echo = echo;
    /* Initialise les broches */
    pinMode(trigger, OUTPUT);
    digitalWrite(trigger, LOW); // La broche TRIGGER doit être à LOW au repos
    pinMode(echo, INPUT);
}

float UltraSonic::getDistance(){
    /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);

    /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
    long measure = pulseIn(echo, HIGH, MEASURE_TIMEOUT);

    /* 3. Calcul la distance à partir du temps mesuré */
    float distance_cm = (measure / 2.0 * SOUND_SPEED) / 10;

  /* Affiche les résultats en mm, cm et m */
//   Serial.print(F("Distance: "));
//   Serial.print(distance_mm);
//   Serial.print(F("mm ("));
//   Serial.print(distance_mm / 10.0, 2);
//   Serial.print(F("cm, "));
//   Serial.print(distance_mm / 1000.0, 2);
//   Serial.println(F("m)"));
    return distance_cm;
}