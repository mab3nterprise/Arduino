// A bar graph that responds to how close you are

const int SER =8;
const int LATCH =9;
const int CLK = 10;
const int DIST =0;

//Possible LED settings
int vals[9] = {0,1,3,7,25,31,63,127,255}; 

//Maximum value provided by sensor
int maxVal = 500;

//Minimum value provided by sensor
int minVal = 0;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);
}

void loop() {
  int distance = analogRead(DIST);
  distance = map(distance, minVal, maxVal, 0, 8);
  distance = constrain(distance,0,8);

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLK, MSBFIRST, vals[distance]);
  digitalWrite(LATCH,HIGH);
  delay(10);

}
