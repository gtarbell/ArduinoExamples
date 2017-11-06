#include <Servo.h>

int clawOpen =160;
int clawClosed = 149;
int currentClaw =0;

int extendArmMin = 30;
int extendArmMax = 175;
int currentExtend = 0;

int clawPin = 6;
int extendPin = 9;
int joystick1PinX =0;
int joystick1PinY = 1;

int baseMin = 30;
int baseMax = 175;
int currentBase = 0;

int liftMin = 30;
int liftMax = 175;
int currentLift = 0;

int basePin = 7;
int liftPin = 8;
int joystick2PinX =2;
int joystick2PinY = 3;

Servo clawServo;
Servo extendServo;
Servo baseServo;
Servo liftServo;

int xValue1 = 0;     
int yValue1 = 0; 
int xValue2 = 0;     
int yValue2 = 0;        

void setup() {
  // put your setup code here, to run once:
  clawServo.attach(clawPin);
  extendServo.attach(extendPin);
  baseServo.attach(basePin);
  liftServo.attach(liftPin);
  // initialize serial port and set baud rate
  Serial.begin(9600);
  currentClaw = clawClosed;
  clawServo.write(clawClosed);
  currentExtend = extendArmMin;
  extendServo.write(currentExtend);
  currentBase = baseMin;
  baseServo.write(currentBase);
  currentLift = liftMin;
  liftServo.write(currentLift);
}

void loop() {
   
  xValue1 = analogRead(joystick1PinX);
  delay(50);
  yValue1 = analogRead(joystick1PinY);

  if(xValue1 < 100)
  {
    CloseClaw();
  }
  if(xValue1 > 1000)
  {
    OpenClaw();
  }

  if(yValue1 < 100)
  {
    ExtendArm();
  }

  if(yValue1 > 1000)
  {
    RetractArm();
  }
  
  xValue2 = analogRead(joystick2PinX);
  delay(50);
  yValue2 = analogRead(joystick2PinY);

  if(xValue2 < 100)
  {
    RotateBaseClockwise();
  }
  if(xValue2 > 1000)
  {
    RotateBaseCounterClockwise();
  }

  if(yValue2 < 100)
  {
    RaiseArm();
  }

  if(yValue2 > 1000)
  {
    LowerArm();
  }
  Serial.print(xValue1);
  Serial.write ( ","); 
  Serial.println(yValue1);
  Serial.print(xValue2);
  Serial.write ( ","); 
  Serial.println(yValue2);
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

void RotateBaseClockwise()
{
  Serial.write("RotateBaseClockwise - Current baseValue: ");
  Serial.println(String(currentBase));
  
  if(currentBase < RotateBaseClockwise)
  {
    baseServo.write(currentBase +1);
    currentBase++; 
  }

}
void RotateBaseCounterClockwise()
{
  Serial.write("RotateBaseCounterClockwise - Current baseValue: ");
  Serial.println(String(currentBase));
  
  if(currentBase > RotateBaseCounterClockwise)
  {
    baseServo.write(currentBase -1);
    currentBase--; 
  }

}
void RaiseArm()
{
  Serial.write("raiseArm : ");
  Serial.println(String(currentLift));
  
  if(currentLift < liftMax)
  {
    liftServo.write(currentLift + 1);
    currentLift++; 
  }

}

void LowerArm()
{
  Serial.write("LowerArm : ");
  Serial.println(String(currentLift));
  
  if(currentLift > liftMin)
  {
    liftServo.write(currentLift - 1);
    currentLift--; 
  }
}

