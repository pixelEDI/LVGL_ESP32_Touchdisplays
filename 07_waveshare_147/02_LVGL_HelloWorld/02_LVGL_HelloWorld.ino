//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "Display_ST7789.h"
#include "LVGL_Driver.h"

void setup()
{       
  
  LCD_Init();
  Lvgl_Init();

  lv_obj_t *scr = lv_scr_act();

  // Erstelle das erste Label
  lv_obj_t *label1 = lv_label_create(scr);
  lv_label_set_text(label1, "pixeledi");
  lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 20);

  // Erstelle das zweite Label
  lv_obj_t *label2 = lv_label_create(scr);
  lv_label_set_text(label2, "youtube");
  lv_obj_align(label2, LV_ALIGN_TOP_MID, 0, 60);
 
  // Erstelle das dritte Label
  lv_obj_t *label3 = lv_label_create(scr);
  lv_label_set_text(label3, "abonnieren");
  lv_obj_align(label3, LV_ALIGN_TOP_MID, 0, 100);

}

void loop()
{
  Timer_Loop();
  delay(5);
}
