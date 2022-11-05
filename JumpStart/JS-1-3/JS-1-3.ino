/*
  JS-1-3 - alternate blink

*/

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin 8 as an output.
  
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(8, HIGH);     // turn the LED on (HIGH is the voltage level)
  digitalWrite(7, LOW);
  delay(100);                        // wait for a second
  digitalWrite(8, LOW);   // turn the LED off by making the voltage LOW
  digitalWrite(7, HIGH);
  delay(100);                        // wait for a second
}
