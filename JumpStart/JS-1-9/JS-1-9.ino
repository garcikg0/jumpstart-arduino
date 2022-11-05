/*
 * js-1-9
 * 
 * functions and setting LED's via binary strings

"fill up pattern"
};
 */

int pins[8] = {11,10,9,8,7,6,5,4};


void setpins( int number ) {
  
int bits = 128;


for (int i=0; i<8; i++) {
    
  if (bits & number) {    
                       pinMode(pins[i],OUTPUT);
  }
  else {
         pinMode(pins[i],INPUT);
  }
  
                        } // end of for loop

}

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

Serial.begin(9600);
delay(2000);

setpins(B11111111);

}
  
  

void loop() {

  int leds[] = 
{
B00010000,
B00001000,
B00000100,
B00000010,
B00000001,
B00001001,
B00000101,
B00000011,
B00000111,
B00001111,
B00011111,

B00011110,
B00011100,
B00011000

};

for (int j=0; j< sizeof(leds)/sizeof(int); j++) {
  pattern( leds[j] );
  delay(100);
}

}
