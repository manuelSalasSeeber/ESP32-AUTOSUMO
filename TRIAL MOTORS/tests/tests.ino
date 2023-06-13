#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 19 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 18
#define IN2 5

// motor 2 settings
#define IN3 17
#define IN4 16
#define ENB 4// this pin must be PWM enabled pin if Arduino board is used
#define CHB 1

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change


Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB);

void setup() {
  Serial.begin(115200);
  robot.begin();
  //L298N DC Motor by Robojax.com
}

void loop() {
  advance();
  reverse();
}

void advance(){
  robot.rotate(1, 60, CCW);
  robot.rotate(2, 60, CW);
  delay(4000);
}

void reverse() {
  robot.rotate(1, 60, CW);
  robot.rotate(2, 60, CCW);
  delay(4000);
}


