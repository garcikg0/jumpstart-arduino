int lowest=1024;
int highest = 0;

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
delay(2000);

}

void loop() {
  // put your main code here, to run repeatedly:
int x;

x = analogRead(A1);
delay(100);
if (x>highest){
  highest = x;
}

if (x<lowest) {
  lowest = x;
}
Serial.print("High value: ");
Serial.print(highest);
Serial.print(" -- Low value: ");
Serial.print(lowest);
Serial.print(" Reported Value: ");
Serial.println(x);


}
