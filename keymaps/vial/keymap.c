/* Copyright 2020 tominabox1
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Layer 0 Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | TAB  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt |MO(3) |MO(2) |    Space    |MO(1) | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_planck_mit(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
    KC_LCTL, KC_LGUI, KC_LALT, MO(3),   MO(2),        KC_SPC,      MO(1),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Layer 1 12345
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |C-Home|C-End |C-PgUp|C-PgDn|      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |Gui-Lt|Gui-Rt|      |      |      |      |      |      |      |  INS |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt |      | Caps |             |      | Home | PgDn | PgUp | End  |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_planck_mit(
    KC_GRV,  KC_1,          KC_2,         KC_3,          KC_4,             KC_5,    KC_6,   KC_7,     KC_8,       KC_9,      KC_0,      KC_BSPC,
    KC_DEL,  LCTL(KC_HOME), LCTL(KC_END), LCTL(KC_PGUP), LCTL(KC_PGDOWN),  KC_NO,   KC_NO,  KC_MINS,  KC_EQL,     KC_LBRC,   KC_RBRC,   KC_BSLS,
    _______, 0x950,         0x94f,        KC_NO,         KC_NO,            KC_NO,   KC_NO,  KC_NO,    _______,    _______,   KC_INSERT, _______,
    _______, _______,       _______,      _______,       KC_CAPSLOCK,          _______,     _______,  KC_HOME,    KC_PGDOWN, KC_PGUP,   KC_END
),

/* Layer 2 !@#$%
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |  $   |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |      |      |      |      |      |      |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |      |      |      |      |      |      |      |      | Play | Mute |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt |      |      |             |      | Bri- | Vol- | Vol+ | Bri+ |
 * `-----------------------------------------------------------------------------------'
 */
[2] = LAYOUT_planck_mit(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_MUTE, _______,
    _______, _______, _______, _______, _______,      _______,     _______, KC_BRID, KC_VOLD, KC_VOLU, KC_BRIU
),

/* Layer 3 Function & Mouse
 * ,-----------------------------------------------------------------------------------.
 * | Task |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |C-A-D |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F11 |  F12 |      |      |      |      |      |      | MS-4 | MS-5 | MS-WU|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  PrS |  ScL |Pause |      |      |      |      | MS-1 | MS-2 | MS-3 | MS-WD|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt |      |      |    MO(4)    |TG(5) | MS-L | MS-D | MS-U | MS-R |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_planck_mit(
    RCS(KC_ESCAPE), KC_F1,      KC_F2,         KC_F3,    KC_F4,       KC_F5,   KC_F6,  KC_F7,    KC_F8,    KC_F9,   KC_F10,  LCA(KC_DELETE),
    KC_NO,          KC_F11,     KC_F12,        KC_NO,    KC_NO,       KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_BTN4, KC_BTN5, KC_WH_U,
    _______,        KC_PSCREEN, KC_SCROLLLOCK, KC_PAUSE, KC_NO,       KC_NO,   KC_NO,  KC_NO  ,  KC_BTN1,  KC_BTN2, KC_BTN3, KC_WH_D,
    _______,        _______,    _______,       _______,  KC_NO,       MO(4),     TG(5)  ,  KC_MS_L,  KC_MS_D, KC_MS_U, KC_MS_R
),
/* Layer 4 System
 * ,-----------------------------------------------------------------------------------.
 * |      | Eft- | Eft+ |      |      |      |      |      |      |      |      | Reset|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Hue- | Hue+ |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Apple |RGBTOG|Mode+ | Bri- | Bri+ |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[4] = LAYOUT_planck_mit(
    KC_NO,                RGB_SPD,  RGB_SPI,  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,  RESET,
    KC_NO,                RGB_HUD,  RGB_HUI,  RGB_SAD,  RGB_SAI, KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,
    MAGIC_TOGGLE_ALT_GUI, RGB_TOG,  RGB_MOD,  RGB_VAD,  RGB_VAI, KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,
    KC_NO,                KC_NO,    KC_NO,    KC_NO,    KC_NO,         KC_NO,      KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO
),

/* Layer 5 Numberic
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |   Q  |   W  |   E  |   R  |   7  |   8  |   9  |   -  |   /  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |   A  |   S  |   D  |   F  |   4  |   5  |   6  |   +  |   *  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   1  |   2  |   3  |   =  |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  GUI |  Alt | TG(5)|      |      0      |   .  | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[5] = LAYOUT_planck_mit(
    KC_ESC,   KC_Q,      KC_W,    KC_E,    KC_R,  KC_7,   KC_8,   KC_9,    KC_KP_MINUS,  KC_KP_SLASH,     KC_NO,   KC_BSPC,
    KC_DEL,   KC_A,      KC_S,    KC_D,    KC_F,  KC_4,   KC_5,   KC_6,    KC_KP_PLUS,   KC_KP_ASTERISK,  KC_NO,   KC_NO,
    KC_LSFT,  KC_Z,      KC_X,    KC_C,    KC_V,  KC_1,   KC_2,   KC_3,    KC_EQL,       KC_NO,           KC_NO,   KC_ENT ,
    KC_LCTL,  KC_LGUI,   KC_LALT, TG(5),  KC_NO,      KC_0,      KC_DOT,  KC_LEFT,      KC_DOWN,         KC_UP,   KC_RGHT
)

};

