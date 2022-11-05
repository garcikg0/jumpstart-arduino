/*
  JS-4-5
*/



void setup() {
  //Initialize serial and wait for port to open:
  
  Serial.begin(9600);
  
  while (!Serial) {
    ; // wait for serial port to connect. 
  }

  
}

void loop() {
  
  
static char input[15];
char c;
int i,mapped;
float value;

i = 0;


if (Serial.available()) {

Serial.println(value);

  while (Serial.available()) {
    c = (char)Serial.read();
    if ( c != '\n' && i < 15 )
        {
          input[i] = c;
          i++;
        }
}
        input[i] = '\0';
        
        value = atof(input);
        mapped = map(value,62,80,1,11);

        Serial.print("The original value of: ");
        Serial.print(value);
        Serial.print(" will be mapped to: ");
        Serial.println(mapped);
        Serial.println("------------------------");
        
}



        
        
  
}
