/* Copyright 2020 Boardsource
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

#include "getawayvan.h"
#ifdef RGB_MATRIX_ENABLE
led_config_t g_led_config = { {
    { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11},
    {12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23},
    {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 36},
    {37, 39, 41, NO_LED, 42, NO_LED, 44, NO_LED, 45, 46, 48, 50}
}, {
   {  0,  0},    { 20,  0}, { 40,  0}, { 61,  0}, { 81,  0}, {101,  0}, {122,  0}, {142,  0}, {162,  0}, {183,  0}, {203,  0},      {224,  0},
      { 10, 21},    { 30, 21}, { 51, 21}, { 71, 21}, { 91, 21}, {112, 21}, {132, 21}, {152, 21}, {173, 21}, {193, 21}, {214, 21},    {224, 21},
    {  0, 42},         { 20, 42}, { 40, 42}, { 61, 42}, { 81, 42}, {101, 42}, {122, 42}, {142, 42}, {162, 42}, {183, 42}, {203, 42}, {224, 42},
    {  0, 64}, { 20, 64}, { 40, 64},    {0,0},    { 67, 64},    {0,0},       {106, 64},  {0,0},     {144, 64}, {183, 64}, {203, 64}, {224, 64}
}, {
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1, 0, 1,
    1, 0, 1, 0, 1, 4, 0, 4, 1, 1, 0, 1, 0, 1
} };
#endif

