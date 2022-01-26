#ifndef RESTAPI
#define RESTAPI

#include <server.config.h>
#include <webserver.h>

int humidity = 0;

class API
{
    private:
        static void NotFound(AsyncWebServerRequest *request)
        {
            request->send(404, "text/plain", "not found");
        }

    public:

        static void Setup()
        {
            WebServer::Setup();
        }

        static void Start()
        {
            server.on("/get", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(200, "text/json", "{\"data\": \"42\"}");
            });

            server.onNotFound(NotFound);
            server.begin();
        }

        static void DTO(int humidityValue)
        {
            humidity = humidityValue;
        }

};

#endif