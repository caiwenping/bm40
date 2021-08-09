/* Copyright 2020 tominabox1, Richard Goulter <richard.goulter@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "bm40.h"

#if defined(RGB_MATRIX_ENABLE)
#define LED_MATRIX_CENTER { 105, 30 }
led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        { 0,  1,  2,  3,  4,  5,      6,  7,  8,  9, 10, 11},
        {12, 13, 14, 15, 16, 17,     18, 19, 20, 21, 22, 23},
        {24, 25, 26, 27, 28, 29,     30, 31, 32, 33, 34, 35},
        {36, 37, 38, 39, 40, 41, NO_LED, 42, 43, 44, 45, 46}
    }, {
        // LED Index to Physical Position
        {   0,   0 }, { 19,   0 }, {  38,   0 }, {  57,   0 }, {  76,   0 }, {  95,   0 }, {  114,   0 }, { 133,   0 }, { 152,   0 }, { 171,   0 }, { 190,   0 }, { 210,   0 },
        {   0,  19 }, { 19,  19 }, {  38,  19 }, {  57,  19 }, {  76,  19 }, {  95,  19 }, {  114,  19 }, { 133,  19 }, { 152,  19 }, { 171,  19 }, { 190,  19 }, { 210,  19 },
        {   0,  38 }, { 19,  38 }, {  38,  38 }, {  57,  38 }, {  76,  38 }, {  95,  38 }, {  114,  38 }, { 133,  38 }, { 152,  38 }, { 171,  38 }, { 190,  38 }, { 210,  38 },
        {   0,  58 }, { 19,  58 }, {  38,  58 }, {  57,  58 }, {  76,  58 },         {  105,  58 },       { 133,  58 }, { 152,  58 }, { 171,  58 }, { 190,  58 }, { 210,  58 },

        // UNDERGLOW
        {   196, 36 }, {  157,  36 }, {  123, 36 }, { 90,  36 }, { 57,  36 }, { 24,  36 }
    }, {
        // LED Index to Flag
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
        1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
        1, 1, 1, 1, 1,   1,  1, 1, 1, 1, 1,
        2, 2, 2, 2, 2, 2  //under glow
    }
};

const bool text_1[] = {
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 0,   0,  0, 1, 1, 1, 1,
};

const bool text_2[] = {
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 0,   0,  0, 0, 0, 0, 0,
};

const bool text_3[] = {
    0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 1,   1,  1, 0, 0, 0, 0,
};

const bool text_4[] = {
    1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
    1, 1, 1, 1, 0,   0,  0, 1, 1, 1, 1,
};

const bool text_5[] = {
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0,   1,  1, 1, 1, 1, 1,
};


void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        for (uint8_t i = led_min; i <= led_max; i++) {
            if (g_led_config.flags[i] & LED_FLAG_KEYLIGHT) {
                rgb_matrix_set_color(i, 0x00,0x09,0x00);
            }
        }
    }

    uint8_t i,r,g,b;
    for (i = led_min; i <= led_max; i++){
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 1:
                r=0x00; g=0x18; b=0x20;
                if (text_1[i]) rgb_matrix_set_color(i, r,g,b);
                break;
            case 2:
                r=0x20; g=0x00; b=0x27;
                if (text_2[i]) rgb_matrix_set_color(i, r,g,b);
                break;
            case 3:
                r=0x25; g=0x26; b=0x00;
                if (text_3[i]) rgb_matrix_set_color(i, r,g,b);
                break;
            case 4:
                r=0x25; g=0x00; b=0x00;
                if (text_4[i]) rgb_matrix_set_color(i, r,g,b);
                break;
            case 5:
                r=0x03; g=0x18; b=0x00;
                if (text_5[i]) rgb_matrix_set_color(i, r,g,b);
                break;
            default:
                break;
        }
    }
}  // Capslock and layer indicator.


void suspend_power_down_kb(void) {
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_user();
}

#endif
