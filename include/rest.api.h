#ifndef RESTAPI
#define RESTAPI

#include <server.config.h>
#include <webserver.h>

char* _data;

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
                request->send(200, "text/json", _data);
            });

            server.onNotFound(NotFound);
            server.begin();
        }

        static void DTO(char* json)
        {
            _data = json;
        }

};

#endif