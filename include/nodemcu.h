#ifndef NODEMCU
#define NODEMCU




#define S0 D0
#define S1 D1
#define S2 D2
#define S3 D3
#define SIG A0


int rawValue1 = 0;

class Board
{
    private:
        static void Ch0()
        {
            digitalWrite(S0, LOW);
            digitalWrite(S1, LOW);
            digitalWrite(S2, LOW);
            digitalWrite(S3, LOW);

        }

        static int Ch1()
        {
            digitalWrite(S0, HIGH);
            digitalWrite(S1, LOW);
            digitalWrite(S2, LOW);
            digitalWrite(S3, LOW);

            return digitalRead(SIG);

        }

        static int Ch2()
        {
            digitalWrite(S0, LOW);
            digitalWrite(S1, HIGH);
            digitalWrite(S2, LOW);
            digitalWrite(S3, LOW);

            return digitalRead(SIG);
        }

    public:
        static void Setup()
        {
            Serial.begin(115200);

            pinMode(SIG, INPUT);

            pinMode(S0, OUTPUT);
            pinMode(S1, OUTPUT);
            pinMode(S2, OUTPUT);
            pinMode(S3, OUTPUT);

        }

        static void Loop()
        {
            rawValue1 = Ch1();
            Serial.print("sensor 1: ");
            Serial.println(rawValue1);
            delay(1000);


            // rawValue1 = analogRead(SIG);
            // Serial.print("sensor 1: ");
            // Serial.println(rawValue1);
            // delay(1000);


        }
};


#endif