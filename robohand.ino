#include <Servo.h>
const int FLEX1_MIN = 150;
const int FLEX1_MAX = 200;

const int FLEX2_MIN = FLEX1_MIN;
const int FLEX2_MAX = FLEX1_MAX;

const int FLEX3_MIN = FLEX1_MIN;
const int FLEX3_MAX = FLEX1_MAX;

const int FLEX4_MIN = 165;
const int FLEX4_MAX = FLEX1_MAX;

const int FLEX5_MIN = FLEX1_MIN;
const int FLEX5_MAX = FLEX1_MAX;

const int finger1IN = A0;
const int finger2IN = A1;
const int finger3IN = A2;
const int finger4IN = A3;
const int finger5IN = A4;

const int finger1OUT = 3;
const int finger2OUT = 5;
const int finger3OUT = 6;
const int finger4OUT = 9;
const int finger5OUT = 10;

Servo finger1Servo;
Servo finger2Servo;
Servo finger3Servo;
Servo finger4Servo;
Servo finger5Servo;


void setup() {
  Serial.begin(9600);
  finger1Servo.attach(finger1OUT);
  finger1Servo.write(0);
  finger2Servo.attach(finger2OUT);
  finger2Servo.write(0);
  finger3Servo.attach(finger3OUT);
  finger3Servo.write(0);
  finger4Servo.attach(finger4OUT);
  finger4Servo.write(0);
  finger5Servo.attach(finger5OUT);
  finger5Servo.write(0);
}

void loop() 
{
  int finger1Val = sensorRead(finger1IN);
  int servo1Val = map(finger1Val, FLEX1_MIN, FLEX1_MAX, 180, 0); 
  servo1Val = constrain(servo1Val, 0, 180);
//  Serial.print("finger1Val: "); Serial.print(finger1Val); Serial.print(", servo1val: "); Serial.println(servo1Val);
  finger1Servo.write(servo1Val);

  int finger2Val = sensorRead(finger2IN);
  int servo2Val = map(finger2Val, FLEX2_MIN, FLEX2_MAX, 180, 0); 
  servo2Val = constrain(servo2Val, 0, 180);
 // Serial.print("finger2Val: "); Serial.print(finger2Val); Serial.print(", servo2val: "); Serial.println(servo2Val);
  finger2Servo.write(servo2Val);

  int finger3Val = sensorRead(finger3IN);
  int servo3Val = map(finger3Val, FLEX3_MIN, FLEX3_MAX, 180, 0); 
  servo3Val = constrain(servo3Val, 0, 180);
//  Serial.print("finger3Val: "); Serial.print(finger3Val); Serial.print(", servo3val: "); Serial.println(servo3Val);
  finger3Servo.write(servo3Val);

  int finger4Val = sensorRead(finger4IN);
  int servo4Val = map(finger4Val, FLEX4_MIN, FLEX4_MAX, 180, 0); 
  servo4Val = constrain(servo4Val, 0, 180);
  Serial.print("finger4Val: "); Serial.print(finger4Val); Serial.print(", servo4val: "); Serial.println(servo4Val);
  finger4Servo.write(servo4Val);

  int finger5Val = sensorRead(finger5IN);
  int servo5Val = map(finger5Val, FLEX5_MIN, FLEX5_MAX, 180, 0); 
  servo5Val = constrain(servo5Val, 0, 180);
 // Serial.print("finger5Val: "); Serial.print(finger5Val); Serial.print(", servo5val: "); Serial.println(servo5Val);
  finger5Servo.write(servo5Val);
  delay(60);
}

int sensorRead(int slotNumber)
{
   int n = 100;
   long sum = 0;
   for(int i=0;i<n;i++)
   {
      sum = sum + analogRead(slotNumber);
   }
   return sum/n;
}


