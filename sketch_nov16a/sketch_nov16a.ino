#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "Gq2xJ7uj2RbCqHurMycIC_UOpc1YE3by" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SYED AMIR ALI";
char pass[] = "@17807594@";

//Get the button value
BLYNK_WRITE(V0) {
  digitalWrite(4, param.asInt());
}

void setup() {
  //Set the LED pin as an output pin
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop() {
  //Run the Blynk library
  Blynk.run();
}
