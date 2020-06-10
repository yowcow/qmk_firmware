#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  L_QW = 0,
  L_FN,
  L_RS
};

enum {
//    TD_RSFTALT = 0,
    TD_LSFTALT = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
//    [TD_RSFTALT] = ACTION_TAP_DANCE_DOUBLE(KC_RSFT, KC_RALT),
    [TD_LSFTALT] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_LALT)
};

// Shortcut to make keymap more readable
#define FUNCT   MO(L_FN)
#define RAISE   MO(L_RS)
//#define RSFTALT TD(TD_RSFTALT)
#define LSFTALT TD(TD_LSFTALT)
#define IME_TGL RCTL(KC_SPC)
#define VL_DOWN KC__VOLDOWN
#define VL_UP   KC__VOLUP
#define VL_MUTE KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [L_QW] = LAYOUT( \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    XXXXXXX,                        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX, \
    XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, XXXXXXX, \
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, \
    XXXXXXX, KC_ESC,  KC_GRV , KC_LGUI,          KC_LCTL, KC_SPC , LSFTALT,      KC_RSFT, KC_ENT , FUNCT,            KC_MINS, KC_QUOT, KC_BSLS, XXXXXXX  \
  ),

  [L_FN] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_EXLM, KC_AT  , KC_UP  , KC_DLR , KC_PERC, _______,                        _______, KC_PGUP, KC_7   , KC_8   , KC_9   , KC_BSPC, _______, \
    _______, KC_LPRN, KC_LEFT, KC_DOWN, KC_RGHT, KC_RPRN, KC_CIRC,                        KC_AMPR, KC_PGDN, KC_4   , KC_5   , KC_6   , KC_ESC , _______, \
    _______, KC_LBRC, KC_RBRC, KC_HASH, KC_LCBR, KC_RCBR, IME_TGL,                        _______, KC_ASTR, KC_1   , KC_2   , KC_3   , KC_PLUS, _______, \
    _______, RAISE  , _______, _______,          _______, IME_TGL, _______,      _______, _______, _______,          KC_PDOT, KC_0   , KC_EQL , _______  \
  ),

  [L_RS] = LAYOUT( \
    _______, _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______, _______, \
    _______, KC_INS , KC_HOME, XXXXXXX, KC_END , KC_PGUP, _______,                        _______, KC_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______, \
    _______, KC_DEL , VL_DOWN, VL_UP  , VL_MUTE, KC_PGDN, RESET  ,                        _______, KC_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 , _______, \
    _______, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX, XXXXXXX, _______,                        _______, _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          KC_PSCR, KC_SLCK, _______, _______  \
  )
};
