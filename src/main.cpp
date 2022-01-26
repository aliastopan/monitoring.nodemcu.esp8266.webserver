#include <Arduino.h>
#include <rest.api.h>

#define RELAY D8
#define RAIN_PIN A0
float sensorValue = 0;

int dryValue = 1023;
int wetValue = 302;
int friendlyDryValue = 0;
int friendlyWetValue = 100;

void setup()
{
	Serial.begin(115200);
	while (!Serial);

	pinMode(RAIN_PIN, INPUT);

	// pinMode(RELAY, OUTPUT);

	// API::Setup();
	// API::Start();

}

void loop()
{
	int rawValue = analogRead(RAIN_PIN);
	int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);

	Serial.print("Raw: ");
	Serial.print(rawValue);
	Serial.print(" | ");

	Serial.print("Friendly: ");
  	Serial.print(friendlyValue);
  	Serial.println("%");
	// sensorValue = 100 - ((analogRead(RAIN_PIN)/1024) * 100);
	// sensorValue = analogRead(RAIN_PIN);
  	// sensorValue = map(sensorValue,550,10,0,100);
  	// sensorValue = map(sensorValue,1024,0,0,100);

	// delay(1000);
    // Serial.print("SENSOR VALUE: ");
    // Serial.print(sensorValue);
    // Serial.println("%");

	// delay(1000);
	// digitalWrite(RELAY, LOW);
	// delay(1000);
	// digitalWrite(RELAY, HIGH);
    // Serial.println("Bleh.");

}