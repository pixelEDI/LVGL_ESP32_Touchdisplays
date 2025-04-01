//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
#include "roboto.c"

void lv_font_montserrat_test(void) {
  lv_obj_t * label1 = lv_label_create(lv_screen_active());  
  lv_label_set_text(label1, "Füße, Übergrößen, Grüße");
  lv_obj_center(label1);  
} 

void lv_font_mit_umlaute(){
  lv_obj_t * label1 = lv_label_create(lv_screen_active());  
  lv_label_set_text(label1, "Füße, Übergrößen, Grüße");
  lv_obj_center(label1);  
  lv_obj_set_style_text_font(label1, &roboto, LV_PART_MAIN);
}

void setup() {
  touchscreen_setup();
  // umlaute werden nicht richtig dargestellt
  lv_font_montserrat_test();
  // Wenn die Convertierung richtig umgesetzt wird
  // werden die Umlaute richtig dargestellt
  // lv_font_mit_umlaute();
  
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);           
}
