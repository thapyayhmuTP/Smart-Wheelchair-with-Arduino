int motor1=5;
int motor2=6;
int motor3=10;
int motor4=11;
int enable = 9 ;
int autospeed = 80;
int left_IR=13;
int right_IR=12;
int casecount = 0;
long durationRight;
int distanceRight;
long durationLeft;
int distanceLeft;
int trigPinRight=7; //black
int echoPinRight=8;
int trigPinLeft=2;
int echoPinLeft=3;
int buzzvariable=4;
void setup() {
  Serial.begin(9600);
  pinMode(motor1,OUTPUT);
  pinMode(motor2,OUTPUT);
  pinMode(motor3,OUTPUT);
  pinMode(motor4,OUTPUT);
  pinMode(left_IR,INPUT);
  pinMode(right_IR,INPUT);
  pinMode(trigPinRight,OUTPUT);
  pinMode(echoPinRight,INPUT);
  pinMode(trigPinLeft,OUTPUT);
  pinMode(echoPinLeft,INPUT);
  pinMode(buzzvariable,OUTPUT);
}

void loop() {
   ultrasonicRight();
   ultrasonicLeft();
   if(distanceRight>40 ){
    case1();
    }
   else {
    buzz();
    stayhere();
    }
}
void case1(){
   if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 0){
    forward();
    }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 0){
    turnleft();
  }
  if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 1){
    turnright();
  }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 0){
    analogWrite(enable, 100);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    delay(1000);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    delay(500);
    while(right_IR=!1){
    analogWrite(enable, 90);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    Serial.println("left");
    }
    casecount=1;
  }  
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 1){
    stayhere();
    }
  }

void case2(){
   if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 0){
    forward();
    }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 0){
    turnleft();
  }
  if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 1){
    turnright();
  }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 0){
    forward();
    delay(1000);
    turnright();
    delay(1000);
    casecount=1;
  }  
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 1){
    analogWrite(enable, 85);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    delay(2500);
    while(right_IR==!1){
    analogWrite(enable, 85);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    Serial.println("left");
    }
    casecount=2;
    } 
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 2){
    stayhere();
    }
  
  }

void case3(){
   if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 0){
    forward();
    }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 0){
    turnleft();
  }
  if(digitalRead(left_IR) == 0 && digitalRead(right_IR) == 1){
    turnright();
  }
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 0){
    forward();
    delay(1000);
    turnright();
    delay(1000);
    casecount=1;
  }
if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 1){
    forward();
    delay(1000);
    turnright();
    delay(1000);
    casecount=2;
  }
    
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 2){
    analogWrite(enable, 85);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    delay(2500);
    while(right_IR==!1){
    analogWrite(enable, 85);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
    Serial.println("left");
    }
    casecount=3;
    } 
  if(digitalRead(left_IR) == 1 && digitalRead(right_IR) == 1 && casecount == 3){
    stayhere();
    }
  
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

void ultrasonicLeft() {
digitalWrite(trigPinLeft,HIGH);
delayMicroseconds(2);
digitalWrite(trigPinLeft,LOW);
durationLeft=pulseIn(echoPinLeft,HIGH);
distanceLeft=durationLeft*0.034/2;
Serial.print("  Distance= ");
Serial.println(distanceLeft);
}

void forward(){
    analogWrite(enable, autospeed);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    Serial.println("go");
  }
void turnleft(){
    analogWrite(enable, autospeed);
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
    Serial.println("left");
  }
void turnright(){
    analogWrite(enable, autospeed);
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
    Serial.println("right");  
  }
void stayhere(){
    analogWrite(motor1, 0);
    analogWrite(motor2, 0);
    analogWrite(motor3, 0);
    analogWrite(motor4, 0);
    Serial.println("Stop");
  }
void buzz(){
  digitalWrite(buzzvariable,HIGH);
  delay(100);
  digitalWrite(buzzvariable,LOW);
  delay(100);
  }
