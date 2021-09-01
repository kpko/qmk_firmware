/* Copyright 2021 StefanGrindelwald
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _VIM
};

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

#define _VIMESC LT(_VIM,KC_ESC) 
#define _VIMSCL LT(_VIM,KC_SCLN) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                           KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        _VIMESC,  HOME_A,  HOME_S,  HOME_D,  HOME_F,  KC_G,                                           KC_H,    HOME_J,  HOME_K,  HOME_L,  _VIMSCL, KC_QUOT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                           KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        MO(_FN1), KC_GRV,  KC_EQL,  KC_LEFT, KC_RGHT,                                                          KC_UP,   KC_DOWN, KC_LBRC, KC_RBRC, MO(_FN1),
                                                               KC_LCTL, KC_LALT,    KC_RGUI, KC_RCTL,
                                                                        KC_HOME,    KC_PGUP,
                                                     KC_SPACE, KC_BSPC,  KC_END,    KC_PGDN, KC_TAB,  KC_ENT
    ),
    [_FN1] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        _______,  _______, _______, _______, _______, _______,                                        _______, _______, _______,  _______, _______, _______,
        _______,  _______, _______, _______, _______, _______,                                        _______, _______, _______,  _______, _______, _______,
        MO(_FN2), _______, _______, _______, _______, _______,                                        _______, _______, RGB_RMOD, RGB_MOD, RGB_TOG, MO(_FN2),
        _______,  _______, KC_MUTE, KC_VOLD, KC_VOLU,                                                          RGB_VAI, RGB_VAD,  RGB_SAI, RGB_SAD, _______,
                                                               _______, _______,    _______, _______,
                                                                        _______,    RGB_HUI,
                                                      _______, _______, _______,    RGB_HUD, _______, _______
    ),
    [_FN2] = LAYOUT(
        KC_CAPS,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______,  _______, _______, _______,
        _______, _______, _______, RESET,   _______, _______,                                        _______, _______, RESET,    _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                        _______, _______, RGB_RMOD, RGB_MOD, RGB_TOG, _______,
        _______, _______, KC_MUTE, KC_VOLD, KC_VOLU,                                                          RGB_VAI, RGB_VAD,  RGB_SAI, RGB_SAD, _______,
                                                              _______, _______,    _______, _______,
                                                                       _______,    RGB_HUI,
                                                     _______, _______, _______,    RGB_HUD, _______, _______
    ),
    [_VIM] = LAYOUT(
        KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                          KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE,                                         _______, _______, _______,  _______, _______, _______,
        _______, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,                                          KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
        _______, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                         _______, _______, _______,  _______, _______, _______,
        _______,  _______, _______, _______, _______,                                                          _______, _______,  _______, _______, _______,
                                                               _______, _______,    _______, _______,
                                                                        _______,    _______,
                                                      _______, _______, _______,    _______, _______, _______
    )

};
