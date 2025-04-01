/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font Roboto-Italic-VariableFont_wdth,wght.ttf --symbols ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789ÄÖÜäöüßé,!.?;:()[]{}<>@#$%^&*_ -+=|\\/~`"'

 --format lvgl -o roboto.c
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl.h"
#endif

#ifndef ROBOTO
#define ROBOTO 1
#endif

#if ROBOTO

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x24, 0x96, 0xd2, 0x3, 0x0,

    /* U+0022 "\"" */
    0x56, 0xa0,

    /* U+0023 "#" */
    0xa, 0x12, 0x12, 0x7f, 0x24, 0x24, 0x28, 0xfe,
    0x48, 0x50, 0x90,

    /* U+0024 "$" */
    0x4, 0x18, 0x71, 0xf2, 0x24, 0x4c, 0xe, 0x4,
    0x8d, 0x1b, 0xe3, 0x82, 0xc, 0x0,

    /* U+0025 "%" */
    0x70, 0x50, 0x92, 0x94, 0x68, 0x8, 0x16, 0x29,
    0x49, 0x49, 0x6,

    /* U+0026 "&" */
    0x1c, 0x36, 0x26, 0x24, 0x38, 0x30, 0x69, 0x4f,
    0xc6, 0x46, 0x3a,

    /* U+0027 "'" */
    0x68,

    /* U+0028 "(" */
    0x3, 0x24, 0x4c, 0x88, 0x88, 0x88, 0x84, 0x40,

    /* U+0029 ")" */
    0x20, 0x84, 0x30, 0x84, 0x21, 0x18, 0x84, 0x62,
    0x33, 0x0,

    /* U+002A "*" */
    0x21, 0x3e, 0x47, 0x48,

    /* U+002B "+" */
    0x10, 0x41, 0xc, 0xfc, 0x82, 0x8, 0x20,

    /* U+002C "," */
    0x69, 0x0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x2, 0xc, 0x10, 0x40, 0x82, 0x4, 0x10, 0x20,
    0x81, 0x4, 0x0,

    /* U+0030 "0" */
    0x39, 0x14, 0x61, 0x86, 0x18, 0x63, 0x8a, 0x67,
    0x0,

    /* U+0031 "1" */
    0x3f, 0x22, 0x22, 0x26, 0x64, 0x40,

    /* U+0032 "2" */
    0x1c, 0x45, 0x88, 0x10, 0x61, 0x82, 0x8, 0x20,
    0x83, 0xf8,

    /* U+0033 "3" */
    0x1c, 0x4d, 0x88, 0x10, 0x63, 0x81, 0x3, 0xc4,
    0x89, 0xe0,

    /* U+0034 "4" */
    0x6, 0x1c, 0x38, 0xa3, 0x4c, 0x91, 0x7f, 0xc,
    0x18, 0x20,

    /* U+0035 "5" */
    0x3e, 0xc1, 0x2, 0x7, 0x89, 0x81, 0x2, 0x8d,
    0x11, 0xc0,

    /* U+0036 "6" */
    0x18, 0x84, 0x10, 0xbb, 0x38, 0x61, 0x8f, 0x27,
    0x0,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x40, 0x82, 0xc, 0x10, 0x60,
    0x83, 0x0,

    /* U+0038 "8" */
    0x1c, 0x44, 0x89, 0x12, 0x67, 0x99, 0x23, 0xc6,
    0x88, 0xe0,

    /* U+0039 "9" */
    0x39, 0x3c, 0x61, 0x87, 0x37, 0xc2, 0x8, 0x4e,
    0x0,

    /* U+003A ":" */
    0x60, 0x0, 0x6,

    /* U+003B ";" */
    0x30, 0x0, 0x6, 0x64, 0xc0,

    /* U+003C "<" */
    0x4, 0x39, 0xc6, 0x3, 0x1, 0x80, 0x0,

    /* U+003D "=" */
    0xfc, 0x0, 0x3e,

    /* U+003E ">" */
    0x40, 0x60, 0x30, 0x33, 0x8c, 0x20, 0x0,

    /* U+003F "?" */
    0x7b, 0x28, 0x82, 0x18, 0xc2, 0x18, 0x0, 0x4,
    0x0,

    /* U+0040 "@" */
    0x7, 0x81, 0x86, 0x10, 0x22, 0x72, 0x44, 0x94,
    0x91, 0x49, 0x15, 0x92, 0x91, 0x29, 0xb6, 0x4d,
    0xc4, 0x0, 0x20, 0x1, 0xe0,

    /* U+0041 "A" */
    0x2, 0x3, 0x1, 0x81, 0x60, 0x90, 0x88, 0x44,
    0x7e, 0x21, 0xb0, 0xd0, 0x20,

    /* U+0042 "B" */
    0x3e, 0x23, 0x21, 0x23, 0x62, 0x7c, 0x42, 0x42,
    0x42, 0x46, 0xfc,

    /* U+0043 "C" */
    0x1c, 0x62, 0x43, 0xc3, 0x80, 0x80, 0x80, 0x80,
    0x86, 0xc4, 0x78,

    /* U+0044 "D" */
    0x3e, 0x23, 0x21, 0x21, 0x61, 0x61, 0x41, 0x43,
    0x42, 0x46, 0xf8,

    /* U+0045 "E" */
    0x3f, 0x20, 0x20, 0x20, 0x60, 0x7e, 0x40, 0x40,
    0x40, 0x40, 0xfe,

    /* U+0046 "F" */
    0x3f, 0x20, 0x20, 0x20, 0x60, 0x7e, 0x40, 0x40,
    0x40, 0x40, 0xc0,

    /* U+0047 "G" */
    0x1c, 0x62, 0x43, 0xc0, 0x80, 0x80, 0x8e, 0x82,
    0x82, 0x46, 0x7c,

    /* U+0048 "H" */
    0x20, 0x88, 0x22, 0x8, 0x82, 0x60, 0x9f, 0xe4,
    0x19, 0x4, 0x41, 0x10, 0x4c, 0x10,

    /* U+0049 "I" */
    0x22, 0x22, 0x26, 0x64, 0x44, 0x40,

    /* U+004A "J" */
    0x2, 0x4, 0x8, 0x10, 0x60, 0xc1, 0x2, 0x85,
    0x99, 0xe0,

    /* U+004B "K" */
    0x21, 0x91, 0x89, 0x85, 0x87, 0x83, 0xc1, 0xa0,
    0x88, 0x46, 0x21, 0x30, 0xc0,

    /* U+004C "L" */
    0x20, 0x82, 0x8, 0x61, 0x84, 0x10, 0x41, 0xf,
    0xc0,

    /* U+004D "M" */
    0x30, 0x33, 0x7, 0x30, 0x63, 0xe, 0x78, 0xa6,
    0x9a, 0x49, 0x64, 0xb6, 0x4a, 0x44, 0xe4, 0xc4,
    0x40,

    /* U+004E "N" */
    0x30, 0xcc, 0x23, 0x8, 0xe2, 0x68, 0x9b, 0x64,
    0x59, 0x1c, 0x43, 0x10, 0xcc, 0x30,

    /* U+004F "O" */
    0x1c, 0x62, 0x43, 0xc1, 0x83, 0x83, 0x83, 0x82,
    0x82, 0xc4, 0x78,

    /* U+0050 "P" */
    0x3e, 0x10, 0x88, 0x64, 0x36, 0x13, 0x19, 0xf8,
    0x80, 0x40, 0x20, 0x30, 0x0,

    /* U+0051 "Q" */
    0x1c, 0x62, 0x43, 0xc3, 0x83, 0x83, 0x82, 0x82,
    0x86, 0xc4, 0x78, 0x4, 0x0,

    /* U+0052 "R" */
    0x3e, 0x23, 0x21, 0x21, 0x61, 0x62, 0x7c, 0x44,
    0x46, 0x42, 0xc2,

    /* U+0053 "S" */
    0x1e, 0x23, 0x61, 0x60, 0x30, 0x1c, 0x6, 0x2,
    0xc2, 0x46, 0x3c,

    /* U+0054 "T" */
    0xff, 0x10, 0x10, 0x10, 0x10, 0x10, 0x30, 0x30,
    0x20, 0x20, 0x20,

    /* U+0055 "U" */
    0x41, 0x43, 0x43, 0xc2, 0xc2, 0x82, 0x82, 0x86,
    0x84, 0xcc, 0x78,

    /* U+0056 "V" */
    0xc1, 0xc3, 0x42, 0x46, 0x44, 0x4c, 0x68, 0x68,
    0x30, 0x30, 0x30,

    /* U+0057 "W" */
    0xc6, 0x3c, 0x62, 0x4e, 0x24, 0xa4, 0x4a, 0x45,
    0x2c, 0x52, 0x85, 0x28, 0x62, 0x86, 0x30, 0x41,
    0x0,

    /* U+0058 "X" */
    0x21, 0x91, 0x8c, 0x82, 0xc1, 0xc0, 0x40, 0x70,
    0x68, 0x64, 0x23, 0x30, 0x80,

    /* U+0059 "Y" */
    0xc3, 0x42, 0x46, 0x6c, 0x28, 0x38, 0x30, 0x30,
    0x20, 0x20, 0x20,

    /* U+005A "Z" */
    0x3f, 0x3, 0x2, 0x4, 0xc, 0x18, 0x10, 0x20,
    0x60, 0xc0, 0xfe,

    /* U+005B "[" */
    0x39, 0x8, 0x46, 0x31, 0x8, 0x42, 0x11, 0x88,
    0x70,

    /* U+005C "\\" */
    0xc4, 0x44, 0x44, 0x22, 0x22, 0x23,

    /* U+005D "]" */
    0x38, 0xc4, 0x21, 0x8, 0xc6, 0x21, 0x8, 0x42,
    0x70,

    /* U+005E "^" */
    0x22, 0x75, 0xd9,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x4c,

    /* U+0061 "a" */
    0x3c, 0xc8, 0x19, 0xe4, 0x58, 0xb3, 0x3a,

    /* U+0062 "b" */
    0x20, 0x40, 0x83, 0xe6, 0x68, 0x50, 0xa1, 0x47,
    0x8a, 0xe0,

    /* U+0063 "c" */
    0x3c, 0xcd, 0xa, 0x4, 0x8, 0x91, 0x1c,

    /* U+0064 "d" */
    0x3, 0x3, 0x2, 0x3a, 0x66, 0x42, 0x46, 0x46,
    0x44, 0x44, 0x7c,

    /* U+0065 "e" */
    0x3c, 0xc9, 0x1b, 0xfc, 0x8, 0x11, 0x1c,

    /* U+0066 "f" */
    0x39, 0x11, 0xe4, 0x21, 0x18, 0x84, 0x20,

    /* U+0067 "g" */
    0x3a, 0xcd, 0xa, 0x34, 0x68, 0x91, 0x3a, 0x5,
    0x11, 0xc0,

    /* U+0068 "h" */
    0x20, 0x40, 0x83, 0xe6, 0x68, 0xd1, 0xa2, 0x45,
    0x8b, 0x10,

    /* U+0069 "i" */
    0x20, 0x16, 0x92, 0x4b, 0x0,

    /* U+006A "j" */
    0x8, 0x0, 0x31, 0x88, 0x42, 0x11, 0x8c, 0x42,
    0x70,

    /* U+006B "k" */
    0x20, 0x40, 0x83, 0x36, 0xcb, 0x1c, 0x38, 0x59,
    0x93, 0x10,

    /* U+006C "l" */
    0x24, 0x96, 0x92, 0x4b, 0x0,

    /* U+006D "m" */
    0x7d, 0xcc, 0xc5, 0x18, 0xa3, 0x14, 0x42, 0x88,
    0xf1, 0x1e, 0x22,

    /* U+006E "n" */
    0x7c, 0xcd, 0x1a, 0x34, 0x48, 0xb1, 0x62,

    /* U+006F "o" */
    0x1c, 0xcd, 0xa, 0x14, 0x28, 0xd1, 0x1c,

    /* U+0070 "p" */
    0x7c, 0xcd, 0xa, 0x14, 0x28, 0xf1, 0x7c, 0x81,
    0x2, 0x0,

    /* U+0071 "q" */
    0x3a, 0xcd, 0xa, 0x34, 0x68, 0x91, 0x3e, 0x4,
    0x18, 0x30,

    /* U+0072 "r" */
    0x7b, 0x10, 0x84, 0x23, 0x18,

    /* U+0073 "s" */
    0x3d, 0x94, 0x1c, 0x1c, 0x1c, 0xde,

    /* U+0074 "t" */
    0x21, 0x1c, 0x42, 0x31, 0x8, 0x43, 0x0,

    /* U+0075 "u" */
    0xc7, 0x18, 0xe3, 0x8a, 0x28, 0xbe,

    /* U+0076 "v" */
    0x8e, 0x29, 0xb4, 0x51, 0x86, 0x10,

    /* U+0077 "w" */
    0x88, 0xcc, 0x66, 0x52, 0xaa, 0x75, 0x31, 0x18,
    0x88,

    /* U+0078 "x" */
    0x46, 0x58, 0xa1, 0x83, 0xf, 0x12, 0x46,

    /* U+0079 "y" */
    0x23, 0x22, 0x26, 0x34, 0x3c, 0x18, 0x18, 0x10,
    0x10, 0x20, 0xc0,

    /* U+007A "z" */
    0x7e, 0x8, 0x20, 0x83, 0xc, 0x30, 0x7e,

    /* U+007B "{" */
    0x0, 0xc4, 0x63, 0x10, 0x98, 0x63, 0x18, 0xc6,
    0x10, 0x0,

    /* U+007C "|" */
    0x24, 0x94, 0x92, 0x49, 0x48,

    /* U+007D "}" */
    0x20, 0x84, 0x21, 0x8, 0x41, 0x19, 0x88, 0x42,
    0x22, 0x0,

    /* U+007E "~" */
    0x62, 0x92, 0x8c,

    /* U+00C4 "Ä" */
    0x5, 0x80, 0x0, 0x80, 0xc0, 0x60, 0x58, 0x24,
    0x22, 0x11, 0x1f, 0x88, 0x6c, 0x34, 0x8,

    /* U+00D6 "Ö" */
    0x12, 0x0, 0x1c, 0x62, 0x43, 0xc1, 0x83, 0x83,
    0x83, 0x82, 0x82, 0xc4, 0x78,

    /* U+00DC "Ü" */
    0x16, 0x0, 0x41, 0x43, 0x43, 0xc2, 0xc2, 0x82,
    0x82, 0x86, 0x84, 0xcc, 0x78,

    /* U+00DF "ß" */
    0x1c, 0x4c, 0x9b, 0x26, 0xc9, 0x11, 0x21, 0x43,
    0x8f, 0xf0,

    /* U+00E4 "ä" */
    0x16, 0x0, 0x1, 0xe6, 0x40, 0xcf, 0x22, 0xc5,
    0x99, 0xd0,

    /* U+00E9 "é" */
    0x4, 0x10, 0x1, 0xe6, 0x48, 0xdf, 0xe0, 0x40,
    0x88, 0xe0,

    /* U+00F6 "ö" */
    0x36, 0x0, 0x0, 0xe6, 0x68, 0x50, 0xa1, 0x46,
    0x88, 0xe0,

    /* U+00FC "ü" */
    0x2c, 0x0, 0x31, 0xc6, 0x38, 0xe2, 0x8a, 0x2f,
    0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 55, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 56, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 70, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 8, .adv_w = 134, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 122, .box_w = 7, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 33, .adv_w = 159, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 135, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 38, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 8},
    {.bitmap_index = 56, .adv_w = 74, .box_w = 4, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 64, .adv_w = 76, .box_w = 5, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 74, .adv_w = 94, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 78, .adv_w = 123, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 85, .adv_w = 43, .box_w = 3, .box_h = 4, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 87, .adv_w = 60, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 88, .adv_w = 57, .box_w = 2, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 89, .adv_w = 90, .box_w = 7, .box_h = 12, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 100, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 122, .box_w = 4, .box_h = 11, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 135, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 155, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 174, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 122, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 193, .adv_w = 54, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 47, .box_w = 4, .box_h = 9, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 201, .adv_w = 110, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 208, .adv_w = 119, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 211, .adv_w = 114, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 218, .adv_w = 103, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 195, .box_w = 12, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 248, .adv_w = 142, .box_w = 9, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 135, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 272, .adv_w = 141, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 143, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 123, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 120, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 148, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 327, .adv_w = 155, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 59, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 136, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 117, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 190, .box_w = 12, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 155, .box_w = 10, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 150, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 137, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 150, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 447, .adv_w = 134, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 129, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 469, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 141, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 491, .adv_w = 138, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 502, .adv_w = 193, .box_w = 12, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 519, .adv_w = 136, .box_w = 9, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 532, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 543, .adv_w = 130, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 58, .box_w = 5, .box_h = 14, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 563, .adv_w = 89, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 569, .adv_w = 58, .box_w = 5, .box_h = 14, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 578, .adv_w = 91, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 581, .adv_w = 98, .box_w = 6, .box_h = 1, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 582, .adv_w = 67, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 583, .adv_w = 118, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 590, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 114, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 607, .adv_w = 123, .box_w = 8, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 115, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 76, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 642, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 652, .adv_w = 53, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 657, .adv_w = 52, .box_w = 5, .box_h = 14, .ofs_x = -2, .ofs_y = -3},
    {.bitmap_index = 666, .adv_w = 110, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 676, .adv_w = 53, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 191, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 692, .adv_w = 120, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 699, .adv_w = 124, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 706, .adv_w = 122, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 716, .adv_w = 123, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 726, .adv_w = 74, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 112, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 737, .adv_w = 71, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 120, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 750, .adv_w = 105, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 756, .adv_w = 163, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 108, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 772, .adv_w = 103, .box_w = 8, .box_h = 11, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 783, .adv_w = 108, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 74, .box_w = 5, .box_h = 15, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 800, .adv_w = 53, .box_w = 3, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 805, .adv_w = 74, .box_w = 5, .box_h = 15, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 815, .adv_w = 148, .box_w = 8, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 818, .adv_w = 142, .box_w = 9, .box_h = 13, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 833, .adv_w = 150, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 846, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 118, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 115, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 124, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 120, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_1[] = {
    0x0, 0x12, 0x18, 0x1b, 0x20, 0x25, 0x32, 0x38
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 196, .range_length = 57, .glyph_id_start = 96,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 3,
    3, 8,
    8, 3,
    8, 8,
    13, 3,
    13, 8,
    15, 3,
    15, 8,
    16, 16
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -12, -12, -12, -12, -19, -19, -19, -19,
    -24
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 9,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 2,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t roboto = {
#else
lv_font_t roboto = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if ROBOTO*/

