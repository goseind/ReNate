/* 
  Sketch generated by the Arduino IoT Cloud Thing "ReNate"
  https://create.arduino.cc/cloud/things/c2865a75-bdd7-4c38-be34-253a99ba873e 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float ph_value_sval;
  float soil_moisture_sval;
  float temp_sval;
  CloudRelativeHumidity humididy;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"

const int dry = 4; // value for dry sensor
const int wet = 1; // value for wet sensor

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  // Moisture Sensor Data Collection
  soil_moisture_sval = analogRead(A0); // Read value from sensor pin
  // Serial.println(soil_moisture);
 
  humididy = map(soil_moisture_sval, wet, dry, 100, 0); 

  // Serial.print(humididy);
  // Serial.println("%");
  
  // Temp Sensor Data
  temp_sval = analogRead(A1);
  temp_sval = temp_sval * 0.48828125;
  
  //PH Sensor Data
  ph_value_sval = analogRead(A2);
  delay(1000);
  }

/*
  Since PhValue is READ_WRITE variable, onPhValueChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPhValueChange()  {
  // Add your code here to act upon PhValue change
}

/*
  Since SoilMoisture is READ_WRITE variable, onSoilMoistureChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSoilMoistureChange()  {
  // Add your code here to act upon SoilMoisture change
}

/*
  Since SoilMoistureSval is READ_WRITE variable, onSoilMoistureSvalChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onSoilMoistureSvalChange()  {
  // Add your code here to act upon SoilMoistureSval change
}

/*
  Since PhValueSval is READ_WRITE variable, onPhValueSvalChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onPhValueSvalChange()  {
  // Add your code here to act upon PhValueSval change
}

/*
  Since Humididy is READ_WRITE variable, onHumididyChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onHumididyChange()  {
  // Add your code here to act upon Humididy change
}

/*
  Since TempSval is READ_WRITE variable, onTempSvalChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onTempSvalChange()  {
  // Add your code here to act upon TempSval change
}