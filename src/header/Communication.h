#ifndef COMMUNICATION
#define COMMUNICATION
#include <Arduino.h>

class Communication {

    public:
        Communication();
        void init(int baud);
        void sendData(String msg);
        String readSerialPort();
};

#endif