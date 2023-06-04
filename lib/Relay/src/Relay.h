#ifndef Relay_h
#define Relay_h

#include "Arduino.h"

class Relay {

    private:

        int pin;

    public:

        Relay(int);

        // getters
        boolean getState();

        // commands
        void on();
        void off();
        void toggle();

};

#endif