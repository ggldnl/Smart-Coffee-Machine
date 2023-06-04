#include <Relay.h>

#define SERIAL_BAUDRATE 9600

#define RELAY_BOILER      D0
#define RELAY_PUMP        D1

Relay relay(RELAY_BOILER);

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    Serial.print("Relay state: ");
    Serial.println(relay.getState());
}

void loop() {
    relay.toggle();
    Serial.print("Relay state: ");
    Serial.println(relay.getState());
    delay(1000);
}