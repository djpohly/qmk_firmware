#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"


// to build this keymap
// make ergodox_ez:djpohly:teensy

enum custom_keycodes {
	PLACEHOLDER = SAFE_RANGE, // can always be here
	// add customs here
};


#define BASE         0 // base dvorak layer
#define SYMBNUM      1 // symbols etc
#define KEYNAV       2 // arrow/mouse navigation, fn keys

#define DJP_QWERTY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT_ergodox(
		// left hand
		KC_NO,             KC_1,      KC_2,       KC_3,       KC_4,    KC_5,    RESET,
#ifdef DJP_QWERTY
		KC_TAB,            KC_Q,      KC_W,       KC_E,       KC_R,    KC_T,    S(LALT(KC_ENTER)),
		KC_LCTRL,          KC_A,      KC_S,       KC_D,       KC_F,    KC_G,
		KC_LSHIFT,         KC_Z,      KC_X,       KC_C,       KC_V,    KC_B,    KC_NO,
#else
		KC_TAB,            KC_QUOTE,  KC_COMMA,   KC_DOT,     KC_P,    KC_Y,    S(LALT(KC_ENTER)),
		KC_LCTRL,          KC_A,      KC_O,       KC_E,       KC_U,    KC_I,
		KC_LSHIFT,         KC_SCOLON, KC_Q,       KC_J,       KC_K,    KC_X,    KC_NO,
#endif
		RALT(KC_SYSREQ),   KC_NO,     KC_NO,      MO(KEYNAV), MO(SYMBNUM),

		// left thumb cluster
		         KC_ESC,   KC_NO,
		                   KC_NO,
		KC_LALT, KC_ENTER, KC_SPACE,

		// right hand
		DEBUG,  KC_6,  KC_7,      KC_8,      KC_9,   KC_0,   KC_BSPC,
#ifdef DJP_QWERTY
		KC_BSPC, KC_Y,  KC_U,      KC_I,      KC_O,   KC_P,   KC_LBRACKET,
		         KC_H,  KC_J,      KC_K,      KC_L,   KC_SCOLON,   CTL_T(KC_QUOTE),
		KC_NO,   KC_N,  KC_M,      KC_COMMA,  KC_DOT, KC_SLASH,   SFT_T(S(KC_RBRACKET)),
#else
		KC_BSPC, KC_F,  KC_G,      KC_C,      KC_R,   KC_L,   KC_SLASH,
		         KC_D,  KC_H,      KC_T,      KC_N,   KC_S,   CTL_T(KC_MINUS),
		KC_DELT, KC_B,  KC_M,      KC_W,      KC_V,   KC_Z,   SFT_T(S(KC_EQUAL)),
#endif
		           MO(SYMBNUM), MO(KEYNAV),  KC_NO,  KC_NO,  KC_NO,

		// right thumb cluster
		KC_NO, KC_ESC,
		KC_NO,
		KC_NO, GUI_T(KC_TAB), KC_SPACE
	),

	[SYMBNUM] = LAYOUT_ergodox(
		// left hand
		KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,        KC_TRNS,   KC_TRNS,
#ifdef DJP_QWERTY
		KC_TAB,   KC_GRAVE, S(KC_2), S(KC_MINUS), S(KC_EQUAL), S(KC_7),   KC_TRNS,
		KC_SPACE, S(KC_3),  S(KC_4), S(KC_9),     S(KC_0),     KC_RBRACKET,
		KC_TRNS,  KC_TRNS,  S(KC_5), KC_MINUS,    KC_EQUAL,    S(KC_6),   KC_TRNS,
#else
		KC_TAB,   KC_GRAVE, S(KC_2), S(KC_LBRACKET), S(KC_RBRACKET), S(KC_7),   KC_TRNS,
		KC_SPACE, S(KC_3),  S(KC_4), S(KC_9),        S(KC_0),        KC_EQUAL,
		KC_TRNS,  KC_TRNS,  S(KC_5), KC_LBRACKET,    KC_RBRACKET,    S(KC_6),   KC_TRNS,
#endif
		KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,        KC_TRNS,
		// left thumb cluster
		         KC_TRNS, KC_TRNS,
		                  KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,

		// right hand
#ifdef DJP_QWERTY
		KC_TRNS, KC_A,         KC_N,    KC_I,   KC_H,    KC_D,    KC_TRNS,
		KC_TRNS, S(KC_8),      KC_7,    KC_8,   KC_9,    KC_Y,    KC_BSLASH,
#else
		KC_TRNS, KC_A,         KC_B,    KC_C,   KC_D,    KC_E,    KC_TRNS,
		KC_TRNS, S(KC_8),      KC_7,    KC_8,   KC_9,    KC_F,    KC_BSLASH,
#endif
		         S(KC_BSLASH), KC_4,    KC_5,   KC_6,    KC_0,    KC_TRNS,
		KC_TRNS, S(KC_GRAVE),  KC_1,    KC_2,   KC_3,    S(KC_1), KC_TRNS,
#ifdef DJP_QWERTY
		                       KC_TRNS, KC_W,   KC_TRNS, KC_TRNS, KC_TRNS,
#else
		                       KC_TRNS, KC_DOT, KC_TRNS, KC_TRNS, KC_TRNS,
#endif

		// right thumb cluster
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	),  

	// key navigation layer
	[KEYNAV] = LAYOUT_ergodox(
		// left hand
		KC_TRNS, KC_F1,   KC_F2,      KC_F3,      KC_F4,       KC_F5,   KC_TRNS,
		KC_TRNS, KC_TRNS, KC_MS_BTN2, KC_MS_UP,   KC_MS_BTN1,  KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS,     KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, 

		// thumb cluster
		         KC_TRNS, KC_TRNS,
		                  KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS,

		// right hand
		KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_F12,
		         KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_PGDN, KC_PGUP, KC_TRNS,  KC_TRNS,
		                  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,

		// thumb cluster
		KC_TRNS, KC_TRNS,
		KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS
	),  
};

const uint16_t PROGMEM fn_actions[] = {
	[1] = ACTION_LAYER_TAP_TOGGLE(1)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		// handle customs here
		/*
		   case VRSN:
		   if (record->event.pressed) {
		   SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
		   }
		   return false;
		   break;
		   */
	}

	return true;
}

uint32_t layer_state_set_user(uint32_t state) {
	ergodox_board_led_off();
	ergodox_right_led_1_off();
	ergodox_right_led_2_off();
	ergodox_right_led_3_off();

	uint8_t layer = biton32(state);
	switch (layer) {
		case SYMBNUM:
			ergodox_right_led_1_on();        
			break;
		case KEYNAV:
			ergodox_right_led_2_on();
			break;
	}
	return state;
}

// vim:set ts=4 sw=4 sts=4:
