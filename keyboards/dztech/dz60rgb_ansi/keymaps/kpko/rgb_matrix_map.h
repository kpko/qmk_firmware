#ifdef RGB_MATRIX_ENABLE

// Custom RGB Colours
#define RGB_NORD_BASE 0x2E, 0x34, 0x40
#define RGB_NORD_BRIGHT 0x4C, 0x56, 0x6A
#define RGB_NORD_RED 0xBF, 0x61, 0x6A
#define RGB_NORD_YELLOW 0xEB, 0xCB, 0x8B
#define RGB_NORD_GREEN 0xA3, 0xBE, 0x8C
#define RGB_NORD_GREEN_LIGHT 0x8F, 0xBC, 0xBB
#define RGB_NORD_VIOLET 0xB4, 0x8E, 0xAD

// neo tokyo
#define RGB_NEON_PINK 0xEA, 0x00, 0xD9
#define RGB_NEON_LIGHT_PINK 0x71, 0x1C, 0x91
#define RGB_NEON_CYAN 0x0A, 0xBD, 0xC6

// RGB LED locations
enum led_location_map {
    LED_BSPC, 
    LED_EQL, 
    LED_MINS, 
    LED_0, 
    LED_9, 
    LED_8, 
    LED_7, 
    LED_6, 
    LED_5, 
    LED_4, 
    LED_3, 
    LED_2, 
    LED_1, 
    LED_ESC, 
    LED_BSLS, 
    LED_RBRC, 
    LED_LBRC, 
    LED_P, 
    LED_O, 
    LED_I, 
    LED_U, 
    LED_Y, 
    LED_T, 
    LED_R, 
    LED_E, 
    LED_W, 
    LED_Q, 
    LED_TAB, 
    LED_ENT, 
    LED_QUOT, 
    LED_SCLN, 
    LED_L, 
    LED_K, 
    LED_J, 
    LED_H, 
    LED_G, 
    LED_F, 
    LED_D, 
    LED_S, 
    LED_A, 
    LED_CAPS, 
    LED_RSFT, 
    LED_SLSH, 
    LED_DOT, 
    LED_COMM, 
    LED_M, 
    LED_N, 
    LED_B, 
    LED_V, 
    LED_C, 
    LED_X, 
    LED_Z, 
    LED_LSFT, 
    LED_RCTL, 
    LED_FN, 
    LED_RGUI, 
    LED_RALT, 
    LED_SPC, 
    LED_LALT, 
    LED_LGUI, 
    LED_LCTL
};

const uint8_t LED_LIST_NUMROW_FULL[] = { LED_ESC, LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0, LED_MINS, LED_EQL, LED_BSPC };
const uint8_t LED_LIST_NUMROW[] = { LED_1, LED_2, LED_3, LED_4, LED_5, LED_6, LED_7, LED_8, LED_9, LED_0 };

const uint8_t LED_LIST_NUMPAD[] = {
    LED_7, LED_8, LED_9,
    LED_U, LED_I, LED_O,
    LED_J, LED_K, LED_L,
    LED_M, LED_COMM, LED_DOT
};

const uint8_t LED_LIST_HJKL[] = { LED_H, LED_J, LED_K, LED_L };

#endif
