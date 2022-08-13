//Make a mouse

#include <Mouse.h>

const int LEFT_BUTTON = 4;
const int MIDDLE_BUTTON = 3;
const int RIGHT_BUTTON = 2;
const int X_AXIS = 0;
const int Y_AXIS = 1;


void setup() {
  Mouse.begin();
  pinMode(MIDDLE_BUTTON, INPUT);

}

void loop() {
  int xVal = readJoystick(X_AXIS);
  int yVal = readJoystick(Y_AXIS);

  Mouse.move(xVal, yVal, 0);

  readButton(LEFT_BUTTON, MOUSE_LEFT);
  readButton(MIDDLE_BUTTON, MOUSE_MIDDLE);
  readButton(RIGHT_BUTTON, MOUSE_RIGHT);

  delay(5);
}

//Reads joystick value, scales it, and adds dead range in middle
int readJoystick(int axis)
{
  int val = analogRead(axis);
  val = map(val, 0, 1023, -10, 10);

  if (val <= 2 && val >= -2)
    return 0;

  else
    return val;
}

//Read a button and issue a mouse command
void readButton(int pin, char mouseCommand)
{
  //IF  button is depressed, click if it hasn't already been clicked
  if (digitalRead(pin) == HIGH)
  {
    if (!Mouse.isPressed(mouseCommand))
    {
      Mouse.press(mouseCommand);
    }
  }
  //Release the mouse if it has been clicked.
  else {
    if (Mouse.isPressed(mouseCommand))
    {
      Mouse.release(mouseCommand);
    }
  }


}
