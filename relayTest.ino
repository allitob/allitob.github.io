
 // This sketch is part of Video Tutorial showing how to control a 5V relay
 // please watch the video at this URL: https://youtu.be/N-fFk51Eb8s
 // Written by Ahmad Shamshiri for Robojax.com video on October 12, 2018 at 21:19 in Ajax, Ontario 
 // Introduction to 5V relay.
int relayPin = 3;// define pin for relay

void setup() {
  // Robojax.com relay tutorial 20181012
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);// initialize serial monitor
  Serial.println("Robojax.com Relay Module");
  digitalWrite(relayPin, HIGH);// turn relay ON
  delay(2000);// wait for boot
}

void loop() {
  // Robojax.com relay tutorial 20181012
  digitalWrite(relayPin, HIGH);// turn relay ON
    Serial.println("Relay ON");
  delay(5000);// wait for 5 seconds
   
  
  digitalWrite(relayPin, LOW);// turn relay OFF
       Serial.println("Relay OFF");
  delay(3000);// wait for 3 secons
}
