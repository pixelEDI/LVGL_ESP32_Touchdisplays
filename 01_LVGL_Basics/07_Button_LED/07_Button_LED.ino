//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
const byte CYD_LED_RED=4;
const byte CYD_LED_BLUE=17;

void lv_button_gui(void) {
  lv_obj_t * button = lv_button_create(lv_screen_active());
  lv_obj_align(button, LV_ALIGN_CENTER, 0, -40);
  lv_obj_add_flag(button, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(button, LV_SIZE_CONTENT);
  lv_obj_t * button_label = lv_label_create(button);
  lv_label_set_text(button_label, "Led ein");
  lv_obj_center(button_label);
  lv_obj_add_event_cb(button, button_event_handler, LV_EVENT_ALL, button_label);
  
  lv_obj_t * toggle_switch = lv_switch_create(lv_screen_active());
  lv_obj_add_event_cb(toggle_switch, toggle_switch_event_handler, LV_EVENT_ALL, NULL);
  lv_obj_add_flag(toggle_switch, LV_OBJ_FLAG_EVENT_BUBBLE);
  lv_obj_align(toggle_switch, LV_ALIGN_CENTER, 0, 40);

} 

static void button_event_handler(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * button = (lv_obj_t*) lv_event_get_target(e);
  lv_obj_t * button_label = (lv_obj_t*) lv_event_get_user_data(e);
  if(code == LV_EVENT_VALUE_CHANGED) {
    bool is_checked = lv_obj_has_state(button, LV_STATE_CHECKED);
    const char *state_text = is_checked ? "ein" : "aus";
    lv_label_set_text_fmt(button_label, "LED %s", state_text);

    digitalWrite(CYD_LED_RED, !lv_obj_has_state(button, LV_STATE_CHECKED));
  }
}

static void toggle_switch_event_handler(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * toggle_switch = (lv_obj_t*) lv_event_get_target(e);
  if(code == LV_EVENT_VALUE_CHANGED) {
 
    digitalWrite(CYD_LED_BLUE, !lv_obj_has_state(toggle_switch, LV_STATE_CHECKED));
  }
}

void setup() {
  touchscreen_setup();
  pinMode(CYD_LED_RED, OUTPUT);
  pinMode(CYD_LED_BLUE, OUTPUT);
  digitalWrite(CYD_LED_RED, HIGH);
  digitalWrite(CYD_LED_BLUE, HIGH);
  lv_button_gui();
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);           
}

