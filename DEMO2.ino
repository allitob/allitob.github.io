// PWM #################################################
const int fan_control_pin = 9;
int count = 0;
unsigned long start_time;
int rpm;
// #####################################################

//RELAY ################################################
int relayPin = 3;// define pin for relay
// #####################################################

//SHT31 ################################################
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_SHT31.h"

Adafruit_SHT31 sht31 = Adafruit_SHT31();
byte degree[8] =
{
0b00011,
0b00011,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000,
0b00000
};
// ######################################################

// ULTRA_SONIC ##########################################
const int Anode = 11;
const int Echo = 13;
const int Trigger = 12;

float distance;
unsigned long duration;
// ######################################################

void setup() {

// PWM ##################################################
  pinMode(fan_control_pin, OUTPUT);
  analogWrite(fan_control_pin, 0);
  Serial.begin(9600);
// ######################################################

//RELAY #################################################
  // Robojax.com relay tutorial 20181012
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);// initialize serial monitor
  Serial.println("Robojax.com Relay Module");
  // digitalWrite(relayPin, LOW);// turn relay ON
  delay(2000);// wait for boot
// ######################################################

//SHT31 #################################################
  while (!Serial)
  delay(10); // will pause Zero, Leonardo, etc until serial console opens
 
  Serial.println("SHT31 test");
  if (! sht31.begin(0x44)) { // Set to 0x45 for alternate i2c addr
  Serial.println("Couldn't find SHT31");
  while (1) delay(1);
}
// ######################################################

//ULTRA_SONIC ###########################################
  pinMode(Anode, OUTPUT);
  digitalWrite(Anode, HIGH);
  
  pinMode(Trigger, OUTPUT);
  digitalWrite(Trigger, LOW);
  
  pinMode(Echo, INPUT);
//#######################################################

}

void loop() {
 
  for(int i=0;i<300;i++) {

    digitalWrite(Trigger, HIGH);
    delayMicroseconds (50);
    digitalWrite(Trigger, LOW);

    duration = pulseIn(Echo, HIGH);
    distance = duration / 58.0;
    if(distance > 17) {
      Serial.println("Fylla þarf vatnið!");
    }
    
    float h = sht31.readHumidity();
    
    if(int(h)<40) {
      Serial.print(i);
      Serial.print(": ");
      Serial.print("raki er(%): ");
      Serial.println(h);
      digitalWrite(relayPin, HIGH);

      Serial.print ("     vatnstankur: ");
      Serial.println (distance,1);
    }
    else {
      Serial.print(i);
      Serial.print(": ");
      Serial.print("raki er(%): ");
      Serial.println(h);
      digitalWrite(relayPin, LOW);

      Serial.print ("     vatnstankur: ");
      Serial.println (distance,1);
    }
    delay(1000);
    Serial.println();
    }

    //viftukeyrsla
    Serial.print("Loftræsting í 30 sek");
    analogWrite(fan_control_pin, 255);
    delay(30000);
    analogWrite(fan_control_pin, 0);
    Serial.println();
}
