#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

enum {
  L_QWERTY = 0,
  L_FUNCT
};

// Shortcut to make keymap more readable
#define FN_L        MO(L_FUNCT)
#define FNS_L       LM(L_FUNCT, MOD_LSFT)
//#define LT_BSLS     RGUI_T(KC_BSLS)
#define LT_QUOT     LT(L_FUNCT, KC_QUOT)
//#define LT_EQL      MT(LM(L_FUNCT, MOD_LSFT), KC_EQL)
#define VOL_DOWN    KC__VOLDOWN
#define VOL_UP      KC__VOLUP
#define VOL_MUTE    KC__MUTE

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * | ESC  |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   0  |Pscree|
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  `   |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  | Space|                    | Enter|   N  |   M  |   ,  |   .  |   /  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_QWERTY] = LAYOUT( \
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC ,                        KC_DEL , KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, \
    XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_TAB ,                        KC_BSPC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,  \
    FN_L,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LGUI,                        KC_RGUI, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT_QUOT, \
    KC_LGUI, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_SPC ,                        KC_ENT , KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS, \
    KC_LALT, XXXXXXX, XXXXXXX, KC_LGUI,          KC_LCTL, KC_SPC , KC_LSFT,      KC_RSFT, KC_ENT , KC_RCTL,          KC_RGUI, KC_PGUP, KC_PGDN, KC_RALT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F12 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  ~   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  | Space|                    | Enter|   N  |   M  |   <  |   >  |   ?  | Shift|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt | EISU |||||||| Lower| Space|  Del |||||||| Bksp | Enter| Raise|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [L_FUNCT] = LAYOUT(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,                        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, _______, \
    _______, VOL_DOWN,VOL_UP,  VOL_MUTE,XXXXXXX, XXXXXXX, _______,                        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,                        _______, XXXXXXX, XXXXXXX, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______, _______, _______,      _______, _______, _______,          _______, KC_HOME, KC_END,  _______  \
  )
};
