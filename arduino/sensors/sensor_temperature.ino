// Temperatur
int sensorPin = A0;

double Thermistor(int RawADC)
{
    double Temp;
    Temp = log(10000.0 * ((1024.0 / RawADC - 1)));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp )) * Temp );
    Temp = Temp - 273.15;            // Konvertierung von Kelvin in Celsius
    return Temp;
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int readVal = analogRead(sensorPin);
  double temp =  Thermistor(readVal);

  // Ausgabe auf die serielle Schnittstelle
  Serial.print("Aktuelle Temperatur ist:");
  Serial.print(temp); 
      Serial.print(char(186)); //Ausgabe <°> Symbol
  Serial.println("C");
  Serial.println("---------------------------------------");

  delay(500);
}
