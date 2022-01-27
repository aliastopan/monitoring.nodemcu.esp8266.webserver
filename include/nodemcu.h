#ifndef NODEMCU
#define NODEMCU
#include<MUX74HC4067.h>

#define S0 D0
#define S1 D1
#define S2 D2
#define S3 D3
#define EN D4
#define SIG A0

MUX74HC4067 mux(D4, D0, D1, D2, D3);

int rawValue1 = 0;
int rawValue2 = 0;

class Board
{
    public:
        static void Setup()
        {
            Serial.begin(115200);

            mux.signalPin(SIG, INPUT, ANALOG);


        }

        static void Loop()
        {
            rawValue1 = mux.read(1);
            rawValue2 = mux.read(2);

            Serial.print("ch.1: ");
            Serial.print(rawValue1);
            Serial.print(" | ");
            Serial.print("ch.2: ");
            Serial.print(rawValue2);
            Serial.print("\n");
            delay(1000);


        }
};


#endif