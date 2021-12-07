#include QMK_KEYBOARD_H
#ifdef AUDIO_ENABLE
#include "muse.h"
float tone_startup[][2] = SONG(SONIC_RING);
#endif
#include "eeprom.h"
#include "keymap_german.h"
#include "keymap_nordic.h"
#include "keymap_french.h"
#include "keymap_spanish.h"
#include "keymap_hungarian.h"
#include "keymap_swedish.h"
#include "keymap_br_abnt2.h"
#include "keymap_canadian_multilingual.h"
#include "keymap_german_ch.h"
#include "keymap_jp.h"
#include "keymap_korean.h"
#include "keymap_bepo.h"
#include "keymap_italian.h"
#include "keymap_slovenian.h"
#include "keymap_lithuanian_azerty.h"
#include "keymap_danish.h"
#include "keymap_norwegian.h"
#include "keymap_portuguese.h"
#include "keymap_contributions.h"
#include "keymap_czech.h"
#include "keymap_romanian.h"
#include "keymap_russian.h"
#include "keymap_uk.h"
#include "keymap_estonian.h"
#include "keymap_belgian.h"
#include "keymap_us_international.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)
#define KC_PC_UNDO LCTL(KC_Z)
#define KC_PC_CUT LCTL(KC_X)
#define KC_PC_COPY LCTL(KC_C)
#define KC_PC_PASTE LCTL(KC_V)
#define ES_LESS_MAC KC_GRAVE
#define ES_GRTR_MAC LSFT(KC_GRAVE)
#define ES_BSLS_MAC ALGR(KC_6)
#define NO_PIPE_ALT KC_GRAVE
#define NO_BSLS_ALT KC_EQUAL
#define LSA_T(kc) MT(MOD_LSFT | MOD_LALT, kc)
#define BP_NDSH_MAC ALGR(KC_8)

#define __________ KC_TRNS

enum planck_keycodes {
  RGB_SLD = EZ_SAFE_RANGE,
  MCRO_0,
  MCRO_1,
  MCRO_2,
  MCRO_3,
  MCRO_4,
  MCRO_5,
};

enum planck_layers {
  _QWERTY_MAC,
  _QWERTY_WIN,
  _LOWER,
  _RAISE,
  _ADJUST,
  _NAVIGATE,
  _NUMPAD,
};

uint16_t current_base_layer = _QWERTY_MAC;

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define WEBUSB WEBUSB_PAIR
#define SYNWIN 
#define SYNMAC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTY - Mac
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY_MAC] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,      
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,       
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,       
    TT(_NUMPAD)  , KC_LCTL, KC_LALT, KC_LGUI, LOWER  , KC_SPC , XXXXXXX, RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

  /* QWERTY - Windows
   * ,-----------------------------------------------------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
   * |------+------+------+------+------+-------------+------+------+------+------+------|
   * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
   * |------+------+------+------+------+------|------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------+------+------+------+------+------+------|
   * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
   * `-----------------------------------------------------------------------------------'
   */
  [_QWERTY_WIN] = LAYOUT_planck_grid(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,      
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,       
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,       
    TT(_NUMPAD)  , KC_LGUI, KC_LALT, KC_LCTL, LOWER  , KC_SPC , XXXXXXX, RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
  ),

  [_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, 
    KC_DEL , _______, KC_LBRC, KC_LCBR, KC_LPRN, MCRO_0 , MCRO_1 , KC_RPRN, KC_RCBR, KC_RBRC, KC_RCBR, KC_PIPE,        
    KC_INS , KC_F7  , KC_F8  , KC_F9  , KC_F10 , MCRO_2 , MCRO_3 , KC_NUHS, KC_NUBS, KC_HOME, KC_END , _______, 
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_RAISE] = LAYOUT_planck_grid(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______, 
    KC_DEL , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_MINS, KC_EQL , KC_LBRC, KC_RBRC, KC_BSLS,      
    _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______, 
    _______, _______, _______, _______, _______, TO(_NAVIGATE)  , XXXXXXX, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),
  
  [_ADJUST] = LAYOUT_planck_grid(
    WEBUSB , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET,          
    KC_BSPC, _______, AU_ON  , AU_OFF , AU_TOG , _______, _______, RGB_TOG, RGB_VAI, RGB_VAD, _______, _______, 
    _______, _______, MU_ON  , MU_OFF , MU_TOG , _______, _______, RGB_MOD, RGB_HUI, RGB_HUD, _______, _______, 
    _______, _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_NAVIGATE] = LAYOUT_planck_grid(
    _______, _______, KC_BTN2, KC_MS_U, KC_BTN1, MCRO_4 , MCRO_5, KC_ACL0, KC_ACL1, KC_ACL2, _______, _______, 
    TO(_QWERTY_MAC)  , KC_WH_U, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______, 
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    TO(_QWERTY_MAC)  , _______, _______, _______, _______, _______, XXXXXXX, _______, _______, _______, _______, _______
  ),

  [_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_PAST, _______, 
    _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PSLS, KC_PEQL,    
    _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS, KC_PENT,    
    _______, _______, _______, _______, _______, _______, XXXXXXX, KC_KP_0, KC_KP_0, KC_PDOT, KC_PMNS, KC_PENT
  ),

};

extern bool g_suspend_state;
extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
  PLAY_SONG(tone_startup);
}

const uint8_t PROGMEM ledmap[][DRIVER_LED_TOTAL][3] = {
    [5] = { {0,0,0}, {0,0,0}, {0,245,245}, {74,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {252,255,232}, {252,255,232}, {252,255,232}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {74,255,255}, {74,255,255}, {74,255,255}, {0,245,245}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [6] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {0,245,245}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {41,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {131,255,255}, {74,255,255}, {219,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {131,255,255}, {131,255,255}, {219,255,255}, {74,255,255}, {219,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < DRIVER_LED_TOTAL; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

void rgb_matrix_indicators_user(void) {
  if (g_suspend_state || keyboard_config.disable_layer_led) { return; }
  switch (biton32(layer_state)) {
    case 5:
      set_layer_color(5);
      break;
    case 6:
      set_layer_color(6);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
    #ifdef CONSOLE_ENABLE
        uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    #endif 

  switch (keycode) {
    case MCRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_MINUS));

    }
    break;
    case MCRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_MINUS) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));

    }
    break;
    case MCRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_COMMA)) SS_DELAY(100) SS_TAP(X_EQUAL));

    }
    break;
    case MCRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_EQUAL) SS_DELAY(100) SS_LSFT(SS_TAP(X_DOT)));

    }
    break;
    case MCRO_4:
    if (record->event.pressed) {
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      SEND_STRING("s");
      clear_keyboard();
      set_single_persistent_default_layer(_QWERTY_WIN);
      current_base_layer = _QWERTY_WIN;
      return false;
    }
    break;
    case MCRO_5:
    if (record->event.pressed) {
      register_code(KC_LSHIFT);
      register_code(KC_LCTRL);
      register_code(KC_LALT);
      SEND_STRING("x");
      clear_keyboard();
      set_single_persistent_default_layer(_QWERTY_MAC);
      current_base_layer = _QWERTY_MAC;
      return false;
    }
    break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

#ifdef AUDIO_ENABLE
bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
    if (muse_mode) {
        if (IS_LAYER_ON(_RAISE)) {
            if (clockwise) {
                muse_offset++;
            } else {
                muse_offset--;
            }
        } else {
            if (clockwise) {
                muse_tempo+=1;
            } else {
                muse_tempo-=1;
            }
        }
    } else {
        if (clockwise) {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_DOWN);
            unregister_code(KC_MS_WH_DOWN);
        #else
            register_code(KC_PGDN);
            unregister_code(KC_PGDN);
        #endif
        } else {
        #ifdef MOUSEKEY_ENABLE
            register_code(KC_MS_WH_UP);
            unregister_code(KC_MS_WH_UP);
        #else
            register_code(KC_PGUP);
            unregister_code(KC_PGUP);
        #endif
        }
    }
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
    case RAISE:
    case LOWER:
        return false;
    default:
        return true;
    }
}
#endif

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


