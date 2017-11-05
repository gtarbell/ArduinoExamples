#include <Servo.h>

int clawPort = 9;
Servo myservo;
int desiredPosition = 0; 
int currentPosition =0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(clawPort);
  // initialize serial port and set baud rate
  Serial.begin(9600);
  Serial.write("input servo value between 0 and 180");
  currentPosition = myservo.read();
  Serial.println("current servo position: " + String(currentPosition));

  Serial.println("input new servo value between 0 and 180");
}

void loop() {
  

  if(Serial.available() > 0)
  {
    desiredPosition = Serial.readString().toInt();

    Serial.print("Heading to value: ");
    Serial.println(desiredPosition, DEC);

    if( desiredPosition > currentPosition)
    {
      for(int i = currentPosition; i <= desiredPosition; i++)
      {
        myservo.write(i);
        delay(15);
      }
      currentPosition = desiredPosition;
    }
    else
    {
      for(int i = currentPosition; i >= desiredPosition; i--)
      {
        myservo.write(i);
        delay(15);
      }
      currentPosition = desiredPosition;
    }
    Serial.println("done");
    
   
  }
}
