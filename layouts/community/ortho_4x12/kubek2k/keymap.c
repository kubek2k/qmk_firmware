// Can't Remember Sh*t Keymap for 4x12 ortho
// http://www.keyboard-layout-editor.com/#/gists/c6c0ac051b2b118a34ef84ebadab54c7

#include QMK_KEYBOARD_H
#include "action_layer.h"
#ifdef AUDIO_ENABLE
  #include "audio.h"
#endif
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Fn/( |Ctrl/[| Alt/{| GUI/-| Lower|SpcLwr|  Tab | Raise| GUI/+| Alt/}|Ctrl/]| Fn/) |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,    KC_BSPC, \
  KC_TAB,  LCTL_T(KC_A),    LALT_T(KC_S),    LGUI_T(KC_D),    KC_F,   KC_G,    KC_H,    KC_J,   RGUI_T(KC_K), RALT_T(KC_L), RCTL_T(KC_SCLN), KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,    KC_M,   KC_COMM, KC_DOT, KC_SLSH, SFT_T(KC_ENT), \
  _LOWER, KC_LCTL, KC_LALT, KC_LGUI, LOWER,  LT(_LOWER, KC_SPC),  KC_TAB,  RAISE,  KC_RGUI, KC_RALT, KC_RCTL, _RAISE\
),

/* Lower   (switched to # because KP# were weird in terminal emulators)
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  Tab |  !   |  @   |  #   |   $  |  %   |   ^  |   &  |   *  |   (  |   )  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12( \
   XXXXXXX,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,  KC_8, KC_9,    KC_0,  KC_DEL, \
   _______,   LSFT(KC_1),   LSFT(KC_2),  LSFT(KC_3),   LSFT(KC_4),   LSFT(KC_5),   LSFT(KC_6),  LSFT(KC_7), LSFT(KC_8), LSFT(KC_9),  LSFT(KC_0), LSFT(KC_QUOT), \
   _______,   _______,   _______,   _______,  KC_LBRC,  KC_RBRC, _______,  _______,  _______, _______, KC_MINUS,  KC_EQUAL, \
   KC_ESC, _______, _______, _______, _______, _______,  _______, _______,  _______, _______, _______, _______ \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |   F1 |   F2  |  F3 |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |RightC| M-Up | LeftC|QWERTY| Left | Down |  Up  | Right|  |   |   `  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |  <   |  >   |  \   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  Ins |      | Home | PGDN | PGUP |  End |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12( \
  XXXXXXX,   KC_F1, KC_F2, KC_F3,  KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, \
  _______,   KC_VOLD,   KC_VOLU, KC_MUTE, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RIGHT,   _______,  KC_GRV, \
  _______,   KC_MPRV,   KC_MPLY, KC_MFFD, _______, _______, _______, _______, LSFT(KC_COMM), LSFT(KC_DOT), KC_BSLASH, _______, \
  _______,   _______,   _______, _______, MO(_ADJUST), _______, _______, _______, _______, _______,   _______,  _______ \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | C-A-I|Qwerty|      |      |Reset |Macro0|      |      |      |      |PLOVER|C-A-D |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Caps | Arrow|      |Aud on|Audoff| Game |AGswap|AGnorm| PrtSc|ScrLck| Break|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff| Prev | Next | Mute | VolDn| VolUp|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite|      |      |      |      | Play/Pause  |      | BL_T |BL_DEC|BL_INC|BL_ST |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12( \
  RESET, _______,   _______, _______, _______, _______,  _______, _______, _______, RGB_SAI, RGB_SAD, _______, \
  _______, _______, _______, _______,   _______,  _______, _______, _______,  _______, RGB_VAI,  RGB_VAD,  _______, \
  _______, _______,  _______,  _______,   _______,  _______, _______,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ , _______ , _______ \
)


};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // this is the function signature -- just copy/paste it into your keymap file as it is.
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      break;
  }
  return MACRO_NONE;
};

void persistant_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
    }
    return true;
}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
    case _RAISE:
        rgblight_sethsv (225,  100, rgblight_get_val());
        break;
    case _LOWER:
        rgblight_sethsv (0,  100, rgblight_get_val());
        break;
    case _ADJUST:
        rgblight_sethsv (290,  100, rgblight_get_val());
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv (117,  100, rgblight_get_val());
        break;
    }
  return state;
}

void matrix_init_user(void) {
        rgblight_sethsv (117,  100, rgblight_get_val());
}
