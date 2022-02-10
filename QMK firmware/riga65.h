// Copyright 2021 Georgs Narbuts (@georgsnarbuts)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define _x_ KC_NO

#include "quantum.h"

/* This is a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */

#define LAYOUT_iso( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,      K0E, K0F, \
    K10,      K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D,      K1F, \
    K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F, \
    K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, K3F, \
    K40, K41,      K43,           K46,                K4A, K4B, K4C, K4D, K4E, K4F  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, _x_, K0E, K0F}, \
    { K10, _x_, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, _x_, K1F}, \
    { K20, _x_, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, K2E, K2F}, \
    { K30, K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, _x_, K3D, K3E, K3F}, \
    { K40, K41, _x_, K43, _x_, _x_, K46, _x_, _x_, _x_, K4A, K4B, K4C, K4D, K4E, K4F}  \
}

#define LAYOUT_ansi( \
    K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C,      K0E, K0F, \
    K10,      K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F, \
    K20,      K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D,      K2F, \
    K30,      K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B,      K3D, K3E, K3F, \
    K40, K41,      K43,           K46,                K4A, K4B, K4C, K4D, K4E, K4F  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, _x_, K0E, K0F}, \
    { K10, _x_, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C, K1D, K1E, K1F}, \
    { K20, _x_, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B, K2C, K2D, _x_, K2F}, \
    { K30, _x_, K32, K33, K34, K35, K36, K37, K38, K39, K3A, K3B, _x_, K3D, K3E, K3F}, \
    { K40, K41, _x_, K43, _x_, _x_, K46, _x_, _x_, _x_, K4A, K4B, K4C, K4D, K4E, K4F}  \
}

