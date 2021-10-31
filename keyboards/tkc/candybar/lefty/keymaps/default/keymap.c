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

#define _BL 0
#define _PADL 1
#define _FN 2
#define _FD 3
#define _FNS 4
#define _SYMBOLS 5

enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR,
  REVPLUS,
  STARPSCR
};

#define RIGHTCURSOR
//#define FOUROPS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: Base Layer (Default Layer)
   */
  #ifdef RIGHTCURSOR
  #ifndef FOUROPS
  // This base layer has cursor keys on the right and 2 function keys
[_BL] = LAYOUT(
  KC_7  , KC_8,  KC_9   ,KC_MINS,          KC_ESC ,            KC_Q   , KC_W  , KC_E, KC_R  , KC_T, KC_Y, KC_U, KC_I   , KC_O  , KC_P   ,KC_LBRC ,         KC_BSPC , \
  KC_4  , KC_5,  KC_6   ,REVPLUS,          MT(MOD_LCTL,KC_TAB),KC_A   , KC_S  , KC_D, KC_F  , KC_G, KC_H, KC_J, KC_K   , KC_L  , KC_SCLN,                  KC_ENT  , \
  KC_1  , KC_2,  KC_3   ,LT(_PADL,KC_NUBS),KC_LSFT,            KC_Z   , KC_X,   KC_C, KC_V  , KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP  ,      MT(MOD_RSFT,KC_SLSH), \
  KC_0, KC_QUOTE,KC_SLSH,MO(_FD),          LT(_FN,KC_NUHS),    KC_LGUI, KC_LALT,KC_SPC,LT(_SYMBOLS,KC_SPC),KC_SPC, LT(_SYMBOLS,KC_QUOTE),KC_LEFT, KC_DOWN, KC_RGHT),
  #else
  // This base layer has cursor keys on the right and 2 function keys, but with 4 operator keys on the num pad
[_BL] = LAYOUT(
  KC_7  , KC_8,  KC_9   ,STARPSCR,       KC_ESC ,  KC_Q   , KC_W  , KC_E, KC_R  , KC_T, KC_Y, KC_U, KC_I   , KC_O  , KC_P   ,KC_LBRC ,         KC_BSPC , \
  KC_4  , KC_5,  KC_6   ,LT(_PADL,KC_MINS),MT(MOD_LCTL,KC_TAB),KC_A   , KC_S  , KC_D, KC_F  , KC_G, KC_H, KC_J, KC_K   , KC_L  , KC_SCLN,                  KC_ENT  , \
  KC_1  , KC_2,  KC_3   ,REVPLUS,        KC_LSFT,            KC_Z   , KC_X,   KC_C, KC_V  , KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_UP  ,      MT(MOD_RSFT,KC_SLSH), \
  KC_0, KC_QUOTE,KC_SLSH,MO(_FD),        LT(_FN,KC_NUHS),    KC_LGUI, KC_LALT,KC_SPC,LT(_SYMBOLS,KC_SPC),KC_SPC, LT(_SYMBOLS,KC_QUOTE),KC_LEFT, KC_DOWN, KC_RGHT),
  #endif
  #else
  // This base layer has cursor keys on the left and 1 function key
[_BL] = LAYOUT(
  KC_7  , KC_8,  KC_9   , KC_MINS, KC_ESC ,            KC_Q   , KC_W   , KC_E, KC_R   , KC_T  , KC_Y, KC_U   , KC_I   , KC_O   , KC_P   , KC_LBRC , KC_BSPC , \
  KC_4  , KC_5,  KC_6   , REVPLUS, MT(MOD_LCTL,KC_TAB),KC_A   , KC_S   , KC_D, KC_F   , KC_G  , KC_H, KC_J   , KC_K   , KC_L   , KC_SCLN,          KC_ENT  , \
  KC_1  , KC_2,  KC_3   , KC_UP,   KC_LSFT,            KC_Z   , KC_X, KC_C   , KC_V  , KC_B, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT , \
  KC_0,  KC_LEFT,KC_DOWN, KC_RIGHT,MO(_FN),            KC_LGUI, KC_LALT,                KC_SPC,       KC_SPC , KC_SPC,  KC_RALT, KC_QUOT, KC_NUBS, KC_RALT),
  #endif
  
  /* Keymap _PADL: Numpad Layer
  */
  #ifndef FOUROPS
  [_PADL] = LAYOUT(
  KC_P7 , KC_P8, KC_P9  , KC_PMNS, KC_ESC  ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, KC_BSPC, KC_BSPC , \
  KC_P4 , KC_P5, KC_P6  , KC_PPLS,MT(MOD_LCTL,KC_TAB),XXXXXXX,KC_SLCK, TO(_BL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT , \
  KC_P1 , KC_P2, KC_P3  , KC_PAST, KC_LSFT,          XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, KC_NLCK, XXXXXXX, XXXXXXX, KC_PDOT, KC_PSLS, KC_RSFT , \
  KC_P0,  KC_PDOT,KC_PSLS,_______, _______, KC_APP,  KC_LALT,        KC_SPC,     KC_SPC , KC_SPC,                   KC_APP  ,XXXXXXX, XXXXXXX, XXXXXXX),
  #else
  [_PADL] = LAYOUT(
  KC_P7 , KC_P8, KC_P9  , KC_PAST, KC_ESC  ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR, KC_BSPC, KC_BSPC , \
  KC_P4 , KC_P5, KC_P6  , KC_PMNS,MT(MOD_LCTL,KC_TAB),XXXXXXX,KC_SLCK, TO(_BL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PENT , \
  KC_P1 , KC_P2, KC_P3  , KC_PPLS, KC_LSFT,          XXXXXXX, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, KC_NLCK, XXXXXXX, XXXXXXX, KC_PDOT, KC_PSLS, KC_RSFT , \
  KC_P0,  KC_PDOT,KC_PSLS,KC_PENT, _______, KC_APP,  KC_LALT,        KC_SPC,     KC_SPC , KC_SPC,                   KC_APP  ,XXXXXXX, XXXXXXX, XXXXXXX),
  #endif

  /* Keymap _FD: Numpad as cursor keys layer and mouse
  */
  [_FD] = LAYOUT(
  KC_HOME, KC_UP,   KC_PGUP ,_______,KC_1  ,KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9,  KC_0, KC_MINS, KC_EQL,  KC_EQL, \
  KC_LEFT, XXXXXXX, KC_RIGHT,_______,KC_LCTL, KC_WH_U, KC_SLCK, TO(_BL), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT,          KC_PENT , \
  KC_END,  KC_DOWN, KC_PGDN ,_______,KC_LSFT, KC_WH_D, XXXXXXX, KC_CALC, XXXXXXX, XXXXXXX, KC_NLCK, XXXXXXX, XXXXXXX, KC_PDOT, KC_MS_U,   KC_RSFT , \
  KC_INS,  KC_DEL,  XXXXXXX, _______,_______, KC_APP,  KC_LALT,                KC_MS_BTN1,     KC_MS_BTN1 , KC_MS_BTN2,  KC_RALT, KC_MS_L, KC_MS_D, KC_MS_R),

  /* Keymap _FN: Function key Layer
  */
  [_FN] = LAYOUT(
  KC_F7 , KC_F8,  KC_F9 , KC_PGUP, KC_GRV  ,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,KC_INS, XXXXXXX,KC_PSCR,KC_RBRC,KC_DEL , \
  KC_F4 , KC_F5,  KC_F6 , KC_PGDN,MT(MOD_LCTL,KC_CAPS),XXXXXXX, KC_SLCK, TO(_BL), XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX, KC_QUOTE, KC_NUHS, \
  KC_F1 , KC_F2,  KC_F3 , XXXXXXX, KC_LSFT,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAUS, TO(_PADL),XXXXXXX,XXXXXXX, XXXXXXX, KC_PGUP, KC_RSFT , \
  KC_F10, KC_F11, KC_F12, _______, _______, KC_APP,  KC_LALT,                KC_SPC,       KC_SPC , KC_SPC,         OSM(MOD_RALT), KC_HOME,  KC_PGDN, KC_END),

  /* Keymap _SYMBOLS: Symbols Layer (holding AltGr)
  */
  [_SYMBOLS] = LAYOUT(
  KC_7 , KC_8,  KC_9   , KC_MINS, RALT(KC_GRV),KC_1,KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL, \
  RALT(KC_4),KC_5,KC_6 , REVPLUS, KC_LCTL, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), S(KC_MINS), \
  KC_1 , KC_2,  KC_3   , XXXXXXX, KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX,RALT(KC_4),XXXXXXX,XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_SLSH, KC_RSFT , \
  KC_0,KC_QUOTE,KC_SLSH, _______, _______, KC_APP,  KC_LALT,                KC_SPC,  KC_SPC , KC_SPC,_______ ,OSM(MOD_RALT),KC_MINS, KC_EQL),
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
        register_code(KC_LSHIFT);
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
        register_code(KC_LSHIFT);
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