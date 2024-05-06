// Codigo para arduino
/*
Usado em conjunto com o codigo UDP_ServerESP8266.ino
este arquivo mostra no promt serial do computador conectado
ao arduino a mensagem recebida pelo ESP8266 que é recebida 
pelo arduino por serial
*/
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); //RX, TX

// for reference use https://www.youtube.com/watch?v=ji71cHaGW8w&t=379s

String IncomingString="";
boolean strReady = false;

void setup() {
  Serial.begin(9600);
  mySerial.begin(115200);
  delay(5000);
}

void loop() {

  IncomingString="";
  strReady = false;

  while (mySerial.available()){
    IncomingString = mySerial.readString();
    strReady = true;
  }
  if (strReady){
    Serial.println("Received: " + IncomingString);   
  }

}
