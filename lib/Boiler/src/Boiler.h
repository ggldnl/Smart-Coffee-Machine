#ifndef Boiler_h
#define Boiler_h

#include <Relay.h>

enum class Temperature {
  Cold,
  Boiling,  // first thermistor triggered, about 110 deg
  Steam     // second thermistor triggered, about 125 deg
};

class Boiler : private Relay {

    private:

        int isBoilingPin;
        int isSteamPin;
        Temperature targetTemp = Temperature::Cold;

    public:

        Boiler(int, int, int);

        // getters
        boolean getState();
        Temperature getTemp();
        Temperature getTargetTemp();

        // setters
        void setTargetTemp(Temperature);

        // processors
        void work();

};

#endif