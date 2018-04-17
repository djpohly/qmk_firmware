// Waples layout for Let's Split (rev2)
// Made changes from the default

#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _DVORAK 1
#define _GAME 2
#define _LEFTY 3
#define _RIGHTY 4
#define _DUAL 5

enum letssplit_keycodes {
  QWERTY = SAFE_RANGE,
  DVORAK,
  GAME,
  LEFTY,
  RIGHTY,
  DUAL,
};

#define TG_NKRO MAGIC_TOGGLE_NKRO     // Toggle NKRO
#define CTLESC MT(MOD_LCTL, KC_ESC)    // Hold for left Ctrl, tap for Esc
#define SHFTENT MT(MOD_RSFT, KC_ENT)    // Hold for right Shift, tap for Enter
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
  CTLESC,  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, SHFTENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT, \
  KC_PSCR, KC_BSPC, KC_LALT, KC_CAPS, LEFTY, KC_LGUI, KC_SPC, RIGHTY, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_DVORAK] = KEYMAP( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,    KC_F,   KC_G,   KC_C,    KC_R,    KC_L,  KC_BSPC, \
  CTLESC,  KC_A,    KC_O,    KC_E,    KC_U,  KC_I,    KC_D,   KC_H,   KC_T,    KC_N,    KC_S,  SHFTENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,    KC_B,   KC_M,   KC_W,    KC_V,    KC_Z,  KC_SLSH, \
  KC_PSCR, KC_LGUI, KC_LALT, KC_CAPS, LEFTY, KC_BSPC, KC_SPC, RIGHTY, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT \
),

[_GAME] = KEYMAP( \
  KC_TAB,  KC_Q, KC_W, KC_E, KC_R,  KC_T,   _______, _______, _______, _______, _______, QWERTY, \
  CTLESC,  KC_A, KC_S, KC_D, KC_F,  KC_G,   _______, _______, _______, _______, _______, _______, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V,  KC_B,   _______, _______, _______, _______, _______, _______, \
  KC_LCTL, KC_1, KC_2, KC_3, LEFTY, KC_SPC, KC_BSPC, RIGHTY,   KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT \
),

[_LEFTY] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  _______, _______, _______, _______, _______, _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_INS,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END \
),

[_RIGHTY] = KEYMAP( \
  KC_GRV,  KC_1,  KC_2,   KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_DEL,  KC_F1, KC_F2,  KC_F3,  KC_F4,   _______, KC_EQL,  KC_MINS, KC_BSLS, KC_SLSH, _______, _______, \
  _______, KC_F5, KC_F6,  KC_F7,  KC_F8,   _______, _______, _______, _______, _______, _______, _______,
  _______, KC_F9, KC_F10, KC_F11, _______, _______, _______, _______, _______, _______, _______, _______ \
),

[_DUAL] =  KEYMAP( \
  RESET,   _______, _______, _______, _______, QWERTY,  GAME,    _______, _______, _______, _______, RESET, \
  _______, KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, \
  _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, TG_NKRO, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, DVORAK,  _______, _______, _______, _______, _______ \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAME);
      }
      return false;
      break;
    case LEFTY:
      if (record->event.pressed) {
        layer_on(_LEFTY);
        update_tri_layer(_LEFTY, _RIGHTY, _DUAL);
      } else {
        layer_off(_LEFTY);
        update_tri_layer(_LEFTY, _RIGHTY, _DUAL);
      }
      return false;
      break;
    case RIGHTY:
      if (record->event.pressed) {
        layer_on(_RIGHTY);
        update_tri_layer(_LEFTY, _RIGHTY, _DUAL);
      } else {
        layer_off(_RIGHTY);
        update_tri_layer(_LEFTY, _RIGHTY, _DUAL);
      }
      return false;
      break;
    case DUAL:
      if (record->event.pressed) {
        layer_on(_DUAL);
      } else {
        layer_off(_DUAL);
      }
      return false;
      break;
  }
  return true;
}
