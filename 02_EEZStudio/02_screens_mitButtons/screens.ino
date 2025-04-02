//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
#include "ui.h"

void button_click_toscreen2(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);

  if(code== LV_EVENT_CLICKED){
    loadScreen(SCREEN_ID_SCREEN2);
  }
}

void button_click_toscreen1(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);

  if(code== LV_EVENT_CLICKED){
    loadScreen(SCREEN_ID_MAIN);
  }
}

void setup() {
  touchscreen_setup();

  ui_init();

  lv_obj_add_event_cb(objects.btn1, button_click_toscreen2, LV_EVENT_ALL, NULL);
  lv_obj_add_event_cb(objects.btn2_2, button_click_toscreen1, LV_EVENT_ALL, NULL);

}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
