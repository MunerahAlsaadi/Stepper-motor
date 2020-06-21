#include <Stepper.h>

const int stepsPerRevolution = 150; 


Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11); // initialize the stepper library on pins 8 through 11:

int stepCount = 0; 

void setup() {
  // nothing to do inside the setup
}

void loop() {

  int sensorReading = analogRead(A0); // read the sensor value
  int motorSpeed = map(sensorReading, 0, 1023, 0, 250);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    myStepper.step(stepsPerRevolution / 100); // step 1/100 of a revolution
  }
}