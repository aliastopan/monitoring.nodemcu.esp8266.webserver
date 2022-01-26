#ifndef RESTAPI
#define RESTAPI

#include <LittleFS.h>
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

        static String Processor(const String& var)
        {
            if(var == "HUMIDITY"){
                return String(humidity);
            }
            return String();
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
                request->send(LittleFS, "/index.html", String(), false, Processor);
            });

            server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request){
                request->send(LittleFS, "/styles.css","text/css");
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