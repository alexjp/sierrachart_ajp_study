#include "main.h"

#ifndef LIB_TRADE_H
#define LIB_TRADE_H

float trade_ticksize(SCStudyInterfaceRef sc, int mult);
int load_ticksize_multiplier_from_file(SCStudyInterfaceRef sc);
float round_to_ticksize_trade(SCStudyInterfaceRef sc, float value, int mult);
std::pair <int, s_SCNewOrder > lib_trade_modify_stop(SCStudyInterfaceRef sc, int index, int position_quantity, s_SCTradeOrder & stop, float min_offset, float price, int force);
std::pair <int, s_SCNewOrder > lib_trade_modify_target(SCStudyInterfaceRef sc, int index, int position_quantity, s_SCTradeOrder & target, float min_offset, float price, int force);
std::pair <int, s_SCTradeOrder> lib_trade_find_stop(SCStudyInterfaceRef sc);
std::pair <int, s_SCTradeOrder > lib_trade_find_target(SCStudyInterfaceRef sc);

#endif // LIB_H
