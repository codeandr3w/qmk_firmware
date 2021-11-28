/* Copyright 2021 Enrique Cabrera
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

enum _LAYERS {
  _BASE = 0,
  _EDIT,
  _MOUSE,
  _SYMBOLS,
  _FN,
  _CSYMBOLS
  };
  

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Default Alpha-only layer */
    KC_ESC,        KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    SFT_T(KC_NUBS),KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSHIFT,
    LT(_FN,KC_NUHS), KC_LGUI, KC_LALT,        LT(_CSYMBOLS,KC_SPC),  KC_SPC, LT(_CSYMBOLS,KC_QUOT),  RALT_T(KC_LBRC),KC_APP,RCTL_T(KC_RBRC)
  ),
  [_EDIT] = LAYOUT( /* Layer 1: Edit layer */
    KC_ESC,        KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    SFT_T(KC_NUBS),KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   RSFT_T(KC_SLSH),
    LT(_FN,KC_NUHS), KC_LGUI, KC_LALT,        LT(_SYMBOLS,KC_SPC),  KC_SPC, LT(_SYMBOLS,KC_QUOT),  KC_LEFT, KC_DOWN, KC_RIGHT
  ),  
  [_SYMBOLS] = LAYOUT( /* LAYER 2: Numbers/symbols */
    KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    S(KC_MINS),S(KC_1),S(KC_2),S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_NUHS),
    KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SLSH, KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,  KC_SPC,           KC_TRNS, RALT_T(KC_LBRC),KC_APP,RCTL_T(KC_RBRC)
  ),

  [_FN] = LAYOUT( /* LAYER 3: Function */
    KC_GRV,  XXXXXXX, XXXXXXX, TO(_EDIT),KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_PSCR, KC_DEL,
    KC_LCTL, TO(_BASE),XXXXXXX,XXXXXXX, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_QUOT, KC_NUHS,
    KC_LSFT, RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI, XXXXXXX, TO(_MOUSE),XXXXXXX,XXXXXXX,KC_PGUP, KC_RSFT,
    _______, KC_TRNS, KC_TRNS,                   KC_TRNS, KC_TRNS,          _______, KC_HOME, KC_PGDN, KC_END
  ),
  
  [_CSYMBOLS] = LAYOUT( /* LAYER 4: Numbers/symbols with cursor keys */
    KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    S(KC_MINS),S(KC_1),S(KC_2),S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_NUHS),
    KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_UP,   KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,  KC_SPC,           KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
  ),

  [_MOUSE] = LAYOUT( /* LAYER 5: Mouse and media keys */
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_U, KC_WH_D, KC_MS_U, KC_RSFT,
    _______, _______, _______,                   KC_BTN1,  KC_BTN2,         _______, KC_MS_L, KC_MS_D, KC_MS_R
  ),
};

const rgblight_segment_t PROGMEM my_edit_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED},
  {11,2, HSV_GREEN},
  {23,2, HSV_GREEN},
  {34,1, HSV_RED},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {39,1, HSV_GREEN},
  {41,1, HSV_GREEN},
  {45,1, HSV_BLUE},
  {46,1, HSV_RED},
  {48,1, HSV_RED},
  {50,1, HSV_RED},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12,HSV_BLACK},
  {12,1, HSV_GREEN},
  {13,11,HSV_BLACK},
  {24,1, HSV_GREEN},
  {25,7, HSV_BLACK},
  {32,3, HSV_WHITE},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {39,1, HSV_GREEN},
  {41,2, HSV_GREEN},
  {42,1, HSV_WHITE},
  {44,1, HSV_WHITE},
  {45,1, HSV_BLUE},
  {46,1, HSV_WHITE},
  {48,1, HSV_WHITE},
  {50,1, HSV_WHITE},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 10,HSV_CYAN},
  {24,1, HSV_GREEN},
  {26,6, HSV_BLACK},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {39,1, HSV_GREEN},
  {41,1, HSV_GREEN},
  {45,1, HSV_BLUE},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_symbolscursor_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 10,HSV_CYAN},
  {24,1, HSV_GREEN},
  {26,6, HSV_BLACK},
  {34,1, HSV_RED},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {39,1, HSV_GREEN},
  {41,1, HSV_GREEN},
  {45,1, HSV_BLUE},
  {46,1, HSV_RED},
  {48,1, HSV_RED},
  {50,1, HSV_RED},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}  
);

const rgblight_segment_t PROGMEM my_alpha_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED},
  {11,2, HSV_GREEN},
  {23,2, HSV_GREEN},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {39,1, HSV_GREEN},
  {41,1, HSV_GREEN},
  {45,1, HSV_BLUE},
  {46,1, HSV_GREEN},
  {48,1, HSV_GREEN},
  {50,1, HSV_GREEN},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 2, HSV_BLACK},
  {3, 1, HSV_BLUE},
  {4, 6, HSV_RED},
  {11,2, HSV_GREEN},
  {13,1, HSV_BLUE},
  {14,2, HSV_OFF},
  {16,6, HSV_RED},
  {20,2, HSV_RED},
  {24,1, HSV_GREEN},
  {25,5, HSV_RED},
  {30,1, HSV_OFF},
  {31,1, HSV_BLUE},
  {32,2, HSV_OFF},
  {36,1, HSV_GREEN},
  {37,1, HSV_BLUE},
  {41,1, HSV_GREEN},
  {45,1, HSV_BLUE},
  {46,1, HSV_GREEN},
  {48,1, HSV_GREEN},
  {50,1, HSV_GREEN},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}  
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(  
  my_alpha_layer,
  my_edit_layer,
  my_symbols_layer,
  my_fn_layer,
  my_symbolscursor_layer,
  my_mouse_layer
);

bool led_update_user(led_t led_state) {
  rgblight_set_layer_state(0, true);
  return true;
}

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, 0));
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  bool l0 = layer_state_cmp(state, _BASE);
  bool l1 = layer_state_cmp(state, _EDIT);
  bool l2 = layer_state_cmp(state, _SYMBOLS);
  bool l3 = layer_state_cmp(state, _FN);
  bool l4 = layer_state_cmp(state, _CSYMBOLS);
  bool l5 = layer_state_cmp(state, _MOUSE);
  rgblight_set_layer_state(3, l3);
  rgblight_set_layer_state(2, l2);
  rgblight_set_layer_state(1, !l0 && l1 && !l2 && !l3 && !l4 && !l5);
  rgblight_set_layer_state(0, l0 && !l1 && !l2 && !l3 && !l4 && !l5);
  rgblight_set_layer_state(4, l4);
  rgblight_set_layer_state(5, l5);
  return state;
}  