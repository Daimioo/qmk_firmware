/* Copyright 2021 Richard Goulter
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

#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layers {
  _DVORAK,
  _QWERTY,
  _CHILDPROOF,
  _NAVR,
  _MOUR,
  _MEDR,
  _NSL,
  _NSSL,
  _FUNL,
};

#define DVORAK     DF(_DVORAK)
#define QWERTY     DF(_QWERTY)
#define CHILDPROOF     DF(_CHILDPROOF)
#define SPC_NAVR  LT(_NAVR, KC_SPC)
#define TAB_MOUR  LT(_MOUR, KC_TAB)
#define ESC_MEDR  LT(_MEDR, KC_ESC)
#define BKSP_NSL   LT(_NSL, KC_BSPC)
#define ENT_NSSL  LT(_NSSL, KC_ENT)
#define DEL_FUNL  LT(_FUNL, KC_DEL)

/* Home Row, outer column */
#define LCTLESC LCTL_T(KC_ESC)
#define RCTLENT RCTL_T(KC_ENT)

/* Home Row Mods, Dvorak, LH */
#define LALTT_A LALT_T(KC_A)
#define LGUIT_O LGUI_T(KC_O)
#define LCTLT_E LCTL_T(KC_E)
#define LSFTT_U LSFT_T(KC_U)

/* Home Row Mods, QWERTY, LH */
// #define LALTT_A LALT_T(KC_A)
#define LGUIT_S LGUI_T(KC_S)
#define LCTLT_D LCTL_T(KC_D)
#define LSFTT_F LSFT_T(KC_F)

/* Home Row Mods, Dvorak, RH */
#define RSFTT_H RSFT_T(KC_H)
#define RCTLT_T RCTL_T(KC_T)
#define RGUIT_N RGUI_T(KC_N)
#define RALTT_S RALT_T(KC_S)

/* Home Row Mods, QWERTY, RH */
#define RSFTT_J RSFT_T(KC_J)
#define RCTLT_K RCTL_T(KC_K)
#define RGUIT_L RGUI_T(KC_L)
#define RALTTSC RALT_T(KC_SCLN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_DVORAK] = LAYOUT(
  KC_QUOT, KC_COMM, KC_DOT,   KC_P,     KC_Y,        KC_F,     KC_G,     KC_C,    KC_R,    KC_L,
  LALTT_A, LGUIT_O, LCTLT_E,  LSFTT_U,  KC_I,        KC_D,     RSFTT_H,  RCTLT_T, RGUIT_N, RALTT_S,
  KC_SCLN, KC_Q,    KC_J,     KC_K,     KC_X,        KC_B,     KC_M,     KC_W,    KC_V,    KC_Z,
                    TAB_MOUR, ESC_MEDR, SPC_NAVR,    BKSP_NSL, ENT_NSSL, DEL_FUNL
),

[_QWERTY] = LAYOUT(
  KC_Q,    KC_W,     KC_E,     KC_R,     KC_T,        KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
  LALTT_A, LGUIT_S,  LCTLT_D,  LSFTT_F,  KC_G,        KC_H,     RSFTT_J,  RCTLT_K,  RGUIT_L, RALTTSC,
  KC_Z,    KC_X,     KC_C,     KC_V,     KC_B,        KC_N,     KC_M,     KC_COMM,  KC_DOT,  KC_QUOT,
                     TAB_MOUR, ESC_MEDR, SPC_NAVR,    BKSP_NSL, ENT_NSSL, DEL_FUNL
),

[_NAVR] = LAYOUT( \
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,    KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, _______,
  _______, _______, _______, _______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END, KC_INS,
                    _______, _______, _______,    _______, _______, _______
),

[_MOUR] = LAYOUT( \
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______,    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  _______, _______, _______, _______, _______,    KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______,
                    _______, _______, _______,    KC_BTN1, KC_BTN2, KC_BTN3
),

[_MEDR] = LAYOUT( \
  _______, _______, _______, _______, _______,    RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI,
  _______, _______, _______, _______, _______,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______,
  _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
                    _______, _______, _______,    KC_MPLY, KC_MSTP, KC_MUTE
),

[_NSL] = LAYOUT( \
  KC_LBRC, KC_7, KC_8,   KC_9, KC_RBRC,    _______, _______, _______, _______, _______,
  KC_GRV,  KC_4, KC_5,   KC_6, KC_EQL,     _______, _______, _______, _______, _______,
  KC_SLSH, KC_1, KC_2,   KC_3, KC_BSLS,    _______, _______, _______, _______, _______,
                 KC_DOT, KC_0, KC_MINS,    _______, _______, _______
),

[_NSSL] = LAYOUT( \
  KC_LCBR, KC_AMPR, KC_ASTR, KC_LPRN, KC_RCBR,    _______, _______, _______, _______, _______,
  KC_TILD, KC_DLR,  KC_PERC, KC_CIRC, KC_PLUS,     _______, _______, _______, _______, _______,
  KC_QUES, KC_EXLM, KC_AT,   KC_HASH, KC_PIPE,      _______, _______, _______, _______, _______,
                    KC_LPRN, KC_RPRN, KC_UNDS,    _______, _______, _______
),

[_FUNL] = LAYOUT( \
  KC_F12, KC_F7, KC_F8,    KC_F9,   _______,    _______, _______, _______, _______, _______,
  KC_F11, KC_F4, KC_F5,    KC_F6,   _______,    _______, _______, _______, _______, _______,
  KC_F10, KC_F1, KC_F2,    KC_F3,   _______,    _______, _______, _______, _______, _______,
                  _______, _______, _______,    _______, _______, _______
),

};

void board_init(void) {
  // B9 is configured as I2C1_SDA in the board file; that function must be
  // disabled before using B7 as I2C1_SDA.
  // setPinInputHigh(A9);

  // This still doesn't 'solve' A9 not handling properly. :/
  palSetPadMode(GPIOA, 9, PAL_MODE_INPUT_PULLUP | PAL_MODE_ALTERNATE(0));
}

void keyboard_post_init_user(void) {
  // Call the post init code.
#ifdef RGBLIGHT_ENABLE
  rgblight_enable_noeeprom(); // enables Rgb, without saving settings
  rgblight_sethsv_noeeprom(180, 255, 255); // sets the color to teal/cyan without saving
  // rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING); // sets mode to Fast breathing without saving
  rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 4); // sets mode to Fast breathing without saving

#endif
#ifdef RGB_MATRIX_ENABLE
  // rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
#endif
}

void print_info_about_gpioa_pin(uint32_t pin) {
#ifdef CONSOLE_ENABLE
  uint32_t moder = GPIOA->MODER; // mode
  uint32_t otyper = GPIOA->OTYPER; // output type
  uint32_t ospeedr = GPIOA->OSPEEDR; // output speed type
  uint32_t pupdr = GPIOA->PUPDR; // pull-up/pull-down
  uint32_t afrl = GPIOA->AFRL; // alternate function (low)
  uint32_t afrh = GPIOA->AFRH; // alternate function (high)

  uprintf("A%d:: ", pin);
  // PIN_MODE_INPUT(n)
  // PIN_MODE_OUTPUT(n)
  // PIN_MODE_ALTERNATE(n)
  // PIN_MODE_ANALOG(n)
  if ((moder & PIN_MODE_INPUT(pin)) > 0) {
    uprintf("m: I, ");
  }
  if ((moder & PIN_MODE_OUTPUT(pin)) > 0) {
    uprintf("m: O, ");
  }
  if ((moder & PIN_MODE_ALTERNATE(pin)) > 0) {
    uprintf("m: AL, ");
  }
  if ((moder & PIN_MODE_ANALOG(pin)) > 0) {
    uprintf("m: AN, ");
  }

  // PIN_OTYPE_PUSHPULL(n)
  // PIN_OTYPE_OPENDRAIN(n)
  if ((otyper & PIN_OTYPE_PUSHPULL(pin)) > 0) {
    uprintf("t: PP, ");
  }
  if ((otyper & PIN_OTYPE_OPENDRAIN(pin)) > 0) {
    uprintf("t: OD, ");
  }

  // output data register
  // PIN_ODR_LOW(n)
  // PIN_ODR_HIGH(n)

  // PIN_OSPEED_VERYLOW(n)
  // PIN_OSPEED_LOW(n)
  // PIN_OSPEED_MEDIUM(n)
  // PIN_OSPEED_HIGH(n)
  if ((ospeedr & PIN_OSPEED_VERYLOW(pin)) > 0) {
    uprintf("os: VL, ");
  }
  if ((ospeedr & PIN_OSPEED_LOW(pin)) > 0) {
    uprintf("os: L, ");
  }
  if ((ospeedr & PIN_OSPEED_MEDIUM(pin)) > 0) {
    uprintf("os: M, ");
  }
  if ((ospeedr & PIN_OSPEED_HIGH(pin)) > 0) {
    uprintf("os: H, ");
  }

  // PIN_PUPDR_FLOATING(n)
  // PIN_PUPDR_PULLUP(n)
  // PIN_PUPDR_PULLDOWN(n)
  if ((pupdr & PIN_PUPDR_FLOATING(pin)) > 0) {
    uprintf("PU/PD: F, ");
  }
  if ((pupdr & PIN_PUPDR_PULLUP(pin)) > 0) {
    uprintf("PU/PD: PU, ");
  }
  if ((pupdr & PIN_PUPDR_PULLDOWN(pin)) > 0) {
    uprintf("PU/PD: PD, ");
  }

  // PIN_AFIO_AF(n, v)
  if (pin < 8) {
    for (int af = 0; af < 16; af++) {
      if ((afrl & PIN_AFIO_AF(pin, af)) > 0) {
        uprintf("AF: %d", af);
      }
    }
  } else {
    for (int af = 0; af < 16; af++) {
      if ((afrh & PIN_AFIO_AF(pin, af)) > 0) {
        uprintf("AF: %d", af);
      }
    }
  }
  uprintf("\n");
#endif
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE

#endif 
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
}
