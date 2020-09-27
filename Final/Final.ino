
// Codigo final carregado no modulo rele+ESP8266
/* 
Codigo usa como base outros codigos como FelipeFolopeReleEsp8266
e UDP_ServerESP8266 disponiveis no mesmo git

Apos conectar a uma rede espera por uma mensagem por UDP na porta 4210
Ao receber uma mensagem pode responder das seguintes formas:
ON/OFF - Liga ou desliga o rele dependo a msg - retorna msg 'OK'
REG - Usado para termos o primeiro contato com o modulo - retorno msg 'REG'
CON - A ser implementado - retornara estado atual do rele 'ON' ou 'OFF'
Msg recebida n reconhecida como comando interno - retorna msg '404'
*/
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const uint8_t relayOff[] = {0xA0, 0x01, 0x00, 0xA1};
const uint8_t relayOn[] = {0xA0, 0x01, 0x01, 0xA2};

const char* ssid = "";
const char* password = "";

WiFiUDP Udp;
unsigned int localUdpPort = 4210;  // local port to listen on
char incomingPacket[255];  // buffer for incoming packets
const char replyOk[] = "OK";  // a reply string to send back
const char replyReg[] = "REG";  // a reply string to send back
const char reply404[] = "404";  // a reply string to send back

void setup(){
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
  }
  Udp.begin(localUdpPort);
}

void loop(){
  int packetSize = Udp.parsePacket();
  if (packetSize){
    int len = Udp.read(incomingPacket, 255);
    if (len > 0){
      incomingPacket[len] = 0;
    }
    if (String("ONOFF").indexOf(String(incomingPacket)) > 0){
      if (String(incomingPacket) == "On") Serial.write(relayOn, 4);
      else if (String(incomingPacket) == "Off") Serial.write(relayOff, 4);
        // send back a reply, to the IP address and port we got the packet from
        Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
        Udp.write(replyOk);
        Udp.endPacket();
    }
    else if (String("REG").indexOf(String(incomingPacket)) > 0) {
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(replyReg);
      Udp.endPacket();
    }
    else if (String("CON").indexOf(String(incomingPacket)) > 0) {
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(replyReg);
      Udp.endPacket();
    }
    else {
      Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
      Udp.write(reply404);
      Udp.endPacket();
    }
  }
}
