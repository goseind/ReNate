int motor1pin1 = 2;
int motor1pin2 = 3;



int motor2pin1 = 4;
int motor2pin2 = 5;

int motor3pin1 = 8;
int motor3pin2 = 9;



int motor4pin1 = 10;
int motor4pin2 = 11;

void setup() {
// put your setup code here, to run once:
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
  forward();
  stopp();
  backward();
  stopp();
  delay(2500);
  rightSpotTurn();
  stopp();
  delay(5000);
}





void forward(){
  // Vorwärtsfahren
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(2500);
}


void stopp(){
  //Stopp
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, LOW);
  delay(2000);
}


void backward(){
  //Rückwärtsfahren
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(2500);
}

void rightSpotTurn(){
  // Rechts herum auf der Stelle drehen
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  delay(2000);
}

void leftSpotTurn(){
  // Rechts herum auf der Stelle drehen
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  delay(2000);
}
