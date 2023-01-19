/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Custom keys
#define LT_ESCV LT(1, KC_ESC)
#define LT_QUOV LT(1, KC_QUOT)
#define MT_CTLZ MT(MOD_LCTL, KC_Z)
#define MT_CTLS MT(MOD_RCTL, KC_SLSH)
#define MT_ALTX MT(MOD_LALT, KC_X)

// Home row mods
// Left-hand home row mods
#define GUI_A LGUI_T(KC_A)
#define ALT_S LALT_T(KC_S)
#define SFT_D LSFT_T(KC_D)
#define CTL_F LCTL_T(KC_F)
// Right-hand home row mods
#define CTL_J RCTL_T(KC_J)
#define SFT_K RSFT_T(KC_K)
#define ALT_L RALT_T(KC_L)
#define GUI_SCN RGUI_T(KC_SCLN)

// Layers
#define _DEFAULT 0
#define _VIM 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      LT_ESCV,   GUI_A,   ALT_S,   SFT_D,   CTL_F,    KC_G,                         KC_H,   CTL_J,   SFT_K,   ALT_L, GUI_SCN, LT_QUOV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, MT_CTLZ, MT_ALTX,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, MT_CTLS, KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(2),  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),
  //
  // VIM LAYER
  //
  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, _______, _______, _______,                      XXXXXXX, KC_VOLD, KC_VOLU, XXXXXXX, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,   MO(2), _______,    _______,   MO(3), _______
                                      //`--------------------------'  `--------------------------'
  ),
  //
  // LOWER
  //
  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                       KC_DOT,    KC_7,    KC_8,    KC_9, KC_PSLS, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                      KC_COMM,    KC_4,    KC_5,    KC_6, KC_PAST, KC_PPLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______,  KC_F11,  KC_F12, XXXXXXX, XXXXXXX, XXXXXXX,                         KC_0,    KC_1,    KC_2,    KC_3, KC_PMNS, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______,   MO(4), _______
                                      //`--------------------------'  `--------------------------'
  ),
  //
  // RAISE
  //
  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_PSCR,  KC_INS, KC_HOME, KC_PGUP, KC_PAUS,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, KC_SCRL,  KC_DEL,  KC_END, KC_PGDN, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______,  MO(4),  _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),
  //
  // ADJUST
  //
  [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, RGB_VAD, RGB_VAI, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_VIM 2
#define L_LOWER 4
#define L_RAISE 8
#define L_ADJUST 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_VIM:
            oled_write_ln_P(PSTR("VIM"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

#define RGB_NEON_PINK 0xEA, 0x00, 0xD9
#define RGB_NEON_LIGHT_PINK 0x71, 0x1C, 0x91
#define RGB_NEON_CYAN 0x0A, 0xBD, 0xC6

#if RGB_MATRIX_ENABLE

/* LED_TAB,LED_Q,LED_W,LED_E,LED_R,LED_T,LED_Y,LED_U,LED_I,LED_O,LED_P,LED_BSPC, */
/* LED_ESCV,LED_A,LED_S,LED_D,LED_F,LED_G,LED_H,LED_J,LED_K,LED_L,LED_SCLN,LED_QUOV, */
/* LED_LSFT,LED_CTLZ,MT_ALTX,LED_C,LED_V,LED_B,LED_N,LED_M,LED_COMM,LED_DOT,LED_CTLS,LED_ESC, */
/* LED_LGUI,LED_LOWER,LED_SPC,LED_ENT,LED_RAISE,LED_RALT */
/* //  // left half */
/* //  24 23 18 17 10  9 */
/* //  25 22 19 16 11  8 */ 
/* //  26 21 20 15 12  7 */ 
/* //           14 13  6 */ 
/* //  // right half */
/* //  36 37 44 45 50 51 */
/* //  35 38 43 46 49 52 */
/* //  34 39 42 47 48 53 */
/* //  41 40 33 */

enum led_loc_map {
  LED_TAB = 24,
  LED_Q = 23,
  LED_W = 18,
  LED_E = 17,
  LED_R = 10,
  LED_T = 9,
  LED_Y = 36,
  LED_U = 37,
  LED_I = 44,
  LED_O = 45,
  LED_P = 50,
  LED_BSPC = 51,
  LED_ESCV = 25,
  LED_A = 22,
  LED_S = 19,
  LED_D = 16,
  LED_F = 11,
  LED_G = 8,
  LED_H = 35,
  LED_J = 38,
  LED_K = 43,
  LED_L = 46,
  LED_SCLN = 49,
  LED_QUOV = 52,
  LED_LSFT = 26,
  LED_CTLZ = 21,
  LED_ALTX = 20,
  LED_C = 15,
  LED_V = 12,
  LED_B = 7,
  LED_N = 34,
  LED_M = 39,
  LED_COMM = 42,
  LED_DOT = 47,
  LED_CTLS = 48,
  LED_ESC = 53,
  LED_LGUI = 14,
  LED_LOWER = 13,
  LED_SPC = 6,
  LED_ENT = 41,
  LED_RAISE = 40,
  LED_RALT = 33
};

HSV rgb_to_hsv(RGB rgb)
{
    HSV hsv;
    unsigned char rgbMin, rgbMax;

    rgbMin = rgb.r < rgb.g ? (rgb.r < rgb.b ? rgb.r : rgb.b) : (rgb.g < rgb.b ? rgb.g : rgb.b);
    rgbMax = rgb.r > rgb.g ? (rgb.r > rgb.b ? rgb.r : rgb.b) : (rgb.g > rgb.b ? rgb.g : rgb.b);
    
    hsv.v = rgbMax;
    if (hsv.v == 0)
    {
        hsv.h = 0;
        hsv.s = 0;
        return hsv;
    }

    hsv.s = 255 * (rgbMax - rgbMin) / hsv.v;
    if (hsv.s == 0)
    {
        hsv.h = 0;
        return hsv;
    }

    if (rgbMax == rgb.r)
        hsv.h = 0 + 43 * (rgb.g - rgb.b) / (rgbMax - rgbMin);
    else if (rgbMax == rgb.g)
        hsv.h = 85 + 43 * (rgb.b - rgb.r) / (rgbMax - rgbMin);
    else
        hsv.h = 171 + 43 * (rgb.r - rgb.g) / (rgbMax - rgbMin);

    return hsv;
}

RGB custom_cap_rgb(uint8_t r, uint8_t g, uint8_t b) {
  RGB rgb = {g,r,b}; // deal with it
  HSV hsv = rgb_to_hsv(rgb);
  if (hsv.v > rgb_matrix_get_val()) {
    hsv.v = rgb_matrix_get_val();
  }
  RGB rgb_result = hsv_to_rgb(hsv);
  return rgb_result;
}

void custom_set_color_all(uint8_t r, uint8_t g, uint8_t b) {
  RGB rgb = custom_cap_rgb(r, g, b);
  rgb_matrix_set_color_all(rgb.r, rgb.g, rgb.b);
}
void custom_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b) {
  RGB rgb = custom_cap_rgb(r, g, b);
  rgb_matrix_set_color(index, rgb.r, rgb.g, rgb.b);
}

void keyboard_post_init_user(void) {
  //rgblight_setrgb_range(RGB_NEON_PINK, 0, 27);
  //rgblight_sethsv_range(HSV_NEON_PINK, 0, 27);
  //rgblight_sethsv_slave(HSV_NEON_CYAN);
  rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
  custom_set_color_all(RGB_NEON_PINK); 
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  uint8_t layer = get_highest_layer(layer_state);

  switch(layer){ 
    case _VIM:
      custom_set_color_all(RGB_NEON_PINK); 
      break;
    case _LOWER:
      custom_set_color_all(RGB_NEON_PINK); 

      /* rgb_matrix_set_color(LED_H, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_J, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_K, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_L, RGB_NEON_CYAN); */
      /* rgb_set_list(LED_LIST_NUMROW, ARRAYSIZE(LED_LIST_NUMROW), RGB_NEON_PINK); */
      /* highlight_debug_keys(); */

      // F keys
      custom_set_color(LED_Q, RGB_NEON_CYAN);
      custom_set_color(LED_W, RGB_NEON_CYAN);
      custom_set_color(LED_E, RGB_NEON_CYAN);
      custom_set_color(LED_R, RGB_NEON_CYAN);
      custom_set_color(LED_T, RGB_NEON_CYAN);
      custom_set_color(LED_A, RGB_NEON_CYAN);
      custom_set_color(LED_S, RGB_NEON_CYAN);
      custom_set_color(LED_D, RGB_NEON_CYAN);
      custom_set_color(LED_F, RGB_NEON_CYAN);
      custom_set_color(LED_G, RGB_NEON_CYAN);
      custom_set_color(LED_CTLZ, RGB_NEON_CYAN);
      custom_set_color(LED_ALTX, RGB_NEON_CYAN);

      // num block 
      custom_set_color(LED_N, RGB_NEON_CYAN);
      custom_set_color(LED_M, RGB_NEON_CYAN);
      custom_set_color(LED_COMM, RGB_NEON_CYAN);
      custom_set_color(LED_DOT, RGB_NEON_CYAN);
      custom_set_color(LED_J, RGB_NEON_CYAN);
      custom_set_color(LED_K, RGB_NEON_CYAN);
      custom_set_color(LED_L, RGB_NEON_CYAN);
      custom_set_color(LED_U, RGB_NEON_CYAN);
      custom_set_color(LED_I, RGB_NEON_CYAN);
      custom_set_color(LED_O, RGB_NEON_CYAN);
      break;
    case _RAISE:
      // default color
      custom_set_color_all(RGB_NEON_PINK); 
      break;
    case _ADJUST:
      custom_set_color_all(RGB_RED);
      break;
    default:
      // default color
      custom_set_color_all(RGB_NEON_PINK); 

      // hjkl 
      custom_set_color(LED_H, RGB_NEON_CYAN); 
      custom_set_color(LED_J, RGB_NEON_CYAN); 
      custom_set_color(LED_K, RGB_NEON_CYAN); 
      custom_set_color(LED_L, RGB_NEON_CYAN); 
      /* rgb_matrix_set_color(LED_ESC, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_BSPC, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_LCTL, RGB_NEON_CYAN); */
      /* rgb_matrix_set_color(LED_RCTL, RGB_NEON_CYAN); */
      break;
  }

  if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
    custom_set_color(0, RGB_RED);
  }
}


/* // Custom RGB Colours */
/* #define RGB_NORD_BASE 0x2E, 0x34, 0x40 */
/* #define RGB_NORD_BRIGHT 0x4C, 0x56, 0x6A */
/* #define RGB_NORD_RED 0xBF, 0x61, 0x6A */
/* #define RGB_NORD_YELLOW 0xEB, 0xCB, 0x8B */
/* #define RGB_NORD_GREEN 0xA3, 0xBE, 0x8C */
/* #define RGB_NORD_GREEN_LIGHT 0x8F, 0xBC, 0xBB */
/* #define RGB_NORD_VIOLET 0xB4, 0x8E, 0xAD */

/* // neo tokyo */
/* led_config_t g_led_config = { { */
/*     {  24,  23,  18,  17,  10,   9 }, */
/*     {  25,  22,  19,  16,  11,   8 }, */
/*     {  26,  21,  20,  15,  12,   7 }, */
/*     { NO_LED, NO_LED, NO_LED,  14,  13,   6 }, */
/*     {  51,  50,  45,  44,  37,  36 }, */
/*     {  52,  49,  46,  43,  38,  35 }, */
/*     {  53,  48,  47,  42,  39,  34 }, */
/*     { NO_LED, NO_LED, NO_LED,  41,  40,  33 } */
/* }, { */
#endif
