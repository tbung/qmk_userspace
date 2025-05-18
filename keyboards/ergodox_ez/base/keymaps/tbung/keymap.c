#include "tap_dance.h"

#include QMK_KEYBOARD_H
#include "version.h"

#define ADAPTIVE_TERM 180

enum layers {
    DEFAULT, // default layer
    SYMBOLS, // symbols
    NAV,     // mouse and other stuff
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    C_UNDO,
    C_CUT,
    C_COPY,
    C_PASTE,
    C_BSPC,
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_KC_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED_WITH_RELEASE(NULL, td_bspc_on_each_release, td_bspc_on_dance_finished, td_bspc_on_dance_reset),
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
  KC_EQL,        KC_1,         KC_2,         KC_3,         KC_4,    KC_5, KC_MUTE,     KC_MPLY, KC_6, KC_7,  KC_8,            KC_9,           KC_0,            KC_MINS,
  KC_DEL,        KC_Q,         KC_W,         KC_E,         KC_R,    KC_T, KC_VOLU,     MS_WHLU, KC_Y, KC_U,  KC_I,            KC_O,           KC_P,            KC_BSLS,
  KC_ESC,        KC_A,         KC_S,         KC_D,         KC_F,    KC_G,                       KC_H, KC_J,  KC_K,            KC_L,           KC_SCLN,         KC_QUOT,
  OSM(MOD_LSFT), LCTL_T(KC_Z), LALT_T(KC_X), LGUI_T(KC_C), KC_V,    KC_B, KC_VOLD,     MS_WHLD, KC_N, KC_M,  LGUI_T(KC_COMM), RALT_T(KC_DOT), RCTL_T(KC_SLSH), OSM(MOD_RSFT),
  _______,       _______,      _______,      KC_LEFT,      KC_RGHT,                                   KC_UP, KC_DOWN,         _______,        _______,         _______,
                                                                 _______, _______,     _______, KC_ESC,
                                                                          _______,     _______,
                                       LSFT_T(KC_SPC), TD(TD_KC_BSPC), _______,     _______, LT(SYMBOLS, KC_TAB), KC_ENT
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
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,         KC_F9,         KC_F10,        KC_F11,
  _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_UNDS, KC_PERC, _______,     _______, _______, _______, _______,       _______,       _______,       KC_F12,
  KC_ASTR, KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  KC_GRV,                        _______, _______, _______,       _______,       _______,       _______,
  KC_HASH, KC_MINS, KC_LBRC, KC_RBRC, KC_CIRC, KC_TILD, _______,     _______, _______, _______, KC_LGUI,       KC_RALT,       KC_RCTL,       QK_RBT,
  _______, _______, KC_AT,   KC_AMPR, KC_DLR,                                          _______, _______,       _______,       _______,       _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______,  C_BSPC, _______,     _______, _______, _______
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
[NAV] = LAYOUT_ergodox_pretty(
  _______, _______,       _______,       _______,       _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______,       _______,       _______,       _______, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, KC_LCTL,       KC_LALT,       KC_LGUI,      _______, _______,                       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  _______, LCTL(KC_Z),    LSFT(KC_DEL),  C_COPY,        C_PASTE, _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______,       _______,       _______,       _______,                                      KC_MS_BTN3, _______, _______, _______, _______,

                                                                 _______, _______,     _______, _______,
                                                                          _______,     _______,
                                                        _______, _______, _______,     _______, KC_MS_BTN1, KC_MS_BTN2
),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // tap_dance_action_t *action;
    os_variant_t os = detected_host_os();

    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
            case C_UNDO:
                if (os == OS_MACOS || os == OS_IOS)
                    register_code16(LCMD(KC_Z));
                else
                    register_code16(LCTL(KC_Z));
                return false;
            case C_CUT:
                if (os == OS_MACOS || os == OS_IOS)
                    register_code16(LCMD(KC_X));
                else
                    register_code16(LSFT(KC_DEL));
                return false;
            case C_COPY:
                if (os == OS_MACOS || os == OS_IOS)
                    register_code16(LCMD(KC_C));
                else
                    register_code16(LCTL(KC_INS));
                return false;
            case C_PASTE:
                if (os == OS_MACOS || os == OS_IOS)
                    register_code16(LCMD(KC_V));
                else
                    register_code16(LSFT(KC_INS));
                return false;
            case C_BSPC:
                if (os == OS_MACOS || os == OS_IOS)
                    register_code16(LALT(KC_BSPC));
                else
                    register_code16(LCTL(KC_BSPC));
                return false;
        }
    } else {
        switch (keycode) {
            case C_UNDO:
                if (os == OS_MACOS || os == OS_IOS)
                    unregister_code16(LCMD(KC_Z));
                else
                    unregister_code16(LCTL(KC_Z));
                return false;
            case C_CUT:
                if (os == OS_MACOS || os == OS_IOS)
                    unregister_code16(LCMD(KC_X));
                else
                    unregister_code16(LSFT(KC_DEL));
                return false;
            case C_COPY:
                if (os == OS_MACOS || os == OS_IOS)
                    unregister_code16(LCMD(KC_C));
                else
                    unregister_code16(LCTL(KC_INS));
                return false;
            case C_PASTE:
                if (os == OS_MACOS || os == OS_IOS)
                    unregister_code16(LCMD(KC_V));
                else
                    unregister_code16(LSFT(KC_INS));
                return false;
            case C_BSPC:
                if (os == OS_MACOS || os == OS_IOS)
                    unregister_code16(LALT(KC_BSPC));
                else
                    unregister_code16(LCTL(KC_BSPC));
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {};

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
