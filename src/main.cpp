#include <Arduino.h>
#include <board.h>
#include <rest.api.h>

void setup()
{
	Board::Setup();

	API::Setup();
	API::Start();

}

void loop()
{
	Board::Loop();

	API::DTO(percentageValue);

	// int rawValue = analogRead(RAIN_PIN);
	// int friendlyValue = map(rawValue, dryValue, wetValue, friendlyDryValue, friendlyWetValue);

	// Serial.print("Raw: ");
	// Serial.print(rawValue);
	// Serial.print(" | ");

	// Serial.print("Friendly: ");
  	// Serial.print(friendlyValue);
  	// Serial.println("%");



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