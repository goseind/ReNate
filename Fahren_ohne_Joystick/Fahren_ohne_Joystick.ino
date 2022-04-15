// Deklaration und Initialisierung der Eingang-Pins
// PWM-Pins: 3, 5, 6, 9, 10, 11
// TO-DO: pins umstecken, so dass 4 PWM Pins frei sind

// Gleichstrommotor 1 - hinten re (pink)
int motor1pin1 = 2;
int motor1pin2 = 4;
int GSM1 = 3;

// Gleichstrommotor 2 - hinten li (grün)
int motor2pin1 = 5;
int motor2pin2 = 7;
int GSM2 = 6;

// Gleichstrommotor 3 - vorne re (orange)
int motor3pin1 = 8;
int motor3pin2 = 10;
int GSM3 = 9;

// Gleichstrommotor 4 - vorne li
int motor4pin1 = 12;
int motor4pin2 = 13;
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
  // 100 Umdrehungen mindestens, sonst laufen die Motoren nicht!
  //stopp(5000);
  //forward(150, 1000);
  //stopp(2000);
  //backward(150, 1000);
  //stopp(2000);
  // Auf der Stelle Drehen
  //leftSpotTurn(250, 1000);
  //stopp(2000);
  //rightSpotTurn(250,1000);
  //stopp(2000);
  // Kurvenfahren
  //left(10, 255, 5000);
  //stopp(2000);
  //right(255, 10, 5000);
  //stopp(2000);
  // sehr gemächtliches Kurvenfahren
  //left(80, 255, 5000);
  //stopp(2000);
  //right(255, 80, 10000);
  //stopp(2000);

}








void forward(int wheelspeed, int drivetime){
  // Vorwärtsfahren
  analogWrite(GSM1, wheelspeed);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  analogWrite(GSM2, wheelspeed);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  analogWrite(GSM3, wheelspeed);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  analogWrite(GSM4, wheelspeed);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(drivetime);
}


void backward(int wheelspeed, int drivetime){
  //Rückwärtsfahren
  analogWrite(GSM1, wheelspeed);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  analogWrite(GSM2, wheelspeed);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  analogWrite(GSM3, wheelspeed);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  analogWrite(GSM4, wheelspeed);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(drivetime);
}

void leftSpotTurn(int wheelspeed, int drivetime){
  // Rechts herum auf der Stelle drehen
  analogWrite(GSM1, wheelspeed);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  analogWrite(GSM2, wheelspeed);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);

  analogWrite(GSM3, wheelspeed);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  analogWrite(GSM4, wheelspeed);
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(drivetime);
}

void rightSpotTurn(int wheelspeed, int drivetime){
  // Rechts herum auf der Stelle drehen
  analogWrite(GSM1, wheelspeed);
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);

  analogWrite(GSM2, wheelspeed);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  analogWrite(GSM3, wheelspeed);
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);

  analogWrite(GSM4, wheelspeed);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(drivetime);
}


void left(int wheelSpeedLeft, int wheelSpeedRight, int drivetime){
  // Links herum fahren
  analogWrite(GSM1, wheelSpeedLeft);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  analogWrite(GSM2, wheelSpeedRight);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  analogWrite(GSM3, wheelSpeedLeft);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  analogWrite(GSM4, wheelSpeedRight);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(drivetime);
}


void right(int wheelSpeedLeft, int wheelSpeedRight, int drivetime){
  // Rechts herum fahren
  analogWrite(GSM1, wheelSpeedLeft);
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);

  analogWrite(GSM2, wheelSpeedRight);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);

  analogWrite(GSM3, wheelSpeedLeft);
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);

  analogWrite(GSM4, wheelSpeedRight);
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(drivetime);
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
