/*
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
#include "action_layer.h"
#include "action_tapping.h"
#include "debug.h"
#include "keymap_swedish_mac_iso.h"
// #include "sendstring_swedish.h"
// #include "sendstring_swedish_mac_iso.h"

#include "quantum.h"

// clang-format off

const uint8_t ascii_to_shift_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 1, 1, 1, 0, 1, 1, 0),
    KCLUT_ENTRY(1, 1, 1, 0, 0, 0, 0, 1),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 1, 1, 0, 1, 1, 1),
    KCLUT_ENTRY(0, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 1, 1, 1, 1, 1),
    KCLUT_ENTRY(1, 1, 1, 0, 0, 0, 1, 1),
    KCLUT_ENTRY(1, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0)
};

const uint8_t ascii_to_altgr_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 0, 0, 0, 1, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(1, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 1, 1, 1, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 1, 1, 1, 1, 0)
};

const uint8_t ascii_to_dead_lut[16] PROGMEM = {
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),

    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 1, 0),
    KCLUT_ENTRY(1, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 0, 0),
    KCLUT_ENTRY(0, 0, 0, 0, 0, 0, 1, 0)
};

const uint8_t ascii_to_keycode_lut[128] PROGMEM = {
    // NUL   SOH      STX      ETX      EOT      ENQ      ACK      BEL
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // BS    TAB      LF       VT       FF       CR       SO       SI
    KC_BSPC, KC_TAB,  KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // DLE   DC1      DC2      DC3      DC4      NAK      SYN      ETB
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    // CAN   EM       SUB      ESC      FS       GS       RS       US
    XXXXXXX, XXXXXXX, XXXXXXX, KC_ESC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

    //       !        "        #        $        %        &        '
    KC_SPC,  SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_QUOT,
    // (     )        *        +        ,        -        .        /
    SE_8,    SE_9,    SE_QUOT, SE_PLUS, SE_COMM, SE_MINS, SE_DOT,  SE_7,
    // 0     1        2        3        4        5        6        7
    SE_0,    SE_1,    SE_2,    SE_3,    SE_4,    SE_5,    SE_6,    SE_7,
    // 8     9        :        ;        <        =        >        ?
    SE_8,    SE_9,    SE_DOT,  SE_COMM, SE_LABK, SE_0,    SE_LABK, SE_PLUS,
    // @     A        B        C        D        E        F        G
    SE_2,    SE_A,    SE_B,    SE_C,    SE_D,    SE_E,    SE_F,    SE_G,
    // H     I        J        K        L        M        N        O
    SE_H,    SE_I,    SE_J,    SE_K,    SE_L,    SE_M,    SE_N,    SE_O,
    // P     Q        R        S        T        U        V        W
    SE_P,    SE_Q,    SE_R,    SE_S,    SE_T,    SE_U,    SE_V,    SE_W,
    // X     Y        Z        [        \        ]        ^        _
    SE_X,    SE_Y,    SE_Z,    SE_8,    SE_PLUS, SE_9,    SE_DIAE, SE_MINS,
    // `     a        b        c        d        e        f        g
    SE_ACUT, SE_A,    SE_B,    SE_C,    SE_D,    SE_E,    SE_F,    SE_G,
    // h     i        j        k        l        m        n        o
    SE_H,    SE_I,    SE_J,    SE_K,    SE_L,    SE_M,    SE_N,    SE_O,
    // p     q        r        s        t        u        v        w
    SE_P,    SE_Q,    SE_R,    SE_S,    SE_T,    SE_U,    SE_V,    SE_W,
    // x     y        z        {        |        }        ~        DEL
    SE_X,    SE_Y,    SE_Z,    SE_7,    SE_LABK, SE_0,    SE_DIAE, KC_DEL
};

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define PROG 3 // programming keys
#define VIM  4 // vim like keys
#define TAPPING_TERM_PER_KEY

// #undef TAPPING_TOGGLE
// #define TAPPING_TOGGLE 2

uint8_t mod_state;

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  PE_TILD,
  PE_GRAV,
  PE_LARR,
  PE_RARR,
  PE_LEAR,
  PE_REAR,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |   !  |  "   |  #   |  #   |  %   |      |           |      |   &  |  /   |  (   |  )   |  =   |  ?     |
 * |  ESC   |   1  |  2 @ |  3 £ |  4 $ |  5   | F2   |           |  ~   |   6  |  7 { |  8 [ |  9 ] |  0 } |  + \   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    | Q    | W    | E    |R(met)| T    | ~L1  |           |  L1  | Y    |U(met)| I    | O    | P    | Å      |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | ~L3    |A(alt)| S    | D    |F(pro)|G(vim)|------|           |------| H    |J(pro)| K    | L    | Ö    | Ä      |
 * |--------+------+------+------+------+------|      |           | Del  |------+------+------+------+------+--------|
 * | LShft  |Z(ctl)| X    | C    | V    |B(ctl)|  '   |           |      |N(ctl)| M(L2)| ,    | .    |-(ctl)| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | LCtl |  ^   | *    | LAlt | LGui |                                       | Space| |    | Left | Rght |  '   |
 *   |      |  " ~ | '  ´ |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,--------------.
 *                                        | LCtl | LAlt |       | Home |   End  |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |  ~   |       | PgUp |       |
 *                                 | Space|Back- |------|       |------|  Tab  |Enter |
 *                                 |      |space | Esc  |       | PgDn |  CTL  | ALT  |
 *                                 `--------------------'       `---------------------'
 */

[BASE] = LAYOUT_ergodox(  // layer 0 : default
    // left hand
    KC_ESC,         KC_1,     KC_2,     KC_3,    KC_4,    KC_5,   KC_F2,
    KC_TAB,          KC_Q,     KC_W,     KC_E,    KC_R ,    KC_T,   MO(SYMB),
    MO(PROG),        KC_A,     LALT_T(KC_S),     KC_D,    KC_F,    KC_G,
    KC_LSFT,         KC_Z,     KC_X,     KC_C,    KC_V,    KC_B,                    TT(VIM),
    KC_LCTRL,  SE_CIRC,  SE_ASTR,  KC_LALT, KC_LGUI,
                                               KC_LCTRL,  KC_LALT,
                                                          SE_TILD,
                                         LT(SYMB, KC_ENTER), KC_ENTER, SE_BSLS,
    // right hand

         SE_TILD,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,     KC_BSPC,
         KC_ENTER,  KC_Y,   KC_U, KC_I,    KC_O,    KC_P,     SE_ARNG,
                    KC_H,   KC_J, KC_K,    RALT_T(KC_L),    SE_ODIA,  SE_ADIA,
         TO(SYMB),    KC_N,   LT(MDIA, KC_M)       , KC_COMM, KC_DOT,  SE_MINS,  KC_RSFT,
                            KC_RGUI , KC_RALT, KC_LGUI, SE_PLUS,  SE_QUOT,
         KC_HOME,        KC_END,
         KC_PGUP,
         KC_PGDN, CTL_T(KC_TAB), KC_SPACE
),

/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |  /   |   *  |  -   |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |  F1  |  F2  |  F3  |  F4  |      |      |           |      |      |  7   |  8   |  9   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F5  |  F6  |  F7  |  F8  |      |------|           |------|      |  4   |  5   |  6   |  +   |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |  F9  |  F10 |  F11 |  F12 |      |      |           |      |      |  1   |  2   |  3   | Enter|        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |  0   | ,    |  UP  | DOWN |  RIGHT |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   LCTL(KC_UP), KC_TRNS,
       KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   LCTL(KC_DOWN),
       KC_TRNS, KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       TO(BASE), LALT(KC_UP), KC_7,    KC_8,    KC_9,    KC_PPLS, KC_TRNS,
                LALT(KC_DOWN), KC_4,    KC_5,    KC_6,    KC_PPLS, KC_TRNS,
       RESET,   KC_TRNS, KC_1,    KC_2,    KC_3,    KC_UP , KC_TRNS,
                         KC_0,    KC_COMM, KC_LEFT ,  KC_DOWN, KC_RIGHT,
       SE_GRV, SE_ACUT,
       SE_DIAE,
       KC_TRNS, KC_TRNS, KC_TRNS

),

/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------| WHLU | Play | Pause| Prev | Next |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      | Lclk | Rclk |      |      |           |      | WHLD |VolDn |VolUp | Mute |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |LeClk |RiClk |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
       KC_TRNS,  SE_QUOT, SE_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_WH_U, KC_MPLY, KC_MPLY, KC_MPRV, KC_MNXT, KC_TRNS,
       KC_TRNS,  KC_WH_D, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_MPRV, KC_MNXT,
       KC_VOLU,
       KC_VOLD, KC_MPLY, KC_MUTE
),
/* Keymap 3: Programming keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      | Alt+Up |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |  (   |  )   |      |      |      |           |      |      |  {   |   }  |      |      |Alt+Down|
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |  [   |  ]   |      |      |------|           |------|  `   |  <   |   >  |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// PROGRAMMUNICATION
[PROG] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, SE_SLSH, SE_BSLS, SE_ASTR,
       SE_DQUO, KC_COPY, KC_PSTE, SE_LPRN, SE_RPRN, SE_EQL, SE_MINS,
       SE_QUOT, PE_GRAV, KC_CUT, SE_LBRC, SE_RBRC, SE_COLN,
       KC_TRNS, SE_HASH, PE_RARR, SE_LCBR, SE_RCBR, SE_SCLN, SE_UNDS,
       KC_TRNS, KC_TRNS, KC_TRNS, SE_LABK, SE_RABK,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, TO(VIM), TO(BASE), KC_TRNS,
       KC_TRNS,  SE_PIPE, SE_LCBR, SE_RCBR, SE_EXLM, SE_QUES, SE_DLR,
                 SE_SCLN, SE_LABK, SE_RABK, SE_HASH, SE_PERC, SE_AMPR,
       KC_TRNS,  KC_TRNS, SE_MINS, SE_PLUS, SE_CIRC, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: Vim arrow keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | home | pgdn | pgup | end  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| left | down |  up  | rght |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Vim keys
[VIM] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_END, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_HOME, KC_TRNS, KC_TRNS, KC_LALT, KC_LCTL,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_LSFT, KC_LSFT,
                                                    KC_TRNS,
                                  KC_ENTER, KC_ENTER, KC_LSHIFT,
    // right hand
       KC_TRNS,  KC_TRNS, KC_PGUP, KC_TRNS, TO(VIM), TO(BASE), KC_TRNS,
       KC_TRNS,  KC_PGUP, KC_HOME, KC_END, KC_PGDN, KC_TRNS, KC_TRNS,
                 KC_LEFT, KC_DOWN, KC_UP , KC_RIGHT, KC_TRNS, KC_TRNS,
       KC_ENTER,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TAB, KC_SPACE
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

}

// Combos
enum combos {
    QW_ESC,
    YU_LPAREN,
    UI_RPAREN,
    HJ_LBRACE,
    JK_RBRACE,
    ER_LBRACKET,
    RT_RBRACKET,
    DF_LANGLE,
    FG_RANGLE,
    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
const uint16_t PROGMEM combo_qw_esc[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_yu_lparen[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM combo_ui_rparen[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM combo_hj_lbracket[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM combo_jk_rbracket[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_er_lbracket[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_rt_rbracket[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_df_langle[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_fg_rangle[] = {KC_F, KC_G, COMBO_END};

combo_t key_combos[] = {
    [QW_ESC] = COMBO(combo_qw_esc, KC_ESC),
    [YU_LPAREN] = COMBO(combo_yu_lparen, SE_LPRN),
    [UI_RPAREN] = COMBO(combo_ui_rparen, SE_RPRN),
    [HJ_LBRACE] = COMBO(combo_hj_lbracket, SE_LCBR),
    [JK_RBRACE] = COMBO(combo_jk_rbracket, SE_RCBR),
    [ER_LBRACKET] = COMBO(combo_er_lbracket, SE_LBRC),
    [RT_RBRACKET] = COMBO(combo_rt_rbracket, SE_RBRC),
    [DF_LANGLE] = COMBO(combo_df_langle, SE_LABK),
    [FG_RANGLE] = COMBO(combo_fg_rangle, SE_RABK),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();

  switch (keycode) {
    case PE_TILD:
        if (record->event.pressed) {
            SEND_STRING("~");
        }
        return false;
    case PE_GRAV:
        if (record->event.pressed) {
            SEND_STRING("`");
        }
        return false;
    // case PE_LARR:
    //     if (record->event.pressed) {
    //         SEND_STRING("<-");
    //     }
    //     return false;
    // case PE_RARR:
    //     if (record->event.pressed) {
    //         SEND_STRING("->");
    //     }
    //     return false;
    // case PE_LEAR:
    //     if (record->event.pressed) {
    //         SEND_STRING("<=");
    //     }
    //     return false;
    // case PE_REAR:
    //     if (record->event.pressed) {
    //         SEND_STRING("=>");
    //     }
    //     return false;
    default:
        return true;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_A) || LCTL_T(KC_B) || LCTL_T(KC_N):
            return TAPPING_TERM + 2250;
        // case LT(1, KC_GRV):
        //     return 130;
        default:
            return TAPPING_TERM;
    }
}

const key_override_t delete_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &delete_key_override,
    NULL // Null terminate the array of overrides!
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        case 3:
            ergodox_right_led_3_on();
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
        default:
            // none
            break;
    }

};
