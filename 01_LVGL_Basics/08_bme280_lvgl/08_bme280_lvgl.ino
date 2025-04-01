//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

#define I2C_SDA 27
#define I2C_SCL 22
TwoWire I2CBME = TwoWire(0);
Adafruit_BME280 bme;

static void set_temp(void * text_label_temp_value, int32_t v) {
  float bme_temp = bme.readTemperature();
  lv_obj_set_style_text_color((lv_obj_t*) text_label_temp_value, lv_palette_main(LV_PALETTE_BLUE), 0);
  
  String bme_temp_text = String(bme_temp) + "C";
  lv_label_set_text((lv_obj_t*) text_label_temp_value, bme_temp_text.c_str());
  Serial.print("Temperature: ");
  Serial.println(bme_temp_text);
}

void lv_create_temperature_ui(void) {
  lv_obj_t * text_label_temp = lv_label_create(lv_screen_active());
  lv_label_set_text(text_label_temp, "Temperatur:");
  lv_obj_set_style_text_align(text_label_temp, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(text_label_temp, LV_ALIGN_CENTER, 0, -40);

  lv_obj_t * text_label_temp_value = lv_label_create(lv_screen_active());
  lv_label_set_text(text_label_temp_value, "--.--");
  lv_obj_set_style_text_align(text_label_temp_value, LV_TEXT_ALIGN_CENTER, 0);
  lv_obj_align(text_label_temp_value, LV_ALIGN_CENTER, 0, 0);

  static lv_style_t style_temp;
  lv_style_init(&style_temp);
  lv_style_set_text_font(&style_temp, &lv_font_montserrat_36);
  lv_obj_add_style(text_label_temp_value, &style_temp, 0);

  lv_anim_t a_temp;
  lv_anim_init(&a_temp);
  lv_anim_set_exec_cb(&a_temp, set_temp);
  lv_anim_set_duration(&a_temp, 1000000);
  lv_anim_set_playback_duration(&a_temp, 1000000);
  lv_anim_set_var(&a_temp, text_label_temp_value);
  lv_anim_set_values(&a_temp, 0, 100);
  lv_anim_set_repeat_count(&a_temp, LV_ANIM_REPEAT_INFINITE);
  lv_anim_start(&a_temp);
}


void setup() {

 I2CBME.begin(I2C_SDA, I2C_SCL, 100000);
  bool status;
  status = bme.begin(0x76, &I2CBME);
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  touchscreen_setup();
  lv_create_temperature_ui();
}

void loop() {
  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);           
}

