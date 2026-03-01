#include <Servo.h>
#include <SoftwareSerial.h>

// HC05 RX, TX
SoftwareSerial BT(2, 3); // RX, TX

int IN1 = 8;
int IN2 = 9;

Servo servo1;
Servo servo2;
Servo servo3;

int servoPin1 = 5;
int servoPin2 = 7;
int servoPin3 = 6;

int currentAngle1 = 10;
int currentAngle2 = 10;
int currentAngle3 = 90;

// Hàm quay chậm cho servo 1
void slowServo1(int targetAngle, int delayTime)
{
  if (targetAngle > currentAngle1)
  {
    for (int angle = currentAngle1; angle <= targetAngle; angle++)
    {
      servo1.write(angle);
      delay(delayTime);
    }
  }
  else
  {
    for (int angle = currentAngle1; angle >= targetAngle; angle--)
    {
      servo1.write(angle);
      delay(delayTime);
    }
  }
  currentAngle1 = targetAngle;
}

// Hàm quay chậm cho servo 2
void slowServo2(int targetAngle, int delayTime)
{
  if (targetAngle > currentAngle2)
  {
    for (int angle = currentAngle2; angle <= targetAngle; angle++)
    {
      servo2.write(angle);
      delay(delayTime);
    }
  }
  else
  {
    for (int angle = currentAngle2; angle >= targetAngle; angle--)
    {
      servo2.write(angle);
      delay(delayTime);
    }
  }
  currentAngle2 = targetAngle;
}

// Hàm quay chậm cho servo 3
void slowServo3(int targetAngle, int delayTime)
{
  if (targetAngle > currentAngle3)
  {
    for (int angle = currentAngle3; angle <= targetAngle; angle++)
    {
      servo3.write(angle);
      delay(delayTime);
    }
  }
  else
  {
    for (int angle = currentAngle3; angle >= targetAngle; angle--)
    {
      servo3.write(angle);
      delay(delayTime);
    }
  }
  currentAngle3 = targetAngle;
}

// Hàm hạ pittong
void Down()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(7000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
}

// Hàm nâng pittong
void Up()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(5000);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(1000);
}

void TN()
{
  Down();
  Up();

  // Servo 1 quay
  slowServo1(75, 20);
  delay(1000);

  Down();

  // Servo 2 quay
  slowServo2(120, 20);
  delay(1000);

  Up();

  // Servo 1 quay
  slowServo1(0, 20);
  delay(1000);

  slowServo3(148, 20);
  delay(1000);
  Down();

  // Servo 2 quay
  slowServo2(10, 20);
  delay(1000);

  Up();

  slowServo1(36, 20); // Lay hoa chat 5
  delay(1000);

  Down();

  // Servo 2 quay
  slowServo2(120, 20);
  delay(1000);

  Up();

  // Servo 1 quay
  slowServo1(0, 20);
  delay(1000);

  Down();

  // Servo 2 quay
  slowServo2(10, 20);
  delay(1000);

  Up();

  // Servo 3 quay
  slowServo3(15, 20);
  delay(1000);

  // Servo 3 quay
  slowServo3(90, 20);
  delay(1000);

  Down();
}

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);

  // vị trí khởi động an toàn
  servo1.write(currentAngle1);
  servo2.write(currentAngle2);
  servo3.write(currentAngle3);

  
  BT.begin(9600);
  Serial.begin(9600);

  delay(500);
}

void loop()
{
  if (BT.available())
  {
    int cmd = BT.read();
    Serial.println(cmd);
    if (cmd == 0) //Bom hoa chat
    {
      slowServo2(10, 20);
      delay(1000);
    }
    else if (cmd == 1) //Hut hoa chat
    {
      slowServo2(120, 20);
      delay(1000);
    }
    else if (cmd == 2) //Ha piston
    {
      Down();
    }
    else if (cmd == 3) //Nang piston
    {
      Up();
    }
    else if (cmd == 4) // Lay hoa chat 1
    {
      slowServo1(75, 20);
      delay(1000);
    }
    else if (cmd == 5)
    {
      slowServo1(36, 20); // Lay hoa chat 5
      delay(1000);
    }
    else if (cmd == 6) // Thuc hien thi nghiem
    {
      TN();
    }
    else if (cmd == 7)
    {
      slowServo3(15, 20);
      delay(1000);
    }
    else if (cmd == 8)
    {
      slowServo1(0, 20);
      delay(1000);
    }

    else if (cmd == 9)
    {
      slowServo3(148, 20);
      delay(1000);
    }

    else if (cmd == 10)
    {
      slowServo3(90, 20);
      delay(1000);
    }
  }
}