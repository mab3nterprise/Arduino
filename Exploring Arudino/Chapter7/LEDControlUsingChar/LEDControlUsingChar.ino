//Listing 7-4
//Single Character COntrol of an LED

const int LED = 9;

char data;

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop()
{
  if (Serial.available() > 0)
  {
    data = Serial.read();
    //Turn LED ON
    if (data == '1')
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }
    //Turn LED OFF
    else if (data == '0')
    {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
  
}
