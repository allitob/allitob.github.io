#include <NewPing.h>
NewPing sonar(10,11,20); // Sidasta talan er max fjarlaegd sem skynjarinn maelir (cm)

void setup() {

Serial.begin(9600);
delay(50);

}

void loop() {

  Serial.print("The Distance is: ");
  Serial.println(sonar.ping_cm());
  delay(250);

}
