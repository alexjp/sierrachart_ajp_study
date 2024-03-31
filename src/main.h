#ifndef MAIN_H
#define MAIN_H

#include <windows.h>
#include <sierrachart.h>

//#define _CONST_DEBUG 0;

int const _EXPANSION_MAX = 10;

COLORREF const color_bear = RGB(98, 9, 9);
COLORREF const color_bull = RGB(9, 80, 98);

COLORREF const color_success = RGB(0, 200, 100);
COLORREF const color_bad = RGB(200, 100, 0);
COLORREF const color_even = RGB(125, 125, 125);

COLORREF const color_select_tool = RGB(0, 0, 0);

const int SYMBOL_TEXT_DRAWING_DELTA = 80338335;
const int SYMBOL_TEXT_DRAWING_COUNTDOWN = 80338336;

const int SYMBOL_TEXT_DRAWING_PROFIT = 81338337;
const int SYMBOL_TEXT_DRAWING_STOP = 81338338;
const int SYMBOL_TEXT_DRAWING_RR = 81338339;

const int SYMBOL_TOOL_DRAWING_RETM = 81338340;
const int SYMBOL_TOOL_DRAWING_RETG = 81338341;
const int SYMBOL_TOOL_DRAWING_BEGIN = 81338342;
const int SYMBOL_TOOL_DRAWING_END = 81338343;
const int SYMBOL_TOOL_DRAWING_ARROW = 81338344;

#endif // MAIN_H
