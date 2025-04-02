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

void update_buttons() {
    for (int i = 0; i < 4; i++) {
      String newTextde = vokabeln_de[i].voc;
      lv_label_set_text(labels_de[i], newTextde.c_str());
      lv_obj_set_style_bg_color(buttons_de[i], lv_color_hex(0xeffc171), LV_PART_MAIN);
      lv_obj_set_user_data(buttons_de[i], (void*)vokabeln_de[i].id);  
    
      String newTextit = vokabeln_it[i].voc;
      lv_label_set_text(labels_it[i], newTextit.c_str());
      lv_obj_set_style_bg_color(buttons_it[i], lv_color_hex(0xd793df), LV_PART_MAIN);
      lv_obj_set_user_data(buttons_it[i], (void*)vokabeln_it[i].id);  
    }
}

static void btn_event_handler(lv_event_t *e) {
   lv_obj_t* btn = (lv_obj_t*)lv_event_get_target(e);
  int btn_id = (int)lv_obj_get_user_data(btn);  // ID des Buttons
  lv_event_code_t code = lv_event_get_code(e);

  // Nur fortfahren, wenn der Button "losgelassen" wurde (also wirklich geklickt wurde)
  if (code == LV_EVENT_CLICKED) {
    Serial.print("Button ID: ");
    Serial.println(btn_id);

    // Überprüfen, ob der erste Button noch nicht gesetzt wurde
    if (firstButtonID == -1) {
      firstButtonID = btn_id;
      btn1 = (lv_obj_t*)lv_event_get_target(e);
      Serial.println("Erster Button ausgewählt");
    }
    // Überprüfen, ob der zweite Button geklickt wurde
    else if (secondButtonID == -1) {
      secondButtonID = btn_id;
      btn2 = (lv_obj_t*)lv_event_get_target(e);
      Serial.println("Zweiter Button ausgewählt");

      // Überprüfen, ob die IDs gleich sind
      if (firstButtonID == secondButtonID) {
        Serial.println("Die IDs sind gleich!");

        //globale variablen
        // lv_obj_del(btn1);
        // lv_obj_del(btn2);
        lv_obj_remove_state(btn1, LV_STATE_CHECKED);
        lv_obj_remove_state(btn2, LV_STATE_CHECKED);
        lv_obj_set_style_bg_color(btn1, lv_color_hex(0x33FF57), LV_PART_MAIN);
        lv_obj_set_style_bg_color(btn2, lv_color_hex(0x33FF57), LV_PART_MAIN);
        correct_counter ++;

        if(correct_counter >= 4){
          correct_counter = 0;
          state = GETNEWDATA;
        }

      } else {
        Serial.println("Die IDs sind unterschiedlich.");
        lv_obj_remove_state(btn1, LV_STATE_CHECKED);
        lv_obj_remove_state(btn2, LV_STATE_CHECKED);
      }

      // Zurücksetzen der Button-IDs für den nächsten Vergleich
      firstButtonID = -1;
      secondButtonID = -1;
    }
  }
}

void lv_create_buttons() {

  lv_obj_t* label;

  //  lv_obj_clean(lv_scr_act());

  // Erstelle 4 Buttons auf der linken Seite mit den Vokabeln
  for (int i = 0; i < 4; i++) {
    lv_obj_t* btn = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 10, 10 + i * 60);  // Weniger Abstand oben und vertikale Position
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn, LV_SIZE_CONTENT);

    lv_obj_set_style_bg_color(btn, lv_color_hex(0xffc171), LV_PART_MAIN);

    // Text für den Button setzen (Deutsch)
    String buttonText = vokabeln_de[i].voc;
    labels_de[i] = lv_label_create(btn);


    lv_label_set_text(labels_de[i], buttonText.c_str());
    lv_obj_center(labels_de[i]);
    // ID als user_data hinzufügen
    lv_obj_set_user_data(btn, (void*)vokabeln_de[i].id);
    buttons_de[i] = btn;
  }

  // Erstelle 4 Buttons auf der rechten Seite mit italienischen Vokabeln
  for (int i = 0; i < 4; i++) {
    lv_obj_t* btn = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_RIGHT, -10, 10 + i * 60);  // Weniger Abstand oben und vertikale Position
    lv_obj_add_flag(btn, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_height(btn, LV_SIZE_CONTENT);


    lv_obj_set_style_bg_color(btn, lv_color_hex(0xd793df), LV_PART_MAIN);

    // Text für den Button setzen (Italienisch)
    String buttonText = vokabeln_it[i].voc;
    labels_it[i] = lv_label_create(btn);

    lv_label_set_text(labels_it[i], buttonText.c_str());
    lv_obj_center(labels_it[i]);
    // ID als user_data hinzufügen
    lv_obj_set_user_data(btn, (void*)vokabeln_it[i].id);
    buttons_it[i] = btn;
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
      Serial.println("GETNEWDATA");
      client.publish("voc/generate", "get new vocabulary");
      state = WAIT;
      break;
    case UPDATEBUTTON:
      Serial.println("UPDATEBUTTON");
      update_buttons();
      state = WAIT;
      break;
    case SHOWDATA:
      Serial.println("SHOWDATA");
      // lv_obj_clean(lv_screen_active());
      lv_create_buttons();
      state = WAIT;
      break;

    case WAIT:
      break;
  }

  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
