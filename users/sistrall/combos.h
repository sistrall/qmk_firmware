#pragma once

#include QMK_KEYBOARD_H

#include "keymap_italian_mac_iso.h"

#include "keycodes.h"
#include "tap_dances.h"

enum combos {
    LEFT_HALF_TOGGLE_TAP_NUMBERS_LAYER,
    LEFT_HALF_TOGGLE_TAP_NAVIGATION_LAYER,

    LEFT_HALF_SQUARE_BRACKET_OPEN,
    LEFT_HALF_CURLY_BRACKET_OPEN,
    LEFT_HALF_LABK,

    RIGHT_HALF_TOGGLE_TAP_NUMBERS_LAYER,
    RIGHT_HALF_TOGGLE_TAP_NAVIGATION_LAYER,

    RIGHT_HALF_SQUARE_BRACKET_CLOSE,
    RIGHT_HALF_CURLY_BRACKET_CLOSE,
    RIGHT_HALF_RABK,

    LAST_COMBO_POSITION_PLUS_ONE,
};

uint16_t COMBO_LEN = LAST_COMBO_POSITION_PLUS_ONE;

const uint16_t PROGMEM left_half_square_bracket_open[] = {LC_Z, LA_X, COMBO_END};
const uint16_t PROGMEM left_half_curly_bracket_open[] = {LA_X, IT_C, COMBO_END};
const uint16_t PROGMEM left_half_labk[] = {IT_C, IT_D, COMBO_END};

const uint16_t PROGMEM right_half_square_bracket_close[] = {RA_DOT, RC_MINS, COMBO_END};
const uint16_t PROGMEM right_half_curly_bracket_close[] = {TD(TD_CQ), RA_DOT, COMBO_END};
const uint16_t PROGMEM right_half_rabk[] = {IT_H, TD(TD_CQ), COMBO_END};

combo_t key_combos[] = {
    COMBO(left_half_square_bracket_open, IT_LBRC),
    COMBO(left_half_curly_bracket_open, IT_LCBR),
    COMBO(left_half_labk, IT_LABK),

    COMBO(right_half_square_bracket_close, IT_RBRC),
    COMBO(right_half_curly_bracket_close, IT_RCBR),
    COMBO(right_half_rabk, IT_RABK),
};
