/* Copyright 2021 Yiancar-Designs
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

enum custom_keycodes {
    KC_P00 = QK_KB_0
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_all( /* Base */
<<<<<<< HEAD:keyboards/geonworks/w1_at/keymaps/via/keymap.c
    KC_F1, KC_F2,     QK_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,    KC_NUM,  KC_PMNS, KC_PSLS, KC_PAST,
    KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,            KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
    KC_F5, KC_F6,     KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,             KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
    KC_F7, KC_F8,     KC_LSFT, KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, MO(1),              KC_P1,   KC_P2,   KC_P3,   KC_PMNS,
    KC_F9, KC_F10,    KC_LCTL,          KC_LALT,                        KC_SPC,                                    KC_RALT,          KC_RCTL,            KC_P0,   KC_P00,  KC_PDOT, KC_PENT),
=======
    KC_F1, KC_F2,     KC_GRAVE,KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUBS, KC_BSPC,   KC_ESC,  KC_NLCK, KC_SLCK, LT(1,KC_PSCR),
    KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,            KC_P7,   KC_P8,   KC_P9,   KC_PAST,
    KC_F5, KC_F6,     KC_LCTL, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,             KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
    KC_F7, KC_F8,     KC_LSFT, KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,            KC_P1,   KC_P2,   KC_P3,   KC_PPLS,
    KC_F9, KC_F10,    MT(MOD_RALT,KC_LALT),      KC_LALT,                        KC_SPC,                                    KC_RALT,          KC_CAPS,            KC_P0,   KC_P00,  KC_PDOT, KC_PPLS),
>>>>>>> 0773eb33d5f53acd7bbce9e7802d4713115ef295:keyboards/w1_at/keymaps/via/keymap.c

[1] = LAYOUT_all( /* FN */
    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(2),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,     XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUSE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
    XXXXXXX, XXXXXXX, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_R,          KC_MS_BTN2,          XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,
    XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_D, KC_TRNS, KC_TRNS,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LGUI, KC_RGUI, KC_LALT,          KC_TRNS,                            KC_MS_BTN1,                                  KC_RALT,          KC_RALT,             XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT),

[2] = LAYOUT_all( /* Base for 7u */
    KC_F1, KC_F2,     KC_GRAVE,KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_NUBS, KC_BSPC,   KC_ESC,  KC_NLCK, KC_SLCK, LT(3,KC_PSCR),
    KC_F3, KC_F4,     KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_NUHS,            KC_P7,   KC_P8,   KC_P9,   KC_PAST,
    KC_F5, KC_F6,     MT(MOD_LCTL,KC_CAPS),KC_A,KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,    KC_P4,   KC_P5,   KC_P6,   KC_PMNS,
    KC_F7, KC_F8,     KC_LSFT, KC_NUBS, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RGUI,            KC_P1,   KC_P2,   KC_P3,   KC_PPLS,
    KC_F9, KC_F10,    KC_LCTL,          KC_LALT,                        KC_SPC,                                    KC_RALT,          KC_RCTL,            KC_P0,   KC_P00,  KC_PDOT, KC_PPLS),

[3] = LAYOUT_all( /* Mod for 7u */
    KC_F11,  KC_F12,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(0),   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_DEL,     XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUSE,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX,             XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR,
    XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_R,          KC_MS_BTN2,          XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS,
    XXXXXXX, XXXXXXX, KC_TRNS, XXXXXXX, KC_VOLU, KC_VOLD, KC_MUTE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MS_D, KC_TRNS, KC_TRNS,             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_LGUI, KC_RGUI, KC_LCTL,          KC_LALT,                            KC_MS_BTN1,                                  KC_RALT,          KC_RCTL,             XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT),
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch(keycode) {
            case KC_P00:
                tap_code(KC_P0);
                tap_code(KC_P0);
                return false;
        }
    }
    return true;
}
