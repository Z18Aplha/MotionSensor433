#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Debug-Test");
  delay(1000);
  Serial.println("Done");
  delay(1000);

  Serial.println("This is for you, GitHub :D");

}
