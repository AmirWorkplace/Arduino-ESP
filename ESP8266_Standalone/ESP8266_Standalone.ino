
#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLSgETUamP"
#define BLYNK_DEVICE_NAME "COLLAGE PROJECT"
#define BLYNK_AUTH_TOKEN "Gq2xJ7uj2RbCqHurMycIC_UOpc1YE3by"
/* Fill-in your Template ID (only if using Blynk.Cloud) */
//#define BLYNK_TEMPLATE_ID   "YourTemplateID"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SYED AMIR ALI";
char pass[] = "@17807594@";


BLYNK_WRITE(V0){
  int pinData1 = param.asInt();
  digitalWrite(4, pinData1);
}

BLYNK_WRITE(V1){
  int pinData2 = param.asInt();
  digitalWrite(2, pinData2);
}

BLYNK_WRITE(V2){
  int pinData3 = param.asInt();
  digitalWrite(12, pinData3);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
