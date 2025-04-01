//        _          _          _ _
//  _ __ (_)_  _____| | ___  __| (_)
// | '_ \| \ \/ / _ \ |/ _ \/ _` | |
// | |_) | |>  <  __/ |  __/ (_| | |
// | .__/|_/_/\_\___|_|\___|\__,_|_|
// |_|
// https://links.pixeledi.eu
// LVGL mit ESP32 | 04.2025

#define LGFX_USE_V1
#include "Arduino.h"
#include <lvgl.h>
#include "demos/lv_demos.h"
#include <LovyanGFX.hpp>
#include "CST816D.h"

// I2C pins
#define I2C_SDA 4
#define I2C_SCL 5
// Touch panel interrupt and reset pins
#define TP_INT 0
#define TP_RST -1

// I2C address for the I/O extender
#define PI4IO_I2C_ADDR 0x43

bool timerstart = false;
unsigned long previousMillis = millis();

lv_obj_t* arc_obj;
lv_obj_t* label_obj;

// Buffer size definition
#define buf_size 120
lv_obj_t *label;
// LGFX class definition for display device interface
class LGFX : public lgfx::LGFX_Device {
  // Internal components of the LGFX class
  lgfx::Panel_GC9A01 _panel_instance;
  lgfx::Bus_SPI _bus_instance;
public:
  LGFX(void) {
    {
      // Configuration for the SPI bus and panel
      auto cfg = _bus_instance.config();
      cfg.spi_host = SPI2_HOST;
      cfg.spi_mode = 0;
      cfg.freq_write = 80000000;
      cfg.freq_read = 20000000;
      cfg.spi_3wire = true;
      cfg.use_lock = true;
      cfg.dma_channel = SPI_DMA_CH_AUTO;
      cfg.pin_sclk = 6;
      cfg.pin_mosi = 7;
      cfg.pin_miso = -1;
      cfg.pin_dc = 2;
      _bus_instance.config(cfg);
      _panel_instance.setBus(&_bus_instance);
    }
    {
      auto cfg = _panel_instance.config();
      cfg.pin_cs = 10;
      cfg.pin_rst = -1;
      cfg.pin_busy = -1;
      cfg.memory_width = 240;
      cfg.memory_height = 240;
      cfg.panel_width = 240;
      cfg.panel_height = 240;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      cfg.offset_rotation = 0;
      cfg.dummy_read_pixel = 8;
      cfg.dummy_read_bits = 1;
      cfg.readable = false;
      cfg.invert = true;
      cfg.rgb_order = false;
      cfg.dlen_16bit = false;
      cfg.bus_shared = false;
      _panel_instance.config(cfg);
    }
    setPanel(&_panel_instance);
  }
};

// Global instances for the display and touch screen
LGFX tft;
CST816D touch(I2C_SDA, I2C_SCL, TP_RST, TP_INT);

/*Change to your screen resolution*/
static const uint32_t screenWidth = 240;
static const uint32_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[2][screenWidth * buf_size];

#if LV_USE_LOG != 0
// Custom print function for LVGL debugging
void my_print(lv_log_level_t level, const char *file, uint32_t line, const char *fn_name, const char *dsc) {
  Serial.printf("%s(%s)@%d->%s\r\n", file, fn_name, line, dsc);
  Serial.flush();
}
#endif

// Function to handle flushing of display buffer to the screen
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p) {
  if (tft.getStartCount() == 0) {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);

  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

// Function to read touchpad input
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data) {
  bool touched;
  uint8_t gesture;
  uint16_t touchX, touchY;
  touched = touch.getTouch(&touchX, &touchY, &gesture);
  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR;
    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

// Function to initialize I/O extender
void init_IO_extender() {
  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x01);  // test register
  Wire.endTransmission();
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);
  uint8_t rxdata = Wire.read();
  Serial.print("Device ID: ");
  Serial.println(rxdata, HEX);

  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x03);                                                  // IO direction register
  Wire.write((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4));  // set pins 0, 1, 2 as outputs
  Wire.endTransmission();

  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x07);                                                     // Output Hi-Z register
  Wire.write(~((1 << 0) | (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4)));  // set pins 0, 1, 2 low
  Wire.endTransmission();
}

// Function to set I/O pin state on the extender
void set_pin_io(uint8_t pin_number, bool value) {

  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x05);  // test register
  Wire.endTransmission();
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);
  uint8_t rxdata = Wire.read();
  Serial.print("Before the change: ");
  Serial.println(rxdata, HEX);

  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x05);  // Output register

  if (!value)
    Wire.write((~(1 << pin_number)) & rxdata);  // set pin low
  else
    Wire.write((1 << pin_number) | rxdata);  // set pin high
  Wire.endTransmission();

  Wire.beginTransmission(PI4IO_I2C_ADDR);
  Wire.write(0x05);  // test register
  Wire.endTransmission();
  Wire.requestFrom(PI4IO_I2C_ADDR, 1);
  rxdata = Wire.read();
  Serial.print("after the change: ");
  Serial.println(rxdata, HEX);
}

void decrement_timer() {
  int current_value = lv_arc_get_value(arc_obj);
  current_value--;
  lv_arc_set_value(arc_obj, current_value);
  lv_label_set_text(label_obj, String(current_value).c_str());
}

static void arc_changed(lv_event_t *e) {
  lv_event_code_t code = lv_event_get_code(e);              //Get the event code
  lv_obj_t *arc = (lv_obj_t *)lv_event_get_target(e);       //Switch that generated the event
  lv_obj_t *label = (lv_obj_t *)lv_event_get_user_data(e);  //Label or other UI elements we want to update (Optional)

  arc_obj = arc;
  
  if (code == LV_EVENT_VALUE_CHANGED) {
    int timercnt = lv_arc_get_value(arc);
    lv_label_set_text_fmt(label, "%d", timercnt);
  }
}

static void button_go_event(lv_event_t *e) {
    LV_LOG_USER("lets go");
    timerstart = true;
}
void setup() {
  // Initialization of serial communication, I2C, display, touch screen, and LVGL
  Serial.begin(115200); /* prepare for possible serial debug */
  Serial.println("I am LVGL_Arduino");
  Wire.begin(4, 5);
  init_IO_extender();
  delay(100);
  set_pin_io(3, true);
  set_pin_io(4, true);
  set_pin_io(2, true);
  set_pin_io(0, false);  // vibrationsmotor aus
  tft.init();
  tft.initDMA();
  tft.startWrite();
  tft.setColor(0, 0, 0);

  tft.fillScreen(TFT_BLACK);
  delay(200);
  touch.begin();
  lv_init();
#if LV_USE_LOG != 0
  //lv_log_register_print_cb(my_print); /* register print function for debugging */
#endif

  lv_disp_draw_buf_init(&draw_buf, buf[0], buf[1], screenWidth * buf_size);

  /*Initialize the display*/
  static lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  /*Change the following line to your display resolution*/
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the (dummy) input device driver*/
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  /*Create an Arc*/
  lv_obj_t *arc = lv_arc_create(lv_scr_act());
  lv_obj_set_size(arc, 180, 180);
  lv_arc_set_rotation(arc, 135);
  lv_arc_set_bg_angles(arc, 0, 270);
  lv_arc_set_value(arc, 10);
  lv_obj_center(arc);

  lv_obj_t *label = lv_label_create(arc);
  lv_label_set_text(label, "Timer");  // Set the labels text
  lv_obj_center(label);
  lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

  label_obj = label;

  lv_obj_t *btn = lv_btn_create(lv_scr_act());
  lv_obj_set_style_bg_color(btn, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_obj_set_size(btn, 60, 30);
  lv_obj_align_to(btn, arc, LV_ALIGN_CENTER, 0, 35);

  lv_obj_t *btn_label = lv_label_create(btn);  
  lv_label_set_text(btn_label, "Go");       
  lv_obj_center(btn_label);                    

  lv_obj_add_event_cb(arc, arc_changed, LV_EVENT_VALUE_CHANGED, label);
  lv_obj_add_event_cb(btn, button_go_event, LV_EVENT_CLICKED, NULL);
 
  Serial.println("Setup done");
}

void loop() {

  unsigned long currentMillis = millis();
  if (timerstart) {
    if (currentMillis - previousMillis >= 1000) {
      previousMillis = currentMillis;
      int timercnt = lv_arc_get_value(arc_obj);
      if (timercnt > 0) {
        decrement_timer();
      }
      else if(timercnt <= 0){
       
        for (int i = 0; i < 5; i++) {
            set_pin_io(0, true);  

            tft.fillScreen(TFT_RED);
            delay(500);

            set_pin_io(0, false);  
            tft.fillScreen(TFT_BLACK);
            delay(500);
        }
        esp_restart();

      }
    }
  }


  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
}
