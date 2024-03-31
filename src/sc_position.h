#ifndef SC_POSITION_H
#define SC_POSITION_H

#include "main.h"
#include "lib_trade.h"
#include "lib.h"

// SUBGRAPHS
int const _SG_POSITION_BREAKEVEN = 0;
int const _SG_POSITION_TRAIL_TARGET = 1;
int const _SG_POSITION_TRAIL_STOP = 2;
int const _SG_POSITION_TARGET = 3;
int const _SG_POSITION_STOP = 4;

// INPUTS
int const _I_POSITION_REAL_SIMULATION = 1;
int const _I_POSITION_AUTOTRAIL = 2;
int const _I_POSITION_PRICE_TRAIL_OFFSET = 3;
int const _I_BREAKEVEN_FIB = 4;
int const _I_TRAIL_STOP_FIB = 5;
int const _I_TRAIL_TARGET_FIB = 6;
int const _I_POSITION_ENABLED = 7;
int const _I_ATR = 8;
int const _I_POSITION_ATR_MULT = 9;
int const _I_POSITION_USE_EXT_ATR = 10;
int const _I_POSITION_TICKSIZE_MULTIPLIER = 30;

// PERSISTANT
int const _P_POSITION_T_S_LOCKED = 1;
int const _P_POSITION_LAST_INDEX_LOOPED = 2;
int const _P_POSITION_LAST_QUANTITY = 3;

int const _P_POSITION_TRAIL_TARGET = 5;
int const _P_POSITION_TRAIL_STOP = 6;
int const _P_POSITION_BREAKEVEN = 7;
int const _P_POSITION_TARGET = 8;
int const _P_POSITION_STOP = 9;

int const _P_HIDE_BREAKEVEN = 10;

#endif // SC_POSITION_H
