#include <Arduino.h>
#include "header/UltraSonic.h"
#include "header/Presence.h"
#include "header/InfraRed.h"
#include "header/Communication.h"
#include "header/IntervalManager.h"

UltraSonic sonic1 = UltraSonic();
// UltraSonic sonic2 = UltraSonic();
// UltraSonic sonic3 = UltraSonic();

Presence detectPresence = Presence();

InfraRed wasteDetector1 = InfraRed();
// InfraRed wasteDetector2 = InfraRed();
// InfraRed wasteDetector3 = InfraRed();

Communication com = Communication();
IntervalManager timer = IntervalManager();

void setup()
{
  /* Initialise le port série */
  com.init(9600);
  sonic1.init(8, 9);
  // sonic2.init(11,10);
  // sonic3.init(9,8);

  detectPresence.init(2);

  wasteDetector1.init(3);
  // wasteDetector2.init(3);
  // wasteDetector3.init(4);

}

void loop()
{
  // Serial.print(F("Distance détecteur 1 : "));
  // Serial.println(sonic1.getDistance());

  // Serial.print(F("Distance détecteur 2 : "));
  // Serial.println(sonic2.getDistance());

  // if(detectPresence.getIsDetect() == PresenceState::startDetecting) {
  //   Serial.println("Motion detected");
  // }
  //com.readSerialPort();
  // if(wasteDetector1.getIsDetect() == PresenceState::endDetecting) {
  //   delay(1000);
  //   com.sendData((String)sonic1.getDistance());
  // }
  
  //pour test à virer pour l'appli finale
  if(detectPresence.getIsDetect() == PresenceState::endDetecting) {
    delay(1000);
    com.sendData((String)sonic1.getDistance());
  }

  /* Délai d'attente pour éviter d'afficher trop de résultats à la seconde */
  delay(timer.getInterval());
}

