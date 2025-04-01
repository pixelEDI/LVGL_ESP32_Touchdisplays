//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
#include <ArduinoJson.h>  // benoit blanchon
#include "wifi.h"
#include "globals.h"

static void btn_event_handler(lv_event_t *e) {
  lv_obj_t *clickedbtn = (lv_obj_t *)lv_event_get_target(e);
  int btn_id = (int)lv_obj_get_user_data(clickedbtn);
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED) {
    Serial.print("Button ID: ");
    Serial.println(btn_id);

    if (firstButtonID == -1) {
      firstButtonID = btn_id;
      btn1 = (lv_obj_t *)lv_event_get_target(e);
      Serial.println("Erste Vokabel wurde geklickt");
    } else if (secondButtonID == -1) {
      secondButtonID = btn_id;
      btn2 = (lv_obj_t *)lv_event_get_target(e);
      Serial.println("Zweite Vokabel wurde geklickt");

      if (firstButtonID == secondButtonID) {
        Serial.println("Die IDs stimmen überein");
        lv_obj_del(btn1);
        lv_obj_del(btn2);
      } else {
        Serial.println("Die IDS stimmen nicht");
        lv_obj_remove_state(btn1, LV_STATE_CHECKED);
        lv_obj_remove_state(btn2, LV_STATE_CHECKED);
      }

      firstButtonID = -1;
      secondButtonID = -1;
    }
  }
}

void lv_create_buttons() {

  // JSON-Daten mit Vokabeln in Deutsch und Italienisch
  const char *input = R"({
      "vokabeln": [
        {"id": 1, "de": "Apfel", "it": "Mela"},
        {"id": 2, "de": "Haus", "it": "Casa"},
        {"id": 3, "de": "morgen", "it": "domani"},
        {"id": 4, "de": "Baum", "it": "Albero"}
      ]
  })";

  JsonDocument doc;
  DeserializationError error = deserializeJson(doc, input);

  if (error) {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.c_str());
    return;
  }

  JsonArray vokabeln = doc["vokabeln"].as<JsonArray>();

  for (int i = 0; i < 4; i++) {
    lv_obj_t *btn = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 10, 10 + i * 60);
    lv_obj_set_height(btn, LV_SIZE_CONTENT);
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_t *label = lv_label_create(btn);
    String buttonText = String(vokabeln[i]["de"].as<const char *>());
    lv_label_set_text(label, buttonText.c_str());
    lv_obj_center(label);
    lv_obj_set_user_data(btn, (void *)vokabeln[i]["id"].as<int>());
  }

  for (int i = 0; i < 4; i++) {
    lv_obj_t *btn_r = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn_r, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn_r, LV_ALIGN_TOP_RIGHT, -10, 10 + i * 60);
    lv_obj_set_height(btn_r, LV_SIZE_CONTENT);
    lv_obj_set_style_bg_color(btn_r, lv_color_hex(0x4CAF50), LV_PART_MAIN);
    lv_obj_add_flag(btn_r, LV_OBJ_FLAG_CHECKABLE);

    lv_obj_t *label_r = lv_label_create(btn_r);
    String buttonText_r = String(vokabeln[i]["it"].as<const char *>());
    lv_label_set_text(label_r, buttonText_r.c_str());
    lv_obj_center(label_r);
    lv_obj_set_user_data(btn_r, (void *)vokabeln[i]["id"].as<int>());
  }
}

void setup() {
  touchscreen_setup();

  lv_create_buttons();

  connectAP();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  client.setBufferSize(1024);

  state=GETNEWDATA;
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if (!client.loop())
    client.connect("ESP32CYD");


  switch (state) {
    case GETNEWDATA:
      // MQTT PING
      Serial.println("GETNEWDATA");
      client.publish("voc/generate", "get new vocabulary");
      state = WAIT;
      break;
    case UPDATEBUTTON:
      break;
    case SHOWDATA:
      break;
    case WAIT:
      // just chillin
      break;
  }


  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
