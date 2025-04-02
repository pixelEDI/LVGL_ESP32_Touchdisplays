#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *main;
    lv_obj_t *lbl_dashboard;
    lv_obj_t *meter_voltage;
    lv_obj_t *bar_temperature;
    lv_obj_t *lbl_temperature;
    lv_obj_t *lbl_temperature_value;
    lv_obj_t *bar_humidity;
    lv_obj_t *lbl_humidity;
    lv_obj_t *lbl_humidity_value;
    lv_obj_t *lbl_date;
    lv_obj_t *lbl_clock;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_MAIN = 1,
};

void create_screen_main();
void tick_screen_main();

void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/