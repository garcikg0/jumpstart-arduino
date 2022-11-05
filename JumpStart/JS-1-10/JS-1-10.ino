/*

Alternate blink 

JS-1-3
  
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
  delay(100); 
  digitalWrite(8, LOW);     
  digitalWrite(7, HIGH);      
  delay(100);
  digitalWrite(7, LOW);     
  digitalWrite(6, HIGH);      
  delay(100);
  digitalWrite(6, LOW);     
  digitalWrite(5, HIGH);      
  delay(100);
  digitalWrite(5, LOW);     
  digitalWrite(4, HIGH);      
  delay(100);

  digitalWrite(5, HIGH);     
  digitalWrite(4, LOW);      
  delay(100);
  digitalWrite(6, HIGH);     
  digitalWrite(5, LOW);      
  delay(100);
  digitalWrite(7, HIGH);     
  digitalWrite(6, LOW);      
  delay(100);
 
  digitalWrite(7, LOW);      
  delay(100);
 
              
}
