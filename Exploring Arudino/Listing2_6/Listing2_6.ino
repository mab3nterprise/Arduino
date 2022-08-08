const int BLED = 9;
const int GLED = 10;
const int RLED = 11;
const int BUTTON =2;

boolean lastButton = LOW;
boolean currentButton = LOW;
int ledMode =0;

void setup()
{
  pinMode ( BLED, OUTPUT);
  pinMode ( GLED, OUTPUT);
  pinMode ( RLED, OUTPUT);
  pinMode ( BUTTON, INPUT);
}

boolean debounce (boolean last)
{
  boolean current = digitalRead(BUTTON);
  if (last != current)
  {
    delay(5);
    current = digitalRead(BUTTON);
  }
  return current;
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
    digitalWrite(RLED, 127);
    digitalWrite(GLED, 255);
    digitalWrite(BLED, 127);
  }
  //TEAL(BLUE + GREEN)
  else if (mode ==5)
  {
    digitalWrite(RLED, 255);
    digitalWrite(GLED, 127);
    digitalWrite(BLED, 127);
  }
  //ORANGE(RED + Green)
  else if (mode ==6)
  {
    digitalWrite(RLED, 127);
    digitalWrite(GLED, 127);
    digitalWrite(BLED, 255);
  }
  //WHITE(RED + BLUE + GREEN)
  else if (mode == 7)
  {
    digitalWrite(RLED, 170);
    digitalWrite(GLED, 170);
    digitalWrite(BLED, 170);
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
  currentButton = debounce(lastButton);
  if (lastButton = LOW && currentButton ==HIGH)
  {
    ledMode++;
  }
  lastButton = currentButton;
  
  if (ledMode ==8) ledMode =0;
  setMode(ledMode);
}
