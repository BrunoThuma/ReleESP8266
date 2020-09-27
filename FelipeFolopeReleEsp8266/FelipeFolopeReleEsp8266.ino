// Codigo disponivel no blog Felipe Folope sobre introducao a
// utilizacao do modulo ESP8266
uint8_t relayOn[] = {0xA0, 0x01, 0x00, 0xA1};
uint8_t relayOff[] = {0xA0, 0x01, 0x01, 0xA2};
 
void setup() {
 Serial.begin(9600);
}

void loop() {
 Serial.write(relayOn, 4);
 delay(1000);
 Serial.write(relayOff, 4);
 delay(1000);
}
