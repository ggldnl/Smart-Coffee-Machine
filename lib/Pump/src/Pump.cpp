#include <Pump.h>
#include <Relay.h>

Pump::Pump(int _pin): Relay(_pin) {
    // nothing to do here
}

void Pump::on() {
    Relay::on();    
}

void Pump::off() {
    Relay::off();
}

void Pump::toggle() {
    Relay::toggle();
}
