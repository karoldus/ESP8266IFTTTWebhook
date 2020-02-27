#ifndef ESP8266IFTTTWebhook_h
#define ESP8266IFTTTWebhook_h

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class ESP8266IFTTTWebhook
{
	public:
	ESP8266IFTTTWebhook (String EVENT_NAME, String API_KEY);
    void trigger();
	void trigger(String value1);
	void trigger(String value1, String value2);
    void trigger(String value1, String value2, String value3);
	
	private:
	String _EVENT_NAME;
	String _API_KEY;
};


#endif