#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"

extern lv_meter_indicator_t *indicator1;

void setup() {
  LCD_Init();
  Lvgl_Init();
  ui_init();

  // lv_meter_set_indicator_value(objects.meter_voltage, indicator1, 8);
  // lv_bar_set_value(objects.bar_temperature, 50, LV_ANIM_OFF);
  // lv_label_set_text(objects.lbl_temperature_value, "50");
  // lv_bar_set_value(objects.bar_humidity, 10, LV_ANIM_OFF);
  // lv_label_set_text(objects.lbl_humidity_value, "10");
}

void loop() {

  static uint32_t last_update = 0;
  if (millis() - last_update >= 2000) {
    last_update = millis();

    int voltage = random(0, 13);
    int temperature = random(0, 45);
    int humidity = random(0, 100);

    lv_meter_set_indicator_value(objects.meter_voltage, indicator1, voltage);
    lv_bar_set_value(objects.bar_temperature, temperature, LV_ANIM_OFF);
    lv_label_set_text(objects.lbl_temperature_value, String(temperature).c_str());
    lv_bar_set_value(objects.bar_humidity, humidity, LV_ANIM_OFF);
    lv_label_set_text(objects.lbl_humidity_value, String(humidity).c_str());
  }

  Timer_Loop();
  delay(5);
}
