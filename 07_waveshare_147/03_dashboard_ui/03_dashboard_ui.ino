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
#include "ui.h"

void setup()
{       
  LCD_Init();
  Lvgl_Init();
  ui_init();
}

void loop()
{
  Timer_Loop();
  delay(5);
}
