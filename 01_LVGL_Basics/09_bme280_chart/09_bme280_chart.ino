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
unsigned long previousMillis = 0;

#define BME_NUM_READINGS 20
float bme_last_readings[BME_NUM_READINGS] = {-20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0, -20.0};
float scale_min_temp;
float scale_max_temp;

// Draw a label on that chart with the value of the pressed point
static void chart_draw_label_cb(lv_event_t * e) {
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t * chart = (lv_obj_t*) lv_event_get_target(e);

  if(code == LV_EVENT_VALUE_CHANGED) {
    lv_obj_invalidate(chart);
  }
  if(code == LV_EVENT_REFR_EXT_DRAW_SIZE) {
    int32_t * s = (int32_t*)lv_event_get_param(e);
    *s = LV_MAX(*s, 20);
  }
  // Draw the label on the chart based on the pressed point
  else if(code == LV_EVENT_DRAW_POST_END) {
    int32_t id = lv_chart_get_pressed_point(chart);
    if(id == LV_CHART_POINT_NONE) return;

    LV_LOG_USER("Selected point %d", (int)id);

    lv_chart_series_t * ser = lv_chart_get_series_next(chart, NULL);
    while(ser) {
      lv_point_t p;
      lv_chart_get_point_pos_by_id(chart, ser, id, &p);

      int32_t * y_array = lv_chart_get_y_array(chart, ser);
      int32_t value = y_array[id];
      char buf[16];
      #if TEMP_CELSIUS
        const char degree_symbol[] = "\u00B0C";
      #else
        const char degree_symbol[] = "\u00B0F";
      #endif

      // Preparing the label text for the selected data point
      lv_snprintf(buf, sizeof(buf), LV_SYMBOL_DUMMY " %3.2f %s ", float(bme_last_readings[id]), degree_symbol);

      // Draw the rectangular label that will display the temperature value
      lv_draw_rect_dsc_t draw_rect_dsc;
      lv_draw_rect_dsc_init(&draw_rect_dsc);
      draw_rect_dsc.bg_color = lv_color_black();
      draw_rect_dsc.bg_opa = LV_OPA_60;
      draw_rect_dsc.radius = 2;
      draw_rect_dsc.bg_image_src = buf;
      draw_rect_dsc.bg_image_recolor = lv_color_white();
      // Rectangular label size
      lv_area_t a;
      a.x1 = chart->coords.x1 + p.x - 35;
      a.x2 = chart->coords.x1 + p.x + 35;
      a.y1 = chart->coords.y1 + p.y - 30;
      a.y2 = chart->coords.y1 + p.y - 10;
      lv_layer_t * layer = lv_event_get_layer(e);
      lv_draw_rect(layer, &draw_rect_dsc, &a);
      ser = lv_chart_get_series_next(chart, ser);
    }
  }
  else if(code == LV_EVENT_RELEASED) {
    lv_obj_invalidate(chart);
  }
}

// Draw chart
void lv_draw_chart(void) {
  // Clear screen
  lv_obj_clean(lv_scr_act());

  // Create a a text label aligned on top
  lv_obj_t * label = lv_label_create(lv_screen_active());
  lv_label_set_text(label, "BME280 Temperature Readings");
  lv_obj_align(label, LV_ALIGN_TOP_MID, 0, 10);

  // Create a container to display the chart and scale
  lv_obj_t * container_row = lv_obj_create(lv_screen_active());
  lv_obj_set_size(container_row, SCREEN_HEIGHT-20,  SCREEN_WIDTH-40);
  lv_obj_align(container_row, LV_ALIGN_BOTTOM_MID, 0, -10);
  // Set the container in a flexbox row layout aligned center
  lv_obj_set_flex_flow(container_row, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(container_row, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  // Create a chart
  lv_obj_t * chart = lv_chart_create(container_row);
  lv_obj_set_size(chart, SCREEN_HEIGHT-90, SCREEN_WIDTH-70);
  lv_chart_set_point_count(chart, BME_NUM_READINGS);
  lv_obj_add_event_cb(chart, chart_draw_label_cb, LV_EVENT_ALL, NULL);
  lv_obj_refresh_ext_draw_size(chart);

  // Add a data series
  lv_chart_series_t * chart_series = lv_chart_add_series(chart, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);

  for(int i = 0; i < BME_NUM_READINGS; i++) {
    if(float(bme_last_readings[i]) != -20.0) { // Ignores default array values
      // Set points in the chart and scale them with an *100 multiplier to remove the 2 floating-point numbers
      chart_series->y_points[i] = float(bme_last_readings[i]) * 100;
    }
  }
  // Set the chart range and also scale it with an *100 multiplier to remove the 2 floating-point numbers
  lv_chart_set_range(chart, LV_CHART_AXIS_PRIMARY_Y, int(scale_min_temp-1)*100, int(scale_max_temp+1)*100);
  lv_chart_refresh(chart); // Required to update the chart with the new values

  // Create a scale (y axis for the temperature) aligned vertically on the right
  lv_obj_t * scale = lv_scale_create(container_row);
  lv_obj_set_size(scale, 15, SCREEN_WIDTH-90);
  lv_scale_set_mode(scale, LV_SCALE_MODE_VERTICAL_RIGHT);
  lv_scale_set_label_show(scale, true);
  // Set the scale ticks count 
  lv_scale_set_total_tick_count(scale, int(scale_max_temp+2) - int(scale_min_temp-1));
  if((int(scale_max_temp+2) - int(scale_min_temp-1)) < 10) {
    lv_scale_set_major_tick_every(scale, 1); // set y axis to have 1 tick every 1 degree
  }
  else {
    lv_scale_set_major_tick_every(scale, 10); // set y axis to have 1 tick every 10 degrees
  }
  // Set the scale style and range
  lv_obj_set_style_length(scale, 5, LV_PART_ITEMS);
  lv_obj_set_style_length(scale, 10, LV_PART_INDICATOR);
  lv_scale_set_range(scale, int(scale_min_temp-1), int(scale_max_temp+1));
}

// Get the latest BME readings
void get_bme_readings(void) {
  #if TEMP_CELSIUS
    float bme_temp = bme.readTemperature();
  #else
    float bme_temp = 1.8 * bme.readTemperature() + 32;  
  #endif
  
  // Reset scale range (chart y axis) variables
  scale_min_temp = 120.0;
  scale_max_temp = -20.0;

  // Shift values to the left of the array and inserts the latest reading at the end
  for (int i = 0; i < BME_NUM_READINGS; i++) {
    if(i == (BME_NUM_READINGS-1) && float(bme_temp) < 120.0) {
      bme_last_readings[i] = float(bme_temp);  // Inserts the new reading at the end
    }
    else {
      bme_last_readings[i] = float(bme_last_readings[i + 1]);  // Shift values to the left of the array
    }
    // Get the min/max value in the array to set the scale range (chart y axis)
    if((float(bme_last_readings[i]) < scale_min_temp) && (float(bme_last_readings[i]) != -20.0 )) {
      scale_min_temp = bme_last_readings[i];
    }
    if((float(bme_last_readings[i]) > scale_max_temp) && (float(bme_last_readings[i]) != -20.0 )) {
      scale_max_temp = bme_last_readings[i];
    }
  }
  Serial.print("Min temp: ");
  Serial.println(float(scale_min_temp));
  Serial.print("Max temp: ");
  Serial.println(float(scale_max_temp));
  Serial.print("BME last reading: ");
  Serial.println(float(bme_last_readings[BME_NUM_READINGS-1]));
  lv_draw_chart();
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
   get_bme_readings();
}

void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    // save the last time that chart was updated
    previousMillis = currentMillis;
    get_bme_readings();    
  }

  lv_task_handler();  
  lv_tick_inc(5);     
  delay(5);           
}

