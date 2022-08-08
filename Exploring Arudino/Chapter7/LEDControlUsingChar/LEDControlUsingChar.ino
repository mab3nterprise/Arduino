



















//Listing 7-4
//Single Character COntrol of an LED

const int LED=10;

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
    Serial.print(data, DEC);
    
    //Turn LED ON
    if (data >0)
    {
      //Serial.print(data);
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }
    //Turn LED OFF.
    else if (data == "10")
    {
      //Serial.print(data);
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }
  }
  
}
