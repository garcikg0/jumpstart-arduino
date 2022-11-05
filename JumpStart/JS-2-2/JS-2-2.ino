/*
 * js-2-2 - turn LED on/off
 */


int pin=8;

void setup() {
  Serial.begin(9600);
  delay(2000);
  pinMode(pin, OUTPUT); 
  Serial.println("Enter either 'on' or 'off'");
}

void loop() {

String command;

  if(Serial.available()) 
  {
    command = Serial.readStringUntil('\n'); 
    if(command == "on")
    {
      digitalWrite(pin, HIGH); // turn on LED
      Serial.println("LED is turned ON"); 
    }
    else
    if(command == "off")
    {
      digitalWrite(pin, LOW);  // turn off LED
      Serial.println("LED is turned OFF"); 
    }
  }
}
