//Listing 7-3
//Echo Every character

char data;

void setup()
{
  Serial.begin(9600);
  }

 void loop()
 {
  //Only print when data is received
  if (Serial.available() >0)
  {
    data = Serial.read();
    Serial.print(data);
    }
  }
