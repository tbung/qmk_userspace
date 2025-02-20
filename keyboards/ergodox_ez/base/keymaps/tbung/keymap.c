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
};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    TD_TRIPLE_TAP,
    TD_TRIPLE_HOLD
} td_state_t;

typedef struct {
    bool       is_press_action;
    td_state_t state;
} td_tap_t;

// Tap dance enums
enum {
    ADAPTIVE_BSPC,
};

td_state_t td_current_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void td_bspc_finished(tap_dance_state_t *state, void *user_data);
void td_bspc_reset(tap_dance_state_t *state, void *user_data);

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
  KC_EQL,        KC_1,        KC_2,    KC_3,           KC_4,    KC_5, KC_MUTE,     KC_MPLY, KC_6, KC_7,  KC_8,            KC_9,    KC_0,           KC_MINS,
  KC_DEL,        KC_Q,        KC_W,    KC_E,           KC_R,    KC_T, KC_VOLU,     MS_WHLU, KC_Y, KC_U,  KC_I,            KC_O,    KC_P,           KC_BSLS,
  KC_ESC,        KC_A,        KC_S,    KC_D,           KC_F,    KC_G,                       KC_H, KC_J,  KC_K,            KC_L,    KC_SCLN,        KC_QUOT,
  OSM(MOD_LSFT), CTL_T(KC_Z), KC_X,    KC_C,           KC_V,    KC_B, KC_VOLD,     MS_WHLD, KC_N, KC_M,  KC_COMM,         KC_DOT,  CTL_T(KC_SLSH), OSM(MOD_RSFT),
  _______,       _______,     KC_LGUI, ALT_T(KC_LEFT), KC_RGHT,                                   KC_UP, RALT_T(KC_DOWN), KC_RGUI, _______,        _______,
                                                             _______, _______,     _______, _______,
                                                                      _______,     _______,
                                  LT(NAV, KC_SPC), TD(ADAPTIVE_BSPC), _______,     _______, LSFT_T(KC_TAB), LT(SYMBOLS, KC_ENT)
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
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,     _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_EXLM, KC_LCBR, KC_RCBR, KC_AT,   KC_PERC, _______,     _______, _______, _______, _______, _______, _______, KC_F12,
  KC_ASTR, KC_PLUS, KC_LPRN, KC_RPRN, KC_EQL,  KC_GRV,                        _______, _______, _______, _______, _______, _______,
  KC_HASH, KC_AMPR, KC_LBRC, KC_RBRC, KC_CIRC, KC_TILD, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_UNDS, KC_MINS, KC_DLR,                                          _______, _______, _______, _______, _______,
                                               _______, _______,     _______, _______,
                                                        _______,     _______,
                                      _______, _______, _______,     _______, _______, _______
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
  _______, _______,    _______,      _______,      _______,      _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,      _______,      _______,      _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,      _______,      _______,      _______,                       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
  _______, LCTL(KC_Z), LSFT(KC_DEL), LCTL(KC_INS), LSFT(KC_INS), _______, _______,     _______, _______, _______, _______, _______, _______, _______,
  _______, _______,    _______,      _______,      _______,                                              _______, _______, _______, _______, _______,

                                                                 _______, _______,     _______, _______,
                                                                          _______,     _______,
                                                        _______, _______, _______,     _______, _______, _______
),
};
// clang-format on

td_state_t td_current_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else
            return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted)
            return TD_DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return TD_DOUBLE_HOLD;
        else
            return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TD_TRIPLE_TAP;
        else
            return TD_TRIPLE_HOLD;
    } else
        return TD_UNKNOWN;
}

static td_tap_t td_bspc_tap_state = {.is_press_action = true, .state = TD_NONE};

void td_bspc_finished(tap_dance_state_t *state, void *user_data) {
    td_bspc_tap_state.state = td_current_dance(state);
    switch (td_bspc_tap_state.state) {
        case TD_SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case TD_DOUBLE_HOLD:
            tap_code16(LCTL(KC_BSPC));
            break;
        case TD_DOUBLE_SINGLE_TAP:
            tap_code16(LCTL(KC_BSPC));
            break;
        default:
            break;
    }
}

void td_bspc_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_bspc_tap_state.state) {
        case TD_SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        default:
            break;
    }
    td_bspc_tap_state.state = TD_NONE;
}

tap_dance_action_t tap_dance_actions[] = {[ADAPTIVE_BSPC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_bspc_finished, td_bspc_reset)};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    } else {
        switch (keycode) {
            case TD(ADAPTIVE_BSPC):
                action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
                if (action->state.count == 1 && !action->state.finished) tap_code(KC_BSPC);
                if (action->state.count == 2 && !action->state.finished) tap_code16(LCTL(KC_BSPC));
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
