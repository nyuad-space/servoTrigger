#include "config.h"

Servo myServoA; // Create a servo object
Servo myServoB; // Create a servo object

int servoPinA = 9; // Pin connected to the servo 180 -> 0 to activate
int servoPinB = 10; // Pin connected to servo 0 -> 180 to activate

int triggerValue = 1; // Input value to trigger the servo
int resetValue = 2; // Input value to reset the servo
int pos = 0;

void resetServo();
void triggerServo();

void setup() {
  Serial.begin(9600); // Initialize serial communication

  myServoA.attach(servoPinA,950, 2150); // Attach the servo to the corresponding pin
  myServoB.attach(servoPinB,850, 2100); // Attach the servo to the corresponding pin

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 145 degrees
    myServoA.write(pos); 
    myServoB.write(180-pos); // tell servo to go to position in variable 'pos'
    delay(20); // waits 10ms for the servo to reach the position
  }

}

void loop() {
  if (Serial.available() > 0) {
    int input = Serial.parseInt(); // Read the input from the serial monitor

    if (input == triggerValue) {
      triggerServo(); // Trigger the servo
    } else if (input == resetValue) {
      resetServo();
    }
  }
}

void resetServo() {
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 145 degrees
      myServoA.write(pos); 
      myServoB.write(180-pos); // tell servo to go to position in variable 'pos'
      delay(20); // waits 10ms for the servo to reach the position
    }
}

void triggerServo() {
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 145 degrees to 0 degrees
      myServoA.write(pos);
      myServoB.write(180-pos); // tell servo to go to position in variable 'pos'
      delay(20); // waits 10ms for the servo to reach the position
    }
}


// unsigned long startTime = 0;
// unsigned long endTime = 0;

// int initialPos = 0;
// int finalPos = 120;

// bool deployed = false;

// Servo servoOne, servoTwo;

// // FUNCTION PROTOTYPES
// void ledOn(int led, unsigned long delayTime);
// void ledBlink(int led, unsigned long delayTime);
// void ledBlink(int led, unsigned long blinkInterval, unsigned long duration);

// void buzzerOn(unsigned long delayTime);
// void buzzerBeep(unsigned long beepInterval);
// void buzzerBeep(unsigned long beepInterval, unsigned long duration);

// void servoTrigger();

// void setup()
// {
//   // PYRO INPUTS
//   pinMode(pyroSignalA, INPUT);
//   pinMode(pyroSignalB, INPUT);
//   pinMode(pyroSignalC, INPUT);
//   // LED OUTPUTS
//   pinMode(ledLit, OUTPUT);
//   pinMode(ledArmed, OUTPUT);
//   pinMode(ledDeployed, OUTPUT);
//   // BUZZER OUTPUT
//   pinMode(buzzer, OUTPUT);
//   // SERVO OUTPUTS
//   pinMode(servoA, OUTPUT);
//   pinMode(servoB, OUTPUT);
//   // STATE OUTPUTS
//   pinMode(deploymentState, OUTPUT);

//   attachInterrupt(digitalPinToInterrupt(pyroSignalA), servoTrigger, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(pyroSignalB), servoTrigger, CHANGE);
//   attachInterrupt(digitalPinToInterrupt(pyroSignalC), servoTrigger, CHANGE);

//   Serial.begin(9600);
// }

// void loop()
// {


//   int pyroSignalOne = digitalRead(pyroSignalA);
//   int pyroSignalTwo = digitalRead(pyroSignalB);
//   int pyroSignalThree = digitalRead(pyroSignalC);

//   Serial.print("Pyro Signal A: ");
//   Serial.print(pyroSignalOne);

//   Serial.print(" Pyro Signal B: ");
//   Serial.print(pyroSignalTwo);

//   Serial.print(" Pyro Signal C: ");
//   Serial.println(pyroSignalThree);

//   delay(500);

// }

// // FUNCTION DEFINITIONS

// /*** CONTROL SERVO ***/
// void servoTrigger(){

//   servoOne.attach(servoA);
//   servoTwo.attach(servoB);

//   servoOne.write(initialPos);
//   servoTwo.write(initialPos);

//   for(int currentPos = 0; currentPos <= finalPos; currentPos += 1)
//   {
//     servoOne.write(currentPos);
//     servoTwo.write(currentPos);
//     delay(15);
//   }
// }

// /*** CONTROL LEDS ***/
// void ledOn(int led, unsigned long delayTime)
// {
//   if (delayTime == 0)
//   {
//     digitalWrite(led, HIGH);
//   }
//   else
//   {
//     unsigned long currentTime = millis();
//     while (currentTime - startTime < delayTime * 1000)
//     {
//       currentTime = millis();
//       digitalWrite(led, HIGH);
//     }
//     digitalWrite(led, LOW);
//   }
// }

// void ledBlink(int led, unsigned long delayTime)
// {
//   if (millis() - endTime >= delayTime * 1000)
//   {
//     endTime = millis();
//     int ledState = digitalRead(led);
//     digitalWrite(led, !ledState);
//   }
// }

// void ledBlink(int led, unsigned long blinkInterval, unsigned long duration)
// {
//   unsigned long previousMillis = 0;
//   bool ledState = false;

//   pinMode(led, OUTPUT);
//   unsigned long currentMillis = millis();

//   while (currentMillis < duration * 1000)
//   {
//     if (currentMillis - previousMillis >= blinkInterval)
//     {
//       previousMillis = currentMillis;

//       ledState = !ledState;
//       if (ledState)
//       {
//         digitalWrite(led, HIGH);
//       }
//       else
//       {
//         digitalWrite(led, LOW);
//       }
//     }
//     currentMillis = millis();
//   }

//   digitalWrite(led, LOW);

// }

// /*** CONTROL BUZZER ***/
// void buzzerOn(unsigned long delayTime)
// {
//   if (delayTime == 0)
//   {
//     analogWrite(buzzer, 10);
//   }
//   else
//   {
//     unsigned long currentTime = millis();
//     while (currentTime - startTime < delayTime * 1000)
//     {
//       currentTime = millis();
//       analogWrite(buzzer, 10);
//     }
//     analogWrite(buzzer, 0);
//   }
// }

// void buzzerBeep(unsigned long beepInterval)
// {
//   unsigned long previousMillis = 0;
//   bool buzzerState = false;

//   pinMode(buzzer, OUTPUT);
//   unsigned long currentMillis = millis();

//   while (true)
//   {
//     if (currentMillis - previousMillis >= beepInterval)
//     {
//       previousMillis = currentMillis;

//       buzzerState = !buzzerState;
//       if (buzzerState)
//       {
//         analogWrite(buzzer, 10);
//       }
//       else
//       {
//         analogWrite(buzzer, 0);
//       }
//     }
//     currentMillis = millis();
//   }
// }

// void buzzerBeep(unsigned long beepInterval, unsigned long duration)
// {
//   unsigned long previousMillis = 0;
//   bool buzzerState = false;

//   pinMode(buzzer, OUTPUT);
//   unsigned long currentMillis = millis();

//   while (currentMillis < duration * 1000)
//   {
//     if (currentMillis - previousMillis >= beepInterval)
//     {
//       previousMillis = currentMillis;

//       // Toggle the LED state
//       buzzerState = !buzzerState;
//       if (buzzerState)
//       {
//         analogWrite(buzzer, 10);
//       }
//       else
//       {
//         analogWrite(buzzer, 0);
//       }
//     }
//     currentMillis = millis();
//   }
//   analogWrite(buzzer, 0);
// }