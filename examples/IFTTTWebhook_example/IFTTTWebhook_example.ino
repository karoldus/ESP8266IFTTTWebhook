#include <ESP8266IFTTTWebhook.h>
#include <ESP8266WiFi.h>


/////////////////////////////////////////////////
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";
const char* API_KEY = "YOUR_KEY";
const char* WEBHOOK_NAME = "YOUR_EVENT_NAME";
////////////////////////////////////////////////


//button -> GPIO4
#define BUTTON_PIN 4
int current = 0;
int last = 0;

//Create ifttt object
ESP8266IFTTTWebhook ifttt (WEBHOOK_NAME, API_KEY);

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  
  wifiConnect(); 
}

void loop() {

  if(digitalRead(BUTTON_PIN) == LOW)
    current = 1;
  else
    current = 0;

  if(current != last){
    last = current;
    if (current == 1)
      {
        ifttt.trigger("1","a","Something"); //3 values
        delay(5000);
        ifttt.trigger("1"); //1 value
      }     
      
  }
}

void wifiConnect(){
  Serial.print("connecting to ");
  Serial.println(ssid);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}
