//H-Bridge Pins
const int RIGHT_EN = 9;
const int RIGHT_MC1 = 2;
const int RIGHT_MC2 = 3; 
const int LEFT_EN = 10;
const int LEFT_MC1 = 4;
const int LEFT_MC2 = 5;

//Light Sensor Pins
const int LEFT_LIGHT_SENSOR =1;
const int RIGHT_LIGHT_SENSOR =0;

//Movement Thresholds and Speeds
const int LIGHT_THRESHOLD_MIN = 450;  // THe min light to read
//cause movement
const int LIGHT_THRESHOLD_MAX = 1100;  //The max light to read
//cause movement
const int SPEED_MIN = 150;  //Min motor speed
const int SPEED_MAX= 255;  //Max motor speed

void setup()
{
  //The H-Bridge Pins are Outputs
  pinMode(RIGHT_EN, OUTPUT);
  pinMode(RIGHT_MC1, OUTPUT);
  pinMode(RIGHT_MC2, OUTPUT);
  pinMode(LEFT_EN, OUTPUT);
  pinMode(LEFT_MC1, OUTPUT);
  pinMode(LEFT_MC2, OUTPUT);
  
  //Initialze with both motors stopped
  brake("left");
  brake("right");
  
  Serial.begin(9600);
  
}

void loop()
{
  //Read Light Sensors
  int left_light = analogRead(LEFT_LIGHT_SENSOR);
  int right_light = analogRead(RIGHT_LIGHT_SENSOR);
  
  delay (50);
  
  Serial.print("Right: ");
  Serial.print(right_light);
  Serial.print (" ");
  if (right_light >= LIGHT_THRESHOLD_MIN)
  {
    //Map light level to speed and constrain it
    int left_speed = map(right_light, LIGHT_THRESHOLD_MIN, LIGHT_THRESHOLD_MAX, SPEED_MIN, SPEED_MAX);
    left_speed = constrain(left_speed, SPEED_MIN, SPEED_MAX);
    Serial.print(left_speed);
    forward("left", left_speed);
  }
  else
  {
    Serial.print("0");
    brake("left");
  }
  
  Serial.print("\tLeft: ");
  Serial.print(left_light);
  Serial.print(" ");
  if (left_light >= LIGHT_THRESHOLD_MIN)
  {
    //Map light level to speed and constarin it
    int right_speed = map(left_light, LIGHT_THRESHOLD_MIN, LIGHT_THRESHOLD_MAX, SPEED_MIN, SPEED_MAX);
    right_speed = constrain(right_speed, SPEED_MIN, SPEED_MAX);
    Serial.println(right_speed);
    forward("right", right_speed);
  }
  else 
  {
    Serial.println("0");
    brake("right");
  }
 
}

 //MOtor goes forward at given rate (from 0-255)
  //Motor can be "left" or "right"
  void forward (String motor, int rate)
  {
    if(motor == "left")
    {
      digitalWrite(LEFT_EN, LOW);
      digitalWrite(LEFT_MC1, HIGH);
      digitalWrite(LEFT_MC2, LOW);
      digitalWrite(LEFT_EN, rate);
    }
    else if(motor == "right")
    {
      digitalWrite(RIGHT_EN, LOW);
      digitalWrite(RIGHT_MC1, HIGH);
      digitalWrite(RIGHT_MC2, LOW);
      digitalWrite(RIGHT_EN, rate);
    }
  }
  
  //Stops motor
  //Motor can be "left" or right"
  void brake (String motor)
  {
    if(motor == "left")
    {
      digitalWrite(LEFT_EN, LOW);
      digitalWrite(LEFT_MC1, LOW);
      digitalWrite(LEFT_MC2, LOW);
      digitalWrite(LEFT_EN, HIGH);
    }
    else if(motor == "right")
    {
      digitalWrite(RIGHT_EN, LOW);
      digitalWrite(RIGHT_MC1, LOW);
      digitalWrite(RIGHT_MC2, LOW);
      digitalWrite(RIGHT_EN, HIGH);
    }
  }

