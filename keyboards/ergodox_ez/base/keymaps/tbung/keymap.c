#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#include QMK_KEYBOARD_H
#include "version.h"

enum layers {
    DEFAULT, // default layer
    SYMBOLS, // symbols
    MISC,     // mouse and other stuff
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
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |      |           |      |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |      |           |      |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|X/Alt |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |./Alt |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |  L1  | Left | Right|                                       |  Up  | Down |  L1  |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |        |
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |      |       |      |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   |      |       |      |        |      |
 *                                 `--------------------'       `----------------------'
 */
[DEFAULT] = LAYOUT_ergodox_pretty(
  KC_EQL,        KC_1,         KC_2,         KC_3,         KC_4,    KC_5, TD(TD_MUT_PREV),     TD(TD_PLY_NEXT), KC_6, KC_7,  KC_8,            KC_9,           KC_0,            KC_MINS,
  KC_DEL,        KC_Q,         KC_W,         KC_E,         KC_R,    KC_T, KC_VOLU,             MS_WHLU,         KC_Y, KC_U,  KC_I,            KC_O,           KC_P,            KC_BSLS,
  KC_ESC,        KC_A,         KC_S,         KC_D,         KC_F,    KC_G,                                       KC_H, KC_J,  KC_K,            KC_L,           KC_SCLN,         KC_QUOT,
  OSM(MOD_LSFT), LCTL_T(KC_Z), LALT_T(KC_X), LGUI_T(KC_C), KC_V,    KC_B, KC_VOLD,             MS_WHLD,         KC_N, KC_M,  LGUI_T(KC_COMM), LALT_T(KC_DOT), RCTL_T(KC_SLSH), OSM(MOD_RSFT),
  _______,       _______,      KC_LCMD,      KC_LEFT,      KC_RGHT,                                                   KC_UP, KC_DOWN,         KC_LCMD,        _______,         _______,
                                                                 _______, _______,             _______, KC_ESC,
                                                                          _______,             _______,
                                       LSFT_T(KC_SPC), LT(MISC, KC_BSPC), _______,             _______, LT(SYMBOLS, KC_TAB), KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+-----+------+--------|
 * |         |   !  |   {  |   }  |   @  |   %  |      |           |      |      |      |      |      |      |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    *    |   +  |   (  |   )  |   =  |   `  |------|           |------|      |      |      |      |      |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |    #    |   &  |   [  |   ]  |   ^  |   ~  |      |           |      |      |      |      |      |      |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |   _  |   -  |   $  |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMBOLS] = LAYOUT_ergodox_pretty(
  _______,       _______,         KC_AT,           KC_HASH,         KC_DLR,        KC_PERC, _______,     _______, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______, _______,
  KC_CIRC,       KC_EXLM,         KC_LCBR,         KC_RCBR,         KC_MINS,       _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  KC_AMPR,       KC_PLUS,         KC_LPRN,         KC_RPRN,         KC_EQL,        KC_GRV,                        _______, _______, _______, _______, _______, _______,
  OSM(MOD_LSFT), LCTL_T(KC_ASTR), LALT_T(KC_LBRC), LGUI_T(KC_RBRC), KC_UNDS,       KC_TILD, _______,     _______, _______, _______, _______, _______, _______, OSM(MOD_RSFT),
  _______,       _______,         KC_HOME,         MEH(KC_LEFT),    MEH(KC_RIGHT),                                         KC_PGUP, KC_PGDN, KC_END, _______, _______,
                                                                                   _______, _______,     _______, _______,
                                                                                            _______,     _______,
                                                                   _______,  HYPR(KC_BSPC), _______,     _______, _______, MO(SYSTEM)
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MISC] = LAYOUT_ergodox_pretty(
  _______, KC_F1,      KC_F2,      KC_F3,         KC_F4,          KC_F5,      _______,     _______, KC_F6,   KC_F7,       KC_F8,         KC_F9,      KC_F10,  KC_F11,
  _______, HYPR(KC_1), HYPR(KC_2), HYPR(KC_3),    HYPR(KC_4),     HYPR(KC_5), _______,     _______, _______, RALT(KC_U),  _______,       RALT(KC_O), _______, KC_F12,
  _______, RALT(KC_A), RALT(KC_S), _______,       _______,        _______,                          MS_LEFT, MS_DOWN,     MS_UP,         MS_RGHT,    _______, _______,
  _______, KC_UNDO,    KC_CUT,     KC_COPY,       KC_PASTE,       _______,    _______,     _______, _______, _______,     _______,       _______,    _______, _______,
  _______, _______,    _______,    HYPR(KC_LEFT), HYPR(KC_RIGHT),                                            HYPR(KC_UP), HYPR(KC_DOWN), _______,    _______, _______,
                                                                     _______, _______,     _______, _______,
                                                                              _______,     _______,
                                                         MO(SYSTEM), _______, _______,     _______, MS_BTN1, MS_BTN2
),

[SYSTEM] = LAYOUT_ergodox_pretty(
_______, _______, _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, _______, _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, _______, _______,       _______,   _______, _______,                       _______, _______, _______,   _______,       _______, _______,
_______, _______, _______,       _______,   _______, _______, _______,     _______, _______, _______, _______,   _______,       _______, _______,
_______, _______, QK_BOOTLOADER, QK_REBOOT, _______,                                         _______, QK_REBOOT, QK_BOOTLOADER, _______, _______,
                                                     _______, _______,     _______, _______,
                                                              _______,     _______,
                                            _______, _______, _______,     _______, _______, _______
),
};
// clang-format on

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
