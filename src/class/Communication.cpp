#include "header/Communication.h"

Communication::Communication() {}

void Communication::init(int baud) {
    Serial.begin(baud);
}

void Communication::sendData(String msg) {
    Serial.print(msg);
}

String Communication::readSerialPort() {
    String msg = "";
    if(Serial.available()){
        delay(10);
        while(Serial.available() > 0) {
            msg += (char)Serial.read();
        }
        Serial.flush();
    }
    return msg;
}