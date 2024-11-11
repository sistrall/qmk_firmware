#pragma once

#include QMK_KEYBOARD_H

#include "sistrall2.h"

/**
 * Led management
 */

// Light LEDs 4, 5, 6, 7, 8 and 9 in cyan when keyboard number is active.
// LED named 4 on the PCB is identified as 3 in QMK
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_TEAL});

const rgblight_segment_t PROGMEM number_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_SPRINGGREEN});

const rgblight_segment_t PROGMEM symbol_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_MAGENTA});

const rgblight_segment_t PROGMEM navigation_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_RED});

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 20, HSV_YELLOW});

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t *const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(base_layer, number_layer, symbol_layer, navigation_layer, adjust_layer);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, BASE_LAYER));
    rgblight_set_layer_state(1, layer_state_cmp(state, NUMBERS_LAYER));
    rgblight_set_layer_state(2, layer_state_cmp(state, SYMBOLS_LAYER));
    rgblight_set_layer_state(3, layer_state_cmp(state, NAVIGATION_LAYER));
    rgblight_set_layer_state(4, layer_state_cmp(state, ADJUST_LAYER));

    return state;
}

/**
 * Display management
 */

#ifdef OLED_ENABLE

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
//     return OLED_ROTATION_180;
// }

bool oled_task_user(void) {
    //     if (is_keyboard_master()) {
    //         // QMK Logo and version information
    //         // clang-format off
    //         static const char PROGMEM qmk_logo[] = {
    //             0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
    //             0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
    //             0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
    //         // clang-format on

    //         oled_write_P(qmk_logo, false);
    //         oled_write_P(PSTR("sistrall\n\n"), false);

    //         // Host Keyboard Layer Status
    //         oled_write_P(PSTR("Layer: "), false);
    //         switch (get_highest_layer(layer_state | default_layer_state)) {
    //             case ADJUST_LAYER:
    //                 oled_write_ln_P(PSTR("Adjust\n"), false);
    //                 break;
    //             case NAVIGATION_LAYER:
    //                 oled_write_ln_P(PSTR("Navigation\n"), false);
    //                 break;
    //             case NUMBERS_LAYER:
    //                 oled_write_P(PSTR("Numbers\n"), false);
    //                 break;
    //             case SYMBOLS_LAYER:
    //                 oled_write_P(PSTR("Symbols\n"), false);
    //                 break;
    //             case BASE_LAYER:
    //                 oled_write_P(PSTR("Base\n"), false);
    //                 break;
    //             default:
    //                 oled_write_P(PSTR("Undefined\n"), false);
    //         }

    //         // Write host Keyboard LED Status to OLEDs
    //         led_t led_usb_state = host_keyboard_led_state();
    //         oled_write_P(led_usb_state.num_lock ? PSTR("NUMLCK ") : PSTR("       "), false);
    //         oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLCK ") : PSTR("       "), false);
    //         oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    //     } else {
    //         // clang-format off
    //         static const char PROGMEM kyria_logo[] = {
    //             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //             0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //             0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
    //             0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
    //             0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //             0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    //             0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
    //         };
    //         // clang-format on
    //         oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    //     }
    return false;
}

#endif

bool current_gen[HEIGHT][WIDTH];
// bool next_gen[HEIGHT][WIDTH];
bool seeding = true;
// const short seed_startpos_h = HEIGHT / 2 - SEED_HEIGHT / 2;
// const short seed_startpos_w = WIDTH / 2 - SEED_WIDTH / 2;
// short seed_offset = 0;

void render_grid(void)
{
    for(int i = 0; i < HEIGHT; i++) {
        for(int j = 0; j < WIDTH; j++) {
             oled_write_pixel(i, j, true);
        }
    }
}
// int count_neighbours(int row, int col)
// {
//     int count = 0;
//     for(int i = -1; i <= 1; i++) {
//         for(int j = -1; j <= 1; j++) {
//             if (i == 0 && j == 0) continue;
//             int r = (row + i + HEIGHT) % HEIGHT;
//             int c = (col + j + WIDTH) % WIDTH;
//             if(current_gen[r][c]) count++;
//         }
//     }
//     return count;
// }

// void update_state(void)
// {
//     for(int i = 0; i < HEIGHT; i++) {
//         for(int j = 0; j < WIDTH; j++) {
//             int neighbours = count_neighbours(i, j);
//             if(current_gen[i][j]) {
//                 next_gen[i][j] = !(neighbours < 2 || neighbours > 3);
//             } else {
//                 next_gen[i][j] = (neighbours == 3);
//             }
//         }
//     }

//     for(int i = 0; i < HEIGHT; i++) {
//         for(int j = 0; j < WIDTH; j++) {
//             current_gen[i][j] = next_gen[i][j];
//         }
//     }
// }

void start_state_machine(void)
{
    seeding = false;
}

// void reset_state_machine(void)
// {
//     seeding = true;
//     seed_offset = 0;
//     for(int i = 0; i < HEIGHT; i++) {
//         for(int j = 0; j < WIDTH; j++) {
//             current_gen[i][j] = false;
//         }
//     }
// }

// void add_seed(uint16_t keycode)
// {
//     int row = seed_startpos_h + seed_offset / SEED_HEIGHT;
//     int col = seed_startpos_w + seed_offset % SEED_WIDTH;
//     switch(keycode) {
//         case SPACE:
//             seed_offset++;
//             break;
//         case ROWSPACE:
//             seed_offset += SEED_WIDTH;
//             break;
//         default:
//             current_gen[row][col] = true;
//             seed_offset++;
//     }

//     if(seed_offset > SEED_WIDTH * SEED_HEIGHT - 1) {
//         seeding = false;
//         seed_offset = 0;
//     }
// }

void conway_gol(uint16_t keycode)
{
    switch (keycode) {
        case START:
            start_state_machine();
            break;
        case RESET:
            // reset_state_machine();
            render_grid();
            break;
        default:
        oled_write_pixel(1, 2, true);
            // if(seeding) {
            //     add_seed(keycode);
            // } else {
            //     update_state();
            // }
    }
    // render_grid();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_keyboard_master()) {
            conway_gol(keycode);
        }
    }
    return true;
}
