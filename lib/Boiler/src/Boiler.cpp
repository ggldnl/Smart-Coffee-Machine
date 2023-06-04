#include <Boiler.h>

Boiler::Boiler(int _relayPin, int _isBoilingPin, int _isSteamPin) : Relay(_relayPin) {

    // configure thermistor pins
    isBoilingPin = _isBoilingPin;
    isSteamPin = _isSteamPin;

    pinMode(isBoilingPin, INPUT_PULLUP);
    pinMode(isSteamPin, INPUT_PULLUP);
}

boolean Boiler::getState() {
    return Relay::getState();
}

Temperature Boiler::getTemp() {

    // the steam check goes first because the temp is hotter than when boiling
    if (digitalRead(isSteamPin)) {
        return Temperature::Steam;
    }

    if (digitalRead(isBoilingPin)) {
        return Temperature::Boiling;
    }

    return Temperature::Cold;
}

Temperature Boiler::getTargetTemp() {
    return targetTemp;
}

void Boiler::setTargetTemp(Temperature _targetTemp) {
    targetTemp = _targetTemp;
}

void Boiler::work() {

    Temperature temp = getTemp(),
               targetTemp = getTargetTemp();

    // switch relay off if the target temp is achieved
    if (targetTemp == Temperature::Cold || temp == targetTemp || (temp == Temperature::Steam && targetTemp == Temperature::Boiling))
        off();
    else
        on();
}
