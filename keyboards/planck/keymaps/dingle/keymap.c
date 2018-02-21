/* Copyright 2015-2017 Jack Humbert
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

#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  BASE,
  NUM,
  SYMB,
  MOUSE,
  NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BASE
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  \   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | nav  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |mouse |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |num   | spc  | enter|Symb  |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[BASE] = {
  {KC_TAB,  KC_Q,    MT(MOD_MEH, KC_W),    MT(MOD_HYPR, KC_E),    LCAG_T(KC_R),    KC_T,    KC_Y,    LCAG_T(KC_U),    MT(MOD_HYPR, KC_I),    MT(MOD_MEH, KC_O),    KC_P,    KC_BSLS},
  {KC_BSPC,  MT(MOD_LSFT, KC_A),    MT(MOD_LCTL, KC_S),    MT(MOD_LALT, KC_D),    MT(MOD_LGUI, KC_F),    KC_G,    KC_H,    MT(MOD_LGUI, KC_J),    MT(MOD_LALT, KC_K),    MT(MOD_LCTL, KC_L),    MT(MOD_LSFT, KC_SCLN), KC_QUOT},
  {MO(NAV), KC_Z,    KC_X,    MT(MOD_RALT, KC_C),    MT(MOD_RCTL, KC_V),    KC_B,    KC_N,    MT(MOD_RCTL, KC_M),    MT(MOD_RALT, KC_COMM), KC_DOT,  KC_SLSH, MO(MOUSE) },
  {KC_TRNS, KC_LCTL, KC_LALT, KC_LGUI, MO(NUM),   KC_SPC,  KC_ENT,  MO(SYMB),   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT}
},

[NUM] = {
  { KC_TRNS,KC_SLEP,KC_TRNS,KC_TRNS,MOD_HYPR,KC_TRNS,  KC_0,   KC_1,   KC_2,    KC_3,    KC_ASTR, KC_TRNS },
  { KC_TRNS,KC_LSFT,KC_LCTL,KC_LALT,KC_LGUI,KC_TRNS, KC_MINUS, KC_4,   KC_5,    KC_6,    KC_EQL, KC_TRNS },
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_PLUS, KC_7,   KC_8,    KC_9,    KC_SLSH, KC_TRNS },
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_ESC,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS },
},

[SYMB] = {
  { KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_AMPR,KC_TRNS, MOD_HYPR, KC_TRNS,    KC_TRNS,    KC_PWR, KC_F12 },
  { KC_TRNS,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_ASTR, KC_TRNS, KC_LGUI, KC_LALT,   KC_LCTL,    KC_LSFT, KC_TRNS },
  { KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_GRV,KC__MUTE,   KC__VOLDOWN,   KC__VOLUP,    KC_TRNS,    KC_TRNS, KC_TRNS },
  { KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_ESC,KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS,    KC_TRNS,  KC_TRNS },
},

[MOUSE] = {
  {KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_MS_WH_DOWN, KC_BTN1,    KC_MS_U,    KC_BTN2, KC_TRNS, KC_TRNS},
   {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_MS_WH_UP,   KC_MS_L,    KC_MS_D,    KC_MS_R, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_MS_WH_RIGHT, KC_MS_WH_LEFT, KC_TRNS, KC_TRNS,  KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS}
},

[NAV] = {
  {RESET, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,  KC_TRNS, KC_PGUP, KC_HOME,    KC_UP,    KC_END, KC_TRNS, KC_TRNS},
   {KC_TRNS,  KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_PGDOWN,   KC_LEFT,    KC_DOWN,    KC_RIGHT, KC_TRNS, KC_TRNS},
  {KC_TRNS, KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS}
}


};
