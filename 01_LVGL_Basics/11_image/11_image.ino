///        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025
// https://lvgl.io/tools/imageconverter


#include "touchscreen.h"
#include "archlinux.h"

void draw_image(void) {
  LV_IMAGE_DECLARE(archlinux);
  lv_obj_t * img1 = lv_image_create(lv_screen_active());
  lv_image_set_src(img1, &archlinux);
  lv_obj_align(img1, LV_ALIGN_CENTER, 0, 0);
}

void setup() {
  touchscreen_setup();
  draw_image();
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);  
}
