// Deklaration und Initialisierung der Eingang-Pins
// PWM-Pins: 3, 5, 6, 9, 10, 11
// TO-DO: pins umstecken, so dass 4 PWM Pins frei sind

// Gleichstrommotor 1
int motor1pin1 = A5;
int motor1pin2 = 2;
int GSM1 = 3;

// Gleichstrommotor 2
int motor2pin1 = 4;
int motor2pin2 = 6;
int GSM2 = 5;

// Gleichstrommotor 3
int motor3pin1 = 7;
int motor3pin2 = 8;
int GSM3 = 9;

// Gleichstrommotor 4
int motor4pin1 = 10;
int motor4pin2 = 12;
int GSM4 = 11;


void setup() {
  // Motoren
  pinMode(GSM1, OUTPUT);    
  pinMode(GSM2, OUTPUT);
  pinMode(GSM3, OUTPUT);    
  pinMode(GSM4, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  pinMode(motor3pin1, OUTPUT);
  pinMode(motor3pin2, OUTPUT);
  pinMode(motor4pin1, OUTPUT);
  pinMode(motor4pin2, OUTPUT);

}

void loop() {
  forward(10);
  stopp(2000);
 // backward(50);
 // stopp(2000);
 // left(50, 200);
 // stopp(2000);
 // right(200, 50);
 // stopp(2000);
}



void wheel(int motor, bool forwardWheelSpin, int spinSpeed){
  if (forwardWheelSpin == true){
    if(motor == 1){
      digitalWrite(GSM1, spinSpeed);
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
    } else if(motor == 2){
      digitalWrite(GSM2, spinSpeed);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    } else if(motor == 3){
      digitalWrite(GSM3, spinSpeed);
      digitalWrite(motor3pin1, HIGH);
      digitalWrite(motor3pin2, LOW);
    } else if(motor == 4){
      digitalWrite(GSM4, spinSpeed);
      digitalWrite(motor4pin1, HIGH);
      digitalWrite(motor4pin2, LOW);
    }
  } else if (forwardWheelSpin == false){
    if(motor == 1){
      digitalWrite(GSM1, spinSpeed);
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
    } else if(motor == 2){
      digitalWrite(GSM2, spinSpeed);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    } else if(motor == 3){
      digitalWrite(GSM3, spinSpeed);
      digitalWrite(motor3pin1, LOW);
      digitalWrite(motor3pin2, HIGH);
    } else if(motor == 4){
      digitalWrite(GSM4, spinSpeed);
      digitalWrite(motor4pin1, LOW);
      digitalWrite(motor4pin2, HIGH);
    }
  }
}




void forward(int wheelSpeed){
  // Vorwärtsfahren
  wheel(1,true,wheelSpeed);
  wheel(2,true,wheelSpeed);
  wheel(3,true,wheelSpeed);
  wheel(4,true,wheelSpeed);
  //delay(1000);
}


void backward(int wheelSpeed){
  //Rückwärtsfahren
  wheel(1,false,wheelSpeed);
  wheel(2,false,wheelSpeed);
  wheel(3,false,wheelSpeed);
  wheel(4,false,wheelSpeed);
  //delay(1000);
}

void leftSpotTurn(int wheelSpeed){
  // Rechts herum auf der Stelle drehen
  wheel(1,false,wheelSpeed);
  wheel(2,true,wheelSpeed);
  wheel(3,false,wheelSpeed);
  wheel(4,true,wheelSpeed);
  //delay(2000);
}

void rightSpotTurn(int wheelSpeed){
  // Rechts herum auf der Stelle drehen
  wheel(1,true,wheelSpeed);
  wheel(2,false,wheelSpeed);
  wheel(3,true,wheelSpeed);
  wheel(4,false,wheelSpeed);
  //delay(2000);
}

void left(int leftWheelSpeed, int rightWheelSpeed){
  // langsame Linkkurve
  wheel(1,true,rightWheelSpeed);
  wheel(2,true,leftWheelSpeed);
  wheel(3,true,rightWheelSpeed);
  wheel(4,true,leftWheelSpeed);
}

void right(int leftWheelSpeed, int rightWheelSpeed){
  // langsame Rechtskurve
  wheel(1,true,rightWheelSpeed);
  wheel(2,true,leftWheelSpeed);
  wheel(3,true,rightWheelSpeed);
  wheel(4,true,leftWheelSpeed);
}


void stopp(int stopptime){
  //Stopp
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  delay(stopptime);
}
