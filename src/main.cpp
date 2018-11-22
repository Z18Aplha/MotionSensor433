#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// PINs
int pir_sensor = 2;   //interrupt pin 2

//433MHz codes
int motion_code = 13100;

//void declaration
void motion_detected();

void setup() {
  Serial.begin(9600);
  Serial.println("setup begin");
  pinMode(pir_sensor, INPUT);
  mySwitch.enableTransmit(3);
  attachInterrupt(digitalPinToInterrupt(2), motion_detected, RISING);


  Serial.println("setup finished");
}

void loop() {
  //nothing - just waiting for interrupt
  //add powersafing routine, bare model (atmega328) --> able to get power from a battery 
}

void motion_detected(){
  mySwitch.send(motion_code, 24);
  Serial.println("motion detected");
}
