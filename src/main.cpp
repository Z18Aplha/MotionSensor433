#include <Arduino.h>
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

// PINs
int pir_sensor = 2;   //interrupt pin 2

//433MHz codes
unsigned long motion_code = 13100;
unsigned long reset_code = 13200;

//void declaration
void motion_detected();
void motion_reset();

void setup() {
  Serial.begin(9600);
  Serial.println("setup begin");
  pinMode(pir_sensor, INPUT);
  mySwitch.enableTransmit(3);
  attachInterrupt(digitalPinToInterrupt(2), motion_detected, RISING);
  attachInterrupt(digitalPinToInterrupt(2), motion_reset, FALLING);


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

void motion_reset() {
  mySwitch.send(reset_code, 24)
}
