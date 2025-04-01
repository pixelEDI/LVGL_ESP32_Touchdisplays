//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <XPT2046_Touchscreen.h>
#define SCREEN_WIDTH 240
#define SCREEN_HEIGHT 320
/*LVGL draw into this buffer, 1/10 screen size usually works well. The size is in bytes*/
#define DRAW_BUF_SIZE (SCREEN_WIDTH * SCREEN_HEIGHT / 10 * (LV_COLOR_DEPTH / 8))
uint32_t draw_buf[DRAW_BUF_SIZE / 4];

void setup() {
    Serial.begin(115200);
    Serial.println("LVGL Start");
    lv_init();
    lv_display_t * disp;
    disp = lv_tft_espi_create(SCREEN_WIDTH, SCREEN_HEIGHT, draw_buf, sizeof(draw_buf));
    lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_270);
    lv_obj_t * text_label = lv_label_create(lv_screen_active());
    lv_label_set_text(text_label, "Hello pixeledi!");
    lv_obj_align(text_label, LV_ALIGN_CENTER,0,0);
    static lv_style_t style_text_label;
    lv_style_init(&style_text_label);
    lv_style_set_text_font(&style_text_label, &lv_font_montserrat_18);
    lv_obj_add_style(text_label, &style_text_label, 0);  
}
void loop() {
   lv_timer_handler(); 
   delay(5); 
}
