// Copyright (C) 2019, 2020  Keyboard.io, Inc
//
// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

enum layer_names {
    _QW,
    _RS,
    _LW,
    _NV,
};

enum custom_keycodes {
    LGUI_IME = SAFE_RANGE,
    RGUI_IME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_TAB,  KC_BSPC, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    LT(_NV, KC_ESC), KC_LALT, LGUI_IME, KC_LCTL, KC_SPC,  KC_LSFT, KC_RCTL, KC_ENT,  MO(_RS), RGUI_IME, KC_QUOT, KC_MINS
    ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   KC_ASTR, KC_7,    KC_8,    KC_9,    KC_BSLS,
    KC_LPRN, _______, _______, _______, KC_RPRN,                   KC_GRV,  KC_4,    KC_5,    KC_6,    KC_EQL,
    KC_LBRC, KC_RBRC, _______, KC_LCBR, KC_RCBR, KC_CIRC, _______, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_PIPE,
    MO(_LW), _______, _______, _______, _______, _______, _______, _______, _______, KC_DOT,  KC_0,    _______
    ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    _______, _______, _______, _______, _______,                   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, _______, _______, _______,                   _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,
    KC_MUTE, KC_VOLD, KC_VOLU, KC_BRID, KC_BRIU, QK_BOOT, KC_DEL,  _______, KC_F1,   KC_F2,   KC_F3,   KC_F12,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

  [_NV] = LAYOUT( /* [> NAV <] */
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

static uint16_t gui_ime_timer;
static bool     gui_ime_held;
static bool     gui_ime_interrupted;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode != LGUI_IME && keycode != RGUI_IME) {
        if (record->event.pressed && gui_ime_held) {
            gui_ime_interrupted = true;
        }
        return true;
    }

    const uint8_t kc_gui = (keycode == LGUI_IME) ? KC_LGUI : KC_RGUI;
    if (record->event.pressed) {
        gui_ime_timer       = timer_read();
        gui_ime_interrupted = false;
        gui_ime_held        = true;
        register_code(kc_gui);
    } else {
        unregister_code(kc_gui);
        gui_ime_held = false;
        if (!gui_ime_interrupted && timer_elapsed(gui_ime_timer) < TAPPING_TERM) {
            // LNG2 = 英数, LNG1 = かな
            tap_code((keycode == LGUI_IME) ? KC_LNG2 : KC_LNG1);
        }
    }
    return false;
}
