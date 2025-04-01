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
  lv_obj_t * button1 = lv_button_create(lv_screen_active());
  lv_obj_set_size(button1, 190, 90);
  lv_obj_set_style_bg_color(button1, lv_palette_main(LV_PALETTE_RED), 0);
  lv_obj_align(button1, LV_ALIGN_CENTER, 0, -60);

  lv_obj_t * label1 = lv_label_create(button1);
  lv_label_set_text(label1, "Tomate");
  lv_obj_center(label1);

  lv_obj_t * button2 = lv_button_create(lv_screen_active());
  lv_obj_set_size(button2, 100, 40);
  lv_obj_set_style_bg_color(button2, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_obj_align(button2, LV_ALIGN_CENTER, 0, 20);

  lv_obj_t * label2 = lv_label_create(button2);
  lv_label_set_text(label2, "Frosch");
  lv_obj_center(label2);

  lv_obj_t * button3 = lv_button_create(lv_screen_active());
  lv_obj_set_size(button3, 80, 20);
  lv_obj_set_style_bg_color(button3, lv_palette_main(LV_PALETTE_BLUE), 0);
  lv_obj_align(button3, LV_ALIGN_CENTER, 90, 90);

  lv_obj_t * label3 = lv_label_create(button3);
  lv_label_set_text(label3, "Schlumpf");
  lv_obj_center(label3);
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

