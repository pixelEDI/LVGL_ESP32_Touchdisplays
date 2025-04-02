#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;

static lv_meter_scale_t * scale0;
static lv_meter_indicator_t * indicator1;

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 172, 320);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl_dashboard
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_dashboard = obj;
            lv_obj_set_pos(obj, 46, 5);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Dashboard");
        }
        {
            // meter_voltage
            lv_obj_t *obj = lv_meter_create(parent_obj);
            objects.meter_voltage = obj;
            lv_obj_set_pos(obj, 7, 29);
            lv_obj_set_size(obj, 158, 155);
            {
                lv_meter_scale_t *scale = lv_meter_add_scale(obj);
                scale0 = scale;
                lv_meter_set_scale_ticks(obj, scale, 41, 1, 5, lv_color_hex(0xffa0a0a0));
                lv_meter_set_scale_major_ticks(obj, scale, 8, 6, 10, lv_color_hex(0xffdd09b4), 10);
                lv_meter_set_scale_range(obj, scale, 0, 12, 300, 120);
                {
                    lv_meter_indicator_t *indicator = lv_meter_add_needle_line(obj, scale, 5, lv_color_hex(0xff0000ff), -5);
                    indicator1 = indicator;
                    lv_meter_set_indicator_value(obj, indicator, 0);
                }
            }
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff565a61), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // bar_temperature
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.bar_temperature = obj;
            lv_obj_set_pos(obj, 12, 222);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff17f904), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff53f58f), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // lbl_temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_temperature = obj;
            lv_obj_set_pos(obj, 35, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Temperatur: ");
        }
        {
            // lbl_temperature_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_temperature_value = obj;
            lv_obj_set_pos(obj, 107, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "13");
        }
        {
            // bar_humidity
            lv_obj_t *obj = lv_bar_create(parent_obj);
            objects.bar_humidity = obj;
            lv_obj_set_pos(obj, 13, 261);
            lv_obj_set_size(obj, 150, 10);
            lv_bar_set_value(obj, 25, LV_ANIM_OFF);
        }
        {
            // lbl_humidity
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_humidity = obj;
            lv_obj_set_pos(obj, 35, 243);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Feuchtigkeit: ");
        }
        {
            // lbl_humidity_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_humidity_value = obj;
            lv_obj_set_pos(obj, 107, 243);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "73");
        }
        {
            // lbl_date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_date = obj;
            lv_obj_set_pos(obj, 54, 290);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "01.01.1973");
        }
        {
            // lbl_clock
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl_clock = obj;
            lv_obj_set_pos(obj, 70, 304);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &ui_font_roboto, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "13:37");
        }
    }
    
    tick_screen_main();
}

void tick_screen_main() {
}



typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_main,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_main();
}
