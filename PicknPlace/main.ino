#include <Servo.h>

//Servo initialization
Servo s1;
Servo s2;
int s1_pin = 3;
int s2_pin = 11;

//motor
int motor1 = 5;
int motor2 = 6;
int mot1 = 9;
int mot2 = 10;

//Sonar initialization
// const int trigPin = 9;
// const int echoPin = 10;
// float duration, distance;

char state = 0;

void setup() {
  //Servo
  s1.attach(s1_pin);
  s2.attach(s2_pin);

  //Motor Driver
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(mot1, OUTPUT);
  pinMode(mot2, OUTPUT);

  //Sonar
  // pinMode(trigPin, OUTPUT);
  // pinMode(echoPin, INPUT);

  //Motor driver

  Serial.begin(9600); 
}

// int Sonar()
// {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   duration = pulseIn(echoPin, HIGH);
//   distance = (duration*.0343)/2;
//   Serial.print("Distance: ");
//   Serial.println(distance);

//   if(distance < 10)
//   {
//     return 0;
//   }
//   else
//   {
//     return 1;
//   }
// }
void ArmControl(char state)
{
  if(state == '1') //Manipulator open
  {
    s1.write(90);
    Serial.println("Manipulator +90");
  }
  else if(state == '2') //Manipulator close
  {
    s1.write(0);
    Serial.println("Manipulator 0");
  }
  else if(state == '3') //Claw open
  {
    s2.write(180);
    Serial.println("Claw +0");
  }
  else if(state == '4') //Claw close
  {
    s2.write(0);
    Serial.println("Claw +180");
  }
}

void loop() 
{
  if(Serial.available() > 0)
  { // Checks whether data is comming from the serial port
    state = Serial.read(); // Reads the data from the serial port
    Serial.println();
    Serial.print("Input: ");
    Serial.println(state);

    ArmControl(state);

    if (state=='d') //right move
    {
      digitalWrite(motor1, HIGH);
      digitalWrite(motor2, LOW);
      digitalWrite(mot1, LOW);
      digitalWrite(mot2, LOW);
    }

    else if (state=='a') //left move
    {
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, HIGH);
      digitalWrite(mot1, LOW);
      digitalWrite(mot2, LOW);
    }

    else if (state=='w') //forward
    {
      digitalWrite(motor1, HIGH);
      digitalWrite(motor2, HIGH);
      digitalWrite(mot1, LOW);
      digitalWrite(mot2, LOW);
    }

    else if (state=='s') //backward
    {
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(mot1, HIGH);
      digitalWrite(mot2, HIGH); 
    }

    else if (state =='x') //stop
    {
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      digitalWrite(mot1, LOW);
      digitalWrite(mot2, LOW);
    } 

    // delay(500);
  }

  // Serial.println("!! SERIAL CONN ERROR..............");
}