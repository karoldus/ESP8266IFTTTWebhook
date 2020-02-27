#include <ESP8266HTTPClient.h>
#include "Arduino.h"
#include "ESP8266IFTTTWebhook.h"

ESP8266IFTTTWebhook::ESP8266IFTTTWebhook (String EVENT_NAME, String API_KEY)
{
	_EVENT_NAME = EVENT_NAME;
	_API_KEY = API_KEY;
}




void ESP8266IFTTTWebhook::trigger()
{
  trigger("", "", "");
}

void ESP8266IFTTTWebhook::trigger(String value1)
{
  trigger(value1, "", "");
}

void ESP8266IFTTTWebhook::trigger(String value1, String value2)
{
  trigger(value1, value2, "");
}

void ESP8266IFTTTWebhook::trigger(String value1, String value2, String value3)
{
	HTTPClient http;

    http.begin("http://maker.ifttt.com/trigger/" + _EVENT_NAME + "/with/key/" + _API_KEY);
    http.addHeader("Content-Type", "application/json");
	
	String values = "{\"value1\":\"" + value1 + "\", \"value2\":\"" + value2 + "\", \"value3\":\"" + value3 + "\"}";
	
    int httpCode = http.POST(values);

    http.end();
}