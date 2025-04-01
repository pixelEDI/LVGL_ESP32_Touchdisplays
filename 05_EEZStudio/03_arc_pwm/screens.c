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

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 320, 240);
    {
        lv_obj_t *parent_obj = obj;
        {
            // lbl1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.lbl1 = obj;
            lv_obj_set_pos(obj, 156, 205);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xffd1c505), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "0");
        }
        {
            // arc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc = obj;
            lv_obj_set_pos(obj, 53, 10);
            lv_obj_set_size(obj, 262, 221);
            lv_arc_set_value(obj, 0);
            lv_arc_set_bg_start_angle(obj, 155);
            lv_arc_set_bg_end_angle(obj, 25);
            lv_obj_set_style_arc_width(obj, 25, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_color(obj, lv_color_hex(0xff132e5b), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_arc_width(obj, 25, LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // scale1
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.scale1 = obj;
            lv_obj_set_pos(obj, 95, 53);
            lv_obj_set_size(obj, 157, 136);
            lv_scale_set_mode(obj, LV_SCALE_MODE_ROUND_INNER);
            lv_scale_set_range(obj, 0, 100);
            lv_scale_set_total_tick_count(obj, 26);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, true);
            lv_obj_set_style_length(obj, 5, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff741515), LV_PART_INDICATOR | LV_STATE_DEFAULT);
        }
        {
            // led1
            lv_obj_t *obj = lv_led_create(parent_obj);
            objects.led1 = obj;
            lv_obj_set_pos(obj, 147, 105);
            lv_obj_set_size(obj, 32, 32);
            lv_led_set_color(obj, lv_color_hex(0xff4949aa));
            lv_led_set_brightness(obj, 0);
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
