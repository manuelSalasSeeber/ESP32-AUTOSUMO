#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 19
#define IN1 18
#define IN2 5

// motor 2 settings
#define IN3 17
#define IN4 16
#define ENB 4
#define CHB 1

const int CCW = 2; // counter clockwise
const int CW  = 1; // clockwise

#define motor1 1 //motor 1 id
#define motor2 2 // motor 2 id

Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB);

// Sensor
const int Trigger = 23;   // digital pin 2 for sensor Trigger 
const int Echo = 22;   // digital pin 3 for sensor Echo

void setup() {
  Serial.begin(9600);
  robot.begin();
  pinMode(Trigger, OUTPUT); // trigger pin as output
  pinMode(Echo, INPUT);  // echo pin as input
  digitalWrite(Trigger, LOW); // initialize trigger at 0
}


void loop() {
  
  long t; //tiempo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delay(100);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm

  Serial.print("Distancia: ");
  Serial.print(d);      //Enviamos serialmente el valor de la distancia
  Serial.print("cm");
  Serial.println();

  if (d < 400){ // mientras el sensor no mida nada mas cerca que 40cm
    brakeMotors();
    delay(500);
    attack();
    delay(2000); 
  }

  turn();
  
}
void turn() {
  robot.rotate(motor1, 60, CW);
  robot.brake(motor2);
  }

void attack() {
  robot.rotate(motor1, 80, CW);
  robot.rotate(motor2, 80, CCW);
}

void brakeMotors(){
  robot.brake(motor1);
  robot.brake(motor2);
}


