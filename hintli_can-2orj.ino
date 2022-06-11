
int ledPin = 6;
int ledPin2 = 8;
int ledPin3 = 7;
int trigPin = 11;
int echoPin = 12;
int trigPin2 = 9;
int echoPin2 = 10;
int trigPin3 = 4;
int echoPin3 = 5;

//our L298N control pins
const int LeftMotorForward = A0;
const int LeftMotorBackward = A1;
const int RightMotorForward = A3;
const int RightMotorBackward = A4;
boolean goesForward = false;


void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  
  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);

  delay(500);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
}



void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
}

void loop() {
  int duration, distance;
  
  digitalWrite (trigPin, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin, LOW);
  duration = pulseIn (echoPin, HIGH);
  distance = (duration/2) / 29.1;


  int duration2, distance2;
  digitalWrite (trigPin2, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin2, LOW);
  duration2 = pulseIn (echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;

  int duration3, distance3;
  digitalWrite (trigPin3, HIGH);
  delayMicroseconds (10);
  digitalWrite (trigPin3, LOW);
  duration3 = pulseIn (echoPin3, HIGH);
  distance3 = (duration3/2) / 29.1;

      Serial.print(distance);  
      Serial.print("cm");
      Serial.println();
  
  int flash=map(distance,0,100,0,1000);//Maps LEDB to blink in intervals up to one second. Blinks slower the further away objects are.
  
  
  if (distance < 30) {  // Change the number for long or short distances.
    digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
    delay(flash);
    digitalWrite(ledPin,LOW);
    delay(flash);
    
    
    if (distance <= 20){
      int distanceRight = 0;
      int distanceLeft = 0;
      digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
      delay(flash);
      digitalWrite(ledPin,LOW);
      delay(flash);
    
      digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
      delay(flash);
      digitalWrite(ledPin,LOW);
      delay(flash);
      moveStop();
      delay(300);
      moveBackward();
      delay(400);
      moveStop();
      delay(300);
      distanceRight = duration2;
      delay(300);
      distanceLeft = duration3;
      delay(300);
      
      digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
      delay(flash);
      digitalWrite(ledPin,LOW);
      delay(flash);
  
      if (distance >= distanceLeft){
        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);
        turnRight();
        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);
        moveStop();
        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);
      }
      else{
        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);

        
        turnLeft();
        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);
        moveStop();

        digitalWrite(ledPin,HIGH);//These 4 lines are the blinking part
        delay(flash);
        digitalWrite(ledPin,LOW);
        delay(flash);
        
        
        }
    
    
    }
    
  }
  
  else {
    moveForward();
    digitalWrite (ledPin, LOW);
  }


   
      Serial.print(distance2);  
      Serial.print("cm");
      Serial.println();
      
   int flash2=map(distance2,0,100,0,1000);//Maps LEDB to blink in intervals up to one second. Blinks slower the further away objects are.
    if (distance2 < 30) {  // Change the number for long or short distances.
    digitalWrite(ledPin2,HIGH);//These 4 lines are the blinking part
    delay(flash2);
    digitalWrite(ledPin2,LOW);
    delay(flash2);
    }
 else {
      digitalWrite (ledPin2, LOW);
    }

    
   
      Serial.print(distance3);  
      Serial.print("cm");
      Serial.println();
    int flash3=map(distance3,0,100,0,1000);//Maps LEDB to blink in intervals up to one second. Blinks slower the further away objects are.
   
    if (distance3 < 30) {  // Change the number for long or short distances.
    digitalWrite(ledPin3,HIGH);//These 4 lines are the blinking part
    delay(flash3);
    digitalWrite(ledPin3,LOW);
    delay(flash3);
    }
 else {
      digitalWrite (ledPin3, LOW);
    }

  }
// Code ends here.
