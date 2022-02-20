//Simple Stepper Control with an H-Bridge
#include <Stepper.h>

//Motor Constants
//Most NEMA-17 Motors have 200 steps/revolution
const int STEPS_PER_REV = 200;

//To do one rotation in a minute,
//we need to know the milliseconds required between steps:
//60 seconds * 100ms / 200steps = 300ms/step
const int MS_PER_STEP = 300;

//H-Bridge Pins
const int COIL1_MC1 = 2;
const int COIL1_MC2 = 3;
const int COIL2_MC1 = 4;
const int COIL2_MC2 = 5;

//Button Pins
const int START = 8;
const int STOP = 9;

//Tracking variables
unsigned long last_time = 0;
unsigned long curr_time = 0;
int steps_taken = 0;

Stepper chronograph(STEPS_PER_REV, COIL1_MC1, COIL1_MC2, COIL2_MC1, COIL2_MC2);

void setup() {

  Serial.begin(9600);
  
  chronograph.setSpeed(200);

  pinMode(START, INPUT_PULLUP);
  pinMode(STOP, INPUT_PULLUP);

}

void loop() {

  while (digitalRead(START));
  last_time = millis();

  while (digitalRead(STOP) ==HIGH && steps_taken <STEPS_PER_REV)
  {
    curr_time = millis();
    if ((curr_time - last_time)>= MS_PER_STEP) {
      chronograph.step(1);
      steps_taken++;
      last_time = curr_time;
    }
  }
    if(steps_taken <STEPS_PER_REV) chronograph.step(-steps_taken);
    steps_taken =0;

}
