#ifndef Pump_h
#define Pump_h

#include <Relay.h>

#include "Arduino.h"

class Pump: private Relay {

    private:

      int pin;

    public:

      Pump(int);

      // commands
      void on();
      void off();
      void toggle();

};

#endif