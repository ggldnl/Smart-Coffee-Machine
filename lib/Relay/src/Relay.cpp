#include "Relay.h"

Relay::Relay(int _pin) {

    // configure pin
    pin = _pin;
    pinMode(pin, OUTPUT);

    // off on init
    off();
}

boolean Relay::getState() {
    return digitalRead(pin);
}

void Relay::on() {
    digitalWrite(pin, HIGH);
}

void Relay::off() {
    digitalWrite(pin, LOW);
}

void Relay::toggle() {
    digitalWrite(pin, !getState());
}
