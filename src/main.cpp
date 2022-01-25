#include <Arduino.h>
#include <rest.api.h>

void setup()
{
	Serial.begin(115200);
	while (!Serial);

	API::Setup();
	API::Start();

}

void loop() {

}