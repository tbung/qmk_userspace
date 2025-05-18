#ifndef TAP_DANCE_H
#define TAP_DANCE_H

#include QMK_KEYBOARD_H

// Tap dance enums
enum {
    TD_KC_BSPC,
};

void td_bspc_on_each_release(tap_dance_state_t *state, void *user_data);
void td_bspc_on_dance_finished(tap_dance_state_t *state, void *user_data);
void td_bspc_on_dance_reset(tap_dance_state_t *state, void *user_data);

#endif
