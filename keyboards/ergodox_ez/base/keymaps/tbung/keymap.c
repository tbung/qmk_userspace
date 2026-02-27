#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    DEFAULT, // default layer
    ONEHAND,
    SYMBOLS, // symbols
    OSNAV,     // mouse and other stuff
    SWAPPED,
    SYSTEM,
};

enum {
    TD_PLY_NEXT,
    TD_MUT_PREV,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    [TD_PLY_NEXT] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT),
    [TD_MUT_PREV] = ACTION_TAP_DANCE_DOUBLE(KC_MUTE, KC_MPRV),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[DEFAULT] = LAYOUT_ergodox_pretty(
  KC_EQL,        KC_1,    KC_2,          KC_3,          KC_4,          KC_5, TD(TD_MUT_PREV),     TD(TD_PLY_NEXT), KC_6, KC_7,          KC_8,            KC_9,           KC_0,    KC_MINS,
  KC_DEL,        KC_Q,    KC_W,          KC_E,          KC_R,          KC_T, KC_VOLU,             MS_WHLU,         KC_Y, KC_U,          KC_I,            KC_O,           KC_P,    KC_BSLS,
  KC_ESC,        KC_A,    KC_S,          KC_D,          KC_F,          KC_G,                                       KC_H, KC_J,          KC_K,            KC_L,           KC_SCLN, KC_QUOT,
  OSM(MOD_LSFT), KC_Z,    LCMD_T(KC_X),  LALT_T(KC_C),  LCTL_T(KC_V),  KC_B, KC_VOLD,             MS_WHLD,         KC_N, RCTL_T(KC_M),  RALT_T(KC_COMM), RCMD_T(KC_DOT), KC_SLSH, OSM(MOD_RSFT),
  _______,       _______, KC_LGUI, LALT_T(KC_LEFT), LCTL_T(KC_RIGHT),                                                   RCTL_T(KC_UP), RALT_T(KC_DOWN),   KC_RGUI,  _______, _______,
                                                                         _______, _______,     _______, _______,
                                                                                  _______,     _______,
                                              LSFT_T(KC_SPC), LT(OSNAV, KC_BSPC), _______,     _______, LT(SYMBOLS, KC_ESC), LCTL_T(KC_ENT)
),
[ONEHAND] = LAYOUT_ergodox_pretty(
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                       _______, _______, _______, _______, _______, _______,
  _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    _______,     _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, _______,
  _______,       _______, OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL),                                                   OSM(MOD_RCTL), OSM(MOD_RALT),   OSM(MOD_RGUI),  _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                          LT(SWAPPED, KC_SPC), _______, _______,     _______, _______, _______
),

[SYMBOLS] = LAYOUT_ergodox_pretty(
  _______,       _______, KC_AT,           KC_HASH,         KC_DLR,          KC_PERC, _______,     _______, KC_CIRC, KC_AMPR,         KC_ASTR,       _______,          _______, _______,
  _______,       KC_EXLM, KC_LCBR,         KC_RCBR,         KC_MINS,         KC_CIRC, _______,     _______, _______, _______,         _______,       _______,          _______, _______,
  KC_AMPR,       KC_PLUS, KC_LPRN,         KC_RPRN,         KC_EQL,          KC_GRV,                        KC_LEFT, KC_DOWN,         KC_UP,         KC_RIGHT,         _______, _______,
  OSM(MOD_LSFT), KC_ASTR, LCMD_T(KC_LBRC), LALT_T(KC_RBRC), LCTL_T(KC_UNDS), KC_TILD, _______,     _______, _______, OSM(MOD_RCTL), OSM(MOD_RALT),   OSM(MOD_RGUI),    _______, _______,
  _______,       _______, KC_HOME,         MEH(KC_LEFT),    MEH(KC_RIGHT),                                           KC_PGUP,         KC_PGDN,       KC_END,           _______, _______,
                                                                             _______, _______,     _______, _______,
                                                                                      _______,     _______,
                                                      LSFT_T(KC_TAB),  HYPR(KC_BSPC), _______,     _______, _______, MO(SYSTEM)
),

[OSNAV] = LAYOUT_ergodox_pretty(
  KC_F11,  KC_F1,      KC_F2,              KC_F3,              KC_F4,              KC_F5,      _______,     _______, KC_F6,   KC_F7,           KC_F8,         KC_F9,            KC_F10,   KC_F11,
  KC_F12,  KC_F6,      KC_F7,              KC_F8,              KC_F9,              KC_F10,     _______,     _______, _______, _______,         _______,       _______,          _______,  KC_F12,
  _______, HYPR(KC_1), HYPR(KC_2),         HYPR(KC_3),         HYPR(KC_4),         HYPR(KC_5),                       KC_LEFT, KC_DOWN,         KC_UP,         KC_RIGHT,         _______, _______,
  _______, KC_UNDO,    LCMD_T(KC_CUT),     LALT_T(KC_COPY),    LCTL_T(KC_PASTE),   KC_AGAIN,   _______,     _______, _______, OSM(MOD_RCTL), OSM(MOD_RALT),   OSM(MOD_RGUI),    _______, _______,
  _______, _______,    _______,            HYPR(KC_LEFT),      HYPR(KC_RIGHT),                                                HYPR(KC_UP),     HYPR(KC_DOWN), _______,          _______, _______,
                                                                                      _______, _______,     _______, _______,
                                                                                               _______,     _______,
                                                                          MO(SYSTEM), _______, _______,     _______, _______, _______
),

[SWAPPED] = LAYOUT_ergodox_pretty(
  KC_MINS,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    TD(TD_MUT_PREV),     TD(TD_PLY_NEXT),KC_1,    KC_2,    KC_3,    KC_4,    KC_5, KC_EQL,
  KC_BSLS,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_VOLU,             MS_WHLU,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, KC_DEL,
  KC_QUOT,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,                                      KC_A,    KC_S,    KC_D,    KC_F,    KC_G, KC_ESC,
  OSM(MOD_LSFT), KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_VOLD,             MS_WHLD,        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, OSM(MOD_RSFT),
  _______,       _______, OSM(MOD_RGUI), RALT_T(KC_TAB), RCTL_T(KC_ENT),                                                   OSM(MOD_LCTL), OSM(MOD_LALT),   OSM(MOD_LGUI),  _______, _______,
                                                          _______, _______,     _______, _______,
                                                                   _______,     _______,
                                                 _______, _______, _______,     _______, _______, _______
),
// TODO: Maybe add application specific layer toggles to this (specific games, DnD, ...)
[SYSTEM] = LAYOUT_ergodox_pretty(
_______, _______,     _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, TG(ONEHAND), _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, _______,     _______,       _______,   _______, _______,                       _______, _______, _______,   _______,       _______, _______,
_______, _______,     _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, _______,     QK_BOOTLOADER, QK_REBOOT, _______,                                         _______, QK_REBOOT, QK_BOOTLOADER, _______, _______,
                                                         _______, _______,     _______, _______,
                                                                  _______,     _______,
                                                _______, _______, _______,     _______, _______, _______
),
};
// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // mod-tap only supports simple keycodes, intercept tap so we can send KC_UNDS (which is shifted)
        case LCTL_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
    }
    return true;
}

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
            break;
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
            break;
        default:
            break;
    }

    return state;
};
