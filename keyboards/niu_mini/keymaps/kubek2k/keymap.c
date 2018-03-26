#include "kb.h"

#define BASE_LAYER 0
#define NUMBER_LAYER 1
#define SYMBOL_LAYER 2
#define GUI_LAYER 3
#define NAVIGATION_LAYER 4
#define KEYBOARD_LAYER 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = {
{        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, LT(5, KC_QUOT), },
{        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(4, KC_SCLN), CTL_T(KC_ENT), },
{        KC_LSPO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSPC, },
{        LT(3, KC_LBRC), ALL_T(LSFT(KC_LBRC)), KC_LALT, KC_LGUI, MO(1), KC_SPC, KC_SPC, MO(2), KC_RGUI, KC_RALT, ALL_T(LSFT(KC_RBRC)), LT(3, KC_RBRC) }
    },

    [NUMBER_LAYER] = { 
{        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, },
{        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, },
{        KC_TRNS, KC_MINS, KC_EQL, KC_GRV, KC_BSLS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
    },

    [SYMBOL_LAYER] = { 
{        KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS, },
{        KC_TRNS, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_TRNS, },
{        KC_TRNS, KC_UNDS, KC_PLUS, KC_TILD, KC_PIPE, KC_TRNS, KC_TRNS, KC_TRNS, KC_LABK, KC_RABK, KC_QUES, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
    },

    [GUI_LAYER] = {
{        LGUI(KC_GRV), LCTL(LALT(LSFT(KC_1))), LCTL(LALT(LSFT(KC_2))), LCTL(LALT(LSFT(KC_3))), LCTL(LALT(LSFT(KC_4))), LCTL(LALT(LSFT(KC_5))), LCTL(LALT(LSFT(KC_6))), LCTL(LALT(LSFT(KC_7))), LCTL(LALT(LSFT(KC_8))), LCTL(LALT(LALT(KC_9))), LCTL(LALT(LSFT(KC_0))), LGUI(KC_TAB), },
{        KC_TRNS, LALT(LSFT(KC_A)), LALT(LSFT(KC_S)), LALT(LSFT(KC_D)), LALT(LSFT(KC_F)), KC_TRNS, LALT(LSFT(KC_H)), LALT(LSFT(KC_J)), LALT(LSFT(KC_K)), LALT(LALT(KC_L)), KC_TRNS, KC_TRNS, },
{        KC_TRNS, LALT(LSFT(KC_Z)), KC_TRNS, KC_TRNS, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, LALT(LSFT(KC_COMM)), LALT(LSFT(KC_DOT)), KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_SLCK, LALT(LSFT(KC_SPC)), LALT(LSFT(KC_SPC)), KC_PAUS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS }
    },

    [NAVIGATION_LAYER] = {
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_HOME, KC_PGUP, KC_PGDN, KC_END, KC_LEFT, KC_UP, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
    },

    [KEYBOARD_LAYER] = {
{        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        BL_TOGG, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, },
{        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS }
    },
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
