#include "main.h"
#include "lib.h"

SCSFExport scsf_Tradewindow(SCStudyInterfaceRef sc)
{

    SCInputRef Tradewindow_auto_atr = sc.Input[1];
    SCInputRef Tradewindow_range = sc.Input[2];
    SCInputRef Tradewindow_stop_multiplier = sc.Input[3];
    SCInputRef Tradewindow_target_multiplier = sc.Input[4];
    SCInputRef Tradewindow_stop_static_add = sc.Input[5];
    SCInputRef Tradewindow_target_static_add = sc.Input[6];
    SCInputRef Tradewindow_client_type_orders = sc.Input[7];

    sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

    if (sc.SetDefaults) {

        sc.GraphName = "TradeWindow Manager";
        sc.StudyDescription = "TradeWindow Manager: Sets TradeWindow stop and target from specified range and multiplier";

        sc.GraphUsesChartColors = true;

        sc.ValueFormat = VALUEFORMAT_INHERITED;
        sc.GraphRegion = 0;
        sc.DisplayAsMainPriceGraph = false;
        sc.AutoLoop = 0;
        sc.StandardChartHeader = 1;

        Tradewindow_auto_atr.Name = "Use Range (1:Chart, 2:ATR file)";
        Tradewindow_auto_atr.SetInt(1);

        Tradewindow_range.Name = "Range";
        Tradewindow_range.SetFloat(0.0);

        Tradewindow_stop_multiplier.Name = "Stop range multiplier";
        Tradewindow_stop_multiplier.SetFloat(1);

        Tradewindow_target_multiplier.Name = "Target range multiplier";
        Tradewindow_target_multiplier.SetFloat(1);

        Tradewindow_stop_static_add.Name = "Stop static tick add";
        Tradewindow_stop_static_add.SetFloat(0);

        Tradewindow_target_static_add.Name = "Target static tick add";
        Tradewindow_target_static_add.SetFloat(0);

        Tradewindow_client_type_orders.Name = "Use Client side orders";
        Tradewindow_client_type_orders.SetInt(1);
        return;
    }

    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
        sc.AddMessageToLog("Doing Initial Load", 0);
#endif

        if (Tradewindow_auto_atr.GetInt() == 1) {
            n_ACSIL::s_BarPeriod chart_period;
            sc.GetBarPeriodParameters(chart_period);
            if (chart_period.IntradayChartBarPeriodType == IBPT_RANGE_IN_TICKS_TRUE || chart_period.IntradayChartBarPeriodType == IBPT_RANGE_IN_TICKS_STANDARD)
                Tradewindow_range.SetFloat(chart_period.IntradayChartBarPeriodParameter1 * sc.TickSize);
        }

        if (Tradewindow_auto_atr.GetInt() == 2) {
            SCString path;
            std::ifstream input(path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "atr"));

            int timeframe = 0;
            float atr = 0;
            if (input) {
                input >> timeframe >> atr;
                Tradewindow_range.SetFloat(atr);
                input.close();
            }
        }

        float calculated_stop = sc.RoundToTickSize((Tradewindow_range.GetFloat() * Tradewindow_stop_multiplier.GetFloat()) + (Tradewindow_stop_static_add.GetInt() * sc.TickSize));
        float calculated_target = sc.RoundToTickSize(Tradewindow_range.GetFloat() * Tradewindow_target_multiplier.GetFloat() + (Tradewindow_target_static_add.GetInt() * sc.TickSize));

        if (calculated_stop > 0 && calculated_target > 0) {

#ifdef _CONST_DEBUG
            sc.AddMessageToLog("Setting Order", 0);
#endif
            s_SCNewOrder _new_order;
            _new_order.OrderQuantity = sc.TradeWindowOrderQuantity;
            _new_order.OCOGroup1Quantity = sc.TradeWindowOrderQuantity;
            if (Tradewindow_client_type_orders.GetInt() > 0) {
                _new_order.AttachedOrderStop1Type = SCT_ORDERTYPE_STOP_WITH_BID_ASK_TRIGGERING;
                _new_order.AttachedOrderTarget1Type = SCT_ORDERTYPE_LIMIT_IF_TOUCHED_CLIENT_SIDE;
            }
            _new_order.Stop1Offset = calculated_stop;
            _new_order.Target1Offset = calculated_target;
            sc.SetAttachedOrders(_new_order);
        }

//         sc.AddMessageToLog("TRADEWINDOW CALLED", 0);
    }

}

