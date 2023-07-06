#include "config.h"

Servo myServoA; // Create a servo object
Servo myServoB; // Create a servo object

unsigned long startTime = 0;
unsigned long endTime = 0;

int servoPinA = 9;  // Pin connected to the servo 180 -> 0 to activate
int servoPinB = 10; // Pin connected to servo 0 -> 180 to activate

int pos = 0;

bool armed = false;

bool servoTriggered = false;

void resetServo();
void triggerServo();
void ledBlink(int led, unsigned long delayTime);
void buzzerBeep(unsigned long beepInterval);

void setup()
{

  Serial.begin(9600);

  pinMode(pyroSignalA, INPUT);
  pinMode(pyroSignalB, INPUT);

  pinMode(ledLit, OUTPUT);
  pinMode(ledArmed, OUTPUT);
  pinMode(ledDeployed, OUTPUT);

  pinMode(buzzer, OUTPUT);

  myServoA.attach(servoPinA, 950, 2150);
  myServoB.attach(servoPinB, 850, 2100);

  // for (pos = 0; pos <= 180; pos += 1)
  // {
  //   myServoA.write(pos);
  //   myServoB.write(180-pos);
  //   delay(20);
  // }

  myServoA.write(175);
  myServoB.write(10);
  delay(20);

  armed = true;
}

void loop()
{

  int pyroSignalOne = digitalRead(pyroSignalA);
  int pyroSignalTwo = digitalRead(pyroSignalB);

  Serial.print("pyroSignalOne: ");
  Serial.print(pyroSignalOne);
  Serial.print(" pyroSignalTwo: ");
  Serial.println(pyroSignalTwo);

  if (pyroSignalOne == 0 || pyroSignalTwo == 0)
  {
    triggerServo();
  }

  if(armed == true){
    ledBlink(ledArmed, 200);
  }
  else if (armed == false){
    ledBlink(ledDeployed, 500);
  }
}

void triggerServo()
{
  for (pos = 180; pos >= 0; pos -= 1)
  {
    myServoA.write(pos);
    myServoB.write(180 - pos);
    delay(10);
  }
  armed = false;
}

void resetServo()
{
  for (pos = 0; pos <= 180; pos += 1)
  {
    myServoA.write(pos);
    myServoB.write(180 - pos);
    delay(20);                 
  }
  armed = true;
}

void ledBlink(int led, unsigned long delayTime)
{
  if (millis() - endTime >= delayTime)
  {
    endTime = millis();
    int ledState = digitalRead(led);
    digitalWrite(led, !ledState);
  }
}

void buzzerBeep(unsigned long beepInterval)
{
  unsigned long previousMillis = 0;
  bool buzzerState = false;

  pinMode(buzzer, OUTPUT);
  unsigned long currentMillis = millis();

  while (true)
  {
    if (currentMillis - previousMillis >= beepInterval)
    {
      previousMillis = currentMillis;

      buzzerState = !buzzerState;
      if (buzzerState)
      {
        analogWrite(buzzer, 2);
      }
      else
      {
        analogWrite(buzzer, 0);
      }
    }
    currentMillis = millis();
  }
}