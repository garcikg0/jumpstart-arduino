/*

Sequential LED Blink

JS-1-6
  
*/

int pins[] = {8,7,6,5,4};


// the setup function runs once when you press reset or power the board

void setup() {

int i;

  for (i=4; i<9; ++i) {
     pinMode(i,OUTPUT);
  }
  

}

// the loop function runs over and over again forever
void loop() {
  
  
  for (int j=0; j<5; ++j) {

  digitalWrite( pins[j], HIGH);
  delay(100);
  digitalWrite(pins[j], LOW);
  
  }
  
}
 
