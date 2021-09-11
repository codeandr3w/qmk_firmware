/* Copyright 2020 Boardsource
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

enum layers {
    _ALPHA,   //  this layer matches the symbols on the keycaps
    _EDIT,    //  this layer is for editing it has cursor keys and natural shift placement
    _FUNCTION,//  this layer has function keys and numpad
    _SYMBOLS, //  this layer has all the symbols on it
    _NUMPAD,  //  this layer has a numpad
    _MOUSE,   //  this layer has mouse keys and media keys
    _FNL,     //  this layer is always used with the left bottom long key
    _FNR,      //  this layer is always used with the right bottom long key
    _ALPHAH   // duplicate of Alpha for overlaying alpha on top
};

enum KCOL_KEYTYPES {
        KCOL_ALPHA,
        KCOL_NUM,
        KCOL_MOD,
        KCOL_LAYER,
        KCOL_SYMBOL,
        KCOL_BLANK,
        KCOL_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA] = LAYOUT(
    KC_TAB,    KC_Q,      KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,   KC_A,      KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    MT(MOD_LSFT,KC_1),KC_2,KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_9,    MT(MOD_RSFT,KC_0),
    LT(_SYMBOLS,KC_3),MT(MOD_LGUI,KC_4),MT(MOD_LALT,KC_5),MO(_FNL),MT(MOD_LSFT,KC_SPC),KC_SPC,MO(_FNR),MT(MOD_RALT,KC_6),KC_7,KC_8
  ),

  [_ALPHAH] = LAYOUT(
    KC_TAB,    KC_Q,      KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,   KC_A,      KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    MT(MOD_LSFT,KC_1),KC_2,KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_9,    MT(MOD_RSFT,KC_0),
    LT(_SYMBOLS,KC_3),MT(MOD_LGUI,KC_4),MT(MOD_LALT,KC_5),MO(_FNL),MT(MOD_LSFT,KC_SPC),KC_SPC,MO(_FNR),MT(MOD_RALT,KC_6),KC_7,KC_8
  ),

  [_FNL] = LAYOUT(
    KC_ESC,  KC_GRV,  XXXXXXX, TO(_EDIT), XXXXXXX, KC_HOME,   KC_PGUP,KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC, KC_DEL,
    KC_LCTL, XXXXXXX, TO(_SYMBOLS), TO(_ALPHA),OSL(_FUNCTION),KC_END, KC_PGDN,  KC_SCOLON,KC_QUOTE, KC_NUHS, KC_ENT, 
    _______, KC_NUBS, RGB_TOG, RGB_MOD, RGB_HUD,  RGB_VAD, RGB_SAD, TO(_NUMPAD),TO(_MOUSE),KC_DOT,  KC_UP,   KC_SLSH,
    TO(_ALPHA),OSM(MOD_LGUI),OSM(MOD_LALT),_______, KC_LSHIFT,KC_SPC, OSM(MOD_RALT),      KC_LEFT,  KC_DOWN, KC_RIGHT 
  ),

  [_FNR] = LAYOUT(
    _______, S(KC_GRV), _______, TO(_EDIT),  _______,  S(KC_HOME),   S(KC_PGUP),S(KC_MINS),S(KC_EQL),S(KC_LBRC),S(KC_RBRC), _______,
    _______, _______,   _______, TO(_ALPHA), OSL(_FUNCTION),S(KC_END), S(KC_PGDN),  S(KC_SCOLON),S(KC_QUOTE), S(KC_NUHS), _______, 
    _______, S(KC_NUBS),_______, RGB_RMOD,   RGB_HUI,  RGB_VAI, RGB_SAI, TO(_NUMPAD),TO(_MOUSE),S(KC_DOT),S(KC_UP),S(KC_SLSH),
    _______, OSM(MOD_RGUI),OSM(MOD_RALT),_______, KC_LSHIFT,KC_SPC, _______,            S(KC_LEFT),  S(KC_DOWN), S(KC_RIGHT) 
  ),

  [_FUNCTION] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_INS,  XXXXXXX, KC_PSCR,KC_BSPC,
    KC_LCTL, XXXXXXX, KC_SLCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_ENT,
    KC_F1,   KC_F2,   KC_F11,  KC_F12,  KC_CAPS, XXXXXXX, XXXXXXX, XXXXXXX, KC_APP,  XXXXXXX, KC_9,   KC_0,
    KC_F3,   KC_F4,   KC_F5,   KC_LALT, KC_LSHIFT,KC_SPC, KC_RALT,                   KC_6,    KC_7,   KC_8
 ),
 
  [_MOUSE] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, KC_BRIU, XXXXXXX, XXXXXXX, KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, XXXXXXX,
    KC_LCTL, KC_WH_U, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, KC_ENT,
    KC_LSFT, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, KC_MS_U, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, MO(_FNL),KC_BTN1, KC_BTN2, MO(_FNR),                  KC_MS_L, KC_MS_D, KC_MS_R
 ),
 
  [_NUMPAD] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_BSPC,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PENT,
    KC_1,    KC_2,    XXXXXXX, KC_NLCK, KC_CALC, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_9,    KC_0,
    KC_3,    KC_4,    KC_5,    MO(_FNL),KC_LSHIFT,KC_SPC, MO(_FNR),                  KC_6,    KC_7,    KC_8
 ),
 
  [_SYMBOLS] = LAYOUT(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),   S(KC_5),   S(KC_6),   S(KC_7),       S(KC_8), S(KC_9), S(KC_0),
    KC_LSHIFT,XXXXXXX,  XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, KC_SCLN, KC_DOT, KC_SLSH,
    TO(_ALPHA),KC_LGUI,KC_LALT, MO(_FNL),KC_LSHIFT,KC_SPC, MO(_FNR),                        S(KC_SCLN),S(KC_DOT),S(KC_SLSH)
 ),
 
  [_EDIT] = LAYOUT(
    LT(_ALPHAH,KC_TAB),KC_Q,KC_W,KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    KC_LSHIFT,KC_NUBS,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_UP,   MT(MOD_RSFT,KC_SLASH),
    MO(_SYMBOLS),KC_LGUI,KC_LALT,MO(_FNL),KC_SPC,KC_SPC,  MO(_FNR),                  KC_LEFT, KC_DOWN, KC_RIGHT
 )
};

static enum layers display_layer=_ALPHA;
static int layercount=0;

layer_state_t layer_state_set_user(layer_state_t state) {
//  rgb_matrix_mode (RGB_MATRIX_CUSTOM_my_cool_effect);
  display_layer=get_highest_layer(state);
  layercount++;
  return state;
}

static enum KCOL_KEYTYPES alphatypes [] = {
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_NUM, KCOL_NUM, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM,
  KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_LAYER, KCOL_MOD, KCOL_ALPHA, KCOL_LAYER, KCOL_NUM, KCOL_NUM, KCOL_NUM
  };
  
static enum KCOL_KEYTYPES fn1types [] = {
  KCOL_FN, KCOL_ALPHA, KCOL_BLANK, KCOL_LAYER, KCOL_BLANK, KCOL_MOD, KCOL_MOD, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_MOD,
  KCOL_MOD, KCOL_BLANK, KCOL_LAYER, KCOL_LAYER, KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_MOD,
  KCOL_MOD, KCOL_SYMBOL, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_LAYER, KCOL_SYMBOL, KCOL_FN, KCOL_SYMBOL,
  KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_MOD, KCOL_ALPHA, KCOL_MOD, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES edittypes [] = {
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD, KCOL_SYMBOL, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_FN, KCOL_SYMBOL,
  KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES functiontypes [] = {
  KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_MOD, KCOL_BLANK, KCOL_MOD, KCOL_MOD,
  KCOL_MOD, KCOL_BLANK, KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_MOD,
  KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_MOD, KCOL_BLANK, KCOL_FN, KCOL_FN,
  KCOL_FN, KCOL_FN, KCOL_FN, KCOL_MOD, KCOL_MOD, KCOL_ALPHA, KCOL_MOD, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES mousetypes [] = {
  KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_BLANK,
  KCOL_MOD, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_MOD,
  KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_FN, KCOL_BLANK,
  KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES numpadtypes [] = {
  KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_MOD,
  KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_MOD,
  KCOL_NUM, KCOL_NUM, KCOL_BLANK, KCOL_MOD, KCOL_FN, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM,
  KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_LAYER, KCOL_MOD, KCOL_ALPHA, KCOL_LAYER, KCOL_NUM, KCOL_NUM, KCOL_NUM
  };
  
static enum KCOL_KEYTYPES symbolstypes [] = {
  KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_MOD,
  KCOL_MOD, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL
  };
  
enum KCOL_KEYTYPES get_colour_keytype (int key) {
  key = key-10;
  if (key<0 || key>=45)
    return KCOL_BLANK;
  enum KCOL_KEYTYPES *ptypes = alphatypes;
  if (display_layer==_FNL || display_layer==_FNR)
    ptypes = fn1types;
  if (display_layer==_EDIT)
    ptypes = edittypes;  
  if (display_layer==_SYMBOLS)
    ptypes = symbolstypes;  
  if (display_layer==_NUMPAD)
    ptypes = numpadtypes;
  if (display_layer==_MOUSE)
    ptypes = mousetypes;
  if (display_layer==_FUNCTION)
    ptypes = functiontypes;  
  return ptypes[key];
 }