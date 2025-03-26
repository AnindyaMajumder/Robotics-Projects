char inp;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT);  //IN1
  pinMode(4, OUTPUT);  //IN2
  pinMode(5, OUTPUT);  //IN3
  pinMode(7, OUTPUT);  //IN4
}

void loop() {
  if(Serial.available()>0)
  {
    inp = Serial.read();
    Serial.println(inp);

    if(inp == 'F')  //Forward
    {
      //Right motor
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);

      //Left motor
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
    }
    else if(inp == 'B') //Backward
    {
      //Right motor
      digitalWrite(2, HIGH);
      digitalWrite(4, LOW);

      //Left motor
      digitalWrite(5, HIGH);
      digitalWrite(7, LOW);
    }
    else if(inp == 'R') //Right turn
    {
      //Right motor
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);

      //Left motor
      digitalWrite(5, LOW);
      digitalWrite(7, HIGH);
    }
    else if(inp == 'L') //Left turn
    {
      //Right motor
      digitalWrite(2, LOW);
      digitalWrite(4, HIGH);

      //Left motor
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
    }
    if(inp == 'S')  //STOP
    {
      //Right motor
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);

      //Left motor
      digitalWrite(5, LOW);
      digitalWrite(7, LOW);
    }

    // delay(500);
  }

}
