#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[0] = LAYOUT_all(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_GRV, KC_BSPC,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX, KC_RSFT, MO(1),
    KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    XXXXXXX, KC_RALT, LT(2,KC_DEL), LT(2,KC_DEL),KC_RCTL
),

[1] = LAYOUT_all(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, KC_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_PWR,  KC_PSCR, KC_UP,   XXXXXXX, KC_BSLS,
    LCTL_T(KC_CAPS),KC_A,KC_S, KC_D,    KC_F,    KC_G,    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_LEFT, KC_RIGHT,XXXXXXX, KC_PENT,
    _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_VAI, BL_TOGG, KC_NUM,  BL_BRTG, XXXXXXX, XXXXXXX, KC_DOWN, XXXXXXX, KC_RSFT, _______,
    KC_LCTL, _______, _______,                            KC_SPC,                    XXXXXXX, _______, KC_APP,  KC_APP,  KC_RCTL
),

[2] = LAYOUT_all(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_GRV, KC_DEL,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  KC_PWR,  KC_PSCR, KC_MS_U, XXXXXXX, KC_BSLS,
    LCTL_T(KC_CAPS),KC_A,KC_S, KC_D,    KC_F,    KC_G,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_MS_L, KC_MS_R, XXXXXXX, KC_PENT,
    _______, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD, RGB_VAD, BL_STEP, KC_NUM,  BL_BRTG, KC_WH_U, KC_WH_D, KC_MS_D, XXXXXXX, KC_RSFT, _______,
    KC_LCTL, _______, _______,                            KC_BTN1,                   XXXXXXX, KC_BTN2, _______, _______, KC_RCTL
)


};

