//Sending Multiple Variables at Once
//Send data in this format: <0-100>,<0-100>,<0,100>\n
//Where the three numbers represent precentage brightness of R, G, B. 

//Define LED Pins
const int RED =11;
const int GREEN =10;
const int BLUE =9;


void setup() 
{
Serial.begin(9600);
Serial.setTimeout(10);

//Set pins as outputs
  pinMode(RED, OUTPUT);`
pinMode(BLUE, OUTPUT);

//Turn off the LED
//It is common-anode, so setting the cathode pins to HIGH turns the LED off
digitalWrite(RED, HIGH);
digitalWrite(GREEN, HIGH);
digitalWrite(BLUE, HIGH);
}


void loop() 
{
  //Read data when it's available in the buffer
  if (Serial.available() >0)
  {
    //Expect to receive 3 intergers over serial
    //parseINT will "block" until a valid intger is recived
    //parseInt knows full integer was recived one a comma or newline is seen
    //parseInt only removes invalid characters before the found int, not after
    int val1 = Serial.parseInt();
    int val2 = Serial.parseInt();
    int val3 = Serial.parseInt();
    
    //Throw out anything that remains in the buffer after integers are read
    while (Serial. available())
    {
      Serial.read();
     }

    //Constrain the recived values to be only from 0 to 100%
    int val1c = constrain(val1,0,100);
    int val2c = constrain(val2,0,100);
    int val3c = constrain(val3,0,100);

    //Map the values from percentages to analog values
    int rval = map(val1c,0,100,255,0);   //first valid integer
    int gval = map(val2c,0,100,255,0);   //second valid integer
    int bval = map(val3c,0,100,255,0);   //third valid integer

    //set LED brightness
    analogWrite(RED, rval);
    analogWrite(GREEN, gval);
    analogWrite(BLUE, bval);

    //Report Values that were used to set the LED
    Serial.println("Red:  " + String(val1c) + "%");
    Serial.println("Green:  " + String(val2c) + "%");
    Serial.println("Blue:  " + String(val3c) + "%\n");
    
   }
}
