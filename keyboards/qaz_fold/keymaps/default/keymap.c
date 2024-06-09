#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _NUM_SYM,
  _NAV,
  _FN,
  _ALPHA
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    LCTL_T(KC_A), KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,     KC_ENT,
    LSFT_T(KC_Z), KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,          RSFT_T(KC_DOT),
    MO(_NAV),     KC_LGUI,KC_LALT, KC_SPACE, LT(_NUM_SYM,KC_SPACE),KC_RALT, KC_BSPC, LT(_FN,KC_DEL),
    KC_ESC, KC_TAB, KC_RSFT, MO(_ALPHA)
  ),

  [_ALPHA] = LAYOUT_split_space(
    KC_Q, KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,     KC_P,
    KC_A, KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,     KC_SCLN,
    KC_Z, KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM,          KC_DOT,
    MT(_NAV, KC_NUHS),    KC_NUBS,KC_LALT, KC_SPACE, LT(_NUM_SYM,KC_SPACE),KC_SLSH, KC_BSPC, KC_TRNS,
    KC_GRAVE, KC_TAB, KC_TRNS, KC_TRNS
  ),

  [_NUM_SYM] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    LCTL_T(KC_MINS), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SCLN, KC_QUOTE, KC_NUHS, KC_EQUAL,
    KC_LSFT, KC_Z, KC_NUBS, XXXXXXX, XXXXXXX, XXXXXXX, KC_SLSH, KC_LBRC, KC_RBRC,
    RGB_TOG, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_MINS, KC_EQUAL, KC_TRNS, KC_TRNS    
  ),

  [_NAV] = LAYOUT_split_space(
    KC_GRAVE,     XXXXXXX,   XXXXXXX,   QK_BOOT,   XXXXXXX,   KC_HOME,  KC_PGUP,   KC_PGDN,KC_RIGHT,    KC_BSPC,
    LCTL_T(KC_A), XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_LEFT,  KC_DOWN,   KC_UP,  KC_RIGHT,    KC_ENT,
    LSFT_T(KC_Z), RGB_TOG, XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   KC_M, KC_COMM,            RSFT_T(KC_DOT),
    MO(_NAV),     KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_RALT, KC_RGUI, KC_TRNS,
    KC_GRAVE, KC_CAPS, KC_TRNS, KC_TRNS    
  ),

  [_FN] = LAYOUT_split_space(
    KC_F1,         KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,   KC_F9,     KC_F10,
    LCTL_T(KC_A), KC_S,   KC_D,   KC_F,   KC_G,   KC_MS_L,  KC_MS_D,   KC_MS_U,  KC_MS_R, LT(3,KC_ENT),
    LSFT_T(KC_Z), KC_X, KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,            RSFT_T(KC_DOT),
    MO(_NAV),     KC_LALT, KC_LGUI, KC_BTN1, KC_BTN2, KC_RALT, KC_RGUI, KC_TRNS,
    KC_F11, KC_F12, KC_TRNS, KC_TRNS    
  )


};

void keyboard_post_init_user(void) {
    // Enable the LED layers
        rgblight_mode(RGBLIGHT_MODE_BREATHING);
        rgblight_sethsv_noeeprom(85, 255, 255);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BASE:
//        rgblight_setrgb (0x15,  0x00, 0x00);
        rgblight_mode(RGBLIGHT_MODE_BREATHING);
        uint8_t h = 85;
/*doesn't work here:        if (get_mods() & MOD_MASK_SHIFT) {
          h = 0;
        } else  if (get_mods() & MOD_MASK_CTRL) {
          h = 0;
        } else if (get_mods() & MOD_MASK_ALT) {
          h = 201;
        } else if (get_mods() & MOD_MASK_GUI) {
          h = 148;
        }*/
        rgblight_sethsv_noeeprom(h, 255, 255);
        break;
    case _NAV:
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb (0x15,  0x00, 0x15);
        break;
    case _FN:
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb (0x00,  0x15, 0x00);
        break;
    case _ALPHA:
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb (0x15,  0x15, 0x15);
        break;
    case _NUM_SYM:
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb (0x00,  0x15, 0x15);
        break;
    default: //  for any other layers, or the default layer
        rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        rgblight_setrgb (0x15,  0x00, 0x00);
        break;
    }
  return state;
}
