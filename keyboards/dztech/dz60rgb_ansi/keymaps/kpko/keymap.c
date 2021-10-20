// my dz60rgb ansi 2.1 layout - kpko

#include QMK_KEYBOARD_H
#include "rgb_matrix_map.h"

#define ARRAYSIZE(arr)  sizeof(arr)/sizeof(arr[0])

#define _BASE 0
#define _FUN 1
#define _VIM 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_60_ansi(
        KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC,
        KC_TAB,           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        LT(_VIM, KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI,          KC_LALT,                   KC_SPC,                             KC_RALT, KC_RGUI,          MO(_FUN), KC_RCTL
    ),
    [_FUN] = LAYOUT_60_ansi(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_DEL,
        _______,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, KC_PSCR, KC_SLCK, KC_PAUS, RESET,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGUP, _______,
        _______,          _______, _______, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, _______, KC_DEL,  KC_END,  KC_PGDN,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
    ),
    [_VIM] = LAYOUT_60_ansi(
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,  KC_UP, KC_RIGHT, _______, _______, _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______,          _______,                   _______,                            _______, _______,          _______, _______
    ),
};

// RGB
#ifdef RGB_MATRIX_ENABLE
void rgb_set_list(const uint8_t* list, size_t list_size, uint8_t r, uint8_t g, uint8_t b) {
  for (uint8_t i=0; i<list_size; i++) {
    rgb_matrix_set_color(list[i], r, g, b);
  }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  switch(get_highest_layer(layer_state)){ 
    case _FUN:
      rgb_matrix_set_color_all(RGB_OFF);
      rgb_matrix_set_color(LED_BSLS, RGB_RED);
      rgb_matrix_set_color(LED_1, RGB_NEON_PINK);
      rgb_matrix_set_color(LED_N, RGB_NEON_PINK);
      break;
    case _VIM:
      rgb_matrix_set_color_all(RGB_OFF);
      rgb_matrix_set_color(LED_H, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_J, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_K, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_L, RGB_NEON_CYAN);
      rgb_set_list(LED_LIST_NUMROW, ARRAYSIZE(LED_LIST_NUMROW), RGB_NEON_PINK);
      break;
    default:
      rgb_matrix_set_color_all(RGB_NEON_PINK); // Default startup colour

      rgb_matrix_set_color(LED_H, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_J, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_K, RGB_NEON_CYAN);
      rgb_matrix_set_color(LED_L, RGB_NEON_CYAN);

      /* rgb_matrix_set_color(LED_1, RGB_NORD_RED); */
      /* rgb_matrix_set_color(LED_2, RGB_NORD_BRIGHT); */
      /* rgb_matrix_set_color(LED_3, RGB_NORD_VIOLET); */
      /* rgb_matrix_set_color(LED_4, RGB_NORD_YELLOW); */
      /* rgb_matrix_set_color(LED_5, 0x71, 0x1C, 0x91); */
      /* rgb_matrix_set_color(LED_6, 0xEA, 0x00, 0xD9); */
      /* rgb_matrix_set_color(LED_7, 0x0A, 0xBD, 0xC6); */
      /* rgb_matrix_set_color(LED_8, 0x3B, 0x55, 0xCE); */
      break;
  }

  if (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color(LED_ESC, RGB_RED);
  }
}
#endif

void keyboard_post_init_user(void) {
    #ifdef RGB_MATRIX_ENABLE
        rgb_matrix_set_color_all(0xEA, 0x00, 0xD9); // Default startup colour
    #endif
}
