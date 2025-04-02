
#include "credentials.h"
#include "globals.h"
#include <Arduino.h>
#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>

// MQTT
String clientId = "ESP32CYD";
const char *mqtt_server = "65.21.105.35";
const char *mqtt_user = "";
const char *mqtt_password = "";
WiFiClient espClient;
PubSubClient client(espClient);
long lastMsg = 0;
char msg[50];
int value = 0;

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str(), mqtt_user, mqtt_password)) {
      Serial.println("connected");
      client.subscribe("voc/new");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char *topic, byte *message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;

  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  if (String(topic) == "voc/new") {
    Serial.println("MQTT ON");


//     const char *input = R"({
//     "vokabeln": [
//         {"id": 1, "de": "Apfel", "it": "Mela"},
//         {"id": 2, "de": "Haus", "it": "Casa"},
//         {"id": 3, "de": "morgen", "it": "domani"},
//         {"id": 4, "de": "Baum", "it": "Albero"}
//     ]
// })";

//     JsonDocument doc;
//     DeserializationError error = deserializeJson(doc, input);



    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, messageTemp);

    if (error) {
        Serial.print("deserializeJson() failed: ");
        Serial.println(error.c_str());
        return;
    }

// Arrays für die deutschen und italienischen Vokabeln
  JsonArray german_voc = doc["german_voc"].as<JsonArray>();
  JsonArray italian_voc = doc["italian_voc"].as<JsonArray>();


  // Vokabeln aus beiden Arrays auslesen
  for (int i = 0; i < 4; i++) {

    // 1 zeile debug
    String voc_de = german_voc[i]["de"].as<String>();
    Serial.println(voc_de);

    vokabeln_de[i].id = german_voc[i]["id"].as<int>();
    vokabeln_de[i].voc = voc_de;
    
    vokabeln_it[i].id = italian_voc[i]["id"].as<int>();
    vokabeln_it[i].voc = italian_voc[i]["it"].as<String>();
  }
    state = UPDATEBUTTON;
  }
  // } else if (String(topic) == "office/light/off") {
  //   Serial.println("MQTT OFF");
  // }
}

void connectAP() {

  Serial.println("Connecting to WiFi..");
  WiFi.begin(ssid, password);

  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
    cnt++;

    if (cnt > 30)
      ESP.restart();
  }
  Serial.println(WiFi.localIP());
}