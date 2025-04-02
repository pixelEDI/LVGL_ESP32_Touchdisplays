#include "Display_ST7789.h"
#include "LVGL_Driver.h"
#include "ui.h"
#include "globals.h"
#include "wifimqtt.h"

extern lv_meter_indicator_t *indicator1;

void setup() {
  Serial.begin(115200);
  LCD_Init();
  Lvgl_Init();
  ui_init();

  connectAP();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  state = GETUPDATE;
  // lv_meter_set_indicator_value(objects.meter_voltage, indicator1, 8);
  // lv_bar_set_value(objects.bar_temperature, 50, LV_ANIM_OFF);
  // lv_label_set_text(objects.lbl_temperature_value, "50");
  // lv_bar_set_value(objects.bar_humidity, 10, LV_ANIM_OFF);
  // lv_label_set_text(objects.lbl_humidity_value, "10");
}

void loop() {

  if (!client.connected()) {
    reconnect();
  }
  if (!client.loop())
    client.connect("esp32c6dashboard");

  static uint32_t last_update = 0;
  if (millis() - last_update >= 5000) {  

    last_update = millis();
    state = GETUPDATE;
  }

  switch(state){
    case GETUPDATE:
    client.publish("dashboard/update", "pixeledi auf yt abonnieren!");
    delay(1000);
    state=WAIT;
    break;
    case WAIT:
    //just chillin
    break;
    case SHOWVALUES:
     lv_meter_set_indicator_value(objects.meter_voltage, indicator1, mySensorData.voltage);
      lv_bar_set_value(objects.bar_temperature, mySensorData.temperature, LV_ANIM_OFF);
      lv_bar_set_value(objects.bar_humidity, mySensorData.humidity, LV_ANIM_ON);

      lv_label_set_text(objects.lbl_humidity_value, String(mySensorData.humidity).c_str());
      lv_label_set_text(objects.lbl_temperature_value, String(mySensorData.temperature).c_str());
      lv_label_set_text(objects.lbl_clock, mySensorData.update_clock.c_str());
      lv_label_set_text(objects.lbl_date,  mySensorData.update_date.c_str());
      state = WAIT;
    break;
  }

  Timer_Loop();
  delay(5);
}
