#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  L_QW = 0,
  L_UP,
  L_LO
};

// Shortcut to make keymap more readable
#define RAISE   LT(L_UP, KC_ESC)
#define LOWER   LT(L_LO, KC_BSLS)
#define VOL_DN  KC__VOLDOWN
#define VOL_UP  KC__VOLUP
#define VOL_MT  KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_QW] = LAYOUT( \
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,                        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,                         KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC,                         KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
    XXXXXXX, RAISE,   KC_GRV,  KC_LGUI,          KC_LCTL, KC_SPC,  KC_LSFT,      KC_RSFT, KC_ENT,  KC_RCTL,          KC_RGUI, KC_QUOT, LOWER,   XXXXXXX  \
  ),

  [L_UP] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,                          _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MINS, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL,  _______, \
    _______, _______, KC_LALT, _______,          _______, _______, _______,      _______, _______, _______,          XXXXXXX, XXXXXXX, _______, _______  \
  ),

  [L_LO] = LAYOUT(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, VOL_DN,  VOL_UP,  VOL_MT,  XXXXXXX, XXXXXXX, KC_ESC,                         _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______, \
    _______, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          XXXXXXX, KC_RALT, _______, _______  \
  )
};
