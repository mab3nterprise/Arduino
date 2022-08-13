#include <Servo.h>

const int SERVO = 9;
const int IR = 0;

const int LED1 = 3;
const int LED2 = 5;
const int LED3 = 6;
const int LED4 = 11;

Servo myServo; //Servo Object
int dist1 = 0; //Quadrant 1 Distance
int dist2 = 0; //Quadrant 2 Distance
int dist3 = 0; //Quadrant 3 Distance
int dist4 = 0; //Quadrant 4 Distance

void setup() {
  myServo.attach(SERVO);
  pinMode(LED1, OUTPUT);  //Set LED to Output
  pinMode(LED2, OUTPUT);  //Set LED to Output
  pinMode(LED3, OUTPUT);  //Set LED to Output
  pinMode(LED4, OUTPUT);  //Set LED to Output
}

void loop() 
{
  //Sweep the Servo into 4 regions and cahnge the LEDs
  dist1 = readDistance (15); //MeasureIRDistance at 15degrees
  analogWrite(LED1, dist1);   //Adjust LED Brightness
  delay(300);                 //Delay before next measurement

  dist2 = readDistance (65); //MeasureIRDistance at 65degrees
  analogWrite(LED2, dist2);   //Adjust LED Brightness
  delay(300);                 //Delay before next measurement

  dist3 = readDistance (115); //MeasureIRDistance at 115degrees
  analogWrite(LED3, dist3);   //Adjust LED Brightness
  delay(300);                 //Delay before next measurement

  dist4 = readDistance (165); //MeasureIRDistance at 165degrees
  analogWrite(LED4, dist4);   //Adjust LED Brightness
  delay(300);                 //Delay before next measurement
}

int readDistance(int pos)
{
  myServo.write(pos);
  delay(600);
  int dist = analogRead(IR);
  dist = map(dist, 50, 500, 0,255);
  dist = constrain(dist, 0, 255);
  return dist;
  }
