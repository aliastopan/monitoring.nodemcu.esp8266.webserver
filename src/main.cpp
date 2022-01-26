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
	API::Loop();
}