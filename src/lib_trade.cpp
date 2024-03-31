#include "lib_trade.h"
#include "sc_swing.h"

float trade_ticksize(SCStudyInterfaceRef sc, int tick_mult) {
	if (tick_mult < 1)
		return 1 * sc.TickSize;
	return tick_mult * sc.TickSize;
}
float round_to_ticksize_trade(SCStudyInterfaceRef sc, float value, int mult) {
	//return sc.RoundToTickSize(value);
	return sc.RoundToTickSize(value, trade_ticksize(sc, mult));
}
int load_ticksize_multiplier_from_file(SCStudyInterfaceRef sc) {
	SCString ticksize_path;
	int _ticksize = 1;
	std::ifstream ticksize_input(ticksize_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "ticksize"));

	if (ticksize_input.is_open()) {
		int ticksize_multiplier;
		ticksize_input >> ticksize_multiplier;
		if (ticksize_multiplier > 0 )
			_ticksize = ticksize_multiplier;
		ticksize_input.close();
	}
	return _ticksize;
}
std::pair <int, s_SCNewOrder > lib_trade_modify_stop(SCStudyInterfaceRef sc, int index, int position_quantity, s_SCTradeOrder & stop, float min_offset, float price, int force) {
    float _last_price = sc.Close[index];

    s_SCNewOrder _new_stop;
//SCString log;
//    sc.AddMessageToLog(log.Format("%d, %f, %f, %f, %f",position_quantity, price, (_last_price - min_offset), _last_price, min_offset), 1);
    if ((position_quantity > 0 && price < (_last_price - min_offset)) || (position_quantity < 0 && price > (_last_price + min_offset))) {
//        sc.AddMessageToLog("Entering Modify Stop: 0", 1);
        if (force == 1 || (position_quantity > 0 && price > stop.Price1) || (position_quantity < 0 && price < stop.Price1)) {
//            sc.AddMessageToLog("Entering Modify Stop: 1", 1);
            _new_stop.InternalOrderID = stop.InternalOrderID;
            _new_stop.Price1 = price;
            int _success = sc.ModifyOrder(_new_stop);
//            if (_success)
//                sc.AddMessageToLog("Entering Modify Stop: 2", 1);

#ifdef _CONST_DEBUG
            SCString log;
            sc.AddMessageToLog(log.Format("Success: %d, Modifying Stop: %f", _success, price), 1);
            if (_success <= 0)
            sc.AddMessageToLog(sc.GetTradingErrorTextMessage(_success), 0);
#endif

            return std::make_pair(_success, _new_stop);
        }
    }

    return std::make_pair(0, _new_stop);
}
std::pair <int, s_SCNewOrder > lib_trade_modify_target(SCStudyInterfaceRef sc, int index, int position_quantity, s_SCTradeOrder & target, float min_offset, float price, int force) {
    float _last_price = sc.Close[index];

    s_SCNewOrder _new_target;

    if ((position_quantity > 0.0 && price > (_last_price - min_offset)) || (position_quantity < 0.0 && price < (_last_price + min_offset))) {

        if (force == 1 || (position_quantity > 0.0 && price > target.Price1) || (position_quantity < 0.0 && price < target.Price1)) {
            _new_target.InternalOrderID = target.InternalOrderID;
            _new_target.Price1 = price;
            int _success = sc.ModifyOrder(_new_target);

#ifdef _CONST_DEBUG
            SCString log;
            sc.AddMessageToLog(log.Format("Success: %d, Modifying Target: %f", _success, price), 1);

            if (_success <= 0)
                sc.AddMessageToLog(sc.GetTradingErrorTextMessage(_success), 0);
#endif

            return std::make_pair(_success, _new_target);
        }

    }

    return std::make_pair(0, _new_target);
}
std::pair <int, s_SCTradeOrder> lib_trade_find_stop(SCStudyInterfaceRef sc) {
    s_SCTradeOrder stop;

    int found_stop = sc.GetNearestStopOrder(stop);
    if (!found_stop) {
        int Index = 0;

        while (sc.GetOrderByIndex(Index, stop) != SCTRADING_ORDER_ERROR)
        {
            Index++; // Increment the index for the next call to sc.GetOrderByIndex

            if (stop.OrderStatusCode != SCT_OSC_OPEN && stop.OrderStatusCode != SCT_OSC_HELD)
                continue;

//            if (stop.ParentInternalOrderID == 0) //This means this is not an Attached Order
//                continue;

            if ( stop.OrderTypeAsInt == SCT_ORDERTYPE_STOP || stop.OrderTypeAsInt == SCT_ORDERTYPE_STOP_WITH_BID_ASK_TRIGGERING ) {
                found_stop = 1;
                break;
            }
        }
    }

#ifdef _CONST_DEBUG
    SCString log;
    sc.AddMessageToLog(log.Format("Found Stops: %d", found_stop), 1);
#endif

    return std::make_pair(found_stop, stop);
}
std::pair <int, s_SCTradeOrder > lib_trade_find_target(SCStudyInterfaceRef sc) {
    s_SCTradeOrder target;

    int found_target = sc.GetNearestTargetOrder(target);
    if (!found_target) {
        int Index = 0;

        while (sc.GetOrderByIndex(Index, target) != SCTRADING_ORDER_ERROR)
        {

            Index++; // Increment the index for the next call to sc.GetOrderByIndex

            if (target.OrderStatusCode != SCT_OSC_OPEN && target.OrderStatusCode != SCT_OSC_HELD)
                continue;

//            if (target.ParentInternalOrderID == 0) //This means this is not an Attached Order
//                continue;
            //SCString log;
            //sc.AddMessageToLog(log.Format("Found Target Type: %d", target.OrderTypeAsInt), 1);

            if ( target.OrderTypeAsInt == SCT_ORDERTYPE_LIMIT || target.OrderTypeAsInt == SCT_ORDERTYPE_MARKET_IF_TOUCHED_CLIENT_SIDE ) {
                found_target = 1;
                break;
            }

        }
    }

#ifdef _CONST_DEBUG
    SCString log;
    sc.AddMessageToLog(log.Format("Found Targets: %d", found_target), 1);
#endif

    return std::make_pair(found_target, target);
}
