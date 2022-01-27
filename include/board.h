#ifndef BOARD
#define BOARD

#define RELAY_PIN D8
#define ANALOG_PIN A0

#define ABSOLUTE_LOW D0
#define ABSOLUTE_HIGH D1

#define SENSOR_1_PIN D2
#define SENSOR_2_PIN D3




int rawValue = 0;
int dryValue = 1023;
// int wetValue = 0;
int wetValue = 302;
int percentageValue = 0;
int percentageDryValue = 0;
int percentageWetValue = 100;

int rawValue1 = 0;
int rawValue2 = 0;
int percentageValue1 = 0;
int percentageValue2 = 0;

class Board
{
    private:
    static int ReadAnalog1()
    {
        digitalWrite(SENSOR_1_PIN, HIGH);
        digitalWrite(SENSOR_2_PIN, LOW);
        return analogRead(0);
    }

    static int ReadAnalog2()
    {
        digitalWrite(SENSOR_1_PIN, LOW);
        digitalWrite(SENSOR_2_PIN, HIGH);
        return analogRead(0);
    }

    public:
    static void Setup()
    {
        Serial.begin(115200);
        while (!Serial);

        // pinMode(RELAY_PIN, OUTPUT);
	    pinMode(ANALOG_PIN, INPUT);

        pinMode(ABSOLUTE_LOW, OUTPUT);
        pinMode(ABSOLUTE_HIGH, OUTPUT);

	    pinMode(SENSOR_1_PIN, OUTPUT);
	    pinMode(SENSOR_2_PIN, OUTPUT);

    }

    static void Loop()
    {
        digitalWrite(ABSOLUTE_LOW, LOW);
        digitalWrite(ABSOLUTE_HIGH, HIGH);

        rawValue1 = ReadAnalog1();
        delay(1000);
        rawValue2 = ReadAnalog2();
        delay(1000);

        Serial.print("sensor 1 = ");
        Serial.print(rawValue1);
        Serial.print(" / sensor 2 = ");
        Serial.println(rawValue2);


    }

};


#endif