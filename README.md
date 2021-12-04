# ESP8266IFTTTWebhook - ESP8266 library
Library for ESP8266 to use [IFTTT](https://ifttt.com) Webhooks.

**This library was created as a hobby by a non-professional programmer. There is no guarantee that everything works correctly.**

## Installation
Download code and include it as a new library into Arduino IDE selecting: *Sketch / include Library / Add .Zip library* . 

You also have to create [IFTTT](https://ifttt.com) account and webhook event ("this" -> Webhook).

## How to use

1. Include ESP8266IFTTTWebhook library in your project:
```cpp
#include <ESP8266IFTTTWebhook.h>
```
### 

2. Instantiate an `ESP8266IFTTTWebhook` object using the event name and your API key:
```cpp
WiFiClient client;
ESP8266IFTTTWebhook ifttt (WEBHOOK_NAME, API_KEY, client);
```
*You can get your API key by going to https://ifttt.com/maker_webhooks and clicking the Documentation button.

3. Trigger the webhook calling `trigger` function with 0 to 3 String values:
```cpp
ifttt.trigger();
ifttt.trigger("value1");
ifttt.trigger("value1", "value2");
ifttt.trigger("value1", "value2", "value3");
```

