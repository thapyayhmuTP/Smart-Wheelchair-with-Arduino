int joystick1 = A0; //y
int joystick2 = A1; //sw
int joystick3 = A2; //x
int motor1 = 5;
int motor2 = 6;
int motor3 = 10;
int motor4 = 11;
int enable = 9;
int value1;
int count;
int uncount = 0;
int durationLeft;
int distanceLeft;
int durationRight;
int distanceRight;
int joyvalue1;
int joyvalue2;
int joyvalue3;
int trigPinLeft= 2;
int echoPinLeft=3;
int trigPinRight= 7;
int echoPinRight=8;
long duration;
int distance;
int buzzvariable=4;
void setup() {
  pinMode(joystick1, INPUT);
  pinMode(joystick2, INPUT);
  pinMode(joystick3, INPUT);
  pinMode(trigPinLeft, OUTPUT);
  pinMode(echoPinLeft, INPUT);
  pinMode(trigPinRight, OUTPUT);
  pinMode(echoPinRight, INPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(buzzvariable,OUTPUT);
  Serial.begin(9600);
}

void loop() {
      joyvalue1 = analogRead(joystick1);
      joyvalue2 = analogRead(joystick2);
      joyvalue3 = analogRead(joystick3);
//      Serial.print(joyvalue1);
//      Serial.print("  ");
//      Serial.print(joyvalue2);
//      Serial.print("  ");
//      Serial.println(joyvalue3);
       ultrasonicLeft();
       ultrasonicRight();
       if(distanceRight<30 || distanceLeft<30){
        digitalWrite(buzzvariable,HIGH);
        }
        if (distanceLeft>30 && distanceRight>30){
          digitalWrite(buzzvariable,LOW);
        }
     
      if (joyvalue3 >= 0 && joyvalue3 < 400 && joyvalue1 > 400 && joyvalue1 < 600)
      {
        value1 = map(joyvalue3, 400, 0, 0, 100);
        backward();
      }
  
      else if (joyvalue3 > 600 && joyvalue3 < 1024 && joyvalue1 > 400 && joyvalue1 < 600)
      {
        value1 = map(joyvalue3, 600, 1023, 0, 100);
        forward();
      }

      if (joyvalue1 >= 0 && joyvalue1 < 400 && joyvalue3 > 400 && joyvalue3 < 600)
      {
        value1 = map(joyvalue1, 400, 0, 0, 100);
        turnright();
      }

      else if (joyvalue1 > 600 && joyvalue1 < 1024 && joyvalue3 > 400 && joyvalue3 < 600)
      {
        value1 = map(joyvalue1, 600, 1023, 0, 100);
        turnleft();
      }

      if (joyvalue3 > 400 && joyvalue3 < 600 && joyvalue1 > 400 && joyvalue1 < 600)
      {
        stayhere();
      }
 
       
     
    }
      
void forward()
{
  analogWrite(enable, value1);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  Serial.println("forward");
}

void backward()
{
  analogWrite(enable, value1);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  Serial.println("backward");
}

void turnleft()
{
  analogWrite(enable, value1);
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  Serial.println("left");
}

void turnright()
{
  analogWrite(enable, value1);
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  Serial.println("right");
}

void stayhere()
{
  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 0);
  //Serial.println("I don't move any fucking places");
}

/*void automatic()
{
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echopin,HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance   ");
  Serial.println(distance);
  Serial.println("auto");
  delay(1000);
  Serial.println(count);
  if (distance < 50)
  {
    stayhere();
  }
}*/
void ultrasonicLeft() {
digitalWrite(trigPinLeft,HIGH);
delayMicroseconds(2);
digitalWrite(trigPinLeft,LOW);
durationLeft=pulseIn(echoPinLeft,HIGH);
distanceLeft=durationLeft*0.034/2;
Serial.print("  Distanceleft= ");
Serial.print(distanceLeft);
             
}

void ultrasonicRight() {
digitalWrite(trigPinRight,HIGH);
delayMicroseconds(2);
digitalWrite(trigPinRight,LOW);
durationRight=pulseIn(echoPinRight,HIGH);
distanceRight=durationRight*0.034/2;
Serial.print("  Distance= ");
Serial.println(distanceRight);
}

void buzz(){
  digitalWrite(buzzvariable,HIGH);
  }
