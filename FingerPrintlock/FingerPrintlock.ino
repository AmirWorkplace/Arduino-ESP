/*************************************************** 
  This is an example sketch for our optical Fingerprint sensor

  Designed specifically to work with the Adafruit BMP085 Breakout 
  ----> http://www.adafruit.com/products/751

  These displays use TTL Serial to communicate, 2 pins are required to 
  interface
  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/
 
 /********************************************************
 This program was modified by pelegren of bedRoonics Labs.
 Hacking is welcomed. Feel free to visit my site for more.
 http://www.instructables.com/member/pelegren/ 
 follow me in twitter:
 https://twitter.com/bedroonicslabs 
 ********************************************************/


#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>
#include<stdint.h>

int getFingerprintIDez();

//DECLARE PIN CONNECTIONS
int pinRelay =12;
int pinFPS = 8;

// DECLARE COUNTER
int count = 0;

// pin #2 is IN from sensor (GREEN wire)
// pin #3 is OUT from arduino  (WHITE wire)
SoftwareSerial mySerial(2, 3);


Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup()  
{
  Serial.begin(9600);
  Serial.println("fingertest");
  
  // SET PIN AS OUTPUT
  pinMode(pinRelay, OUTPUT);
  pinMode(pinFPS, OUTPUT);
  
  //ACTIVATE THE FPS TRANSISTOR
  digitalWrite(pinFPS,HIGH);

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1);
  }
  Serial.println("Waiting for valid finger...");
}

void loop()                     // run over and over again
{
  getFingerprintIDez();
  delay(50);            //FPS internal LED blink speed
  
  
  // use serial to display the information of the counter setup
  Serial.print("Awake for ");
  Serial.print(count);
  Serial.println("sec");
  count++;
  delay(1000);                           // waits for a second
  
    // read the serial data and start count function
  if (Serial.available()) {
    int serialData = Serial.read(); // declare 
    if (serialData == 'Serial') //takes the value from serial
    {
      Serial.println("Serial: No finger detected"); // the count trigger message
      delay(100);     // this delay is required to avoid serial message error
      count = 0;
    }
  }
 
  // check to confirm sleep 
  if (count >= 10) {
      Serial.println("FPS in Sleep Mode");
      delay(100);     // this delay is required to avoid serial message error
      count = 0;
      digitalWrite(pinFPS,LOW);  
  }
  
}

uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!"); 
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); 
  Serial.print(finger.fingerID); 
  
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence); 
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); 
  //SET RELAY TO HIGH TO ACTIVATE
  digitalWrite(pinRelay, HIGH);
  delay(2000);
  digitalWrite(pinRelay,LOW);
  Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); 
  Serial.println(finger.confidence);
  return finger.fingerID; 
 
}
