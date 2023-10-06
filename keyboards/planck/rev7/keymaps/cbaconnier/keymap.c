/* Copyright 2015-2023 Jack Humbert
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
#include "keymap_extras/keymap_swiss_fr.h"
#include "keymap_extras/sendstring_swiss_fr.h"

enum planck_layers { _DVORAK, _LOWER, _RAISE, _MOVE };

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Dvorak
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  |   /  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  | Bksp |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Shift|   :  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | Move | Alt  | GUI  |Lower |    Space    |Raise |Altrgr| Menu | Ctrl |  Vim |
     * `-----------------------------------------------------------------------------------'
     */
    [_DVORAK] = LAYOUT_planck_grid(
        KC_TAB,  CH_QUOT,   CH_COMM, CH_DOT,  CH_P,  CH_Y,    CH_F,    CH_G,  CH_C,    CH_R,   CH_L,    CH_SLSH,
        KC_ESC,  CH_A,      CH_O,    CH_E,    CH_U,  CH_I,    CH_D,    CH_H,  CH_T,    CH_N,   CH_S,    KC_BSPC,
        KC_LSFT, CH_COLN,   CH_Q,    CH_J,    CH_K,  CH_X,    CH_B,    CH_M,  CH_W,    CH_V,   CH_Z,    KC_ENT,
        KC_LCTL, TO(_MOVE), KC_LALT, KC_LGUI, LOWER, _______, KC_SPC,  RAISE, KC_RALT, KC_APP, KC_RCTL, _______
    ),


    /* Lower
     * ,-----------------------------------------------------------------------------------.
     * |      |   7  |   5  |   3  |   1  |   9  |   0  |   2  |   4  |   6  |   8  |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |   `  |   ^  |   ´  |   ¨  |      |      |      |   ç  |      |INSERT|DelWrd|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |Sht/Ent|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |     Bksp    |      |      |  F10 |  F11 |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_LOWER] = LAYOUT_planck_grid(
        _______, CH_7,    CH_5,    CH_3,    CH_1,    CH_9,    CH_0,    CH_2,    CH_4,    CH_6,    CH_8,      _______,
        _______, CH_GRV,  CH_CIRC, CH_ACUT, CH_DIAE, XXXXXXX, XXXXXXX, XXXXXXX, CH_CCED, XXXXXXX, KC_INSERT, LALT(KC_BSPC),
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,    LSFT(KC_ENTER),
        _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______, KC_F10,  KC_F11,    _______
    ),

    /* Raise
     * ,-----------------------------------------------------------------------------------.
     * |   `  |   "  |   !  |   #  |   $  |   (  |   )  |   &  |   *  |   %  |   ^  |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |   ~  |   @  |   ?  |   |  |   {  |   [  |   ]  |   }  |   \  |   -  |   =  | DEL  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |   °  |   ;  |      |      |      |   <  |   >  |      |      |   _  |   +  |Sft/Ent|
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * |      |      |      |      |      |    Space    |      | Home | PgDn | PgUp | End  |
     * `-----------------------------------------------------------------------------------'
     */
    [_RAISE] = LAYOUT_planck_grid(
        CH_GRV,  CH_EXLM, CH_EXLM, CH_HASH, CH_DLR,  CH_LPRN, CH_RPRN, CH_AMPR, CH_ASTR, CH_PERC, CH_CIRC, _______,
        CH_TILD, CH_AT,   CH_QUES, CH_PIPE, CH_LCBR, CH_LBRC, CH_RBRC, CH_RCBR, CH_BSLS, CH_MINS, CH_EQL,  KC_DEL,
        CH_DEG,  CH_SCLN, XXXXXXX, XXXXXXX, XXXXXXX, CH_LABK, CH_LABK, XXXXXXX, XXXXXXX, CH_UNDS, CH_PLUS, LSFT(KC_ENTER),
        _______, _______, _______, _______, _______, _______, KC_SPC,  _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),


    /* Movement layer
    * ,-------------------------------------------------------------------------------------.
    * | Bail   |      |Ctrl← | Up   |Ctrl→ |      |      |      | PgUp |      |      |      |
    * |--------+------+------+------+------+-------------+------+------+------+------+------|
    * |        |      | Left | Down |Right |      |      | Home |      | End  |      |      |
    * |--------+------+------+------+------+------|------+------+------+------+------+------|
    * |        |      |      |      |      |      |      |      | PgDn |      |      |      |
    * |--------+------+------+------+------+------+------+------+------+------+------+------|
    * |        | Bail |      |      |      |             |      |      |      |      | Bail |
    * `-------------------------------------------------------------------------------------'
    */
    [_MOVE] = LAYOUT_planck_grid(
        TO(_DVORAK), XXXXXXX,     LCTL(KC_LEFT), KC_UP,   LCTL(KC_RIGHT), XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, XXXXXXX, XXXXXXX,     XXXXXXX,
        _______,     XXXXXXX,     KC_LEFT,       KC_DOWN, KC_RIGHT,       XXXXXXX, XXXXXXX, KC_HOME, XXXXXXX, KC_END,  XXXXXXX,     XXXXXXX,
        _______,     XXXXXXX,     XXXXXXX,       XXXXXXX, XXXXXXX,        XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, XXXXXXX, XXXXXXX,     _______,
        _______,     TO(_DVORAK), _______,       _______,        _______, XXXXXXX, XXXXXXX, _______, _______, _______, TO(_DVORAK), XXXXXXX
    )

};
