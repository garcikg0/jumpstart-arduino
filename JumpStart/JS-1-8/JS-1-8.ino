/*
 * js-1-8
 * 
 * functions for setting LED's via binary strings
 * 
 */

int pins[8] = {11,10,9,8,7,6,5,4};



void pattern(int number) {

int bits = 128;


for (int i=0; i<8; i++) {
    
  if (bits & number) {    
                       digitalWrite(pins[i],HIGH);
  }
  else {
         digitalWrite(pins[i],LOW);
  }
  
  bits = bits >>1;
  
}

}


void setup() {


for (int i=0; i<8;i++) {
  pinMode(pins[i],OUTPUT);
  
}


}
  
  

void loop() {

  int leds[] = 
{
B00010000,
B00001000,
B00000100,
B00000010,
B00000001
};

for (int j=0; j< sizeof(leds)/sizeof(int); j++) {
  pattern( leds[j] );
  delay(100);
}

}
