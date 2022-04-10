// Deklaration und Initialisierung der Eingang-Pins
int JoyStick_X = A0; // X-Achse-Signal
int JoyStick_Y = A1; // Y-Achse-Signal
int Button = 3; // Knopf

void setup ()
{
pinMode (JoyStick_X, INPUT);
pinMode (JoyStick_Y, INPUT);
pinMode (Button, INPUT);

// Da der Knopf das Signal beim druecken auf Masse zieht,
// schalten wir hiermit den PullUp-Widerstand ein
digitalWrite(Button, HIGH);

Serial.begin (9600); // Serielle Ausgabe mit 9600 bps
}

// Das Programm liest die aktuellen Werte der Eingang-Pins
// und gibt diese auf der seriellen Ausgabe aus
void loop ()
{
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
  if(Knopf==1)
  {
    Serial.println ("nicht gedrückt");
  }
    else if (Knopf==0)
  {
   Serial.println ("gedrückt");
  }
  
  if (x <= 0.1)
  {
    Serial.println (" nach LINKS fahren");
  } else if (x >= 4.8)
  {
    Serial.println (" nach RECHTS fahren");
  } else if (y >= 4.8)
  {
    Serial.println (" nach AB GEHT DIE POST!");
  }  else if (y <= 0.1)
  {
    Serial.println (" RÜCKZUG!");
  }
  delay (200);


}
