//#include "ESP8266.h"

#include "SoftwareSerial.h"
String readString;
SoftwareSerial espSerial(0, 1);

void setup() {
  Serial.begin(115200);
  espSerial.begin(115200);
  delay(2000);
  //Serial.println("AT"); 
}

//debug dooubts
//Software serial and hw serial
//Check you ESP8266 FW version.
void receive()
{
  static char message[1000];
  int i = 0;
  while(espSerial.available() > 0){
    message[i++] = espSerial.read();
  }
  Serial.print(message);
}
void loop() {
  espSerial.println("AT");
  Serial.println("Sent...!");
  delay(5);
  receive();
  delay(500);
}
