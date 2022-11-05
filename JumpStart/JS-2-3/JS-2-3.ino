/*
 * js-2-3 - set time delay for blink 
 */

int pin=8;
int time_delay=50;

void setup() {
  Serial.begin(9600);
  delay(2000);
  pinMode(pin, OUTPUT); 
  Serial.print("Current time delay is set to: ");
  Serial.println(time_delay);
  Serial.println("---------------------");
  Serial.println("Enter a new delay value");
}

void loop() {

String command;


digitalWrite(pin,HIGH);
delay(time_delay);

  if(Serial.available()) 
  {
    command = Serial.readStringUntil('\n'); 
    time_delay = command.toInt();
    Serial.print("New delay is: ");
    Serial.println(time_delay);
  }
digitalWrite(pin,LOW);
delay(time_delay);
}
