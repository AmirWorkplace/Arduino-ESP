
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLSgETUamP"
#define BLYNK_DEVICE_NAME "COLLAGE PROJECT"
#define BLYNK_AUTH_TOKEN "Gq2xJ7uj2RbCqHurMycIC_UOpc1YE3by"
/* Fill-in your Template ID (only if using Blynk.Cloud) */


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

int digitalPin_1 = 2;
int digitalPin_2 = 4;
int digitalPin_3 = 7;
int digitalPin_4 = 8;
int digitalPin_5 = 9;
int digitalPin_6 = 10;
int digitalPin_7 = 12;
int digitalPin_8 = 13;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "SYED AMIR ALI";
char pass[] = "@17807594@";


BLYNK_WRITE(V0){
  digitalWrite(digitalPin_1, param.asInt());
 }

BLYNK_WRITE(V1){
  digitalWrite(digitalPin_2, param.asInt());
 }

BLYNK_WRITE(V2){
  digitalWrite(digitalPin_3, param.asInt());
 }

BLYNK_WRITE(V3){
  digitalWrite(digitalPin_4, param.asInt());
 }

BLYNK_WRITE(V4){
  digitalWrite(digitalPin_5, param.asInt());
 }

BLYNK_WRITE(V5){
  digitalWrite(digitalPin_6, param.asInt());
 }

BLYNK_WRITE(V6){
  digitalWrite(digitalPin_7, param.asInt());
 }

BLYNK_WRITE(V7){
  digitalWrite(digitalPin_8, param.asInt());
 }


void setup()
{
  Serial.begin(115200);

  declearPin(digitalPin_1);
  declearPin(digitalPin_2);
  declearPin(digitalPin_3);
  declearPin(digitalPin_4);
  declearPin(digitalPin_5);
  declearPin(digitalPin_6);
  declearPin(digitalPin_7);
  declearPin(digitalPin_8);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  offAll(digitalPin_1);
  offAll(digitalPin_2);
  offAll(digitalPin_3);
  offAll(digitalPin_4);
  offAll(digitalPin_5);
  offAll(digitalPin_6);
  offAll(digitalPin_7);
  offAll(digitalPin_8);
  Blynk.run();
}

void declearPin(int ledPin){
  pinMode(ledPin, OUTPUT);
}

void offAll(int ledPin){
  digitalWrite(ledPin, LOW);
}
