/* Copyright 2018 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define _DEFAULT 0
#define _ALPHA 1
#define _SPECIAL 2
#define _FUNC 3
#define _ASYMBOLS 4
#define _SYMBOLS 5

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR,
  REVPLUS,
  STARPSCR
};

// this is for switching between 2u backspace vs split backspace
#define KC_RBSP KC_BSPC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _DEFAULT: Base Layer (Default Layer)
   */
  // This base layer has cursor keys on the right and 2 function keys
[_DEFAULT] = LAYOUT(
  KC_7 ,  KC_8,   KC_9  , KC_MINS,  KC_ESC ,            KC_Q   , KC_W  , KC_E, KC_R  , KC_T, KC_Y, KC_U, KC_I   , KC_O  , KC_P   ,KC_NUBS,         KC_RBSP , \
  KC_4 ,  KC_5,   KC_6  , KC_EQL,   MT(MOD_LCTL,KC_TAB),KC_A   , KC_S  , KC_D, KC_F  , KC_G, KC_H, KC_J, KC_K   , KC_L  , KC_SCLN,                  KC_ENT  , \
  KC_1 ,  KC_2,   KC_3  , KC_NUBS,  KC_LSFT,            KC_Z   , KC_X,   KC_C, KC_V  , KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP  ,      LT(_FUNC,KC_SLSH), \
  KC_0,   KC_0,   KC_PDOT,KC_PENT,  MO(_SPECIAL),       KC_LGUI, KC_LALT,KC_SPC,LT(_SYMBOLS,KC_SPC),KC_SPC, LT(_SYMBOLS,KC_QUOTE),KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _ALPHA: Alpha Layer (no cursor keys on the right)
  */
[_ALPHA] = LAYOUT(
  KC_P7 , KC_P8,  KC_P9  ,KC_MINS,  KC_ESC ,            KC_Q   , KC_W  , KC_E, KC_R  , KC_T, KC_Y, KC_U, KC_I   , KC_O  , KC_P   ,KC_NUBS,         KC_RBSP , \
  KC_P4 , KC_P5,  KC_P6  ,REVPLUS,  MT(MOD_LCTL,KC_TAB),KC_A   , KC_S  , KC_D, KC_F  , KC_G, KC_H, KC_J, KC_K   , KC_L  , KC_SCLN,                  KC_ENT  , \
  KC_P1 , KC_P2,  KC_P3  ,STARPSCR, KC_LSFT,            KC_Z   , KC_X,   KC_C, KC_V  , KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH  ,      LT(_FUNC,KC_SLSH),          \
  KC_P0,  KC_P0,  KC_PDOT,KC_PENT,  LT(_SPECIAL,KC_NUHS),KC_LGUI,KC_LALT,KC_SPC,LT(_ASYMBOLS,KC_SPC),KC_SPC, LT(_ASYMBOLS,KC_QUOTE),MT(MOD_RALT,KC_LBRC),LT(_SYMBOLS,KC_QUOTE/*KC_APP*/),MT(MOD_RCTL,KC_RBRC)),

  /* Keymap _FUNC: Cursor keys on pad and mouse
  */
[_FUNC] = LAYOUT(
  KC_F7 , KC_F8,  KC_F9 , KC_F11,  KC_GRV,  S(KC_1) ,S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS),S(KC_EQL), \
  KC_F4 , KC_F5,  KC_F6 , KC_F12,  KC_LCTL, KC_WH_U, KC_SCROLL_LOCK, TO(_DEFAULT), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,          KC_BRK , \
  KC_F1 , KC_F2,  KC_F3 , KC_PSCR, KC_LSFT, KC_WH_D, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, KC_NUM_LOCK, XXXXXXX, XXXXXXX, KC_PDOT, KC_MS_U,   KC_RSFT , \
  KC_F10, KC_F10, KC_BRK, KC_SCROLL_LOCK, _______, KC_APP,  KC_LALT,                KC_MS_BTN1,     KC_MS_BTN1 , KC_MS_BTN2,KC_RALT, KC_MS_L, KC_MS_D, KC_MS_R),

  /* Keymap _SPECIAL: Function keys Layer
  */
[_SPECIAL] = LAYOUT(
  KC_HOME, KC_UP,  KC_PGUP, KC_PMNS,KC_GRV  ,XXXXXXX,XXXXXXX,TO(_DEFAULT),QK_BOOT,XXXXXXX,XXXXXXX,XXXXXXX,KC_INS, KC_PWR,KC_PSCR,KC_DEL,KC_DEL , \
  KC_LEFT, XXXXXXX,KC_RIGHT,KC_PPLS,MT(MOD_LCTL,KC_CAPS),TO(_ALPHA), KC_SCROLL_LOCK, TO(_DEFAULT), XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, KC_QUOTE, KC_BRK, \
  KC_END,  KC_DOWN,KC_PGDN, KC_CALC,KC_LSFT,          RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI,  KC_PAUS, KC_NUM_LOCK, XXXXXXX,XXXXXXX, XXXXXXX, KC_PGUP, KC_RSFT , \
  KC_INS,  KC_INS, KC_DEL,  KC_CALC,_______, KC_APP,  KC_LALT,                KC_SPC,       KC_SPC , KC_SPC,         OSM(MOD_RALT), KC_HOME,  KC_PGDN, KC_END),

  /* Keymap _SYMBOLS: Symbols Layer (holding right FN)
  */
[_SYMBOLS] = LAYOUT(
  S(KC_7) , S(KC_8),  S(KC_9),   KC_PSLS, KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
  S(KC_4) , S(KC_5),  S(KC_6),   KC_PAST, KC_LCTL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_QUOT, KC_NUHS, \
  S(KC_1) , S(KC_2),  S(KC_3)  , KC_CALC, KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX,RALT(KC_4),KC_SCLN,KC_QUOTE, KC_NUHS, KC_LBRC, KC_RBRC, KC_SLSH, KC_RSFT , \
  S(KC_0), S(KC_0),   S(KC_SLSH),KC_CALC, KC_LCTL, KC_APP,  KC_LALT,                KC_SPC,  KC_SPC , KC_SPC,_______ ,KC_RALT,XXXXXXX,XXXXXXX),

  /* Keymap _ASYMBOLS: Alpha-Symbols Layer (holding right Fn from Alphas layer)
  */
[_ASYMBOLS] = LAYOUT(
  S(KC_7) , S(KC_8),  S(KC_9),   KC_PSLS, KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
  S(KC_4) , S(KC_5),  S(KC_6),   KC_PAST, KC_LCTL,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX, KC_QUOT, KC_NUHS, \
  S(KC_1) , S(KC_2),  S(KC_3)  , KC_CALC, KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX,RALT(KC_4),KC_SCLN,KC_QUOTE, KC_NUHS, KC_LBRC, KC_RBRC, KC_UP, KC_RSFT , \
  S(KC_0),  S(KC_0),  S(KC_SLSH),KC_CALC, KC_LCTL, KC_APP,  KC_LALT,                KC_SPC,  KC_SPC , KC_SPC,_______ ,KC_LEFT,KC_DOWN, KC_RIGHT),
};

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case REVPLUS:
    mod_state = get_mods ();
    if (record->event.pressed) {
      if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        register_code(KC_EQL);
      } else {
        register_code(KC_LSFT);
        register_code(KC_EQL);
      }
      set_mods(mod_state);
    } else {
      unregister_code(KC_EQL);
    }
    return false;
  case STARPSCR:
    mod_state = get_mods ();
    if (record->event.pressed) {
      if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
        register_code(KC_PSCR);
      } else {
        register_code(KC_LSFT);
        register_code(KC_8);
      }
      set_mods(mod_state);
    } else {
      unregister_code(KC_8);
      unregister_code(KC_PSCR);
    }
    return false;
  }
  return true;
}

// Light LED 1 red when caps lock is pressed
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_RED}
);
// Light LED 0 yellow when non-cursor keys are active
const rgblight_segment_t PROGMEM my_cursor_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_WHITE}
);
// Light LED 2 and 3 white when symbols are active
const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 1, HSV_WHITE}
);
// Light LED 3 white when numlock is active
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_WHITE}
);
// Light LED 3 off when numlock is inactive
const rgblight_segment_t PROGMEM my_nonumlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 1, HSV_OFF}
);
// Light LED 0,2 and 3 purple when function is active
const rgblight_segment_t PROGMEM my_SPECIAL_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 2, HSV_PURPLE},
    {0, 1, HSV_PURPLE}
);
// Light LED 0 green when mouse keys are active
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE},
    {1, 1, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_nonumlock_layer,
    my_numlock_layer,     // Overrides other layers
    my_cursor_layer,    // Overrides caps lock layer
    my_symbols_layer,    // Overrides other layers
    my_SPECIAL_layer,     // Overrides other layers
    my_mouse_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    rgblight_set_layer_state(2, led_state.num_lock);
    rgblight_set_layer_state(1, !led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _DEFAULT) || layer_state_cmp(state, _ASYMBOLS));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(5, layer_state_cmp(state, _SPECIAL));
    rgblight_set_layer_state(6, layer_state_cmp(state, _FUNC));
    rgblight_set_layer_state(4, (layer_state_cmp(state, _SYMBOLS) || layer_state_cmp(state, _ASYMBOLS)));
    rgblight_set_layer_state(3, !(layer_state_cmp(state, _DEFAULT) || layer_state_cmp(state, _ASYMBOLS)));
    return state;
}
