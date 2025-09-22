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


#include QMK_KEYBOARD_H

enum _LAYERS {
  _EDIT = 0,
  _BASE,
  _SYMBOLS,
  _FUNCTION,
  _CSYMBOLS,
  _FN
  };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT( /* Default Alpha-only layer */
    KC_ESC,        KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    SFT_T(KC_NUBS),KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH, MO(_FN),
    MO(_FUNCTION), KC_LGUI, KC_LALT,      KC_SPC,    LT(_CSYMBOLS,KC_SPC),  LT(_CSYMBOLS,KC_QUOT),  RALT_T(KC_LBRC),LT(_SYMBOLS,KC_APP),RCTL_T(KC_RBRC)
  ),
  [_EDIT] = LAYOUT( /* Edit layer */
    KC_ESC,        KC_Q,    KC_W,    KC_E,  KC_R, KC_T,    KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_TAB), KC_A,    KC_S,    KC_D,  KC_F, KC_G,    KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT,       KC_Z,    KC_X,    KC_C,  KC_V, KC_B,    KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_UP,   MO(_FN),
    MO(_FUNCTION), KC_LGUI, KC_LALT,      KC_SPC,    LT(_SYMBOLS,KC_SPC), LT(_SYMBOLS,KC_QUOT),  KC_LEFT, KC_DOWN, KC_RIGHT
  ),
  [_SYMBOLS] = LAYOUT( /* LAYER 2: Numbers/symbols */
    KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_LCTL, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, KC_NUHS,
    KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SLSH, KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,  KC_TRNS,           KC_TRNS, KC_RALT,KC_RGUI,KC_RCTL
  ),

  [_FUNCTION] = LAYOUT( /* LAYER 3: Function */
    KC_GRV,   XXXXXXX, XXXXXXX, TO(_EDIT),QK_BOOT,  XXXXXXX,    XXXXXXX,  XXXXXXX,KC_INS, KC_PWR, KC_PSCR, KC_DEL,
    LCTL_T(KC_CAPS),TO(_BASE),KC_SCROLL_LOCK,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,  XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, KC_BRK,
    KC_LSFT, RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, RGB_SAI,  KC_NUM_LOCK,     XXXXXXX,XXXXXXX,XXXXXXX, KC_MS_U, KC_RSFT,
    _______, KC_TRNS, KC_TRNS,                   KC_SPC,   KC_SPC,             _______,KC_HOME, KC_PGDN, KC_MS_D
  ),

  [_FN] = LAYOUT( /* LAYER: Fn  keys */
    KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_LCTL,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LSFT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D, KC_WH_U, KC_MS_U, _______,
    _______,_______, _______,                   KC_SPC,  KC_BTN1,          _______, KC_MS_L, KC_MS_D, KC_MS_R
  ),

  [_CSYMBOLS] = LAYOUT( /* LAYER 4: Numbers/symbols with cursor keys */
    KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    KC_LCTL,S(KC_1),S(KC_2),S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_NUHS),
    KC_LSFT, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_UP,   KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS,                   KC_SPC,  KC_SPC,           KC_TRNS, KC_LEFT, KC_DOWN, KC_RIGHT
  )
};

#ifndef RGBLIGHT_ENABLE
typedef struct {
    uint8_t index;  // The first LED to light
    uint8_t count;  // The number of LEDs to light
    uint8_t hue;
    uint8_t sat;
    uint8_t val;
} rgblight_segment_t;

#    define RGBLIGHT_END_SEGMENT_INDEX (255)
#    define RGBLIGHT_END_SEGMENTS \
        { RGBLIGHT_END_SEGMENT_INDEX, 0, 0, 0 }
#    ifndef RGBLIGHT_MAX_LAYERS
#        define RGBLIGHT_MAX_LAYERS 8
#    endif
#    if RGBLIGHT_MAX_LAYERS <= 0
#        error invalid RGBLIGHT_MAX_LAYERS value (must be >= 1)
#    elif RGBLIGHT_MAX_LAYERS <= 8
typedef uint8_t rgblight_layer_mask_t;
#    elif RGBLIGHT_MAX_LAYERS <= 16
typedef uint16_t rgblight_layer_mask_t;
#    elif RGBLIGHT_MAX_LAYERS <= 32
typedef uint32_t rgblight_layer_mask_t;
#    else
#        error invalid RGBLIGHT_MAX_LAYERS value (must be <= 32)
#    endif
#    define RGBLIGHT_LAYER_SEGMENTS(...) \
        { __VA_ARGS__, RGBLIGHT_END_SEGMENTS }
#    define RGBLIGHT_LAYERS_LIST(...) \
        { __VA_ARGS__, NULL }


#endif

#define HSV_MOD HSV_WHITE

const rgblight_segment_t PROGMEM my_edit_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_RED},
  {11,2, HSV_MOD},
  {23,2, HSV_MOD},
  {34,1, HSV_RED},
  {36,1, HSV_BLUE},
  {37,1, HSV_BLUE},
  {39,1, HSV_MOD},
  {41,1, HSV_MOD},
  {45,1, HSV_BLUE},
  {46,1, HSV_RED},
  {48,1, HSV_RED},
  {50,1, HSV_RED},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 10,HSV_CYAN},
  {12,1, HSV_MOD},
  {24,1, HSV_MOD},
  {26,6, HSV_BLACK},
  {36,1, HSV_MOD},
  {37,1, HSV_BLUE},
  {39,1, HSV_MOD},
  {41,1, HSV_MOD},
  {45,1, HSV_BLUE},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_symbolscursor_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 10,HSV_CYAN},
  {24,1, HSV_MOD},
  {26,6, HSV_BLACK},
  {34,1, HSV_RED},
  {36,1, HSV_MOD},
  {37,1, HSV_BLUE},
  {39,1, HSV_MOD},
  {41,1, HSV_MOD},
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
  {11,2, HSV_MOD},
  {23,2, HSV_MOD},
  {36,1, HSV_BLUE},
  {37,1, HSV_BLUE},
  {39,1, HSV_MOD},
  {41,1, HSV_MOD},
  {45,1, HSV_BLUE},
  {46,1, HSV_MOD},
  {48,1, HSV_MOD},
  {50,1, HSV_MOD},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 2, HSV_BLACK},
  {3, 1, HSV_BLUE},
  {4, 1, HSV_RED},
  {5, 3, HSV_OFF},
  {8, 7, HSV_MOD},
  {13,1, HSV_BLUE},
  {14,1, HSV_MOD},
  {15,8, HSV_OFF},
  {23,2, HSV_MOD},
  {25,5, HSV_RED},
  {30,1, HSV_MOD},
  {31,3, HSV_OFF},
  {34,1, HSV_MOD},
  {36,1, HSV_MOD},
  {37,1, HSV_BLUE},
  {41,1, HSV_MOD},
  {45,1, HSV_BLUE},
  {46,1, HSV_MOD},
  {48,1, HSV_MOD},
  {50,1, HSV_MOD},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 12,HSV_RED},
  {12,1, HSV_MOD},
  {13,11,HSV_OFF},
  {24,1, HSV_MOD},
  {25,7, HSV_OFF},
  {32,3, HSV_RED},
  {37,1, HSV_BLUE},
  {41,1, HSV_MOD},
  {45,1, HSV_BLUE},
  {46,1, HSV_MOD},
  {48,1, HSV_MOD},
  {50,1, HSV_MOD},
  {35,1, HSV_BLACK},
  {43,1, HSV_BLACK},
  {47,1, HSV_BLACK},
  {49,1, HSV_BLACK}
);

const rgblight_segment_t PROGMEM my_caps_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {12,1, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_alpha_layer,
  my_edit_layer,
  my_symbols_layer,
  my_function_layer,
  my_symbolscursor_layer,
  my_caps_layer,
  my_fn_layer
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
//    rgblight_set_layer_state(2, led_state.num_lock);
    return true;
}

void keyboard_post_init_user(void) {
  rgblight_layers = my_rgb_layers;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _EDIT));
  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  bool l0 = layer_state_cmp(state, _BASE);
  bool l1 = layer_state_cmp(state, _EDIT);
  bool l2 = layer_state_cmp(state, _SYMBOLS);
  bool l3 = layer_state_cmp(state, _FUNCTION);
  bool l4 = layer_state_cmp(state, _CSYMBOLS);
  bool l6 = layer_state_cmp(state, _FN);
  rgblight_set_layer_state(3, l3);
  rgblight_set_layer_state(2, l2);
  rgblight_set_layer_state(1, l1 && !l2 && !l3 && !l4 && !l6);
  rgblight_set_layer_state(0, l0 && !l1 && !l2 && !l3 && !l4 && !l6);
  rgblight_set_layer_state(4, l4);
  rgblight_set_layer_state(6, l6);
  return state;
}


#ifdef RGB_MATRIX_ENABLE
#error Removed
const rgblight_segment_t* current_lights = my_alpha_layer;

layer_state_t layer_state_set_user(layer_state_t state) {
  if (layer_state_cmp(state, _SYMBOLS))
    current_lights = my_symbols_layer;
  else if (layer_state_cmp(state, _FUNCTION))
    current_lights = my_function_layer;
  else if (layer_state_cmp(state, _CSYMBOLS))
    current_lights = my_symbolscursor_layer;
  else if (layer_state_cmp(state, _EDIT))
    current_lights = my_edit_layer;
  else if (layer_state_cmp(state, _FN))
    current_lights = my_fn_layer;
  else
    current_lights = my_alpha_layer;
  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
  current_lights = my_alpha_layer;
  return true;
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
  int i=0;
  int mv = rgb_matrix_config.hsv.v;
  while (current_lights [i].index != 255) {
    HSV hsv;
    hsv.h = current_lights [i].hue;
    hsv.s = current_lights [i].sat;
    hsv.v = current_lights [i].val;
    if (hsv.v > mv) hsv.v = mv;
    RGB rgb = hsv_to_rgb(hsv);
    int l = current_lights [i].index;
    int n = current_lights [i].count;
    while (n-- > 0)
      rgb_matrix_set_color(l++, rgb.r, rgb.g, rgb.b);
    ++i;
  }
  if (host_keyboard_leds() & (1 << USB_LED_CAPS_LOCK)) {
    rgb_matrix_set_color(12,  0, 255, 0);
  }
}
#endif
