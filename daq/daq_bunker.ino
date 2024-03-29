#include <SoftwareSerial.h>
#define RO_PIN 2
#define DI_PIN 3
#define DE_RE_PIN 4
SoftwareSerial rs485Serial(RO_PIN, DI_PIN); // RO_PIN for Receive, DI_PIN for Transmit
void setup() {
    pinMode(DE_RE_PIN, OUTPUT);
    digitalWrite(DE_RE_PIN, LOW); // MINI DAQ MUST BE LOW TO RECEIVE
    Serial.begin(9600);
    rs485Serial.begin(9600);
}
void loop() {
if (rs485Serial.available())
{ // Receive data from another Arduino and display it on the Serial Monitor
    digitalWrite(DE_RE_PIN, LOW);
    Serial.write(rs485Serial.read());
}
}