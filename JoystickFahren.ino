// Deklaration und Initialisierung der Eingang-Pins
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;
int motor3pin1 = 8;
int motor3pin2 = 9;
int motor4pin1 = 10;
int motor4pin2 = 11;
int JoyStick_X = A0; // X-Achse-Signal
int JoyStick_Y = A1; // Y-Achse-Signal
int Button = 13; // Knopf


void setup() {
// Motor
pinMode(motor1pin1, OUTPUT);
pinMode(motor1pin2, OUTPUT);
pinMode(motor2pin1, OUTPUT);
pinMode(motor2pin2, OUTPUT);
pinMode(motor3pin1, OUTPUT);
pinMode(motor3pin2, OUTPUT);
pinMode(motor4pin1, OUTPUT);
pinMode(motor4pin2, OUTPUT);

//Joystick
pinMode (JoyStick_X, INPUT);
pinMode (JoyStick_Y, INPUT);
pinMode (Button, INPUT);

// Da der Knopf das Signal beim druecken auf Masse zieht,
// schalten wir hiermit den PullUp-Widerstand ein
digitalWrite(Button, HIGH);

Serial.begin (9600); // Serielle Ausgabe mit 9600 bps
}



void loop() {
 //forward();
 //stopp();
 // backward();
 // stopp();
 // delay(2500);
 // rightSpotTurn();
 // stopp();
 // delay(5000);

  float x, y;
  int Knopf;
  int JoyStick_XTest;
  
  //Aktuelle Werte werden ausgelesen, auf den Spannungswert konvertiert...
  x = analogRead (JoyStick_X) * (5.0 / 1023.0);
  y = analogRead (JoyStick_Y) * (5.0 / 1023.0);
  Knopf = digitalRead (Button);
  //JoyStick_XTest = digitalRead (JoyStick_X);
  
  //... und an dieser Stelle ausgegeben
  Serial.print ("X-Achse:"); Serial.print (x, 4); Serial.print ("V, ");
  Serial.print ("Y-Achse:"); Serial.print (y, 4); Serial.print ("V, ");
  Serial.print ("Knopf:");
  
  //links: X:0.00 Y:2.5
  //recht: X:5.00 Y:2.5
  //vorwärts: X:2.5 Y:5.00
  //rückwärts: X:2.5 Y:0.00 
  if(Knopf==0)
  {
    Serial.println ("gedrückt");
    forward();
  }
   else if (Knopf==1)
  {
    Serial.println ("nicht gedrückt");
    stopp();
  }


if (y >= 4.8)
  {
    Serial.println (" Vorwärts fahren!");
    forward();
  }  else if (y <= 0.1)
  {
    Serial.println (" Rückwärts fahren!");
    backward();
  }  else if (x <= 0.1)
  {
    Serial.println (" nach LINKS fahren");
    leftSpotTurn();
  } else if (x >= 4.8)
  {
    Serial.println (" nach RECHTS fahren");
    rightSpotTurn();
  }
  
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
  //delay(1000);
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
  //delay(1000);
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
  //delay(1000);
}

void leftSpotTurn(){
  // Rechts herum auf der Stelle drehen
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  
  digitalWrite(motor3pin1, LOW);
  digitalWrite(motor3pin2, HIGH);
  
  digitalWrite(motor4pin1, HIGH);
  digitalWrite(motor4pin2, LOW);
  //delay(2000);
}

void rightSpotTurn(){
  // Rechts herum auf der Stelle drehen
  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  
  digitalWrite(motor3pin1, HIGH);
  digitalWrite(motor3pin2, LOW);
  
  digitalWrite(motor4pin1, LOW);
  digitalWrite(motor4pin2, HIGH);
  //delay(2000);
}
