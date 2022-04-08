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
// put your main code here, to run repeatedly:
digitalWrite(motor1pin1, HIGH);
digitalWrite(motor1pin2, LOW);

 

 

digitalWrite(motor2pin1, HIGH);
digitalWrite(motor2pin2, LOW);
delay(1000);

 

 

digitalWrite(motor1pin1, LOW);
digitalWrite(motor1pin2, HIGH);

 

 

digitalWrite(motor2pin1, LOW);
digitalWrite(motor2pin2, HIGH);
delay(1000);

 

digitalWrite(motor3pin1, HIGH);
digitalWrite(motor3pin2, LOW);

 

 

digitalWrite(motor4pin1, HIGH);
digitalWrite(motor4pin2, LOW);
delay(1000);

 

digitalWrite(motor3pin1, LOW);
digitalWrite(motor3pin2, HIGH);

 

 

digitalWrite(motor4pin1, LOW);
digitalWrite(motor4pin2, HIGH);
delay(1000);

 


}
