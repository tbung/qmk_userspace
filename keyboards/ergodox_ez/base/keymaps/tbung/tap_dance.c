#include "tap_dance.h"

void td_bspc_on_each_release(tap_dance_state_t *state, void *user_data) {
    if (!state->finished) {
        tap_code(KC_BSPC);
    }
}

void td_bspc_on_dance_finished(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1 && !state->interrupted) {
        layer_on(2);
    } else if (state->count >= 2 && state->pressed) {
        register_code(KC_BSPC);
    }
}

void td_bspc_on_dance_reset(tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        layer_off(2);
    } else {
        unregister_code(KC_BSPC);
    }
}
