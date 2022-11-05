/*

blink in line from 8 -> 4 and repeat

JS-1-4
  
*/

// the setup function runs once when you press reset or power the board

void setup() {
  // initialize digital pin 8 as an output.
  
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);

}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(8, HIGH);
  delay(1000); 
  digitalWrite(8, LOW);     
  digitalWrite(7, HIGH);      
  delay(1000);
  digitalWrite(7, LOW);     
  digitalWrite(6, HIGH);      
  delay(1000);
  digitalWrite(6, LOW);     
  digitalWrite(5, HIGH);      
  delay(1000);
  digitalWrite(5, LOW);     
  digitalWrite(4, HIGH);      
  delay(1000);
  digitalWrite(4,LOW);


                  
                
}
