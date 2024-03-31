#include "main.h"
#include "lib.h"

void do_renko_chart_settings(SCStudyInterfaceRef sc, int timeframe1, int timeframe2, int timeframe3)
{
    n_ACSIL::s_BarPeriod NewBarPeriod;
    sc.GetBarPeriodParameters(NewBarPeriod);
    if ((timeframe1 > 0) && (timeframe2 > 0) && (timeframe3 > 0) && ((NewBarPeriod.IntradayChartBarPeriodParameter1 != timeframe1) || (NewBarPeriod.IntradayChartBarPeriodParameter2 != timeframe2) || (NewBarPeriod.IntradayChartBarPeriodParameter3 != timeframe3) || (NewBarPeriod.IntradayChartBarPeriodType != IBPT_FLEX_RENKO_IN_TICKS_INVERSE_SETTINGS))) {
        NewBarPeriod.ChartDataType = INTRADAY_DATA;
        NewBarPeriod.IntradayChartBarPeriodType = IBPT_FLEX_RENKO_IN_TICKS_INVERSE_SETTINGS;
        NewBarPeriod.IntradayChartBarPeriodParameter1 = timeframe1;
        NewBarPeriod.IntradayChartBarPeriodParameter2 = timeframe2;
        NewBarPeriod.IntradayChartBarPeriodParameter3 = timeframe3;
        sc.SetBarPeriodParameters(NewBarPeriod);
    }
}

SCSFExport scsf_TimeframeRenko(SCStudyInterfaceRef sc)
{

    SCInputRef TIMEFRAMERENKO_timeframe_multiplier = sc.Input[1];
    SCInputRef TIMEFRAMERENKO_bar = sc.Input[2];
    SCInputRef TIMEFRAMERENKO_trend_multiplier = sc.Input[3];
    SCInputRef TIMEFRAMERENKO_reversal_multiplier = sc.Input[4];

    sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

    if (sc.SetDefaults) {

        sc.GraphName = "Timeframe Manager Renko Chart";
        sc.StudyDescription = "Timeframe Manager Renko Chart";

        sc.GraphUsesChartColors = true;

        sc.ValueFormat = VALUEFORMAT_INHERITED;
        sc.GraphRegion = 0;
        sc.DisplayAsMainPriceGraph = false;
        sc.AutoLoop = 0;
        sc.StandardChartHeader = 1;

        TIMEFRAMERENKO_timeframe_multiplier.Name = "Timeframe multiplier";
        TIMEFRAMERENKO_timeframe_multiplier.SetFloat(1);

        TIMEFRAMERENKO_bar.Name = "bar multiplier";
        TIMEFRAMERENKO_bar.SetFloat(1);

        TIMEFRAMERENKO_trend_multiplier.Name = "trend multiplier";
        TIMEFRAMERENKO_trend_multiplier.SetFloat(1);

        TIMEFRAMERENKO_reversal_multiplier.Name = "reversal multiplier";
        TIMEFRAMERENKO_reversal_multiplier.SetFloat(1);

        return;
    }

    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
        sc.AddMessageToLog("Doing Initial Load", 0);
#endif

        SCString path;
        std::ifstream input(path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "atr"));

        if (input) {
            int timeframe;
            float atr;
            input >> timeframe >> atr;
            float atr_calculated = atr * TIMEFRAMERENKO_timeframe_multiplier.GetFloat();
            int calculated_timeframe1 = sc.Round(( atr_calculated * TIMEFRAMERENKO_bar.GetFloat()) / sc.TickSize);
            int calculated_timeframe2 = sc.Round(( atr_calculated * TIMEFRAMERENKO_trend_multiplier.GetFloat()) / sc.TickSize);
            int calculated_timeframe3 = sc.Round(( atr_calculated * TIMEFRAMERENKO_reversal_multiplier.GetFloat()) / sc.TickSize);
            input.close();
            do_renko_chart_settings(sc, calculated_timeframe1, calculated_timeframe2, calculated_timeframe3);
        }
        return;

    }

}

