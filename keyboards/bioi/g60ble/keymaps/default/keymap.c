#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_60_iso_split_bs_rshift(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, LT(2,KC_NUHS),KC_ENT,
    KC_LSFT,LSFT_T(KC_NUBS),KC_Z,KC_X,  KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,MO(1),
    MO(1),   KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RALT, RCTL_T(KC_APP),KC_RCTL
),

[1] = LAYOUT_60_iso_split_bs_rshift(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, KC_DEL,
    KC_TAB,  KC_HOME, KC_UP,   KC_END,  RESET,   XXXXXXX, XXXXXXX, OUT_USB, OUT_BT,  KC_POWER,KC_PSCR, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT,
    KC_LSFT, XXXXXXX, BL_TOGG, BL_BRTG, KC_CAPS, BL_STEP, KC_PAUS, KC_NLCK, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI,          KC_RSFT,MO(1),
    MO(1),   KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, KC_RALT, KC_APP,  KC_RCTL
),

[2] = LAYOUT_60_iso_split_bs_rshift(
    KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, KC_DEL,
    KC_TAB,  KC_HOME, KC_UP,   KC_END,  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_POWER,KC_PSCR, XXXXXXX, XXXXXXX,
    KC_LCTL, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT,
    KC_LSFT, XXXXXXX, BL_TOGG, BL_BRTG, KC_CAPS, BL_STEP, KC_PAUS, KC_NLCK, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI,          KC_RSFT,MO(1),
    MO(1),   KC_LGUI, KC_LALT,                            KC_BTN1,                            KC_BTN2, KC_BTN2, KC_APP,  KC_RCTL
)

};

//F0 is the caps lock pin
void matrix_init_user(void) {
  DDRF &= ~(1 << 0); 
  PORTF &= ~(1 << 0);
}

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
        DDRF |= (1 << 0); PORTF &= ~(1 << 0);
    } else {
        DDRF &= ~(1 << 0); PORTF &= ~(1 << 0);
    }
}

// Light LED 0 yellow when cursor keys are active
const rgblight_segment_t PROGMEM my_cursor_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_YELLOW}
);
// Light LED 1 and 2 white when symbols are active
const rgblight_segment_t PROGMEM my_symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 2, HSV_WHITE}
);
// Light LED 2 blue when numlock is active
const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_CYAN}
);
// Light LED 2 yellow when numlock is inactive
const rgblight_segment_t PROGMEM my_nonumlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 1, HSV_YELLOW}
);
// Light LED 0,1 and 2 purple when function is active
const rgblight_segment_t PROGMEM my_function_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_PURPLE}
);
// Light LED 0 green when mouse keys are active
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE},
    {2, 1, HSV_YELLOW}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_nonumlock_layer,
    my_numlock_layer,     // Overrides other layers
    my_cursor_layer,    // Overrides caps lock layer
    my_symbols_layer,    // Overrides other layers
    my_function_layer,     // Overrides other layers
    my_mouse_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(1, led_state.num_lock);
    rgblight_set_layer_state(0, !led_state.num_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, 1) || layer_state_cmp(state, 2));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(4, layer_state_cmp(state, 1));
    rgblight_set_layer_state(5, layer_state_cmp(state, 1));
    rgblight_set_layer_state(3, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 1));
    return state;
}
