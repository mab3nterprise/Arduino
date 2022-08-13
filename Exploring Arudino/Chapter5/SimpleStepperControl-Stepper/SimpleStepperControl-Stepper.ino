//Simple Stepper Control with an H-Bridge
#include <Stepper.h>

//Motor Constants
//Most NEMA-17 Motors have 200 steps/revolution
const int STEPS_PER_REV = 200;

//H-Bridge Pins
const int COIL1_MC1 =2;
const int COIL1_MC2 =3;
const int COIL2_MC1 =4;
const int COIL2_MC2 =5;

Stepper myStepper(STEPS_PER_REV, COIL1_MC1, COIL1_MC2, COIL2_MC1, COIL2_MC2);

void setup() {
  myStepper.setSpeed(60);

}

void loop() {
  myStepper.step(STEPS_PER_REV);
  delay(500);

  myStepper.step(-STEPS_PER_REV);
  delay(500);

}
