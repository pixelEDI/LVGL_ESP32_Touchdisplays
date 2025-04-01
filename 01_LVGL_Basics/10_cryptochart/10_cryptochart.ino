//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#include "touchscreen.h"
#include <WiFi.h>
#include "secret.h"
#include <HTTPClient.h>
#include <ArduinoJson.h>

const String url = "https://api.coingecko.com/api/v3/coins/solana/market_chart?vs_currency=usd&days=10&interval=daily";
float prices[10];  // Array zum Speichern der Preise
float min_price = 10000;
float max_price = 0;

void get_cyrptos() {
  HTTPClient http;
  http.begin(url);            
  int httpCode = http.GET();  

  if (httpCode > 0) {                   
    String payload = http.getString();  

    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, payload);

    if (error) {
      Serial.print("deserializeJson() failed: ");
      Serial.println(error.c_str());
      return;
    }

    JsonArray pricesArray = doc["prices"];

    // Extrahieren der Preise aus dem JSON und speichern in das Array

    for (int i = 0; i < 10; i++) {
      prices[i] = pricesArray[i][1].as<float>();  // Preise (Index 1) extrahieren

      if (prices[i] > max_price) {
        max_price = prices[i];
      }

      // Minimalen Wert feststellen
      if (prices[i] < min_price) {
        min_price = prices[i];
      }
    }
  } else {
    Serial.println("Fehler bei der HTTP-Anfrage");
  }

  http.end();  
}

void lv_chart() {

  lv_obj_t *label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, "Solana");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 10);


  lv_obj_t *container_row = lv_obj_create(lv_screen_active());
  lv_obj_set_size(container_row, SCREEN_HEIGHT - 20, SCREEN_WIDTH - 40);
  lv_obj_align(container_row, LV_ALIGN_BOTTOM_MID, 0, -10);
  lv_obj_set_flex_flow(container_row, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(container_row, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_obj_t *chart = lv_chart_create(container_row);
  lv_obj_set_size(chart, SCREEN_HEIGHT - 90, SCREEN_WIDTH - 70);
  lv_obj_center(chart);
  lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
  lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, int(min_price - 10), int(max_price + 10));

  int scale_min = int(min_price - 10);
  int scale_max = int(max_price + 10);

  // Berechne die Anzahl der Ticks und den Schritt
  int tick_count = 10;
  int total_ticks = 5;  // Anzahl der Haupt-Ticks, die du anzeigen willst
  int step = tick_count / total_ticks;  // Schrittweite der Ticks

  lv_obj_t *scale = lv_scale_create(container_row);
  lv_obj_set_size(scale, 15, SCREEN_WIDTH - 90);
  lv_scale_set_mode(scale, LV_SCALE_MODE_VERTICAL_RIGHT);
  lv_scale_set_label_show(scale, true);
  lv_scale_set_range(scale, scale_min, scale_max); // Skalenbereich basierend auf deinen Preisen
  lv_scale_set_total_tick_count(scale, total_ticks); // Gesamtanzahl der Ticks
  lv_scale_set_major_tick_every(scale, step); // Schrittweite für Hauptmarkierungen

  lv_chart_series_t *ser1 = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);

  for (uint32_t i = 0; i < 10; i++) {
    lv_chart_set_next_value(chart, ser1, (int)prices[i]);  // int keine float!
    Serial.println((int)prices[i]);
  }

  lv_chart_refresh(chart);
}


void setup() {

 touchscreen_setup();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Verbinde mit Wi-Fi...");
  }
  Serial.println("Verbunden mit Wi-Fi!");

  get_cyrptos();

  lv_chart();
}

void loop() {
  lv_task_handler();  // let the GUI do its work
  lv_tick_inc(5);     // tell LVGL how much time has passed
  delay(5);           // let this time pass
}
