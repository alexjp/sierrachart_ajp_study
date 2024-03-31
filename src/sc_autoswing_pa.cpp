#include "sc_autoswing_pa.h"

int autoswing_pa_set_defaults(SCStudyInterfaceRef sc) {

    if (!sc.SetDefaults)
        return 0;

    sc.GraphName = "Auto Swing Price Action";
    sc.StudyDescription = "Auto Swing based on Price Action";

    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].Name = "Swing Begin Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].ShortName = "Swing Begin Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].SecondaryColorUsed = 1;

    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX].Name = "Swing Begin Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX].ShortName = "Swing Previous Edge";

    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].Name = "Swing End Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].PrimaryColor = COLOR_GREEN;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].ShortName = "Swing End Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].SecondaryColorUsed = 1;

    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX].Name = "Swing End Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX].ShortName = "Swing Previous Edge";

    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].Name = "Swing Previous Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].PrimaryColor = COLOR_GRAY;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].ShortName = "Swing Previous Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].SecondaryColorUsed = 1;

    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX].Name = "Swing Previous Edge";
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX].ShortName = "Swing Previous Edge";


    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].Name = "Swing Minimum Retreacement";
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].PrimaryColor = COLOR_GRAY;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET].ShortName = "Swing Minimum";

    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED].Name = "Proper Swing Retreacement Done";
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED].ShortName = "Swing Retreacement Done";

    sc.Subgraph[_AUTO_SWING_PA_SG_STOP].Name = "Swing STOP";
    sc.Subgraph[_AUTO_SWING_PA_SG_STOP].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_STOP].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_STOP].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_STOP].ShortName = "Swing Stop";

    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT].Name = "Swing LIMIT";
    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT].ShortName = "Swing Limit";

    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].Name = "Swing New/Working Begin";
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].DrawStyle = DRAWSTYLE_LINE;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].PrimaryColor = COLOR_ORANGERED;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].DisplayNameValueInWindowsFlags = 0;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].LineWidth = 2;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN].ShortName = "Swing New/Working Begin";

    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].Name = "Swing New/Working End";
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].DrawStyle = DRAWSTYLE_LINE;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].PrimaryColor = COLOR_ORANGERED;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].DisplayNameValueInWindowsFlags = 0;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].LineWidth = 2;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END].ShortName = "Swing New/Working End";

    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].Name = "Swing Direction";
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION].ShortName = "Swing Direction";

    sc.Input[_AUTO_SWING_PA_I_REPAINT].Name = "Repaint";
    sc.Input[_AUTO_SWING_PA_I_REPAINT].SetInt(1);

    sc.Input[_AUTO_SWING_PA_I_BUTTON_ON].Name = "Button Activate";
    sc.Input[_AUTO_SWING_PA_I_BUTTON_ON].SetInt(13);

    sc.Input[_AUTO_SWING_PA_I_BUTTON_OFF].Name = "Button Deactivate";
    sc.Input[_AUTO_SWING_PA_I_BUTTON_OFF].SetInt(15);

    sc.Input[_AUTO_SWING_PA_I_ATR].Name = "External ATR";
    sc.Input[_AUTO_SWING_PA_I_ATR].SetStudySubgraphValues(6, 0);

    sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].Name = "ATR Multiplier for Stop";
    sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].SetFloat(1);

    sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].Name = "Tick Offset";
    sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].SetInt(1);

    sc.Input[_AUTO_SWING_PA_I_MIN_CANDLES_AFTER_BREAKOUT].Name = "Minimum Bars after breakout";
    sc.Input[_AUTO_SWING_PA_I_MIN_CANDLES_AFTER_BREAKOUT].SetInt(3);

    //    sc.Input[_AUTO_SWING_PA_I_MAX_DISTANCE].Name = "Swing Max Distance";
    //    sc.Input[_AUTO_SWING_PA_I_MAX_DISTANCE].SetFloat(21);

    sc.Input[_AUTO_SWING_PA_I_DATE_TIME_START].Name = "Initial Swing Start";
    sc.Input[_AUTO_SWING_PA_I_DATE_TIME_START].SetDateTime(0);

    sc.Input[_AUTO_SWING_PA_I_DATE_TIME_END].Name = "Initial Swing End";
    sc.Input[_AUTO_SWING_PA_I_DATE_TIME_END].SetDateTime(0);

    sc.Input[_AUTO_SWING_PA_I_ALERT].Name = "Alert";
    sc.Input[_AUTO_SWING_PA_I_ALERT].SetInt(0);

    sc.Input[_AUTO_SWING_PA_I_ATR_MULT].Name = "ATR Multiplier";
    sc.Input[_AUTO_SWING_PA_I_ATR_MULT].SetFloat(1.618);
    sc.Input[_AUTO_SWING_PA_I_ATR_MULT].SetDescription("Upper Band");

    sc.Input[_AUTO_SWING_PA_I_USE_EXT_ATR].Name = "Use External ATR Study";
    sc.Input[_AUTO_SWING_PA_I_USE_EXT_ATR].SetInt(1);

    //    sc.Input[_AUTO_SWING_PA_I_NEW_SWING_EXT].Name = "Required extension for new swing";
    //    sc.Input[_AUTO_SWING_PA_I_NEW_SWING_EXT].SetFloat(127.2);

    sc.Input[_AUTO_SWING_PA_I_STUDY_NAME].Name = "VbP study short name";
    sc.Input[_AUTO_SWING_PA_I_STUDY_NAME].SetString("volumebyprice");

    sc.GraphRegion = 0;
    sc.AutoLoop = 1;
    sc.ScaleRangeType = SCALE_SAMEASREGION;
    sc.DrawStudyUnderneathMainPriceGraph = 1;
    sc.DisplayStudyInputValues = 0;
    sc.DisplayStudyName = 0;
    sc.TransparencyLevel = 90;

    return 1;
}

int autoswing_pa_skip_iteration(SCStudyInterfaceRef sc)
{
    if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.DownloadingHistoricalData)
        return 1;
    return 0;
}

int autoswing_pa_last_call(SCStudyInterfaceRef sc)
{
    if (!sc.LastCallToFunction)
        return 0;

    return 1;
}

void autoswing_pa_set_atr_tick_offset(SCStudyInterfaceRef sc, int index_end) {
    if (index_end > 0 && sc.Input[_AUTO_SWING_PA_I_USE_EXT_ATR].GetInt() > 0) {
        SCFloatArray atrArray;
        SCInputRef i_atr = sc.Input[_AUTO_SWING_PA_I_ATR];
        if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
            float _result = (atrArray[index_end]) / sc.TickSize;
            sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].SetInt(sc.Round(_result));
        }
    }
    else {
        SCString atr_path;

        std::ifstream atr_input(atr_path.Format("conf/%s/%s.conf", sc.Symbol.GetChars(), "atr"));

        if (atr_input.is_open()) {
            int atr;
            atr_input >> atr;
            sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].SetInt(atr);
            atr_input.close();

        }
    }
}


void autoswing_pa_autocolor(SCStudyInterfaceRef sc, int index, int direction) {
    if (direction == 1) {
        sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].PrimaryColor;
        sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].PrimaryColor;
        sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].PrimaryColor;
    }
    if (direction == -1) {
        sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE].SecondaryColor;
        sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE].SecondaryColor;
        sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].DataColor[index] = sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE].SecondaryColor;
    }
}

float autoswing_pa_calculate_stop(SCStudyInterfaceRef sc, float price, int direction) {
    float _offset = sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].GetInt() * sc.TickSize;

    if (direction == 1)
        return price - (_offset * sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].GetFloat());
    if (direction == -1)
        return price + (_offset * sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].GetFloat());
    return price;
}
float autoswing_pa_limit_calc(SCStudyInterfaceRef sc, int direction, float price) {
    float _offset = (sc.Input[_AUTO_SWING_PA_I_TICK_OFFSET].GetInt() * sc.TickSize) ;

    if (direction == 1)
        return price + (_offset * sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].GetFloat());
    if (direction == -1)
        return price - (_offset * sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].GetFloat());
    return price;
}

/*float autoswing_pa_limit_calc(SCStudyInterfaceRef sc, int direction, float price_begin, float price_end) {
    float _mult = sc.Input[_AUTO_SWING_PA_I_NEW_SWING_EXT].GetFloat();
    float result = price_end;

    if (_mult > 0) {
        //        if (direction == 1)
        //            result = calc_fib(sc, _mult, price_begin, price_end);
        //        if (direction == -1)
        result = calc_fib(sc, _mult, price_begin, price_end);
    }
    else if (_mult <= 0) {
        result = calc_fib(sc, 127.2, price_begin, price_end);
    }
    return result;
}*/

void autoswing_pa_zone_swing_tool_remove(SCStudyInterfaceRef sc) {

    SCString study_name;

    int study_bull = sc.GetStudyIDByName(sc.ChartNumber, study_name.Format("%s%s", sc.Input[_AUTO_SWING_PA_I_STUDY_NAME].GetString(), "bull"), 1);
    int study_bear = sc.GetStudyIDByName(sc.ChartNumber, study_name.Format("%s%s", sc.Input[_AUTO_SWING_PA_I_STUDY_NAME].GetString(), "bear"), 1);

    if (study_bull > 0) {
        sc.SetStudyVisibilityState(study_bull, 0);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study_bull, 32, 9);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study_bull, 35, 1);
    }
    if (study_bear > 0) {
        sc.SetStudyVisibilityState(study_bear, 0);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study_bear, 32, 9);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study_bear, 35, 1);
    }

}

void autoswing_pa_volumebyprice(SCStudyInterfaceRef sc, int & sg_direction) {
    autoswing_pa_zone_swing_tool_remove(sc);
    int _index_previous = sc.GetPersistentInt(_AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX);
    int _index_end = sc.GetPersistentInt(_AUTO_SWING_PA_P_END_EDGE_INDEX);


    float date, time;
    SCString study_name;
    if (sg_direction == 1)
        study_name = study_name.Format("%s%s", "volumebyprice", "bull");
    if (sg_direction == -1)
        study_name = study_name.Format("%s%s", "volumebyprice", "bear");

    int study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);

    if (study > 0) {
        time = std::modf(sc.GetEndingDateTimeForBarIndex(_index_previous-1), &date);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study, 36, date);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study, 38, time);

        time = std::modf(sc.GetEndingDateTimeForBarIndex(_index_end), &date);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study, 39, date);
        sc.SetChartStudyInputFloat(sc.ChartNumber, study, 40, time);

        sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 5);

        sc.SetStudyVisibilityState(study, 1);
    }

    sc.SetPersistentInt(_AUTO_SWING_PA_P_VWAP, study);
}

void autoswing_pa_main_iteration_repaint(SCStudyInterfaceRef sc, int index, float & sg_previous_edge, float & sg_begin_edge, float & sg_end_edge, int & sg_direction) {
    int _index_previous = sc.GetPersistentInt(_AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX);
    int _index_begin = sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX);
    int _index_end = sc.GetPersistentInt(_AUTO_SWING_PA_P_END_EDGE_INDEX);


    if ((_index_previous > 0) && (_index_previous < index)) {
        for (int i = _index_previous ; i < index ; i++) {
            //sc.AddMessageToLog("loop",1);
            sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE][i] = sg_previous_edge;
            if (i > _index_begin)
                sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE][i] = sg_begin_edge;
            if (i > _index_end)
                sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE][i] = sg_end_edge;
            autoswing_pa_autocolor(sc, i, sg_direction);
        }
    }

}

void autoswing_pa_main_iteration_update_end_edge_index(SCStudyInterfaceRef sc, int index, int PA, int SG) {
    int _old_index = sc.GetPersistentInt(PA);
    if (_old_index > 0) {
        sc.Subgraph[SG][_old_index] = 0;
    }
    sc.Subgraph[SG][index] = index;
    sc.SetPersistentInt(PA, index);
}

void autoswing_pa_main_iteration_swing(SCStudyInterfaceRef sc, int index, float & sg_previous_edge, float & sg_begin_edge, float & sg_end_edge , float & sg_min_ret, float & sg_stop,  float & sg_limit, int & sg_min_acheived, int & sg_direction) {
    float _min_price = 0;
    float _max_price = 0;
    int SC_RET_LOW_HIGH = 0;
    int SC_BKO_LOW_HIGH = 0;

    if (sg_direction == 1) {
        _min_price = sc.RoundToTickSize(sc.Low[index]);
        _max_price = sc.RoundToTickSize(sc.High[index]);
        SC_RET_LOW_HIGH = SC_LOW;
        SC_BKO_LOW_HIGH = SC_HIGH;
    }
    else if (sg_direction == -1) {
        _min_price = sc.RoundToTickSize(sc.High[index]);
        _max_price = sc.RoundToTickSize(sc.Low[index]);
        SC_RET_LOW_HIGH = SC_HIGH;
        SC_BKO_LOW_HIGH = SC_LOW;
    }

    //    // doing new highs
    //    if (((sg_direction == 1) && (_max_price >= sg_new_end)) ||
    //        ((sg_direction == -1) && (_max_price <= sg_new_end))) {

    //        sg_new_end = _max_price;
    //        sc.SetPersistentInt(_AUTO_SWING_PA_P_NEW_MAX_EDGE_INDEX, index);
    //    }

    //    if (sg_min_acheived == -1) {
    //        if (((sg_direction == 1) && (_max_price >= sg_limit)) ||
    //            ((sg_direction == -1) && (_max_price <= sg_limit))) {
    //            sg_min_acheived = 0;
    //        }
    //    }


    // doing retreacement for the first time
    if (sg_min_acheived == 0) {
        if (((sg_direction == 1) && (_min_price <= sg_min_ret)) ||
                ((sg_direction == -1) && (_min_price >= sg_min_ret))) {
            float new_limit = 0;

            int _index = 0;
            if (sg_direction == 1)
                _index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_BKO_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX));
            else if (sg_direction == -1)
                _index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_BKO_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX));

            if (index - _index > sc.Input[_AUTO_SWING_PA_I_MIN_CANDLES_AFTER_BREAKOUT].GetInt()) {
                autoswing_pa_main_iteration_update_end_edge_index(sc, _index, _AUTO_SWING_PA_P_END_EDGE_INDEX, _AUTO_SWING_PA_SG_END_EDGE_INDEX);
                sg_end_edge = sc.BaseDataIn[SC_BKO_LOW_HIGH][_index];

                new_limit = autoswing_pa_limit_calc(sc, sg_direction, sg_end_edge);

                if (((sg_direction == 1) && (new_limit > sg_limit)) ||
                        ((sg_direction == -1) && (new_limit < sg_limit))) {
                    sg_limit = new_limit;
                }


                if (sc.Input[_AUTO_SWING_PA_I_REPAINT].GetInt() == 1)
                    autoswing_pa_main_iteration_repaint(sc, index, sg_previous_edge, sg_begin_edge, sg_end_edge, sg_direction);
                sg_min_acheived = 1;

            }

            return;
        }
    }

    //    // broken high line
    //    if ( (index > sc.GetPersistentInt(_AUTO_SWING_PA_P_END_EDGE_INDEX) ) && (sg_min_acheived == 1) &&
    //            (((sg_direction == 1) && (_max_price >= sg_end_edge && sg_end_edge != 0)) ||
    //            ((sg_direction == -1) && (_max_price <= sg_end_edge && sg_end_edge != 0))) ) {
    //            sg_previous_edge = sg_end_edge;
    //            sg_end_edge = 0; //sg_new_end;
    //    }

    if (sg_min_acheived == 1) {
        // max reached target after retreacement -> new swing
        if (((sg_direction == 1) && (_max_price >= sg_limit)) ||
                ((sg_direction == -1) && (_max_price <= sg_limit))) {

            sg_previous_edge = sg_end_edge;
            sg_min_ret = sg_end_edge;
            //            float fib = calc_fib(sc, 38.2, sg_begin_edge, sg_end_edge);
            //            if (((sg_direction == 1) && (fib < sg_min_ret)) ||
            //                ((sg_direction == -1) && (fib > sg_min_ret)))
            //                sg_min_ret = fib;

            int _index = 0;

            autoswing_pa_main_iteration_update_end_edge_index(sc, sc.GetPersistentInt(_AUTO_SWING_PA_P_END_EDGE_INDEX), _AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX, _AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX);


            if (sg_direction == 1)
                _index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_RET_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX));
            else if (sg_direction == -1)
                _index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_RET_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX));

            autoswing_pa_main_iteration_update_end_edge_index(sc, _index, _AUTO_SWING_PA_P_BEGIN_EDGE_INDEX, _AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX);

            sg_begin_edge = sc.BaseDataIn[SC_RET_LOW_HIGH][sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX)];


            sg_stop = autoswing_pa_calculate_stop(sc, sg_begin_edge, sg_direction);
            sg_min_acheived = 0;
            autoswing_pa_volumebyprice(sc, sg_direction);
            return;
        }

        int vwap_id = sc.GetPersistentInt(_AUTO_SWING_PA_P_VWAP);
        SCFloatArray vwapArray;
        sc.GetStudyArrayUsingID(vwap_id, 5, vwapArray);

        if (vwap_id > 0 && ((sg_direction == 1) && (_max_price <= vwapArray[index]) && (sc.Open[index] < sc.Close[index])) ||
                ((sg_direction == -1) && (_max_price >= vwapArray[index]) && (sc.Open[index] > sc.Close[index]))) {

            int _alert = sc.Input[_AUTO_SWING_PA_I_ALERT].GetInt();
            if (_alert > 0) {
                if ( (index >= (sc.ArraySize-1)) && (sc.AlertConditionEnabled == 1) ) {
                    s_SCPositionData position;
                    sc.GetTradePosition(position);
                    if (position.PositionQuantity == 0) {
                        SCString alert_text;
                        if (sg_direction == 1)
                            alert_text = "Long";
                        else if (sg_direction == -1)
                            alert_text = "Short";
                        else alert_text = "error";

                        sc.SetAlert(0, alert_text);

                        if (_alert > 1) {
                            sc.PlaySound(alert_path(sc, "swing", alert_text), 1);
                        }
                    }
                }
            }

        }
    }



    // broken swing
    if (((sg_direction == 1) && (_min_price < sg_stop)) ||
            ((sg_direction == -1) && (_min_price > sg_stop))) {

        sg_min_acheived = 0;

        autoswing_pa_main_iteration_update_end_edge_index(sc, sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX), _AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX, _AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX);
        sg_previous_edge = sc.BaseDataIn[SC_BKO_LOW_HIGH][sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX)];
        sg_min_ret = sg_previous_edge;

        sg_direction = sg_direction * -1;

        int _index = 0;
        if (sg_direction == 1)
            _index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_BKO_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX));
        else if (sg_direction == -1)
            _index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_BKO_LOW_HIGH], index, index - sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX));

        autoswing_pa_main_iteration_update_end_edge_index(sc, _index, _AUTO_SWING_PA_P_BEGIN_EDGE_INDEX, _AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX);
        sg_begin_edge = sc.BaseDataIn[SC_BKO_LOW_HIGH][_index];



        sg_stop = autoswing_pa_calculate_stop(sc, sg_begin_edge, sg_direction);
        sg_limit = autoswing_pa_limit_calc(sc, sg_direction, sg_end_edge);
        autoswing_pa_volumebyprice(sc, sg_direction);

        if (sc.Input[_AUTO_SWING_PA_I_REPAINT].GetInt() == 1)
            autoswing_pa_main_iteration_repaint(sc, index, sg_previous_edge, sg_begin_edge, sg_end_edge, sg_direction);

        return;
    }
}

void autoswing_pa_initialize_values(SCStudyInterfaceRef sc, int current_index, int index_previous_edge, int index_start_edge, int index_end_edge, float price_previous_edge, float price_start_edge, float price_end_edge, int direction, int length, int active) {

    autoswing_pa_set_atr_tick_offset(sc, current_index);


    float _price_stop = autoswing_pa_calculate_stop(sc, price_start_edge, direction);
    float _price_new_swing = 0;


    _price_new_swing = autoswing_pa_limit_calc(sc, direction, price_end_edge);

    sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE][index_start_edge] = price_start_edge;
    sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE][index_end_edge] = price_end_edge;
    sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE][index_previous_edge] = price_previous_edge;

    autoswing_pa_main_iteration_update_end_edge_index(sc, index_start_edge, _AUTO_SWING_PA_P_BEGIN_EDGE_INDEX, _AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX);
    autoswing_pa_main_iteration_update_end_edge_index(sc, index_end_edge, _AUTO_SWING_PA_P_END_EDGE_INDEX, _AUTO_SWING_PA_SG_END_EDGE_INDEX);
    autoswing_pa_main_iteration_update_end_edge_index(sc, index_previous_edge, _AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX, _AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX);

    float _min_ret = price_previous_edge;
    //    float fib = calc_fib(sc, 38.2, price_start_edge, price_end_edge);
    //    if (((direction == 1) && (fib < _min_ret)) ||
    //        ((direction == -1) && (fib > _min_ret)))
    //        _min_ret = fib;

    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET][index_start_edge] = _min_ret;
    sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED][index_start_edge] = 0;
    sc.Subgraph[_AUTO_SWING_PA_SG_STOP][index_start_edge] = _price_stop;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN][index_start_edge] = price_start_edge;
    //    sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END][index_start_edge] = price_end_edge;
    sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT][index_start_edge] = _price_new_swing;
    sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION][index_start_edge] = direction;

    sc.SetPersistentInt(_AUTO_SWING_PA_P_DIRECTION, direction);


    sc.SetPersistentInt(_AUTO_SWING_PA_P_LAST_INDEX_LOOPED, index_start_edge);
    sc.SetPersistentInt(_AUTO_SWING_PA_P_SWING_ACTIVE, index_end_edge);

    //    sc.SetPersistentInt(_AUTO_SWING_PA_P_NEW_BEGIN_INDEX_REPAINT, index_start_edge);
    //    sc.SetPersistentInt(_AUTO_SWING_PA_P_NEW_REVERSAL_BEGIN_INDEX_REPAINT, index_end_edge);

    if (sc.Input[_AUTO_SWING_PA_I_REPAINT].GetInt() == 1)
        autoswing_pa_main_iteration_repaint(sc, index_end_edge, price_previous_edge, price_start_edge, price_end_edge, direction);

    autoswing_pa_volumebyprice(sc, direction);

}

void autoswing_pa_main_iteration(SCStudyInterfaceRef sc, int index, int prev_index) {

    SCInputRef SwingStart = sc.Input[_AUTO_SWING_PA_I_DATE_TIME_START];
    SCInputRef SwingEnd= sc.Input[_AUTO_SWING_PA_I_DATE_TIME_END];
    int _date_start_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingStart.GetDateTime());

    // Initializing/Initial swing
    if (index ==_date_start_index)
    {
        int _index_begin, _index_end, _third_index, _direction, _length;
        float _price_begin, _price_end, _third_price;
        int mouse_start = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingStart.GetDateTime());
        int mouse_end = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingEnd.GetDateTime());
        if (process_new_mouse_zone(sc, _index_begin, _index_end, _third_index, _price_begin, _price_end, _third_price, _direction, _length, mouse_start, mouse_end ))
        {
            autoswing_pa_initialize_values(sc, index, _third_index, _index_begin, _index_end, _third_price, _price_begin, _price_end, _direction, _length, 1);
        }
        return;
    }

    // Iterating swing
    if (index > sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX)) {

        float _sg_begin_edge = sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE][prev_index];
        float _sg_end_edge = sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE][prev_index];
        float _sg_previous_edge = sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE][prev_index];

        float _sg_min_ret = sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET][prev_index];
        float _sg_stop = sc.Subgraph[_AUTO_SWING_PA_SG_STOP][prev_index];
        float _sg_limit = sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT][prev_index];
        //        float _sg_new_begin = sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN][prev_index];
        //        float _sg_new_end = sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END][prev_index];

        int _sg_min_acheived = sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED][prev_index];
        int _sg_direction = sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION][prev_index];

        if (sc.GetPersistentInt(_AUTO_SWING_PA_P_SWING_ACTIVE) >= 1) {

            if (index >= sc.GetPersistentInt(_AUTO_SWING_PA_P_END_EDGE_INDEX)) {
                autoswing_pa_main_iteration_swing(sc, index, _sg_previous_edge, _sg_begin_edge, _sg_end_edge, _sg_min_ret, _sg_stop, _sg_limit, _sg_min_acheived, _sg_direction);
            }

        }

        sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE][index] = sc.RoundToTickSize(_sg_begin_edge);
        sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE][index] = sc.RoundToTickSize(_sg_end_edge);
        sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE][index] = sc.RoundToTickSize(_sg_previous_edge);
        sc.Subgraph[_AUTO_SWING_PA_SG_STOP][index] = sc.RoundToTickSize(_sg_stop);
        sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT][index] = sc.RoundToTickSize(_sg_limit);
        //        sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN][index] = sc.RoundToTickSize(_sg_new_begin);
        //        sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END][index] = sc.RoundToTickSize(_sg_new_end);
        sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED][index] = _sg_min_acheived;
        sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION][index] = _sg_direction;

        sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET][index] = sc.RoundToTickSize(_sg_min_ret);

        autoswing_pa_autocolor(sc, index, _sg_direction);
        return;
    }

    // Before Initial Swing, clearing
    if (index < _date_start_index || index < sc.GetPersistentInt(_AUTO_SWING_PA_P_BEGIN_EDGE_INDEX) || SwingStart.GetTime() == SwingEnd.GetTime()) {
        sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_PRICE][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_PRICE][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_PRICE][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_MIN_RET][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_STOP][index] = 0;
        //        sc.Subgraph[_AUTO_SWING_PA_SG_NEW_BEGIN][index] = 0;
        //        sc.Subgraph[_AUTO_SWING_PA_SG_NEW_END][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_LIMIT][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_MIN_ACHEIVED][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_DIRECTION][index] = 0;

        sc.Subgraph[_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX][index] = 0;
        sc.Subgraph[_AUTO_SWING_PA_SG_END_EDGE_INDEX][index] = 0;

        int index_previous = sc.GetPersistentInt(_AUTO_SWING_PA_P_PREVIOUS_EDGE_INDEX);
        if (index_previous == 0 || index != index_previous)
            sc.Subgraph[_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX][index] = 0;
        return;
    }
}

SCSFExport scsf_Auto_Swing_PA(SCStudyInterfaceRef sc)
{
    if (autoswing_pa_set_defaults(sc))
        return;
    if (autoswing_pa_skip_iteration(sc))
        return;
    int last_call = autoswing_pa_last_call(sc);


    SCInputRef ButtonON = sc.Input[_AUTO_SWING_PA_I_BUTTON_ON];
    SCInputRef ButtonOFF = sc.Input[_AUTO_SWING_PA_I_BUTTON_OFF];
    SCInputRef SwingStart = sc.Input[_AUTO_SWING_PA_I_DATE_TIME_START];
    SCInputRef SwingEnd= sc.Input[_AUTO_SWING_PA_I_DATE_TIME_END];

    int& StateButton = sc.GetPersistentInt(_AUTO_SWING_PA_P_STATE_ACS_BUTTON);
    int& MouseStart = sc.GetPersistentInt(_AUTO_SWING_PA_P_STATE_MOUSE_START);
    int& MouseEnd = sc.GetPersistentInt(_AUTO_SWING_PA_P_STATE_MOUSE_END);
    int& LastIndexLooped = sc.GetPersistentInt(_AUTO_SWING_PA_P_LAST_INDEX_LOOPED);

    sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

    // EVENTS REGION

    // Button Off
    if ((sc.MenuEventID == ButtonOFF.GetInt() && sc.PointerEventType == SC_ACS_BUTTON_ON) || last_call)
    {
        LastIndexLooped = 0;
        SwingStart.SetDateTime(0);
        SwingEnd.SetDateTime(0);
        sc.SetPersistentInt(_AUTO_SWING_PA_SG_BEGIN_EDGE_INDEX,0);
        sc.SetPersistentInt(_AUTO_SWING_PA_SG_END_EDGE_INDEX,0);
        sc.SetPersistentInt(_AUTO_SWING_PA_SG_PREVIOUS_EDGE_INDEX,0);
        autoswing_pa_zone_swing_tool_remove(sc);
        StateButton = -1;
        sc.SetCustomStudyControlBarButtonEnable(ButtonOFF.GetInt(), 0);
        sc.FlagFullRecalculate = 1;
        return;
    }

    // Load configuration
    if (sc.Index == 0) {
        std::ifstream file = read_conf(sc);

        if (file) {
            float atr_mult_stop, multiplier;
            int repaint, show_study, alert, use_ext_atr;
            file >> use_ext_atr >> atr_mult_stop >> multiplier >> repaint >> show_study >> alert;

            sc.Input[_AUTO_SWING_PA_I_ATR_MULT_STOP].SetFloat(atr_mult_stop);
            sc.Input[_AUTO_SWING_PA_I_REPAINT].SetInt(repaint);
            sc.Input[_AUTO_SWING_PA_I_ALERT].SetInt(alert);
            sc.Input[_AUTO_SWING_PA_I_USE_EXT_ATR].SetInt(use_ext_atr);

            if (show_study == 1)
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 1);
            else
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 0);

            sc.Input[_AUTO_SWING_PA_I_ATR_MULT].SetFloat(multiplier);

            file.close();
        }
        return;
    }



    // New Trade Swing
    if (sc.MenuEventID == ButtonON.GetInt() || StateButton == ButtonON.GetInt()) {
        if (tool_range_selection(sc, sc.MenuEventID, StateButton, MouseStart, MouseEnd) == 3) {

            SwingStart.SetDateTime(sc.BaseDateTimeIn[MouseStart]);
            SwingEnd.SetDateTime(sc.BaseDateTimeIn[MouseEnd]);
            sc.FlagFullRecalculate = 1;

            StateButton = -1;
        }

        return;
    }

    // Main Iteration

    // Already iterated on this index
    if (LastIndexLooped == sc.Index)
        return;

    int prev_index = sc.Index-1;

    autoswing_pa_main_iteration(sc, sc.Index, prev_index);
    sc.SetPersistentInt(_AUTO_SWING_PA_P_LAST_INDEX_LOOPED, sc.Index);

}
