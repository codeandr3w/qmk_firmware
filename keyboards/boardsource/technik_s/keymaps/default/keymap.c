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
    _DEFAULT,   //  this layer matches the symbols on the keycaps
    _EDIT,    //  this layer is for editing it has cursor keys and natural shift placement
    _QAZ,     // QAZ with symbols on the right
    _ALPHA,   // Normal alpha keys and modifiers without cursor keys
    _SYMBOLS, //  this layer has all the symbols on it
    _NUMPAD,  //  this layer has a numpad
    _MOUSE,   //  this layer has mouse keys and media keys
    _FNL,     //  this layer is my normal FN layer with the bottom left key
    _FNC,     //  this layer is always used with the left bottom long key
    _DEFAULTH   // duplicate of Alpha for overlaying alpha on top
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

  [_DEFAULT] = LAYOUT(
    KC_ESC,    KC_Q,      KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL,KC_TAB),KC_A,KC_S, KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    MT(MOD_LSFT,KC_1),KC_2,KC_Z,   KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_9,    MT(MOD_RSFT,KC_0),
    LT(_FNL,KC_3),MT(MOD_LGUI,KC_4),MT(MOD_LALT,KC_5),LT(_FNC,KC_SCOLON),KC_SPC,KC_SPC,LT(_SYMBOLS,KC_QUOTE),MT(MOD_RALT,KC_6),KC_7,KC_8
  ),

  [_DEFAULTH] = LAYOUT(
    KC_ESC,    KC_Q,      KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL,KC_TAB),   KC_A,      KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    MT(MOD_LSFT,KC_1),KC_2,KC_Z,    KC_X,    KC_C,     KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM, KC_9,    MT(MOD_RSFT,KC_0),
    KC_3,MT(MOD_LGUI,KC_4),MT(MOD_LALT,KC_5),MO(_FNC),MT(MOD_LSFT,KC_SPC),KC_SPC,MO(_SYMBOLS),MT(MOD_RALT,KC_6),KC_7,KC_8
  ),

  [_FNC] = LAYOUT(
    KC_GRV,  TO(_QAZ),XXXXXXX, TO(_EDIT), KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5,   KC_F6,  KC_PSCR, KC_DEL,
    KC_LCTL, TO(_ALPHA), TO(_SYMBOLS), TO(_DEFAULT),KC_F7,KC_F8,KC_F9,  KC_F10, KC_F11,  KC_F12,  KC_NUHS,
    KC_LSHIFT, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD,  RGB_VAD, RGB_SAD, TO(_NUMPAD),TO(_MOUSE),XXXXXXX,  KC_UP,   KC_RSHIFT,
    OSL(_DEFAULTH),OSM(MOD_LGUI),OSM(MOD_LALT),_______, KC_SPC,KC_SPC, KC_QUOTE,      KC_LEFT,  KC_DOWN, KC_RIGHT 
  ),

  [_FNL] = LAYOUT(
    KC_GRV,  TO(_QAZ),XXXXXXX, TO(_EDIT), KC_F1, KC_F2,   KC_F3, KC_F4, KC_F5,   KC_F6,  KC_PSCR, KC_DEL,
    KC_LCTL, TO(_ALPHA), TO(_SYMBOLS), TO(_DEFAULT),KC_F7,KC_F8,KC_F9,  KC_F10, KC_F11,  KC_F12,  KC_NUHS,
    KC_LSHIFT, XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUD,  RGB_VAD, RGB_SAD, TO(_NUMPAD),TO(_MOUSE),XXXXXXX,  KC_PGUP,   KC_RSHIFT,
    OSL(_DEFAULTH),OSM(MOD_LGUI),OSM(MOD_LALT),_______, KC_SPC,KC_SPC, OSM(MOD_RALT),      KC_HOME,  KC_PGDN, KC_END 
  ),

  [_MOUSE] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, RESET,   KC_BRIU, XXXXXXX, KC_VOLU, KC_INS,  XXXXXXX, KC_MPLY, XXXXXXX,
    KC_LCTL, KC_WH_U, KC_SLCK, XXXXXXX, XXXXXXX, KC_BRID, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, KC_ENT,
    KC_LSFT, XXXXXXX, KC_WH_D, XXXXXXX, XXXXXXX, XXXXXXX, KC_BRK,  XXXXXXX, KC_MUTE, XXXXXXX, KC_MS_U, XXXXXXX,
    XXXXXXX, KC_LGUI, KC_LALT, MO(_FNC),KC_BTN1, KC_BTN2, MO(_SYMBOLS),                  KC_MS_L, KC_MS_D, KC_MS_R
 ),
 
  [_NUMPAD] = LAYOUT(
    KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PSLS, KC_KP_7, KC_KP_8, KC_KP_9, KC_PPLS, KC_BSPC,
    KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_PAST, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PENT,
    KC_1,    KC_2,    XXXXXXX, KC_NLCK, KC_CALC, KC_KP_0, KC_KP_1, KC_KP_2, KC_KP_3, KC_PDOT, KC_9,    KC_0,
    KC_3,    KC_4,    KC_5,    MO(_FNC),KC_LSHIFT,KC_SPC, MO(_SYMBOLS),                  KC_6,    KC_7,    KC_8
 ),
 
  [_SYMBOLS] = LAYOUT(
    KC_MINS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_EQL,
    S(KC_MINS),S(KC_1),   S(KC_2),   S(KC_3),   S(KC_4),   S(KC_5),   S(KC_6),   S(KC_7),       S(KC_8), S(KC_9), S(KC_NUHS), 
    KC_LSHIFT,KC_NUBS,  XXXXXXX,   XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, KC_DOT, KC_SLSH,
    KC_NUHS,KC_LGUI,KC_LALT, KC_SCLN,KC_LSHIFT,KC_SPC, MO(_SYMBOLS),                         KC_LBRC,XXXXXXX,KC_RBRC
 ),
 
  [_QAZ] = LAYOUT(
    KC_Q,      KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
    MT(MOD_LCTL,KC_A),KC_S,KC_D, KC_F,     KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    MT(MOD_LSFT,KC_NUBS),KC_Z,KC_X,KC_C,   KC_V,    KC_B,    KC_N,    KC_M,   KC_COMM,  KC_DOT,  KC_UP,   MT(MOD_RSFT,KC_SLSH),
    KC_NUHS,KC_LGUI,KC_LALT,MO(_FNC),MT(MOD_LSFT,KC_SPC),KC_SPC,MO(_SYMBOLS),KC_LEFT,  KC_DOWN, KC_RIGHT
  ),

  [_ALPHA] = LAYOUT(
    LT(_DEFAULTH,KC_ESC),KC_Q,KC_W,KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL,KC_TAB),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    KC_LSHIFT,KC_NUBS,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_DOT,   MT(MOD_RSFT,KC_SLASH),
    LT(_FNL,KC_NUHS),KC_LGUI,KC_LALT,LT(_FNC,KC_SCOLON),KC_SPC,KC_SPC,  LT(_SYMBOLS,KC_QUOTE),MT(MOD_RALT,KC_LBRC), KC_APP, MT(MOD_RCTL,KC_RBRC)
 ),

  [_EDIT] = LAYOUT(
    LT(_DEFAULTH,KC_ESC),KC_Q,KC_W,KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    MT(MOD_LCTL,KC_TAB),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
    KC_LSHIFT,KC_NUBS,KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_UP,   MT(MOD_RSFT,KC_SLASH),
    LT(_FNL,KC_NUHS),KC_LGUI,KC_LALT,LT(_FNC,KC_SCOLON),KC_SPC,KC_SPC,  LT(_SYMBOLS,KC_QUOTE),KC_LEFT, KC_DOWN, KC_RIGHT
 )
};

static enum layers display_layer=_DEFAULT;
static int layercount=0;

layer_state_t layer_state_set_user(layer_state_t state) {
//  rgb_matrix_mode (RGB_MATRIX_CUSTOM_my_cool_effect);
  display_layer=get_highest_layer(state);
  layercount++;
  return state;
}

static enum KCOL_KEYTYPES defaulttypes [] = {
  KCOL_FN, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_NUM, KCOL_NUM, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM,
  KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_NUM, KCOL_NUM, KCOL_NUM
  };
  
static enum KCOL_KEYTYPES fn1types [] = {
  KCOL_SYMBOL, KCOL_LAYER, KCOL_BLANK, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_MOD, KCOL_MOD,
  KCOL_MOD, KCOL_LAYER, KCOL_LAYER, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_SYMBOL,
  KCOL_MOD, KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_LAYER, KCOL_BLANK, KCOL_MOD, KCOL_MOD,
  KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD, KCOL_MOD, KCOL_MOD, KCOL_MOD
  };
  
static enum KCOL_KEYTYPES fnctypes [] = {
  KCOL_SYMBOL, KCOL_LAYER, KCOL_BLANK, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_MOD, KCOL_MOD,
  KCOL_MOD, KCOL_LAYER, KCOL_LAYER, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_SYMBOL,
  KCOL_MOD, KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_LAYER, KCOL_BLANK, KCOL_FN, KCOL_MOD,
  KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES edittypes [] = {
  KCOL_FN,KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD,  KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD,  KCOL_SYMBOL,KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_FN, KCOL_SYMBOL,
  KCOL_LAYER,KCOL_MOD,   KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES alphatypes [] = {
  KCOL_FN,KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD,  KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_MOD,
  KCOL_MOD,  KCOL_SYMBOL,KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_LAYER,KCOL_MOD,   KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_MOD, KCOL_MOD, KCOL_MOD
  };
  
static enum KCOL_KEYTYPES qaztypes [] = {
  KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_MOD,
  KCOL_MOD, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_ALPHA, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_FN, KCOL_SYMBOL,
  KCOL_SYMBOL, KCOL_MOD, KCOL_MOD, KCOL_LAYER, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES mousetypes [] = {
  KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_BLANK, KCOL_FN, KCOL_MOD, KCOL_BLANK, KCOL_FN, KCOL_BLANK,
  KCOL_MOD, KCOL_FN, KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_MOD,
  KCOL_BLANK, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_MOD, KCOL_BLANK, KCOL_FN, KCOL_BLANK, KCOL_FN, KCOL_BLANK,
  KCOL_BLANK, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_LAYER, KCOL_FN, KCOL_FN, KCOL_FN
  };
  
static enum KCOL_KEYTYPES numpadtypes [] = {
  KCOL_FN, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_MOD,
  KCOL_MOD, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_MOD,
  KCOL_NUM, KCOL_NUM, KCOL_BLANK, KCOL_MOD, KCOL_FN, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL, KCOL_NUM, KCOL_NUM,
  KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_LAYER, KCOL_MOD, KCOL_ALPHA, KCOL_LAYER, KCOL_NUM, KCOL_NUM, KCOL_NUM
  };
  
static enum KCOL_KEYTYPES symbolstypes [] = {
  KCOL_SYMBOL, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_NUM, KCOL_SYMBOL,
  KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_MOD, KCOL_SYMBOL, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_BLANK, KCOL_SYMBOL, KCOL_SYMBOL,
  KCOL_SYMBOL, KCOL_MOD, KCOL_MOD, KCOL_SYMBOL, KCOL_ALPHA, KCOL_ALPHA, KCOL_LAYER, KCOL_SYMBOL, KCOL_BLANK, KCOL_SYMBOL
  };
  
enum KCOL_KEYTYPES get_colour_keytype (int key) {
  key = key-10;
  if (key<0 || key>=45)
    return KCOL_BLANK;
  enum KCOL_KEYTYPES *ptypes = defaulttypes;
  if (display_layer==_FNL)
    ptypes = fn1types;
  if (display_layer==_FNC)
    ptypes = fnctypes;
  if (display_layer==_EDIT)
    ptypes = edittypes;  
  if (display_layer==_ALPHA)
    ptypes = alphatypes;  
  if (display_layer==_SYMBOLS)
    ptypes = symbolstypes;  
  if (display_layer==_NUMPAD)
    ptypes = numpadtypes;
  if (display_layer==_MOUSE)
    ptypes = mousetypes;
  if (display_layer==_QAZ)
    ptypes = qaztypes;  
  return ptypes[key];
 }
 
void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_config.mode==RGB_MATRIX_CUSTOM_my_cool_effect) 
      return;
    int v=rgb_matrix_config.hsv.v;
    for (uint8_t i = led_min; i <= led_max; i++) {
      enum KCOL_KEYTYPES type = get_colour_keytype (i);
      if (type != KCOL_ALPHA) {
        unsigned char r=0, g=0, b=0;
        if (type==KCOL_MOD) {
          r=v; g=v; b=0;
        } else if (type==KCOL_SYMBOL) {
          r=v; g=v; b=v;
          continue;
        } else if (type==KCOL_NUM) {
          g=v; b=v;
        } else if (type==KCOL_LAYER) {
          g=v>>2; b=v;
        } else if (type==KCOL_FN) {
          r=v; b=v;	
        }
          
        rgb_matrix_set_color(i, r, g, b);
      }
    }
}
