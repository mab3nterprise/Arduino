//Make a light rider animation

const int SER = 8;
const int LATCH = 9;
const int CLK = 10;

//Seqence of LEDs
int seq[14] = {1, 2, 4, 8, 16, 32, 64, 128, 64, 32, 16, 8, 4, 2};

void setup()
{
  //Set pins as outputs
  pinMode(SER, OUTPUT);
  pinMode(LATCH, OUTPUT);
  pinMode(CLK, OUTPUT);

}

void loop() {
  for (int i = 0; i < 14; i++)
  {
    digitalWrite(LATCH, LOW);
    shiftOut(SER, CLK, MSBFIRST, seq[i]);
    digitalWrite(LATCH, HIGH);
    delay(100);
  }
}
