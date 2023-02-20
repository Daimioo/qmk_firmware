/* Copyright 2020 tominabox1
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
  _PRIMARY,
  _ESPECIAL,
  _NUMPAD,
  _FUNCTION,
  _NAV,
  _MOUSE,
  _MEDIA,
};

#define KC_A_GUI LGUI_T(KC_A)
#define KC_S_ALT LALT_T(KC_S)
#define KC_D_CTL LCTL_T(KC_D)
#define KC_F_SHIFT LSFT_T(KC_F)

#define KC_J_SHIFT RSFT_T(KC_J)
#define KC_K_CTL RCTL_T(KC_K)
#define KC_L_ALT RALT_T(KC_L)
#define KC_QUOTE_GUI RGUI_T(KC_QUOT)

#define ESC_MEDIA LT(_MEDIA, KC_ESC)
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_MOUSE LT(_MOUSE, KC_TAB)
#define ENTER_ESPECIAL LT(_ESPECIAL, KC_ENT)
#define BACK_NUM LT(_NUMPAD, KC_BSPC)
#define DEL_FUNCTION LT(_FUNCTION, KC_DEL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* _PRIMARY
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  |   '  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  |   ,  |   .  |   /  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | ESC  | SPC  |  TAB |             | ENTER | BACK | DEL |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_PRIMARY] = LAYOUT_ortho_4x12_1x2uC(
    KC_Q,     KC_W,      KC_E,             KC_R,            KC_T,        _______,    _______,      KC_Y,                    KC_U,                  KC_I,            KC_O,    KC_P,
    KC_A_GUI, KC_S_ALT,  KC_D_CTL,     KC_F_SHIFT,    KC_G,        _______,    _______,      KC_H,                    KC_J_SHIFT,          KC_K_CTL,    KC_L_ALT, KC_QUOTE_GUI,
    KC_Z,   KC_X,      KC_C,             KC_V,            KC_B,        _______,    _______,      KC_N,                    KC_M, KC_COMM,         KC_DOT, KC_SLSH ,
    _______,  _______,  ESC_MEDIA, SPC_NAV,       TAB_MOUSE,          _______,     ENTER_ESPECIAL,   BACK_NUM,  DEL_FUNCTION,   _______, _______
),

[_ESPECIAL] = LAYOUT_ortho_4x12_1x2uC(
    KC_LCBR, KC_AMPR, KC_ASTR,   KC_LPRN, KC_RCBR,          _______,    _______, _______,    _______,    _______, _______, _______,
    KC_COLN,  KC_DLR,   KC_PERC,   KC_CIRC,   KC_PLUS,      _______,    _______,   KC_RSFT,    KC_RCTL,    KC_RALT, KC_RGUI, _______,
    KC_TILD, KC_EXLM,   KC_AT,   KC_HASH,   KC_PIPE,        _______,    _______,  _______, _______, _______, _______,  _______,
    _______,  _______,  KC_LPRN, KC_RPRN,  KC_UNDS,         _______,    _______,   _______,  _______,   _______, _______
),


[_NUMPAD] = LAYOUT_ortho_4x12_1x2uC(
    KC_LBRC, KC_7, KC_8,   KC_9, KC_RBRC,          _______,    _______, _______,    _______,    _______, _______, _______,
    KC_SCLN,  KC_4,   KC_5,   KC_6,   KC_PEQL,      _______,    _______,   KC_RSFT,    KC_RCTL,    KC_RALT, KC_RGUI, _______,
    KC_GRV, KC_1,   KC_2,   KC_3,   KC_BSLS,        _______,    _______,  _______, _______, _______, _______,  _______,
    _______,  _______,  KC_PDOT, KC_0,  KC_MINUS,         _______,    _______,   _______,  _______,   _______, _______
),


[_FUNCTION] = LAYOUT_ortho_4x12_1x2uC(
    KC_F12, KC_F7, KC_F8,   KC_F9, KC_RBRC,          _______,    _______, _______,    _______,    _______, _______, _______,
    KC_F11,  KC_F4,   KC_F5,   KC_F6,   KC_PEQL,      _______,    _______,   _______,    KC_RSFT,    KC_RCTL, KC_RALT, KC_RGUI,
    KC_F10, KC_F1,   KC_F2,   KC_F3,   KC_BSLS,        _______,    _______,  _______, _______, _______, _______,  _______,
    _______,  _______,  _______, _______,  _______,         _______,    _______,   _______,  _______,   _______, _______
),


[_NAV] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______,   _______, _______,           _______,    _______, _______,    _______,    _______, _______, _______,
    KC_RGUI,  KC_LALT,   KC_LCTL,   KC_LSFT,   _______,      _______,    _______,   KC_LCAP,    KC_LEFT,    KC_DOWN, KC_UP, KC_RIGHT,
    _______, _______,   _______,   _______,   _______,       _______,    _______,  _______, KC_HOME, KC_PGDN, KC_PGUP,  KC_END,
    _______,  _______,  _______, _______,  _______,          _______,    _______,   _______,  _______,   _______, _______
),

[_MOUSE] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______,   _______, _______,           _______,    _______, _______,    _______,    _______, _______, _______,
    KC_RGUI,  KC_LALT,   KC_LCTL,   KC_LSFT,   _______,      _______,    _______,   KC_LCAP,    KC_MS_L,    KC_MS_D, KC_MS_U, KC_MS_R,
    _______, _______,   _______,   _______,   _______,       _______,    _______,  _______, _______, KC_WH_D, KC_WH_U,  _______,
    _______,  _______,  _______, _______,  _______,          _______,    KC_BTN2,   KC_BTN1,  KC_BTN3,   _______, _______
),

[_MEDIA] = LAYOUT_ortho_4x12_1x2uC(
    _______, _______, _______,   _______, _______,           _______,    _______, _______,    _______,    _______, _______, _______,
    KC_RGUI,  KC_LALT,   KC_LCTL,   KC_LSFT,   _______,      _______,    _______, _______,    KC_MPRV,    KC_KB_VOLUME_DOWN, KC_KB_VOLUME_UP, KC_MNXT,
    _______, _______,   _______,   _______,   _______,       _______,    _______,  _______, _______, _______, _______,  _______,
    _______,  _______,  _______, _______,  _______,          _______,    KC_MSTP,   KC_MPLY,  KC_MUTE,   _______, _______
),
};



//layer led colors

bool rgb_matrix_indicators_user(void) {
//disabled keys
  rgb_matrix_set_color(5, 0, 0, 0);
  rgb_matrix_set_color(6, 0, 0, 0);
  rgb_matrix_set_color(17, 0, 0, 0);
  rgb_matrix_set_color(18, 0, 0, 0);
  rgb_matrix_set_color(29, 0, 0, 0);
  rgb_matrix_set_color(30, 0, 0, 0);
  rgb_matrix_set_color(36, 0, 0, 0);
  rgb_matrix_set_color(37, 0, 0, 0);
  rgb_matrix_set_color(41, 0, 0, 0);
  rgb_matrix_set_color(45, 0, 0, 0);
  rgb_matrix_set_color(46, 0, 0, 0);

//   white keys
  rgb_matrix_set_color(0, 255, 255, 255);
  rgb_matrix_set_color(1, 255, 255, 255);
  rgb_matrix_set_color(2, 255, 255, 255);
  rgb_matrix_set_color(3, 255, 255, 255);
  rgb_matrix_set_color(4, 255, 255, 255);
  rgb_matrix_set_color(7, 255, 255, 255);
  rgb_matrix_set_color(8, 255, 255, 255);
  rgb_matrix_set_color(9, 255, 255, 255);
  rgb_matrix_set_color(10, 255, 255, 255);
  rgb_matrix_set_color(11, 255, 255, 255);
  rgb_matrix_set_color(16, 255, 255, 255);
  rgb_matrix_set_color(19, 255, 255, 255);
  rgb_matrix_set_color(24, 255, 255, 255);
  rgb_matrix_set_color(25, 255, 255, 255);
  rgb_matrix_set_color(26, 255, 255, 255);
  rgb_matrix_set_color(27, 255, 255, 255);
  rgb_matrix_set_color(28, 255, 255, 255);
  rgb_matrix_set_color(31, 255, 255, 255);
  rgb_matrix_set_color(32, 255, 255, 255);
  rgb_matrix_set_color(33, 255, 255, 255);
  rgb_matrix_set_color(34, 255, 255, 255);
  rgb_matrix_set_color(35, 255, 255, 255);

//layer indicators
if(IS_LAYER_ON(_PRIMARY)) {
  rgb_matrix_set_color(12, 255, 0, 0);
  rgb_matrix_set_color(13, 255, 0, 0);
  rgb_matrix_set_color(14, 255, 0, 0);
  rgb_matrix_set_color(15, 255, 0, 0);

  rgb_matrix_set_color(20, 255, 0, 0);
  rgb_matrix_set_color(21, 255, 0, 0);
  rgb_matrix_set_color(22, 255, 0, 0);
  rgb_matrix_set_color(23, 255, 0, 0);

//   media yellow
  rgb_matrix_set_color(38, 248, 252, 0);
//   nav blue
  rgb_matrix_set_color(39, 0, 21, 252);
//   mouse green
  rgb_matrix_set_color(40, 0, 255, 55);
//  especial pink
  rgb_matrix_set_color(42, 235, 5, 89);
//   num orange
  rgb_matrix_set_color(43, 252, 80, 0);
//   function cyan
  rgb_matrix_set_color(44, 0, 255, 204);
}

if(IS_LAYER_ON(_MEDIA)) {
//   set mod actions to white
  rgb_matrix_set_color(12, 255, 255, 255);
  rgb_matrix_set_color(13, 255, 255, 255);
  rgb_matrix_set_color(14, 255, 255, 255);
  rgb_matrix_set_color(15, 255, 255, 255);

// set layers to white
  rgb_matrix_set_color(38, 248, 252, 0);
  rgb_matrix_set_color(39, 255, 255, 255);
  rgb_matrix_set_color(40, 248, 255, 255);

  rgb_matrix_set_color(20, 248, 252, 0);
  rgb_matrix_set_color(21, 248, 252, 0);
  rgb_matrix_set_color(22, 248, 252, 0);
  rgb_matrix_set_color(23, 248, 252, 0);

  rgb_matrix_set_color(42, 248, 252, 0);
  rgb_matrix_set_color(43, 248, 252, 0);
  rgb_matrix_set_color(44, 248, 252, 0);
}

if(IS_LAYER_ON(_NAV)) {
//   set mod actions to white
  rgb_matrix_set_color(12, 255, 255, 255);
  rgb_matrix_set_color(13, 255, 255, 255);
  rgb_matrix_set_color(14, 255, 255, 255);
  rgb_matrix_set_color(15, 255, 255, 255);
  
  rgb_matrix_set_color(38, 255, 255, 255);
  rgb_matrix_set_color(39, 0, 21, 252);
  rgb_matrix_set_color(40, 255, 255, 255);

  rgb_matrix_set_color(20, 0, 21, 252);
  rgb_matrix_set_color(21, 0, 21, 252);
  rgb_matrix_set_color(22, 0, 21, 252);
  rgb_matrix_set_color(23, 0, 21, 252);

  rgb_matrix_set_color(32, 0, 21, 252);
  rgb_matrix_set_color(33, 0, 21, 252);
  rgb_matrix_set_color(34, 0, 21, 252);
  rgb_matrix_set_color(35, 0, 21, 252);

  rgb_matrix_set_color(42, 255, 255, 255);
  rgb_matrix_set_color(43, 255, 255, 255);
  rgb_matrix_set_color(44, 255, 255, 255);
}

if(IS_LAYER_ON(_MOUSE)) {
//   set mod actions to white
  rgb_matrix_set_color(12, 255, 255, 255);
  rgb_matrix_set_color(13, 255, 255, 255);
  rgb_matrix_set_color(14, 255, 255, 255);
  rgb_matrix_set_color(15, 255, 255, 255);

  rgb_matrix_set_color(38, 255, 255, 255);
  rgb_matrix_set_color(39, 255, 255, 255);
  rgb_matrix_set_color(40, 0, 255, 55);

  rgb_matrix_set_color(20, 0, 255, 55);
  rgb_matrix_set_color(21, 0, 255, 55);
  rgb_matrix_set_color(22, 0, 255, 55);
  rgb_matrix_set_color(23, 0, 255, 55);

  rgb_matrix_set_color(33, 0, 255, 55);
  rgb_matrix_set_color(34, 0, 255, 55);

  rgb_matrix_set_color(42, 0, 255, 55);
  rgb_matrix_set_color(43, 0, 255, 55);
  rgb_matrix_set_color(44, 0, 255, 55);
}

if(IS_LAYER_ON(_ESPECIAL)) {
  rgb_matrix_set_color(20, 255, 255, 255);
  rgb_matrix_set_color(21, 255, 255, 255);
  rgb_matrix_set_color(22, 255, 255, 255);
  rgb_matrix_set_color(23, 255, 255, 255);

  rgb_matrix_set_color(42, 235, 5, 89);
  rgb_matrix_set_color(43, 255, 255, 255);
  rgb_matrix_set_color(44, 255, 255, 255);
 
 //   layer color setup
  rgb_matrix_set_color(0, 235, 5, 89);
  rgb_matrix_set_color(1, 235, 5, 89);
  rgb_matrix_set_color(2, 235, 5, 89);
  rgb_matrix_set_color(3, 235, 5, 89);
  rgb_matrix_set_color(4, 235, 5, 89);
  rgb_matrix_set_color(12, 235, 5, 89);
  rgb_matrix_set_color(13, 235, 5, 89);
  rgb_matrix_set_color(14, 235, 5, 89);
  rgb_matrix_set_color(15, 235, 5, 89);
  rgb_matrix_set_color(16, 235, 5, 89);
  rgb_matrix_set_color(24, 235, 5, 89);
  rgb_matrix_set_color(25, 235, 5, 89);
  rgb_matrix_set_color(26, 235, 5, 89);
  rgb_matrix_set_color(27, 235, 5, 89);
  rgb_matrix_set_color(28, 235, 5, 89);

  rgb_matrix_set_color(38, 235, 5, 89);
  rgb_matrix_set_color(39, 235, 5, 89);
  rgb_matrix_set_color(40, 235, 5, 89);
}

if(IS_LAYER_ON(_NUMPAD)) {
  rgb_matrix_set_color(20, 255, 255, 255);
  rgb_matrix_set_color(21, 255, 255, 255);
  rgb_matrix_set_color(22, 255, 255, 255);
  rgb_matrix_set_color(23, 255, 255, 255);

  rgb_matrix_set_color(42, 255, 255, 255);
  rgb_matrix_set_color(43, 252, 80, 0);
  rgb_matrix_set_color(44, 255, 255, 255);
    
  //   layer color setup
  rgb_matrix_set_color(0, 252, 80, 0);
  rgb_matrix_set_color(1, 252, 80, 0);
  rgb_matrix_set_color(2, 252, 80, 0);
  rgb_matrix_set_color(3, 252, 80, 0);
  rgb_matrix_set_color(4, 252, 80, 0);
  rgb_matrix_set_color(12, 252, 80, 0);
  rgb_matrix_set_color(13, 252, 80, 0);
  rgb_matrix_set_color(14, 252, 80, 0);
  rgb_matrix_set_color(15, 252, 80, 0);
  rgb_matrix_set_color(16, 252, 80, 0);
  rgb_matrix_set_color(24, 252, 80, 0);
  rgb_matrix_set_color(25, 252, 80, 0);
  rgb_matrix_set_color(26, 252, 80, 0);
  rgb_matrix_set_color(27, 252, 80, 0);
  rgb_matrix_set_color(28, 252, 80, 0);

  rgb_matrix_set_color(38, 252, 80, 0);
  rgb_matrix_set_color(39, 252, 80, 0);
  rgb_matrix_set_color(40, 252, 80, 0);
}

if(IS_LAYER_ON(_FUNCTION)) {
  rgb_matrix_set_color(38, 255, 255, 255);
  rgb_matrix_set_color(39, 255, 255, 255);
  rgb_matrix_set_color(40, 255, 255, 255);

  rgb_matrix_set_color(20, 255, 255, 255);
  rgb_matrix_set_color(21, 255, 255, 255);
  rgb_matrix_set_color(22, 255, 255, 255);
  rgb_matrix_set_color(23, 255, 255, 255);

  rgb_matrix_set_color(42, 255, 255, 255);
  rgb_matrix_set_color(43, 255, 255, 255);
  rgb_matrix_set_color(44, 0, 255, 204);
  
//   layer color setup
  rgb_matrix_set_color(0, 0, 255, 204);
  rgb_matrix_set_color(1, 0, 255, 204);
  rgb_matrix_set_color(2, 0, 255, 204);
  rgb_matrix_set_color(3, 0, 255, 204);
  rgb_matrix_set_color(12, 0, 255, 204);
  rgb_matrix_set_color(13, 0, 255, 204);
  rgb_matrix_set_color(14, 0, 255, 204);
  rgb_matrix_set_color(15, 0, 255, 204);
  rgb_matrix_set_color(24, 0, 255, 204);
  rgb_matrix_set_color(25, 0, 255, 204);
  rgb_matrix_set_color(26, 0, 255, 204);
  rgb_matrix_set_color(27, 0, 255, 204);
}

return false;
};

