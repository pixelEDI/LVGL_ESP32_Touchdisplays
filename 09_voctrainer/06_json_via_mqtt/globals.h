#include <Arduino.h>
#ifndef GLOBALS_
#define GLOBALS_

unsigned long previousMillis = millis();

int firstButtonID = -1;  // -1 bedeutet, dass noch kein Button geklickt wurde
int secondButtonID = -1; // -1 bedeutet, dass noch kein Button geklickt wurde
int correct_counter = 0;

lv_obj_t* btn1;
lv_obj_t* btn2;
lv_obj_t* buttons_de[4];
lv_obj_t* buttons_it[4];
lv_obj_t* labels_de[4];
lv_obj_t* labels_it[4];


struct Vokabel {
  int id;
  String voc;
};

Vokabel vokabeln_de[4];
Vokabel vokabeln_it[4];

// // JsonArray vokabeln;
//   const char* input = R"({
//     "vokabeln": [
//         {"id": 1, "de": "Apfel", "it": "Mela"},
//         {"id": 2, "de": "Haus", "it": "Casa"},
//         {"id": 3, "de": "morgen", "it": "domani"},
//         {"id": 4, "de": "Baum", "it": "Albero"}
//     ]
// })";
// JsonDocument doc;
// DeserializationError error = deserializeJson(doc, input);
// JsonArray vokabeln = doc["vokabeln"].as<JsonArray>();



enum states {
  GETNEWDATA,
  UPDATEBUTTON,
  SHOWDATA,
  WAIT
} state;



#endif