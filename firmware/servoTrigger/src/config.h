#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Servo.h>

/*** LED PINS ***/
#define ledLit 13
#define ledArmed 8
#define ledDeployed 4

/*** BUZZER PINS ***/
#define buzzer 5

/*** SERVO PINS ***/
#define servoA 9
#define servoB 10

/*** PYRO SIGNAL PINS ***/
#define pyroSignalA 2
#define pyroSignalB 3
#define pyroSignalC 7

/*** STATE PINS ***/
#define deploymentState 6

#endif