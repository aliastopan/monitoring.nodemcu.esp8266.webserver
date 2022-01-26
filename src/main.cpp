#include <Arduino.h>
#include <board.h>
#include <rest.api.h>

void setup()
{
	Board::Setup();

	API::Setup();
	API::Start();

}

char* _json = (char*)"{\"data\": \"33\"}";

void loop()
{
	Board::Loop();

	API::DTO(_json);
}