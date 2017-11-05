#include <Servo.h>

int clawOpen =160;
int clawClosed = 149;
int currentClaw =0;

int extendArmMin = 30;
int extendArmMax = 175;
int currentExtend = 0;

int clawPin = 6;
int extendPin = 9;
int joystickPinX =0;
int joystickPinY = 1;

Servo clawServo;
Servo extendServo;

int xValue = 0;     
int yValue = 0;        

void setup() {
  // put your setup code here, to run once:
  clawServo.attach(clawPin);
  extendServo.attach(extendPin);
  // initialize serial port and set baud rate
  Serial.begin(9600);
  currentClaw = clawClosed;
  clawServo.write(clawClosed);
  currentExtend = extendArmMin;
  extendServo.write(currentExtend);
}

void loop() {
   
  xValue = analogRead(joystickPinX);
  delay(50);
  yValue = analogRead(joystickPinY);

  if(xValue < 100)
  {
    CloseClaw();
  }
  if(xValue > 1000)
  {
    OpenClaw();
  }

  if(yValue < 100)
  {
    ExtendArm();
  }

  if(yValue > 1000)
  {
    RetractArm();
  }

  Serial.print(xValue);
  Serial.write ( ","); 
  Serial.println(yValue);

  //delay(50);
  
}

void CloseClaw()
{
  Serial.write("closeClaw - Current clawValue: ");
  Serial.println(String(currentClaw));
  
  if(currentClaw > clawClosed)
  {
    clawServo.write(currentClaw -1);
    currentClaw--; 
  }

}

void OpenClaw()
{
  Serial.write("OpenClaw - Current clawValue: ");
  Serial.println(String(currentClaw));
  
  if(currentClaw < clawOpen)
  {
    clawServo.write(currentClaw + 1 );
    currentClaw++; 
  }

}

void ExtendArm()
{
  Serial.write("extend arm : ");
  Serial.println(String(currentExtend));
  
  if(currentExtend < extendArmMax)
  {
    extendServo.write(currentExtend + 1);
    currentExtend++; 
  }

}

void RetractArm()
{
  Serial.write("RetractArm : ");
  Serial.println(String(currentExtend));
  
  if(currentExtend > extendArmMin)
  {
    extendServo.write(currentExtend - 1);
    currentExtend--; 
  }
}


