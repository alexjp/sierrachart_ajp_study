#ifndef SC_SWING_H
#define SC_SWING_H

#include "main.h"
#include "lib.h"
#include "lib_trade.h"

//#define _CONST_DEBUG 0;

// SUBGRAPHS
int const _LONG_TRADE = 0;
int const _SHORT_TRADE = 1;
int const _INDEX_BEGIN = 2;
int const _INDEX_END = 3;
int const _SG_PRICE_END = 5;
int const _SG_PRICE_BEGIN = 6;
int const _SG_PRICE_THIRD = 7;
int const _TARGET_PRICE = 8;
int const _STOP_PRICE = 9;
int const _AREA_TOP = 10;
int const _AREA_BOTTOM = 11;
int const _ACTIVE = 12;
int const _DIRECTION = 13;
int const _LENGTH = 14;
int const _FIB_ENTRY = 15;
int const _CURRENCY_STOP = 16;
int const _CURRENCY_TARGET = 17;
int const _RR = 18;

// INPUTS
int const _ENTRY_FIB = 0;
int const _TARGET_FIB = 1;
int const _STOP_FIB_LEVEL = 2;
int const _STOP_OFFSET = 3;
int const _MAX_STOP_DISTANCE = 4;
int const _CURRENCY = 5;
int const _I_SWING_REAL_SIMULATION = 6;
int const _I_BUTTON_ON = 7;
int const _I_BUTTON_ON_ALT = 19;
int const _I_BUTTON_TOOGLE_HIDE = 20;
int const _I_BUTTON_OFF = 8;
int const _I_ATR = 9;
int const _I_ATR_MULT = 10;
int const _HSPACE = 11;
int const _VSPACE = 12;
int const _MIN_RR = 13;
int const _FONT_SIZE = 14;
int const _I_SWING_USE_EXT_ATR = 15;
int const _I_SWING_PREVIOUS_SWING_HIGH_LOW = 16;
int const _I_PREV_SWING_HL_STOP_FIB = 17;
int const _I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET = 18;
int const _I_TICKSIZE_MULTIPLIER = 30;




// PERSISTANT
int const _STATE_ACS_BUTTON = 0;
int const _MOUSE_START = 1;
int const _MOUSE_END = 2;

int const _P_INDEX_BEGIN = 3;
int const _P_INDEX_END = 4;
int const _P_DIRECTION = 5;
int const _P_LENGTH = 6;
int const _P_PRICE_END = 7;
int const _P_PRICE_BEGIN = 8;
int const _P_STOP_PRICE = 9;
int const _P_TARGET_PRICE = 10;
int const _P_AREA_TOP = 11;
int const _P_AREA_BOTTOM = 12;
int const _P_ACTIVE = 13;
int const _P_FIB_ENTRY = 14;
int const _P_TRADE_QUANTITY = 15;
int const _P_PRICE_THIRD = 16;
int const _P_INDEX_THIRD = 17;
int const _P_LAST_INDEX_LOOPED = 18;
int const _P_STOP_INITIAL = 19;
int const _P_TARGET_INITIAL = 20;

int const _P_SWING_INITIALIZED = 21;

#endif // SC_SWING_H
