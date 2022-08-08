//Simple Serial Printing Test with a Potentiometer
//Listing 7-1

const int POT=0;

void setup()
{
  Serial.begin(9600); // Start serial port with baud = 9600
}

void loop()
{
  int val = analogRead(POT);
  int per = map(val, 0, 1023, 0, 100);
  Serial.print("AnalogReading: ");
  Serial.print(val);
  Serial.print(" percentage: ");
  Serial.print(per);
  Serial.println("%");
  delay (1000);
}
