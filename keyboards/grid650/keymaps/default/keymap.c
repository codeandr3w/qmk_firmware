/* Copyright 2020 grid
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

// #define LED_DEBUG

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _JIS,
    _FAKEJIS,
    _HIRAGANA,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
// enum custom_keycodes {
//     QMKBEST = SAFE_RANGE,
//     QMKURL
// };

//keymap for test
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//     /* Base */
//     [_BASE] = LAYOUT(
//         KC_1,       KC_2,       MO(_FN),
//         KC_4,       KC_5,       KC_6, 
//         KC_7,       KC_8,       KC_9,
//         KC_A,       KC_B,       KC_C,
//         OUT_USB,    OUT_BT,       KC_F
//     )
//     // [_FN] = LAYOUT(
//     //     QMKBEST, QMKURL,  _______,
//     //         RESET,    XXXXXXX
//     // )
// };



enum my_keycodes {
  FOO = SAFE_RANGE,
  BAR,
  LED_BLE,
  BLE_PWR_OFF,
  BLE_PWR_ON,
  BLE_DFU,
  BLE_SWITCH,
  BLE_PROFILE0,
  BLE_PROFILE1,
  BLE_PROFILE2,
  BLE_PROFILE3,
  BLE_PROFILE4,
  SWITCH_JIS,
  SWITCH_EN,
  SWITCH_FAKEJIS,
  FAKE_EISU,
  FAKE_KANA,
  HIRAGANA,
  BREATHING,
  ON,
  RED,
  BLUE,
  ORANGE
};

#ifdef LED_DEBUG
enum LED_STAT{
  RED_BLINK,
  WHITE_BREATHING,
  WHITE_ON,  
  BLE_ON,
  ORANGE_ON  
};

void set_status_led(enum LED_STAT led_stat,enum LED_STAT current_stat);
#endif

extern bool adafruit_ble_change_profile(int profile);

// BLE keymap for user
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_BSPC,_______,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,_______,KC_DEL,KC_ESC, /* this is the top right key, no idea why */     
        KC_LCTL,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,         KC_PGUP,
        KC_LSFT,KC_NUBS,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,    KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP,  KC_PGDN,
        MO(_FN),KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,   KC_NO,          MT(MOD_RALT,KC_HOME),MT(MOD_RCTL,KC_END),MT(MOD_RCTL,KC_APP),KC_LEFT,KC_DOWN,KC_RGHT,
        KC_F1,  KC_F2,  KC_F3,  KC_F4
    ),
    /* Fake-JIS */
    [_FAKEJIS] = LAYOUT(
        S(KC_MINS), KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_BSPC,_______,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,_______,KC_DEL,KC_ESC, /* this is the top right key, no idea why */     
        FAKE_EISU,KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,  KC_PGUP,
        KC_LSFT,KC_GRV,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,    KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP,  KC_PGDN,
        MO(_FN),KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,   KC_NO,          _______,_______,FAKE_KANA,KC_LEFT,KC_DOWN,KC_RGHT,
        KC_F1,  KC_F2,  KC_F3,  KC_F4
    ),
    /* JIS */
    [_JIS] = LAYOUT(
        KC_JYEN, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,    KC_8,   KC_9,   KC_0,   KC_MINS,KC_EQL, KC_BSPC,KC_BSPC,_______,
        KC_TAB, KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O,   KC_P,   KC_LBRC,KC_RBRC,_______,KC_DEL,KC_ESC, /* this is the top right key, no idea why */     
        MT(MOD_LCTL,KC_CAPS),KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,   KC_L,   KC_SCLN,KC_QUOT,KC_NUHS,KC_ENT,  KC_PGUP,
        KC_LSFT,KC_RO,KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,    KC_M,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,        KC_UP,  KC_PGDN,
        MO(_FN),KC_LGUI,KC_LALT,KC_NO,  KC_NO,  KC_SPACE,KC_NO, KC_NO,   KC_NO,          KC_MHEN,KC_HENK,KC_KANA,KC_LEFT,KC_DOWN,KC_RGHT,
        KC_F1,  KC_F2,  KC_F3,  KC_F4
    ),
    // Function key layer
    [_FN] = LAYOUT(
        KC_LANG1,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_F13 ,KC_DEL, _______,
        BLE_SWITCH,BLE_PROFILE0,BLE_PROFILE1,SWITCH_EN,BLE_PROFILE2,BLE_PROFILE3,BLE_PROFILE4,OUT_USB, _______,_______,KC_PSCR,_______,_______,_______,KC_INS, KC_PSCR,
        MT(MOD_LCTL,KC_CAPS),_______,KC_SLCK,DEBUG,SWITCH_FAKEJIS,_______,OUT_AUTO,SWITCH_JIS,_______,_______,_______,_______,_______,_______,        KC_MS_WH_UP,
        _______,KC__MUTE,  KC_KP_EQUAL,KC_UNDO,KC_CAPS,KC_INT5,OUT_BT,  KC_INT6,_______,_______,KC_SLSH,_______,_______,        KC_MS_U,KC_MS_WH_DOWN,
        _______,KC_APP, _______,_______,_______,_______,_______, _______,_______,        KC_BTN1,KC_BTN2,_______,KC_MS_L,KC_MS_D,KC_MS_R,
        _______,_______,_______,_______        
    )
};

// uint8_t white_led = 1;
uint8_t orange_led = 1;
uint8_t red_led = 1;
uint8_t ble_led = 1;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef LED_DEBUG
    static enum LED_STAT current_stat = WHITE_BREATHING;
    #endif

    int8_t mod_state;

    switch (keycode) {
        // case LED_RED:
        //     if (record->event.pressed) {
        //         // Do something when pressed
        //         PORTB |= (1 << 0);
        //     } else {
        //         // Do something else when release
        //     }
        //     return true; 
        // case KC_E:
        //     if (record->event.pressed) {
        //         // Do something when pressed
        //         PORTB &= ~(1 << 0);
        //     } else {
        //         // Do something else when release
        //     }
        //     return true;
#ifdef LED_DEBUG
     case ORANGE:
        if (record->event.pressed) {                
            set_status_led(ORANGE_ON,current_stat);
            current_stat = ORANGE_ON;
            // xprintf("current stat = %d\n",current_stat);

        } else {
            // Do something else when release
        }
            return true;
    case BREATHING:
        if (record->event.pressed) {
            set_status_led(WHITE_BREATHING,current_stat);
            current_stat = WHITE_BREATHING;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true;    
    case ON:
        if (record->event.pressed) {
            set_status_led(WHITE_ON,current_stat);
            current_stat = WHITE_ON;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true;    
    case RED:
        if (record->event.pressed) {
            set_status_led(RED_BLINK,current_stat);
            current_stat = RED_BLINK;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true; 
    case BLUE:
        if (record->event.pressed) {
            set_status_led(BLE_ON,current_stat);
            current_stat = BLE_ON;
            // xprintf("current stat = %d\n",current_stat);
        } else {
            // Do something else when release
        }
            return true;     
                 
    case LED_BLE:
        if (record->event.pressed) {                
            if(ble_led) {
                ble_led = 0;
                print("BLE LED OFF\n");
                adafruit_ble_set_mode_leds(0);
            } else {
                ble_led = 1;
                print("BLE LED ON\n");
                adafruit_ble_set_mode_leds(1);                                
            }
        } else {
            // Do something else when release
        }
            return true; 
#endif   
    case BLE_PWR_OFF:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) LOW
            PORTD &= ~(1<<5);

            //BLE_OE(PD2) HIGH
            PORTD |= (1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
            
        } else {
            // Do something else when release
        }
            return true;      
    case BLE_PWR_ON:
        if (record->event.pressed) {
            
            //BLE_PWR(PD5) HIGH
            // PORTD &= ~(1<<5);
            PORTD |= (1<<5);

            //BLE_OE(PD2) LOW
            // PORTD |= (1<<2);
            PORTD &= ~(1<<2);

            //DFU_MCU(PC6) HIGH
            // PORTC |= 1 << 6;   //set high
                
        } else {
            // Do something else when release
        }
            return true;         
    case BLE_DFU:
        if (record->event.pressed) {
            //DFU_MCU(PC6) HIGH
            PORTC |= 1 << 6;   //set high
              
        } else {
            // Do something else when release
            //DFU_MCU(PC6) LOW
            PORTC &= ~(1 << 6);   //set high
        }
            return true; 
    case BLE_SWITCH:
        if (record->event.pressed) {
            adafruit_ble_switch_connection();
        }
        return true;
        case BLE_PROFILE0:
        if (record->event.pressed) {
            adafruit_ble_change_profile(0);
        }
        return true;
    case BLE_PROFILE1:
        if (record->event.pressed) {
            adafruit_ble_change_profile(1);
        }
        return true;
    case BLE_PROFILE2:
        if (record->event.pressed) {
            adafruit_ble_change_profile(2);
        }
        return true;
    case BLE_PROFILE3:
        if (record->event.pressed) {
            adafruit_ble_change_profile(3);
        }
        return true;
    case BLE_PROFILE4:
        if (record->event.pressed) {
            adafruit_ble_change_profile(4);
        }
        return true;
    case SWITCH_JIS:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT (SS_LALT ("1")));
            layer_on(_JIS);
            layer_off(_FAKEJIS);
        }
        return true;
    case SWITCH_FAKEJIS:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT (SS_LALT ("1")));
            layer_on(_FAKEJIS);
            layer_off(_JIS);
        }
        return true;
    case SWITCH_EN:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT (SS_LALT ("2")));
            layer_off(_JIS);
            layer_off(_FAKEJIS);
        }
        return true;
    case FAKE_EISU:
        if (record->event.pressed) {
            register_code(KC_LSHIFT);
            register_code(KC_CAPS);
        } else {
            unregister_code(KC_CAPS);
            unregister_code(KC_LSHIFT);
        }
        return false;
    case FAKE_KANA:
        mod_state = get_mods ();
        if (record->event.pressed) {
          if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            register_code(KC_LALT);
            register_code(KC_CAPS);
          } else {
            register_code(KC_LCTL);
            register_code(KC_CAPS);
          }
          set_mods(mod_state);
        } else {
          unregister_code(KC_CAPS);
          if (mod_state & MOD_MASK_SHIFT) {
            del_mods(MOD_MASK_SHIFT);
            unregister_code(KC_LALT);
          } else {
            unregister_code(KC_LCTL);
          }
        }
        return false;
    default:
        return true; // Process all other keycodes normally
    }
}