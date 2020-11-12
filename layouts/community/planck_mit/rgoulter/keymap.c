#include QMK_KEYBOARD_H
#include "action_layer.h"

#include "raw_hid.h"

#include "snake.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
  _DVORAK,
  _QWERTY,
  _SNAKE,
  _LOWER,
  _RAISE,
  _CHILDPROOF,
  _NUMPAD,
  _ADJUST,
};

enum custom_keycodes {
  QUARTER = SAFE_RANGE,
  HALF,
  SNAKE,
  DIRRGHT,
  DIRUP,
  DIRLEFT,
  DIRDOWN
};

char quarter_count = 0;
char half_count = 0;

#define QWERTY     DF(_QWERTY)
#define DVORAK     DF(_DVORAK)
#define CHILDPROOF DF(_CHILDPROOF)
#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define NUMPAD  MO(_NUMPAD)
#define ADJUST  MO(_ADJUST)

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

[_DVORAK] = LAYOUT_planck_mit( \
  KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC, \
  LCTLESC, LALTT_A, LGUIT_O, LCTLT_E, LSFTT_U, KC_I,    KC_D,    RSFTT_H, RCTLT_T, RGUIT_N, RALTT_S, RCTLENT, \
  KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_RSFT, \
  _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_RGUI, KC_RALT, KC_RCTL, NUMPAD \
),

[_QWERTY] = LAYOUT_planck_mit( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  LCTLESC, LALTT_A, LGUIT_S, LCTLT_D, LSFTT_F, KC_G,    KC_H,    RSFTT_J, RCTLT_K, RGUIT_L, RALTTSC, RCTLENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_RSFT, \
  _______, KC_LCTL, KC_LALT, KC_LGUI, LOWER,      KC_SPC,        RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_SNAKE] = LAYOUT_planck_mit( \
  QUARTER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QUARTER, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, HALF,    XXXXXXX, XXXXXXX, HALF,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DIRUP,   XXXXXXX, \
  QUARTER, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, DIRLEFT, DIRDOWN, DIRRGHT \
),

[_LOWER] = LAYOUT_planck_mit( \
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_PIPE, \
  KC_INS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_QUES, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT \
),

[_RAISE] = LAYOUT_planck_mit( \
  KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS, \
  KC_DEL,  _______, _______, _______, _______, _______, _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_SLSH, \
  _______, _______, KC_CUT,  KC_COPY, KC_PSTE, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______,    _______,       _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

[_CHILDPROOF] = LAYOUT_planck_mit( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  LOWER,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RAISE \
),

[_NUMPAD] = LAYOUT_planck_mit( \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,    _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,    _______, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_0,    KC_0,    KC_DOT,  _______  \
),

[_ADJUST] =  LAYOUT_planck_mit( \
  RESET,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, RGB_SPI, RGB_SPD, _______,
  _______, _______, _______, _______, _______, _______, _______, QWERTY,  XXXXXXX, DVORAK,  CHILDPROOF, SNAKE, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_BTN1, KC_BTN2, KC_WH_D, KC_WH_U, \
  _______, _______, _______, _______, _______,     _______,      _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R \
)


};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case DIRUP:
    if (snake_status.last_moved_direction != DIRECTION_DOWN) {
      snake_status.direction = DIRECTION_UP;
    }
    return false;
  case DIRDOWN:
    if (snake_status.last_moved_direction != DIRECTION_UP) {
      snake_status.direction = DIRECTION_DOWN;
    }
    return false;
  case DIRLEFT:
    if (snake_status.last_moved_direction != DIRECTION_RIGHT) {
      snake_status.direction = DIRECTION_LEFT;
    }
    return false;
  case DIRRGHT:
    if (snake_status.last_moved_direction != DIRECTION_LEFT) {
      snake_status.direction = DIRECTION_RIGHT;
    }
 
    // corner
    if (record->event.pressed) {
      quarter_count += 1;
    } else {
      quarter_count -= 1;
    }
    if (quarter_count == 4) {
      reset_keyboard();
    }
    return false;
  case QUARTER:
    // corner
    if (record->event.pressed) {
      quarter_count += 1;
    } else {
      quarter_count -= 1;
    }
    if (quarter_count == 4) {
      reset_keyboard();
    }
    return false;
  case HALF:
    if (record->event.pressed) {
      half_count += 1;
    } else {
      half_count -= 1;
    }
    if (half_count == 2) {
      layer_move(_DVORAK);
      rgb_matrix_mode_noeeprom(RGB_MATRIX_MULTISPLASH);
    }
    return false;
  case SNAKE:
    layer_move(_SNAKE);
    snake_init();
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SNAKE);
    return false;
  }
  return true;
}


// RAW_EPSIZE is 32
void raw_hid_receive(uint8_t *data, uint8_t length) {
    raw_hid_send(data, length);
}

enum combo_events {
  DESKTOP_GO_LEFT,
  DESKTOP_GO_RIGHT,
  LEAD,
};

// can't be keys which have tap-hold
const uint16_t PROGMEM dsk_lower_left_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM dsk_lower_left_combo[] = {LCTLT_E, LSFTT_U, COMBO_END};
const uint16_t PROGMEM dsk_lower_right_combo[] = {KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM dsk_lower_lead_combo[] = {KC_Q, KC_J, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [DESKTOP_GO_LEFT] = COMBO_ACTION(dsk_lower_left_combo),
  [DESKTOP_GO_RIGHT] = COMBO_ACTION(dsk_lower_right_combo),
  [LEAD] = COMBO_ACTION(dsk_lower_lead_combo),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case DESKTOP_GO_LEFT:
      if (pressed) {
        // macOS
        tap_code16(LCTL(KC_LEFT));
      }
      break;
    case DESKTOP_GO_RIGHT:
      if (pressed) {
        // macOS
        tap_code16(LCTL(KC_RIGHT));
      }
      break;
      //   case LEAD:
      //     if (pressed) {
      //       qk_leader_start();
      //     }
      //     break;
  }
}
// LEADER_EXTERNS();
// 
// void matrix_scan_user(void) {
//   LEADER_DICTIONARY() {
//     leading = false;
//     leader_end();
// 
//     SEQ_ONE_KEY(KC_G) {
//       SEND_STRING("Archanan");
//     }
//   }
// }

void rgb_matrix_indicators_user(void) {
  uint8_t layer = get_highest_layer(layer_state);

  // ignore default layer
  if (layer == 0) {
    return;
  }

  for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
    for (uint8_t col = 0; col < MATRIX_COLS; col++) {
      uint8_t led_index = g_led_config.matrix_co[row][col];
      keypos_t pos = { col, row };
      uint16_t keycode = keymap_key_to_keycode(layer, pos);
      bool keycode_set_on_layer = keycode != KC_TRNS && keycode != KC_NO;
      if (led_index != NO_LED && keycode_set_on_layer) {
        rgb_matrix_set_color(led_index, 0xFF, 0x00, 0xFF);
      }
    }
  }
}

void keyboard_post_init_user(void) {
  rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
}
