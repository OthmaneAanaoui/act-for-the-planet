#include <Arduino.h>
#include "header/UltraSonic.h"

UltraSonic sonic1 = UltraSonic();

int inputPin = 6;
int pirState = LOW;
int val = 0;

void setup()
{
  /* Initialise le port série */
  Serial.begin(9600);
  sonic1.init(13, 12);
      pinMode(inputPin, INPUT);

}

void loop()
{
  Serial.print(F("Distance: "));
  Serial.println(sonic1.getDistance());


    val = digitalRead(inputPin);
    if (val == HIGH)
    {
        if (pirState == LOW) {
            Serial.println("Motion detected!");
            pirState = HIGH;
        }
    }
    else {
        if (pirState == HIGH)
        {
            Serial.println("Motion ended!");
            pirState = LOW;
        }
    }



  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(1000);
}

