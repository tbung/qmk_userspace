#include QMK_KEYBOARD_H
#include "version.h"

#define ADAPTIVE_TERM 180

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA, // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
    ADAPTIVE_BSPC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  | LEFT |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Del    |   Q  |   W  |   E  |   R  |   T  |  L1  |           |  L1  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Esc    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------| Hyper|           | Meh  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|X/Alt |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |./Alt |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |  L1  | Left | Right|                                       |  Up  | Down |  L1  |   [  |  ]   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Alt  | LGui |       | Alt  |Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_EQL,          KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_LEFT,              KC_RGHT,      KC_6, KC_7,  KC_8,     KC_9,           KC_0,              KC_MINS,
  KC_DEL,          KC_Q,        KC_W,          KC_E,    KC_R,    KC_T,    TG(SYMB),             TG(SYMB),     KC_Y, KC_U,  KC_I,     KC_O,           KC_P,              KC_BSLS,
  GUI_T(KC_ESC),   KC_A,        KC_S,          KC_D,    KC_F,    KC_G,                                        KC_H, KC_J,  KC_K,     KC_L,           LT(MDIA, KC_SCLN), GUI_T(KC_QUOT),
  KC_LSFT,         CTL_T(KC_Z), LALT_T(KC_X),  KC_C,    KC_V,    KC_B,    ALL_T(KC_NO),         MEH_T(KC_NO), KC_N, KC_M,  KC_COMM,  RALT_T(KC_DOT), CTL_T(KC_SLSH),    KC_RSFT,
  LT(SYMB, KC_GRV), KC_QUOT,     MO(SYMB),      KC_LEFT, KC_RGHT,                                                    KC_UP, KC_DOWN,  MO(SYMB),       KC_LBRC,           KC_RBRC,
                                                                      KC_LALT, KC_LGUI,         KC_LALT, CTL_T(KC_ESC),
                                                                               KC_HOME,         KC_PGUP,
                                               LT(MDIA, KC_SPC), ADAPTIVE_BSPC, KC_END,         KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |   _  |  -   |                                       |   .  |   0  |   =  |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  VRSN,    KC_F1,          KC_F2,           KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,        KC_F10,         KC_F11,
  KC_TRNS, KC_EXLM,        KC_AT,           KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,         KC_ASTR,        KC_F12,
  KC_TRNS, KC_HASH,        KC_DLR,          KC_LPRN, KC_RPRN, KC_GRV,                        KC_DOWN, KC_4,    KC_5,    KC_6,         KC_PLUS,        KC_TRNS,
  KC_TRNS, CTL_T(KC_PERC), LALT_T(KC_CIRC), KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    RALT_T(KC_3), CTL_T(KC_BSLS), KC_TRNS,
  EE_CLR,  KC_TRNS,        KC_TRNS,         KC_UNDS, KC_MINS,                                         KC_DOT,  KC_0,    KC_EQL,       KC_TRNS,        KC_TRNS,
                                                              RGB_MOD, KC_TRNS,     RGB_TOG, RGB_M_P,
                                                                       KC_TRNS,     KC_TRNS,
                                                     RGB_VAD, RGB_VAI, KC_TRNS,     KC_TRNS, RGB_HUD, RGB_HUI
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
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,                       KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS, KC_MPLY,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
),
};
// clang-format on

static struct adaptive_state {
    uint16_t previous_keycode;
    uint32_t time;
} adaptive_state = {KC_NO, 0};

// adapted from https://github.com/openorclose/qmk_firmware/blob/master/keyboards/crkbd/keymaps/openorclose/features/adaptive_keys.h
bool process_adaptive_keys(uint16_t keycode, keyrecord_t *record) {
    bool exit_code = true;

    if (record->event.pressed) {
        uint8_t mods = get_mods();

        // don't interfere if modifiers are involved
        if (mods & MOD_MASK_CAG) {
            return true;
        }

        if ((timer_elapsed32(adaptive_state.time) >= ADAPTIVE_TERM)) {
            goto adaptive_keys_save_keycode;
        }

        switch (adaptive_state.previous_keycode) {
            case ADAPTIVE_BSPC:
                switch (keycode) {
                    case ADAPTIVE_BSPC:
                        tap_code16(LCTL(KC_BSPC));
                        exit_code = false;
                        break;
                }
                break;
        }

    adaptive_keys_save_keycode:
        adaptive_state.previous_keycode = keycode;
        adaptive_state.time             = timer_read32(); // (re)start prior_key timing
    }

    return exit_code;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_adaptive_keys(keycode, record)) {
        return false;
    }

    if (record->event.pressed) {
        switch (keycode) {
            case ADAPTIVE_BSPC:
                register_code(KC_BSPC);
                return false;
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    } else {
        switch (keycode) {
            case ADAPTIVE_BSPC:
                unregister_code(KC_BSPC);
                return false;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (timer_elapsed32(adaptive_state.time) >= ADAPTIVE_TERM) { // 30 seconds
        adaptive_state.time             = timer_read32();
        adaptive_state.previous_keycode = KC_NO;
    }
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
