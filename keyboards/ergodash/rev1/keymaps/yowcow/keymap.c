#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  L_QW = 0,
  L_FN,
  L_RS
};

// Shortcut to make keymap more readable
#define FUNCT   MO(L_FN)
#define RAISE   MO(L_RS)
#define VL_DOWN KC__VOLDOWN
#define VL_UP   KC__VOLUP
#define VL_MUTE KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_QW] = LAYOUT( \
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_GRV ,                        KC_BSLS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_BSPC,                        KC_SPC , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
    XXXXXXX, KC_ESC,  KC_TAB , KC_LGUI,          KC_LCTL, KC_BSPC, KC_LSFT,      KC_RALT, KC_SPC , FUNCT,            KC_MINS, KC_QUOT, KC_ENT , XXXXXXX  \
  ),

  [L_FN] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_EXLM, KC_AT  , KC_UP  , KC_DLR , KC_PERC, _______,                        _______, KC_PGUP, KC_7   , KC_8   , KC_9   , KC_BSPC, _______, \
    _______, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_CIRC,                        KC_AMPR, KC_PGDN, KC_4   , KC_5   , KC_6   , _______, _______, \
    _______, KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, _______,                        _______, KC_ASTR, KC_1   , KC_2   , KC_3   , KC_PPLS, _______, \
    _______, RAISE  , _______, _______,          _______, _______, _______,      _______, _______, _______,          KC_PDOT, KC_0   , KC_PEQL, _______  \
  ),

  [L_RS] = LAYOUT( \
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, KC_INS , KC_HOME, XXXXXXX, KC_END , KC_PGUP, _______,                        _______, KC_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
    _______, KC_DEL,  VL_DOWN, VL_UP  , VL_MUTE, KC_PGDN, RESET  ,                        _______, KC_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______, \
    _______, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, _______,                        _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          KC_PSCR, KC_SLCK, _______, _______  \
  )
};
