

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

int light;
long reading;

light = analogRead(A2);


reading = map(light,
0,400,1,10);
Serial.println(reading);
delay(100);


}
