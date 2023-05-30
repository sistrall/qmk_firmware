// Lets you roll mod-tap keys
// See: https://docs.qmk.fm/#/tap_hold?id=ignore-mod-tap-interrupt
#define IGNORE_MOD_TAP_INTERRUPT

// Kyria is a split keyboard and I connect it
// to an USB port on the left side of my laptop.
// Therefore, to lower the cable clutter on my desk,
// I define left half as the master one.
#define MASTER_LEFT

// The amount of tapping to trigger the toggle on layer tap-toggle keys:
// by setting 1, I say to toggle on a single tap and to activate the layer
// when the key is held down.
#define TAPPING_TOGGLE 1

// This is the global tapping term threshold for the
// tap-hold feature: keys with tap-hold enabled that are kept
// down more than the following amount ar considered hold and
// that triggers their hold behaviour.
#define TAPPING_TERM 240

#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_8
#define RSPC_KEYS KC_RSFT, KC_RSFT, KC_9

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LAYERS

    #define RGBLIGHT_ANIMATIONS
    #define RGBLIGHT_HUE_STEP  8
    #define RGBLIGHT_SAT_STEP  8
    #define RGBLIGHT_VAL_STEP  8
    #define RGBLIGHT_LIMIT_VAL 150
#endif

#ifdef OLED_ENABLE
    #define SPLIT_LAYER_STATE_ENABLE
    #define SPLIT_MODS_ENABLE
    #define SPLIT_OLED_ENABLE
#endif
