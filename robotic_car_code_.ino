
#define enA 10  //Enable 1 L298   Pin enA
#define in1 9  // Motor 1 L298    Pin in1
#define in2 8  // Motor 1 L298   Pin in2
#define in3 7  // Motor 2 L298   Pin in3 
#define in4 6  // Motor 2 L298   Pin in4
#define enB 5  //Enable 2 L298   Pin enB

#define ls A0  // ir left sensor 
#define rs A1  // ir right sensor 

#define echo A2     //Echo pin
#define trigger A3  //Trigger pin

int Set=15;
int distance_L, distance_F, distance_R;

void setup() {

Serial.begin(9600);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
pinMode (in3,OUTPUT);
pinMode(in4,OUTPUT);
pinMode(enA,OUTPUT);
pinMode(enB,OUTPUT);

pinMode(ls,INPUT);
pinMode(rs,INPUT);
pinMode(echo,INPUT);
pinMode(trigger,INPUT);


analogWrite(enA,200);
analogWrite(enB,200);


distance_F =Ultrasconic_read();
delay(500);


}

void loop() {

  distance_F=Ultrasonic_read();
  Serial.print("D F=");Serial.printIn(distance_F);


  if((digitalRead(rs)== 0) && (digitalRead(ls)==0)){
    if(distance_F > Set){forward();}
  }
  
  else if((digitalRead(rs) == 1) && (digitalRead(ls) == 0)){turnRight();}

  else if((digitalRead(rs)== 0) && (digitalRead(ls) == 1)) {turnLeft();}

}

long Ultrasonic_read(){
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  long time = pulseIn (echo, HIGH);
  return time / 29 / 2;
}
void compareDistance(){
    if(distance_L > distance_R){
  turnLeft();
  delay(500);
  forword();
  delay(600);
  turnRight();
  delay(500);
  forword();
  delay(600);
  turnRight();
  delay(400);
  }
  else{
  turnRight();
  delay(500);
  forword();
  delay(600);
  turnLeft();
  delay(500);
  forword();
  delay(600);  
  turnLeft();
  delay(400);
  }
}


void forward(){   //forward

  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void backword() {  //backword
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void turnRight(){  //turnRight
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void turnLeft(){   //turnLeft
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void Stop(){    //Stop
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

