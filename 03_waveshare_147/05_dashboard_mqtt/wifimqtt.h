
#include <Arduino.h>
#include "globals.h"
#include <WiFi.h>
#include <PubSubClient.h>
#include "credentials.h"
#include <ArduinoJson.h>

// MQTT
String clientId = "esp32c6dashboard";
const char *mqtt_server = "65.21.105.35";
const char *mqtt_user = "";
const char *mqtt_password = "";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_password))
    {
      Serial.println("connected");
      client.subscribe("dashboard/newvalues");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char *topic, byte *message, unsigned int length)
{
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++)
  {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();


  if (String(topic) == "dashboard/newvalues")
  {


    JsonDocument doc;

    DeserializationError error = deserializeJson(doc, messageTemp);

    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }

    const char* temperature = doc["temperature"]; 
    const char* humidity = doc["humidity"]; 
    const char* voltage = doc["voltage"]; 
    const char* date = doc["date"]; 
    const char* time = doc["time"]; 

    mySensorData.update_date = date;
    mySensorData.update_clock = time;
    mySensorData.voltage = atoi(voltage);
    mySensorData.temperature = atoi(temperature);
    mySensorData.humidity = atoi(humidity);

    state = SHOWVALUES;
  }

}

void connectAP()
{

  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid, password);

  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
    cnt++;

    if (cnt > 30)
      ESP.restart();
  }
  Serial.println(WiFi.localIP());
}
