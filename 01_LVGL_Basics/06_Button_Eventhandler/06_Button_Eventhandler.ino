//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"

void lv_button_gui(void) {
  lv_obj_t * button = lv_button_create(lv_screen_active());    
  lv_obj_set_size(button, 120, 50);     
  lv_obj_align(button, LV_ALIGN_CENTER, 0, 0);

  lv_obj_t * button_label = lv_label_create(button);     
  lv_label_set_text(button_label, "10x klicken");    
  lv_obj_center(button_label);

  lv_obj_t * text_label_counter = lv_label_create(lv_screen_active());
  lv_label_set_text(text_label_counter, "Wie oft geklickt: 0");
  lv_obj_align(text_label_counter, LV_ALIGN_BOTTOM_MID, 0, -20);

  lv_obj_add_event_cb(button, button_event_cb, LV_EVENT_ALL, text_label_counter);  
} 

static void button_event_cb(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * button = (lv_obj_t*) lv_event_get_target(e);
  lv_obj_t * label = (lv_obj_t*) lv_event_get_user_data(e);
  if(code == LV_EVENT_CLICKED) {
    static uint8_t counter = 0;
    counter++;
    if(counter>=10) {
        lv_label_set_text_fmt(label, "Boom!", counter);
    }
    else {
      lv_label_set_text_fmt(label, "Counter: %d", counter);
    }
  }
}

void setup() {
  touchscreen_setup();
  lv_button_gui();
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);           
}

