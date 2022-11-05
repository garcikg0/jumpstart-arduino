/*
 * js-2-1
 * 
 * functions and setting LED's via binary strings
 * 

 */

int pins[8] = {11,10,9,8,7,6,5,4};



void pattern(int number) {

int bits = 128;


for (int i=0; i<8; i++) {
  Serial.print("Setting pin:");
  Serial.print(pins[i]);
  
  if (bits & number) {    
                          Serial.println(" HIGH");
                       // digitalWrite(pins[i],HIGH);
  }
  else {
            Serial.println(" LOW");
         // digitalWrite(pins[i],LOW);
  }
  
  bits = bits >>1;
  
}

}


void setup() {

Serial.begin(9600);
delay(2000);

  int leds[] = 
{
B00010000,
B00001000,
B00000100,
B00000010,
B00000001
};


  pattern( leds[0] );
  
}
   

void loop() {


  
}
