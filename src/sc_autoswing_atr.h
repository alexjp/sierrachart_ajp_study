#ifndef SC_AUTOSWINGFIB_H
#define SC_AUTOSWINGFIB_H

#include <windows.h>
#include <sierrachart.h>
#include "main.h"
#include "lib.h"

//#define _CONST_DEBUG 0;


int const _AUTO_SWING_SG_BEGIN = 0;
int const _AUTO_SWING_SG_END = 1;
int const _AUTO_SWING_SG_MIN_RET = 3;
int const _AUTO_SWING_SG_RET_BEGIN = 4;
int const _AUTO_SWING_SG_RET_END = 5;
int const _AUTO_SWING_SG_MIN_ACHEIVED = 6;
int const _AUTO_SWING_SG_STOP = 7;
int const _AUTO_SWING_SG_LIMIT = 8;
int const _AUTO_SWING_SG_NEW_BEGIN = 9;
int const _AUTO_SWING_SG_DIRECTION = 10;
int const _AUTO_SWING_SG_ATR_MA = 11;
int const _AUTO_SWING_SG_ATR_VALUE = 12;
int const _AUTO_SWING_SG_ATR_TOP = 13;
int const _AUTO_SWING_SG_ATR_BOTTOM = 14;
int const _AUTO_SWING_SG_NEW_END = 15;

int const _AUTO_SWING_I_ATR = 0;
int const _AUTO_SWING_I_ATR_FIB_LIMIT = 1;
int const _AUTO_SWING_I_ATR_MULT_STOP = 2;
int const _AUTO_SWING_I_TICK_OFFSET = 3;
int const _AUTO_SWING_I_FIB_MIN = 4;
int const _AUTO_SWING_I_FIB_ENTRY = 5;
int const _AUTO_SWING_I_FIB_MAX = 6;
int const _AUTO_SWING_I_MAX_DISTANCE = 7;
int const _AUTO_SWING_I_DATE_TIME_START = 8;
int const _AUTO_SWING_I_DATE_TIME_END = 9;
int const _AUTO_SWING_I_REPAINT = 10;
int const _AUTO_SWING_I_VWAP_LENGTH = 11;
int const _AUTO_SWING_I_ATR_LENGTH = 12;
int const _AUTO_SWING_I_ATR_TYPE = 13;
int const _AUTO_SWING_I_ATR_MULT = 14;
int const _AUTO_SWING_I_ATR_RET_MA = 15;
int const _AUTO_SWING_I_ATR_DRAW = 16;
int const _AUTO_SWING_I_USE_ATR_RET = 17;

int const _AUTO_SWING_I_BUTTON_ON = 20;
int const _AUTO_SWING_I_BUTTON_OFF = 21;
int const _AUTO_SWING_I_ALERT = 22;

int const _AUTO_SWING_P_STATE_ACS_BUTTON = 0;
int const _AUTO_SWING_P_STATE_MOUSE_START = 1;
int const _AUTO_SWING_P_STATE_MOUSE_END = 2;
int const _AUTO_SWING_P_STATE_AUTO_MANUAL = 3;
int const _AUTO_SWING_P_LAST_INDEX_LOOPED = 13;
int const _AUTO_SWING_P_START_INDEX = 20;
int const _AUTO_SWING_P_FINISH_INDEX = 21;
int const _AUTO_SWING_P_DIRECTION = 22;
int const _AUTO_SWING_P_SWING_ACTIVE = 23;
int const _AUTO_SWING_P_NEW_BEGIN_INDEX_REPAINT = 24;
int const _AUTO_SWING_P_NEW_REVERSAL_BEGIN_INDEX_REPAINT = 25;


#endif // SC_AUTOSWINGFIB_H
