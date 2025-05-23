//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"

static void btn_event_handler(lv_event_t *e) {
  // todo
}

void lv_create_buttons() {

  for (int i = 0; i < 4; i++) {
    lv_obj_t *btn = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn, LV_ALIGN_TOP_LEFT, 10, 10 + i*60);
    lv_obj_set_height(btn, LV_SIZE_CONTENT);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Button left");
    lv_obj_center(label);
  }

  for (int i = 0; i < 4; i++) {
    lv_obj_t *btn_r = lv_button_create(lv_screen_active());
    lv_obj_add_event_cb(btn_r, btn_event_handler, LV_EVENT_ALL, NULL);
    lv_obj_align(btn_r, LV_ALIGN_TOP_RIGHT, -10, 10 + i*60);
    lv_obj_set_height(btn_r, LV_SIZE_CONTENT);
    lv_obj_set_style_bg_color(btn_r, lv_color_hex(0x4CAF50), LV_PART_MAIN);

    lv_obj_t *label_r = lv_label_create(btn_r);
    lv_label_set_text(label_r, "Button right");
    lv_obj_center(label_r);
  }
}

void setup() {
  touchscreen_setup();

  lv_create_buttons();
}

void loop() {
  lv_task_handler();
  lv_tick_inc(5);
  delay(5);
}
