// Copyright 2021 Georgs Narbuts (@brunokakis)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

//

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_ansi(
        KC_ESC,  KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,           KC_BSPC, KC_MPLY, \
        KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP, \
        KC_CLCK, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN, \
                 KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,  \
        KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, KC_RGUI,  MO(1),           KC_LEFT, KC_DOWN, KC_RGHT),
    
    [1] = LAYOUT_ansi(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,   KC_DEL,          KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS, \
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, \
        KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                             KC_TRNS, KC_TRNS, MO(1),            KC_TRNS, KC_TRNS, KC_TRNS)
};





#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
}



static void render_logo(void) {
    static const char PROGMEM my_logo[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 
        0x70, 0xe0, 0xc0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x30, 0x30, 0x30, 0x30, 
        0x70, 0xe0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x70, 0xe0, 0xc0, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xc0, 0xf0, 
        0xf0, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0xf0, 0xf0, 0xc0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x27, 0x10, 0x00, 0x93, 0x8c, 0x10, 0x10, 0x18, 0x08, 0x08, 
        0x08, 0x18, 0x10, 0x10, 0x0c, 0x93, 0x80, 0x10, 0x07, 0x5c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x80, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0xe0, 0xff, 0x3f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x80, 0x80, 0x80, 0x80, 
        0x80, 0xc0, 0xe1, 0x73, 0x7f, 0x1e, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x03, 0x0f, 
        0xfc, 0xf0, 0x80, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x12, 0x12, 0x3f, 0xf3, 0x12, 0x00, 0x00, 0x80, 0x03, 0x02, 0x41, 0x80, 0x88, 0x88, 0x78, 
        0x88, 0x88, 0x80, 0x40, 0x01, 0x02, 0x03, 0x00, 0x00, 0xa2, 0xf3, 0x3e, 0x22, 0x22, 0x21, 0x10, 
        0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 
        0x01, 0x01, 0x03, 0x87, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x07, 0x1f, 0x7f, 0xf9, 
        0xe1, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 
        0x00, 0x01, 0x0f, 0x3f, 0xf0, 0xc0, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x02, 0x02, 0x06, 0x04, 0x04, 0x04, 0x04, 
        0x04, 0x04, 0x04, 0x06, 0x02, 0x02, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 
        0x0c, 0x06, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 
        0x03, 0x07, 0x0f, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0f, 0x0f, 0x0c, 0x0c, 
        0x0c, 0x0c, 0x0f, 0x0f, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x0f, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0x0f, 
        0x0f, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0c, 0x0f, 0x0f, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00
        
    };
    
    oled_write_raw_P(my_logo, sizeof(my_logo));
}

bool oled_task_user(void){
    render_logo();
    return false;
}

#endif
