#pragma once

#include QMK_KEYBOARD_H

// My laptop has an Italian layout, so it's useful to have Italian keycodes defined.
#include "keymap_italian_mac_iso.h"

#include "layers.h"

#define VL_ENT LT(NAVIGATION_LAYER, KC_ENT)
#define NL_SPC LT(NUMBERS_LAYER, KC_SPC)

#define MO_NAV MO(NAVIGATION_LAYER)
#define MO_NUM MO(NUMBERS_LAYER)

#define NL_TAB LT(NUMBERS_LAYER, KC_TAB)
#define VL_BSP LT(NAVIGATION_LAYER, KC_BACKSPACE)

#define LG_ESC MT(MOD_LGUI, KC_ESC)
#define RG_ESC MT(MOD_RGUI, KC_ESC)

#define TT_BL TT(BASE_LAYER)
#define TT_NL TT(NUMBERS_LAYER)
#define TT_SL TT(SYMBOLS_LAYER)
#define TT_VL TT(NAVIGATION_LAYER)
#define TT_AL TT(ADJUST_LAYER)

#define LG_A LGUI_T(IT_A)
#define LA_R LALT_T(IT_R)
#define LC_S LCTL_T(IT_S)
#define LC_Z LCTL_T(IT_Z)
#define LA_X LALT_T(IT_X)
#define LC_E LCTL_T(KC_ESC)
#define LS_T LSFT_T(IT_T)

#define RS_N RSFT_T(IT_N)
#define RC_E RCTL_T(IT_E)
#define RA_I RALT_T(IT_I)
#define RG_O RGUI_T(IT_O)
#define RC_MINS RCTL_T(IT_MINS)
#define RA_DOT RALT_T(IT_DOT)

#define LA_TAB LALT_T(KC_TAB)
#define RA_BSPC RALT_T(KC_BSPC)
