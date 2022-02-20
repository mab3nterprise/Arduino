const int POT= 0;
const int MC1 = 2;
const int MC2 = 4;
const int EN = 9;

int val = 0;
int velocity =0;

void setup()
{
 pinMode(MC1, OUTPUT);
 pinMode(MC2, OUTPUT);
 pinMode(EN, OUTPUT);
 pinMode(POT, INPUT);
 brake();
}

//Motor goes forward at given rate (0-255)
void forward (int rate)
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, HIGH);
  digitalWrite(MC2, LOW);
  digitalWrite(EN, rate);
}

//Motor goes backward at given rate (from 0-255)
void reverse (int rate)
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, HIGH);
  digitalWrite(EN, rate);
}

//Stops motor
void brake()
{
  digitalWrite(EN, LOW);
  digitalWrite(MC1, LOW);
  digitalWrite(MC2, LOW);
  digitalWrite(EN, HIGH);
}

void loop()
{
  val = analogRead(POT);
  
  //go forward
  if (val >562)
  {
   velocity = map(val, 562, 1023, 0, 255);
   forward(velocity);
  }
  
  else if (val <462)
  {
   velocity = map(val, 461, 0, 0, 255);
   reverse(velocity);
  }
  else
  {
    brake();
  }
}
