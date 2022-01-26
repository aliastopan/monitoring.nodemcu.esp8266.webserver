#ifndef BOARD
#define BOARD

#define RELAY_PIN D8
#define SOILMOISTURE_PIN A0

int rawValue = 0;
int dryValue = 1023;
int wetValue = 302;
int percentageValue = 50;
int percentageDryValue = 0;
int percentageWetValue = 100;


class Board
{
    public:
    static void Setup()
    {
        Serial.begin(115200);
        while (!Serial);

        pinMode(RELAY_PIN, OUTPUT);
	    pinMode(SOILMOISTURE_PIN, INPUT);
    }

    static void Loop()
    {
        rawValue = analogRead(SOILMOISTURE_PIN);
        percentageValue = map(rawValue, dryValue, wetValue, percentageDryValue, percentageWetValue);
        delay(1000);
  	    Serial.println("Bleh");

    }

};




#endif