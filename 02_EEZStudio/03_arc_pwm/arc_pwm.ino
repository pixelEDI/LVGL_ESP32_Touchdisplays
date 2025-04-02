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
#define CYD_LED_RED 4

static void arc_dimmer_event(lv_event_t *e){
  lv_event_code_t code = lv_event_get_code(e);
  // lv_obj_t *arc = (lv_obj_t)lv_event_get_target(e);

  if(code==LV_EVENT_VALUE_CHANGED){
    int brightness = lv_arc_get_value(objects.arc);
    int brightness_mapped = map(brightness, 0,100,0,255);
    int inverted_mapped = 255 - brightness;

    analogWrite(CYD_LED_RED, inverted_mapped);
    Serial.println(brightness);

    lv_label_set_text_fmt(objects.lbl1, "%d",brightness_mapped);
    lv_obj_set_style_bg_opa(objects.led1, brightness_mapped, LV_PART_MAIN | LV_STATE_DEFAULT);

  }
}

void setup() {
  touchscreen_setup();
  pinMode(CYD_LED_RED, OUTPUT);
  ui_init();
  analogWrite(CYD_LED_RED, 255);

  lv_obj_add_event_cb(objects.arc, arc_dimmer_event, LV_EVENT_VALUE_CHANGED, NULL);
}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
