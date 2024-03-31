#include "main.h"
#include "lib.h"


void do_tick_chart_settings(SCStudyInterfaceRef sc, int timeframe)
{
    n_ACSIL::s_BarPeriod NewBarPeriod;
    sc.GetBarPeriodParameters(NewBarPeriod);
    if ((timeframe > 0) && ((NewBarPeriod.IntradayChartBarPeriodParameter1 != timeframe) || (NewBarPeriod.IntradayChartBarPeriodType != IBPT_NUM_TRADES_PER_BAR))) {
        NewBarPeriod.ChartDataType = INTRADAY_DATA;
        NewBarPeriod.IntradayChartBarPeriodType = IBPT_NUM_TRADES_PER_BAR;
        NewBarPeriod.IntradayChartBarPeriodParameter1 = timeframe;
        sc.SetBarPeriodParameters(NewBarPeriod);
    }
}

SCSFExport scsf_TimeframeTick(SCStudyInterfaceRef sc)
{

    SCInputRef TIMEFRAMETICK_timeframe_multiplier = sc.Input[1];

    sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

    if (sc.SetDefaults) {

        sc.GraphName = "Timeframe Manager Tick Chart";
        sc.StudyDescription = "Timeframe Manager Tick Chart";

        sc.GraphUsesChartColors = true;

        sc.ValueFormat = VALUEFORMAT_INHERITED;
        sc.GraphRegion = 0;
        sc.DisplayAsMainPriceGraph = false;
        sc.AutoLoop = 0;
        sc.StandardChartHeader = 1;

        TIMEFRAMETICK_timeframe_multiplier.Name = "Timeframe multiplier";
        TIMEFRAMETICK_timeframe_multiplier.SetFloat(1);

        return;
    }

    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
        sc.AddMessageToLog("Doing Initial Load", 0);
#endif

        SCString path;
        std::ifstream input(path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "timeframe"));

        if (input) {
            int timeframe;
            input >> timeframe;
            int calculated_timeframe = sc.Round(timeframe * TIMEFRAMETICK_timeframe_multiplier.GetFloat());
            input.close();
            do_tick_chart_settings(sc, calculated_timeframe);
        }
        return;
    }

}

