//Locks your computer when you turn off the lights
#include <Keyboard.h>

const int LIGHT =1;
const int THRESHOLD =100;

void setup() 
{
  Keyboard.begin();

}

void loop() 
{
  int brightness = analogRead(LIGHT);
  
  if(brightness<THRESHOLD)
  {
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.write('l');
    delay(100);
    Keyboard.releaseAll();
    }

}
