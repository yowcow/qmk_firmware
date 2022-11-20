// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
    _FN
};

#define CTL_SPC LCTL_T(KC_SPC)
#define CTL_ENT RCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC,  KC_LALT, KC_LGUI, MO(_LW), CTL_SPC, KC_LSFT, KC_RSFT, CTL_ENT, MO(_RS), KC_RGUI, KC_RALT, KC_BSLS
    ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL,
    KC_LPRN, KC_GRV,  XXXXXXX, XXXXXXX, KC_RPRN,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,
    KC_LBRC, KC_RBRC, XXXXXXX, KC_LCBR, KC_RCBR, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, MO(_FN), _______, _______, _______, _______, _______, _______, _______, _______
    ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_PGUP,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_END,  KC_PGDN, RESET,   KC_DEL,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, MO(_FN), _______, _______, _______
    ),

  [_FN] = LAYOUT( /* [> FUNC <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, KC_BRIU,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F11,
    XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_BRID, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    )

  //  KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN,                   KC_PGDN, KC_F4,   KC_F5,   KC_F6,    KC_F11,
  //  KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, KC_CIRC, KC_DEL,  XXXXXXX, KC_F1,   KC_F2,   KC_F3,    KC_F12,
  //  KC_ESC,  KC_GRV,  _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,  _______
  //  ),

  //[_LW] = LAYOUT( /* [> LOWER <] */
  //  KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_ESC,  KC_7,    KC_8,    KC_9,     KC_MINS,
  //  XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_ASTR, KC_4,    KC_5,    KC_6,     KC_EQL,
  //  KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, RESET,   KC_AMPR, KC_BSLS, KC_1,    KC_2,    KC_3,     KC_QUOT,
  //  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_0,     _______
  //  )
};
