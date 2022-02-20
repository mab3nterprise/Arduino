const int POT = 0;
const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
int val = 0;
int ledMode =0;

const int LOWER_BOUND= 0;
const int UPPER_BOUND = 1023;

void setup()
{
  Serial.begin(9600);
  pinMode(RLED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(GLED, OUTPUT);
  pinMode(POT, INPUT);
}

void setMode(int mode)
{
  //RED
  if (mode ==1)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
  //GREEN
  else if (mode ==2)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, HIGH);
  }
  //BLUE
  else if (mode ==3)
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, LOW);
  }
  //PURPLE(RED + BLUE)
  else if (mode ==4)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, 255);
    digitalWrite(BLED, LOW);
  }
  //TEAL(BLUE + GREEN)
  else if (mode ==5)
  {
    digitalWrite(RLED, 255);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  //ORANGE(RED + Green)
  else if (mode ==6)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, 255);
  }
  //WHITE(RED + BLUE + GREEN)
  else if (mode == 7)
  {
    digitalWrite(RLED, LOW);
    digitalWrite(GLED, LOW);
    digitalWrite(BLED, LOW);
  }
  //OFF (mode =0)
  else
  {
    digitalWrite(RLED, HIGH);
    digitalWrite(GLED, HIGH);
    digitalWrite(BLED, HIGH);
  }
}

void loop()
{
  val = analogRead(POT);
  val = map(val, LOWER_BOUND, UPPER_BOUND, 7, 0);
  //val = constrain(val, 0, 8);  
  setMode(val);
  Serial.println(val);
  delay(500);
}
