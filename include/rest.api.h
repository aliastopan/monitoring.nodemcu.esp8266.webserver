#ifndef RESTAPI
#define RESTAPI

#include <LittleFS.h>
#include <server.config.h>
#include <webserver.h>

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
            if(!LittleFS.begin())
            {
                Serial.println("failed to mount flash file system");
                return;
            }

            server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/index.html", String(), false);
            });

            server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/styles.css","text/css");
            });

            server.onNotFound(NotFound);
            server.begin();
        }


};



#endif