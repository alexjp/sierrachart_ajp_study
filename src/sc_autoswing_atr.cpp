#include "sc_autoswingfib.h"

int autoswing_set_defaults(SCStudyInterfaceRef sc) {

    if (!sc.SetDefaults)
        return 0;

    sc.GraphName = "Auto Swing";
    sc.StudyDescription = "Auto Swing";

    sc.Subgraph[_AUTO_SWING_SG_BEGIN].Name = "Swing Begin";
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].ShortName = "Swing Begin";
    sc.Subgraph[_AUTO_SWING_SG_BEGIN].SecondaryColorUsed = 1;

    sc.Subgraph[_AUTO_SWING_SG_END].Name = "Swing End";
    sc.Subgraph[_AUTO_SWING_SG_END].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_END].PrimaryColor = COLOR_GREEN;
    sc.Subgraph[_AUTO_SWING_SG_END].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_END].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_SG_END].ShortName = "Swing End";
    sc.Subgraph[_AUTO_SWING_SG_END].SecondaryColorUsed = 1;

    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].Name = "Swing Minimum Retreacement";
    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].PrimaryColor = COLOR_GRAY;
    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_MIN_RET].ShortName = "Swing Minimum";


    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN].Name = "Swing Golden Retreacement";
    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN].ShortName = "Swing Golden";

    sc.Subgraph[_AUTO_SWING_SG_RET_END].Name = "Swing Exhaustion Retreacement";
    sc.Subgraph[_AUTO_SWING_SG_RET_END].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_SG_RET_END].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_RET_END].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_RET_END].ShortName = "Swing Exhaustion";

    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED].Name = "Proper Swing Retreacement Done";
    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED].ShortName = "Swing Retreacement Done";

    sc.Subgraph[_AUTO_SWING_SG_STOP].Name = "Swing STOP";
    sc.Subgraph[_AUTO_SWING_SG_STOP].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_SG_STOP].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_STOP].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_STOP].ShortName = "Swing Stop";

    sc.Subgraph[_AUTO_SWING_SG_LIMIT].Name = "Swing LIMIT";
    sc.Subgraph[_AUTO_SWING_SG_LIMIT].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
    sc.Subgraph[_AUTO_SWING_SG_LIMIT].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_LIMIT].LineWidth = 1;
    sc.Subgraph[_AUTO_SWING_SG_LIMIT].ShortName = "Swing Limit";

    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].Name = "Swing New/Working Begin";
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN].ShortName = "Swing New/Working Begin";

    sc.Subgraph[_AUTO_SWING_SG_NEW_END].Name = "Swing New/Working End";
    sc.Subgraph[_AUTO_SWING_SG_NEW_END].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_NEW_END].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_SG_NEW_END].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_NEW_END].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_SG_NEW_END].ShortName = "Swing New/Working End";

    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].Name = "Swing Direction";
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].PrimaryColor = COLOR_ORANGERED;
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].DisplayNameValueInWindowsFlags = 0;
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].LineWidth = 2;
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION].ShortName = "Swing Direction";

    sc.Input[_AUTO_SWING_I_REPAINT].Name = "Repaint";
    sc.Input[_AUTO_SWING_I_REPAINT].SetInt(1);

    sc.Input[_AUTO_SWING_I_BUTTON_ON].Name = "Button Activate";
    sc.Input[_AUTO_SWING_I_BUTTON_ON].SetInt(13);

    sc.Input[_AUTO_SWING_I_BUTTON_OFF].Name = "Button Deactivate";
    sc.Input[_AUTO_SWING_I_BUTTON_OFF].SetInt(15);

    sc.Input[_AUTO_SWING_I_ATR].Name = "External ATR";
    sc.Input[_AUTO_SWING_I_ATR].SetStudySubgraphValues(6, 0);

    sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].Name = "FIBratio/ATRmult for Limit";
    sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].SetFloat(1);

    sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].Name = "ATR Multiplier for Stop";
    sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].SetFloat(1);

    sc.Input[_AUTO_SWING_I_ATR_RET_MA].Name = "ATR Retreacement at MA";
    sc.Input[_AUTO_SWING_I_ATR_RET_MA].SetInt(1);

    sc.Input[_AUTO_SWING_I_TICK_OFFSET].Name = "Tick Offset";
    sc.Input[_AUTO_SWING_I_TICK_OFFSET].SetInt(1);

    sc.Input[_AUTO_SWING_I_FIB_MIN].Name = "Fib Swing Minimum";
    sc.Input[_AUTO_SWING_I_FIB_MIN].SetFloat(38.2);

    sc.Input[_AUTO_SWING_I_FIB_ENTRY].Name = "Fib Swing Entry";
    sc.Input[_AUTO_SWING_I_FIB_ENTRY].SetFloat(61.8);

    sc.Input[_AUTO_SWING_I_FIB_MAX].Name = "Fib Swing Max";
    sc.Input[_AUTO_SWING_I_FIB_MAX].SetFloat(78.6);

    sc.Input[_AUTO_SWING_I_MAX_DISTANCE].Name = "Swing Max Distance";
    sc.Input[_AUTO_SWING_I_MAX_DISTANCE].SetFloat(21);

    sc.Input[_AUTO_SWING_I_DATE_TIME_START].Name = "Initial Swing Start";
    sc.Input[_AUTO_SWING_I_DATE_TIME_START].SetDateTime(0);

    sc.Input[_AUTO_SWING_I_DATE_TIME_END].Name = "Initial Swing End";
    sc.Input[_AUTO_SWING_I_DATE_TIME_END].SetDateTime(0);

    sc.Input[_AUTO_SWING_I_ALERT].Name = "Alert";
    sc.Input[_AUTO_SWING_I_ALERT].SetInt(0);

    sc.Input[_AUTO_SWING_I_ATR_LENGTH].Name = "ATR Length";
    sc.Input[_AUTO_SWING_I_ATR_LENGTH].SetInt(21);
    sc.Input[_AUTO_SWING_I_ATR_LENGTH].SetDescription("ATR Length");

    sc.Input[_AUTO_SWING_I_VWAP_LENGTH].Name = "VWAP Length";
    sc.Input[_AUTO_SWING_I_VWAP_LENGTH].SetInt(21);
    sc.Input[_AUTO_SWING_I_VWAP_LENGTH].SetDescription("VWAP Length");

    sc.Input[_AUTO_SWING_I_ATR_TYPE].Name = "MA Type";
    sc.Input[_AUTO_SWING_I_ATR_TYPE].SetMovAvgType(MOVAVGTYPE_SIMPLE);
    sc.Input[_AUTO_SWING_I_ATR_TYPE].SetDescription("MA Type");

    sc.Input[_AUTO_SWING_I_ATR_MULT].Name = "ATR Multiplier";
    sc.Input[_AUTO_SWING_I_ATR_MULT].SetFloat(1.618);
    sc.Input[_AUTO_SWING_I_ATR_MULT].SetDescription("Upper Band");

    sc.Input[_AUTO_SWING_I_ATR_DRAW].Name = "Draw/Calc ATR";
    sc.Input[_AUTO_SWING_I_ATR_DRAW].SetInt(1);

    sc.Input[_AUTO_SWING_I_USE_ATR_RET].Name = "Use ATR for retreacement";
    sc.Input[_AUTO_SWING_I_USE_ATR_RET].SetInt(0);

    sc.Subgraph[_AUTO_SWING_SG_ATR_MA].Name = "ATR MA";
    sc.Subgraph[_AUTO_SWING_SG_ATR_MA].PrimaryColor = COLOR_RED;
    sc.Subgraph[_AUTO_SWING_SG_ATR_MA].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_ATR_MA].LineWidth = 2;

    sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE].Name = "ATR Value";
    sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE].DrawStyle = DRAWSTYLE_IGNORE;

    sc.Subgraph[_AUTO_SWING_SG_ATR_TOP].Name = "Upper Band";
    sc.Subgraph[_AUTO_SWING_SG_ATR_TOP].PrimaryColor = COLOR_MEDIUMPURPLE;
    sc.Subgraph[_AUTO_SWING_SG_ATR_TOP].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_ATR_TOP].LineStyle = LINESTYLE_DASH;
    sc.Subgraph[_AUTO_SWING_SG_ATR_TOP].LineWidth = 2;

    sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM].Name = "Lower Band";
    sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM].PrimaryColor = COLOR_MEDIUMPURPLE;
    sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM].DrawStyle = DRAWSTYLE_LINE;
    sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM].LineStyle = LINESTYLE_DASH;
    sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM].LineWidth = 2;



    sc.GraphRegion = 0;
    sc.AutoLoop = 1;
    sc.ScaleRangeType = SCALE_SAMEASREGION;
    sc.DrawStudyUnderneathMainPriceGraph = 1;
    sc.DisplayStudyInputValues = 0;
    sc.DisplayStudyName = 0;
    sc.TransparencyLevel = 90;

    return 1;
}

int autoswing_skip_iteration(SCStudyInterfaceRef sc)
{
    if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.DownloadingHistoricalData)
        return 1;
    return 0;
}

int autoswing_last_call(SCStudyInterfaceRef sc)
{
    if (!sc.LastCallToFunction)
        return 0;

    return 1;
}

void autoswing_set_atr_tick_offset_own_atr(SCStudyInterfaceRef sc, int index) {
    if (index > 0) {
        sc.Input[_AUTO_SWING_I_TICK_OFFSET].SetInt((sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE][index]) / sc.TickSize);
    }
    else {
        sc.Input[_AUTO_SWING_I_TICK_OFFSET].SetInt(0);
    }
}

void autoswing_set_atr_tick_offset(SCStudyInterfaceRef sc, int index_end) {
    if (index_end > 0) {
        SCFloatArray atrArray;
        SCInputRef i_atr = sc.Input[_AUTO_SWING_I_ATR];
        if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
            float _result = (atrArray[index_end]) / sc.TickSize;
            sc.Input[_AUTO_SWING_I_TICK_OFFSET].SetInt(sc.Round(_result));
        }
    }
    else {
        sc.Input[_AUTO_SWING_I_TICK_OFFSET].SetInt(0);
    }
}

void autoswing_autocolor(SCStudyInterfaceRef sc, int index, int direction) {
    if (direction == 1) {
        sc.Subgraph[_AUTO_SWING_SG_BEGIN].DataColor[index] = sc.Subgraph[_AUTO_SWING_SG_BEGIN].PrimaryColor;
        sc.Subgraph[_AUTO_SWING_SG_END].DataColor[index] = sc.Subgraph[_AUTO_SWING_SG_END].PrimaryColor;
    }
    if (direction == -1) {
        sc.Subgraph[_AUTO_SWING_SG_BEGIN].DataColor[index] = sc.Subgraph[_AUTO_SWING_SG_BEGIN].SecondaryColor;
        sc.Subgraph[_AUTO_SWING_SG_END].DataColor[index] = sc.Subgraph[_AUTO_SWING_SG_END].SecondaryColor;
    }
}

float autoswing_limit_calc(SCStudyInterfaceRef sc, int direction, float price_begin, float price_end) {
    float _mult = sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].GetFloat();
    float _offset = sc.Input[_AUTO_SWING_I_TICK_OFFSET].GetInt() * sc.TickSize;
    float result = 0;

    if (_mult > 0.0) {
        if (direction == 1)
            result = price_end + (_offset * sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].GetFloat());
        if (direction == -1)
            result = price_end - (_offset * sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].GetFloat());
    }
    else if (_mult < 0.0) {
        result = calc_fib(sc, _mult, price_begin, price_end);
    }
    return result;
}

void autoswing_initialize_values(SCStudyInterfaceRef sc, int current_index, int index_begin, int index_end, int third_index, float price_begin, float price_end, float third_price, int direction, int length, int active) {

    autoswing_set_atr_tick_offset(sc, current_index);

    float _offset = sc.Input[_AUTO_SWING_I_TICK_OFFSET].GetInt() * sc.TickSize;

    float _price_begin = 0;
    float _price_end = 0;
    float _min_ret_fib_value = sc.Input[_AUTO_SWING_I_FIB_MIN].GetFloat();
    int _draw_atr = sc.Input[_AUTO_SWING_I_ATR_DRAW].GetInt();

    float _min_ret;
    if (direction == 1) {
        _price_begin = price_begin - (_offset * sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].GetFloat());
        if (sc.Input[_AUTO_SWING_I_ATR_RET_MA].GetInt() == 1)
            _min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_MA][current_index];
        else
            _min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM][current_index];
    }
    if (direction == -1) {
        _price_begin = price_begin + (_offset * sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].GetFloat());
        if (sc.Input[_AUTO_SWING_I_ATR_RET_MA].GetInt() == 1)
            _min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_MA][current_index];
        else
            _min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_TOP][current_index];
    }

    _price_end = autoswing_limit_calc(sc, direction, price_begin, price_end);

    sc.Subgraph[_AUTO_SWING_SG_BEGIN][index_begin] = price_begin;
    sc.Subgraph[_AUTO_SWING_SG_END][index_begin] = price_end;
    if (_min_ret_fib_value == 0.0 && _draw_atr > 0)
        sc.Subgraph[_AUTO_SWING_SG_MIN_RET][index_begin] = _min_ret;
    else
        sc.Subgraph[_AUTO_SWING_SG_MIN_RET][index_begin] = calc_fib(sc, _min_ret_fib_value, price_begin, price_end);
    sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN][index_begin] = 0;
    sc.Subgraph[_AUTO_SWING_SG_RET_END][index_begin] = 0;
    sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED][index_begin] = 0;
    sc.Subgraph[_AUTO_SWING_SG_STOP][index_begin] = _price_begin;
    sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN][index_begin] = price_begin;
    sc.Subgraph[_AUTO_SWING_SG_NEW_END][index_begin] = price_end;
    sc.Subgraph[_AUTO_SWING_SG_LIMIT][index_begin] = _price_end;
    sc.Subgraph[_AUTO_SWING_SG_DIRECTION][index_begin] = direction;

    sc.SetPersistentInt(_AUTO_SWING_P_START_INDEX, index_begin);
    sc.SetPersistentInt(_AUTO_SWING_P_FINISH_INDEX, index_end);
    sc.SetPersistentInt(_AUTO_SWING_P_DIRECTION, direction);


    sc.SetPersistentInt(_AUTO_SWING_P_LAST_INDEX_LOOPED, index_begin);
    sc.SetPersistentInt(_AUTO_SWING_P_SWING_ACTIVE, index_end);

    sc.SetPersistentInt(_AUTO_SWING_P_NEW_BEGIN_INDEX_REPAINT, index_begin);
    sc.SetPersistentInt(_AUTO_SWING_P_NEW_REVERSAL_BEGIN_INDEX_REPAINT, index_end);

    autoswing_autocolor(sc, current_index, direction);

}

void autoswing_main_iteration_long(SCStudyInterfaceRef sc, int index, float & sg_begin, float & sg_end , float & sg_min_ret, float & sg_entry_ret, float & sg_entry_max, float & sg_stop,  float & sg_limit,  float & sg_new_begin, float & sg_new_end, int & sg_min_acheived, int & sg_direction, float & offset_stop) {
    float _open_prev = sc.RoundToTickSize(sc.Open[index-1]);
    float _close = sc.RoundToTickSize(sc.Close[index]);
    float _low = sc.RoundToTickSize(sc.Low[index]);
    float _high = sc.RoundToTickSize(sc.High[index]);
    int & _index_repaint = sc.GetPersistentInt(_AUTO_SWING_P_NEW_BEGIN_INDEX_REPAINT);
    int & _reversal_repaint = sc.GetPersistentInt(_AUTO_SWING_P_NEW_REVERSAL_BEGIN_INDEX_REPAINT);

    // doing retreacement for the first time
    if ((sg_min_acheived == 0) && (_low <= sg_min_ret)) {
        sg_min_acheived = 1;
        sg_new_begin = _low;
        sg_end = sg_new_end;
        sg_limit = autoswing_limit_calc(sc, sg_direction, sg_begin, sg_end);

        if ( (sc.Input[_AUTO_SWING_I_REPAINT].GetInt() == 1) && (_index_repaint > 0)) {
            for (int i = _index_repaint ; i < index ; i++) {
                sc.Subgraph[_AUTO_SWING_SG_BEGIN][i] = sg_begin;
                sc.Subgraph[_AUTO_SWING_SG_END][i] = sg_end;
                autoswing_autocolor(sc, i, sg_direction);
            }
        }
        _index_repaint = index;
    }

    // doing new highs
    if (_high >= sg_new_end) {
        sg_new_end = _high;
        _reversal_repaint = index;
    }

    // broken high line
    if (_high >= sg_end) {
        if (index > sc.GetPersistentInt(_AUTO_SWING_P_FINISH_INDEX)) {
            sg_end = 0;
        }
    }

    // if swing already did retreacement
    if (sg_min_acheived != 0) {

        // high reached target after retreacement -> new swing
        if (_high >= sg_limit) {
            sg_begin = sg_new_begin;
            sg_stop = sg_begin - offset_stop;
            sg_min_acheived = 0;
        }
        else {
            if (_low < sg_new_begin) {
                sg_new_begin = _low;
                _index_repaint = index;
            }

            int _alert = sc.Input[_AUTO_SWING_I_ALERT].GetInt();
            if (_alert > 0) {
                if ( (index >= (sc.ArraySize-1)) && (sg_entry_ret > 0.0) && (sc.AlertConditionEnabled == 1) && (_close < sg_entry_ret) && (_close > sg_entry_max) && (_close > _open_prev) ) {
                    SCString alert_text = "Long";
                    sc.SetAlert(0, alert_text);

                    if (_alert > 1) {
                        s_SCPositionData position;
                        sc.GetTradePosition(position);
                        if (position.PositionQuantity == 0) {
                            sc.PlaySound(alert_path(sc, alert_text), 1);
                        }
                    }
                }
            }
        }
    }

    // broken swing
    if (_low < sg_stop) {
        float _new_begin = sg_new_end;
        float _new_end = _low;
        sg_min_acheived = 0;
        sg_end = _new_end;
        sg_begin = _new_begin;
        sg_direction = -1;
        sg_limit = autoswing_limit_calc(sc, sg_direction, sg_begin, sg_end);
        sg_stop = sg_begin + offset_stop;
        sg_new_begin = sg_begin;
        sg_new_end = sg_end;
        _index_repaint = _reversal_repaint;


    }
}

void autoswing_main_iteration_short(SCStudyInterfaceRef sc, int index, float & sg_begin, float & sg_end , float & sg_min_ret, float & sg_entry_ret, float & sg_entry_max, float & sg_stop,  float & sg_limit,  float & sg_new_begin, float & sg_new_end, int & sg_min_acheived, int & sg_direction, float & offset_stop) {
    float _open_prev = sc.RoundToTickSize(sc.Open[index-1]);
    float _close = sc.RoundToTickSize(sc.Close[index]);
    float _low = sc.RoundToTickSize(sc.Low[index]);
    float _high = sc.RoundToTickSize(sc.High[index]);
    int & _index_repaint = sc.GetPersistentInt(_AUTO_SWING_P_NEW_BEGIN_INDEX_REPAINT);
    int & _reversal_repaint = sc.GetPersistentInt(_AUTO_SWING_P_NEW_REVERSAL_BEGIN_INDEX_REPAINT);

    // doing retreacement for the first time
    if ( (sg_min_acheived == 0) && (_high >= sg_min_ret) ){
        sg_min_acheived = 1;
        sg_new_begin = _high;
        sg_end = sg_new_end;
        sg_limit = autoswing_limit_calc(sc, sg_direction, sg_begin, sg_end);

        if ( (sc.Input[_AUTO_SWING_I_REPAINT].GetInt() == 1) && (_index_repaint > 0)) {
            for (int i = _index_repaint ; i < index ; i++) {
                sc.Subgraph[_AUTO_SWING_SG_BEGIN][i] = sg_begin;
                sc.Subgraph[_AUTO_SWING_SG_END][i] = sg_end;
                autoswing_autocolor(sc, i, sg_direction);
            }
        }
        _index_repaint = index;

    }

    // doing new lows
    if (_low <= sg_new_end) {
        sg_new_end = _low;
        _reversal_repaint = index;
    }

    // broken high line
    if (_low <= sg_end) {
        if (index > sc.GetPersistentInt(_AUTO_SWING_P_FINISH_INDEX)) {
            sg_end = 0;
        }
    }

    // if swing already did retreacement
    if (sg_min_acheived != 0) {

        // high reached target after retreacement -> new swing
        if (_low <= sg_limit) {
            sg_begin = sg_new_begin;
            sg_stop = sg_begin + offset_stop;
            sg_min_acheived = 0;
        }
        else {
            if (_high > sg_new_begin ) {
                sg_new_begin = _high;
                _index_repaint = index;

            }

            int _alert = sc.Input[_AUTO_SWING_I_ALERT].GetInt();
            if (_alert > 0) {
                if ( (index >= (sc.ArraySize-1)) && (sg_entry_ret > 0.0) && (sc.AlertConditionEnabled == 1) && (_close > sg_entry_ret) && (_close < sg_entry_max) && (_close < _open_prev) ) {
                    SCString alert_text = "Short";
                    sc.SetAlert(0, alert_text);

                    if (_alert > 1) {
                        s_SCPositionData position;
                        sc.GetTradePosition(position);
                        if (position.PositionQuantity == 0) {
                            sc.PlaySound(alert_path(sc, alert_text), 1);
                        }
                    }
                }
            }
        }
    }

    // broken swing
    if (_high > sg_stop) {
        float _new_begin = sg_new_end;
        float _new_end = _high;
        sg_min_acheived = 0;
        sg_end = _new_end;
        sg_begin = _new_begin;
        sg_direction = 1;
        sg_limit = autoswing_limit_calc(sc, sg_direction, sg_begin, sg_end);
        sg_stop  = sg_begin - offset_stop;
        sg_new_begin = sg_begin;
        sg_new_end = sg_end;
        _index_repaint = _reversal_repaint;

    }

}

void autoswing_main_iteration(SCStudyInterfaceRef sc, int index, int prev_index) {

    SCInputRef SwingStart = sc.Input[_AUTO_SWING_I_DATE_TIME_START];
    SCInputRef SwingEnd= sc.Input[_AUTO_SWING_I_DATE_TIME_END];
    int _date_start_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingStart.GetDateTime());

    float _min_ret_fib_value = sc.Input[_AUTO_SWING_I_FIB_MIN].GetFloat();
    int _draw_atr = sc.Input[_AUTO_SWING_I_ATR_DRAW].GetInt();
    int _use_atr_ret = sc.Input[_AUTO_SWING_I_USE_ATR_RET].GetInt();

    if (index ==_date_start_index)
    {
        int _index_begin, _index_end, _third_index, _direction, _length;
        float _price_begin, _price_end, _third_price;
        if (process_new_zone(sc, _index_begin, _index_end, _third_index, _price_begin, _price_end, _third_price, _direction, _length, SwingStart.GetDateTime(), SwingEnd.GetDateTime() ))
        {
            autoswing_initialize_values(sc, index, _index_begin, _index_end, _third_index, _price_begin, _price_end, _third_price, _direction, _length, 1);
        }
    }

    if (index < _date_start_index || index < sc.GetPersistentInt(_AUTO_SWING_P_START_INDEX) || SwingStart.GetTime() == SwingEnd.GetTime()) {
        sc.Subgraph[_AUTO_SWING_SG_BEGIN][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_END][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_MIN_RET][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_RET_END][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_STOP][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_NEW_END][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_LIMIT][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED][index] = 0;
        sc.Subgraph[_AUTO_SWING_SG_DIRECTION][index] = 0;
        return;
    }

    if (index > sc.GetPersistentInt(_AUTO_SWING_P_START_INDEX)) {

        float _sg_begin = sc.Subgraph[_AUTO_SWING_SG_BEGIN][prev_index];
        float _sg_end = sc.Subgraph[_AUTO_SWING_SG_END][prev_index];
        float _sg_min_ret = sc.Subgraph[_AUTO_SWING_SG_MIN_RET][prev_index];
        float _sg_ret_begin = sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN][prev_index];
        float _sg_ret_end = sc.Subgraph[_AUTO_SWING_SG_RET_END][prev_index];
        float _sg_stop = sc.Subgraph[_AUTO_SWING_SG_STOP][prev_index];
        float _sg_limit = sc.Subgraph[_AUTO_SWING_SG_LIMIT][prev_index];
        float _sg_new_begin = sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN][prev_index];
        float _sg_new_end = sc.Subgraph[_AUTO_SWING_SG_NEW_END][prev_index];
        int _sg_min_acheived = sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED][prev_index];
        int _sg_direction = sc.Subgraph[_AUTO_SWING_SG_DIRECTION][prev_index];

        float _offset = sc.Input[_AUTO_SWING_I_TICK_OFFSET].GetInt() * sc.TickSize;

        float _offset_stop = _offset * sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].GetFloat();

        float _previous_begin = _sg_begin;
        //        float _previous_end = _sg_end;

        if (sc.GetPersistentInt(_AUTO_SWING_P_SWING_ACTIVE) >= 1) {

            if (index >= sc.GetPersistentInt(_AUTO_SWING_P_FINISH_INDEX)) {
                autoswing_set_atr_tick_offset(sc, index);

#ifdef _CONST_DEBUG
                {
                    SCString log;
                    sc.AddMessageToLog(log.Format("Current Index:  %d -> Main Iteration: Swing Finish Index %d", sc.Index, sc.GetPersistentInt(_AUTO_SWING_P_FINISH_INDEX)), 1);
                }
#endif

                float max_distance = sc.Input[_AUTO_SWING_I_MAX_DISTANCE].GetFloat();
                if ( (max_distance > 0) && (abs(_sg_begin - _sg_new_end) > (abs(max_distance * _offset)))) {
                    if (_use_atr_ret == 1 && _draw_atr > 0)
                        _sg_min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_MA][index];
                    else
                        _sg_min_ret = calc_fib(sc, sc.Input[_AUTO_SWING_I_FIB_MIN].GetFloat()/1.618, _sg_begin, _sg_new_end);

                }
                else {
                    if (_use_atr_ret == 1 && _draw_atr > 0) {
                        if (sc.Input[_AUTO_SWING_I_ATR_RET_MA].GetInt() == 1)
                            _sg_min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_MA][index];
                        else
                        {
                            if (_sg_direction == 1)
                                _sg_min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM][index];
                            if (_sg_direction == -1)
                                _sg_min_ret = sc.Subgraph[_AUTO_SWING_SG_ATR_TOP][index];
                        }
                    }
                    else
                        _sg_min_ret = calc_fib(sc, _min_ret_fib_value, _sg_begin, _sg_new_end);


                    _sg_ret_begin = calc_fib(sc, sc.Input[_AUTO_SWING_I_FIB_ENTRY].GetFloat(), _sg_begin, _sg_new_end);
                    _sg_ret_end = calc_fib(sc, sc.Input[_AUTO_SWING_I_FIB_MAX].GetFloat(), _sg_begin, _sg_new_end);
                }

                if (_sg_direction == 1)
                    autoswing_main_iteration_long(sc, index, _sg_begin, _sg_end, _sg_min_ret, _sg_ret_begin, _sg_ret_end, _sg_stop, _sg_limit, _sg_new_begin, _sg_new_end, _sg_min_acheived, _sg_direction, _offset_stop);
                else if (_sg_direction == -1)
                    autoswing_main_iteration_short(sc, index, _sg_begin, _sg_end, _sg_min_ret, _sg_ret_begin, _sg_ret_end, _sg_stop, _sg_limit, _sg_new_begin, _sg_new_end, _sg_min_acheived, _sg_direction, _offset_stop);
            }

        }

        sc.Subgraph[_AUTO_SWING_SG_BEGIN][index] = sc.RoundToTickSize(_sg_begin);
        sc.Subgraph[_AUTO_SWING_SG_END][index] = sc.RoundToTickSize(_sg_end);
        sc.Subgraph[_AUTO_SWING_SG_RET_BEGIN][index] = sc.RoundToTickSize(_sg_ret_begin);
        sc.Subgraph[_AUTO_SWING_SG_RET_END][index] = sc.RoundToTickSize(_sg_ret_end);
        sc.Subgraph[_AUTO_SWING_SG_STOP][index] = sc.RoundToTickSize(_sg_stop);
        sc.Subgraph[_AUTO_SWING_SG_LIMIT][index] = sc.RoundToTickSize(_sg_limit);
        sc.Subgraph[_AUTO_SWING_SG_NEW_BEGIN][index] = sc.RoundToTickSize(_sg_new_begin);
        sc.Subgraph[_AUTO_SWING_SG_NEW_END][index] = sc.RoundToTickSize(_sg_new_end);
        sc.Subgraph[_AUTO_SWING_SG_MIN_ACHEIVED][index] = _sg_min_acheived;
        sc.Subgraph[_AUTO_SWING_SG_DIRECTION][index] = _sg_direction;

        if (_min_ret_fib_value == 0.0)
            sc.Subgraph[_AUTO_SWING_SG_MIN_RET][index] = sc.RoundToTickSize(_sg_min_ret);
        else
            sc.Subgraph[_AUTO_SWING_SG_MIN_RET][index] = sc.RoundToTickSize(calc_fib(sc, _min_ret_fib_value, _sg_begin, _sg_new_end));

        autoswing_autocolor(sc, index, _sg_direction);

        //        int & _init_index = sc.GetPersistentInt(_AUTO_SWING_P_NEW_BEGIN_INDEX_REPAINT);
        //        float & _done_repaint = sc.GetPersistentFloat(_AUTO_SWING_P_REPAINT_BEGIN_DONE);
        //        if ( (sc.Input[_AUTO_SWING_I_REPAINT].GetInt() == 1) && (_init_index > 0) && (_sg_begin != _done_repaint) && (_sg_begin > 0.0) && (_sg_end > 0.0)) {
        //            //#ifdef _CONST_DEBUG
        //            {
        //                SCString log;
        //                sc.AddMessageToLog(log.Format("Current Index:  %d -> init_index %d, index: %d, nr bars: %d, begin: %f, previous: %f", sc.Index, _init_index, index, index-_init_index, _sg_begin, _previous_begin), 1);
        //            }
        //            //#endif
        //            for (int i = _init_index ; i <= index ; i++) {
        //                sc.Subgraph[_AUTO_SWING_SG_BEGIN][i] = _sg_begin;
        //                sc.Subgraph[_AUTO_SWING_SG_END][i] = _sg_end;
        //                autoswing_autocolor(sc, i, _sg_direction);
        //            }
        //            _init_index = 0;
        //            _done_repaint = _sg_begin;
        //        }



    }
}

SCSFExport scsf_Auto_Swing(SCStudyInterfaceRef sc)
{

    SCInputRef ButtonON = sc.Input[_AUTO_SWING_I_BUTTON_ON];
    SCInputRef ButtonOFF = sc.Input[_AUTO_SWING_I_BUTTON_OFF];
    SCInputRef SwingStart = sc.Input[_AUTO_SWING_I_DATE_TIME_START];
    SCInputRef SwingEnd= sc.Input[_AUTO_SWING_I_DATE_TIME_END];
    SCInputRef CalcATR= sc.Input[_AUTO_SWING_I_ATR_DRAW];

    int& StateButton = sc.GetPersistentInt(_AUTO_SWING_P_STATE_ACS_BUTTON);
    int& MouseStart = sc.GetPersistentInt(_AUTO_SWING_P_STATE_MOUSE_START);
    int& MouseEnd = sc.GetPersistentInt(_AUTO_SWING_P_STATE_MOUSE_END);
    int& LastIndexLooped = sc.GetPersistentInt(_AUTO_SWING_P_LAST_INDEX_LOOPED);

    sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

    // EVENTS REGION
    if (autoswing_set_defaults(sc))
        return;

    if (sc.Index == 0) {
        std::ifstream file = read_conf(sc);

        if (file) {
            float entry_fib, min_fib, max_fib, atr_mult_limit, atr_mult_stop, multiplier;
            int max_stop_distance, vwap_length, atr_length, ma_type, repaint, show_study, alert, atr_ret_ma, draw_atr, use_atr;
            file >> min_fib >> entry_fib >> max_fib >> max_stop_distance >> atr_mult_limit >> atr_mult_stop >> vwap_length >> atr_length >> ma_type >> multiplier >> atr_ret_ma >> repaint >> show_study >> alert >> use_atr >> draw_atr;

            if (draw_atr == 0 && min_fib == 0.0)
                min_fib = 38.2;

            sc.Input[_AUTO_SWING_I_FIB_MIN].SetFloat(min_fib);
            sc.Input[_AUTO_SWING_I_FIB_ENTRY].SetFloat(entry_fib);
            sc.Input[_AUTO_SWING_I_FIB_MAX].SetFloat(max_fib);
            sc.Input[_AUTO_SWING_I_MAX_DISTANCE].SetInt(max_stop_distance);
            sc.Input[_AUTO_SWING_I_ATR_FIB_LIMIT].SetFloat(atr_mult_limit);
            sc.Input[_AUTO_SWING_I_ATR_MULT_STOP].SetFloat(atr_mult_stop);
            sc.Input[_AUTO_SWING_I_REPAINT].SetInt(repaint);
            sc.Input[_AUTO_SWING_I_ALERT].SetInt(alert);
            sc.Input[_AUTO_SWING_I_ATR_RET_MA].SetInt(atr_ret_ma);
            sc.Input[_AUTO_SWING_I_USE_ATR_RET].SetInt(use_atr);
            sc.Input[_AUTO_SWING_I_ATR_DRAW].SetInt(draw_atr);

            if (show_study == 1)
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 1);
            else
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 0);

            sc.Input[_AUTO_SWING_I_VWAP_LENGTH].SetInt(vwap_length);
            sc.Input[_AUTO_SWING_I_ATR_LENGTH].SetInt(atr_length);
            sc.Input[_AUTO_SWING_I_ATR_TYPE].SetInt(ma_type);
            sc.Input[_AUTO_SWING_I_ATR_MULT].SetFloat(multiplier);

            file.close();
        }
    }

    if (autoswing_skip_iteration(sc))
        return;


    // Remove Trade Management
    int last_call = autoswing_last_call(sc);

    // Calculate VMA if no minimal fib
    if (sc.Input[_AUTO_SWING_I_ATR_DRAW].GetInt() > 0)
    {

//        SCFloatArray atrArray;
//        SCInputRef i_atr = sc.Input[_AUTO_SWING_I_ATR];
//        if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
//            sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE][sc.Index] = atrArray[sc.Index];
//        }
//        else {
            sc.ATR(sc.BaseDataIn, sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE], sc.Input[_AUTO_SWING_I_ATR_LENGTH].GetInt(), sc.Input[_AUTO_SWING_I_ATR_TYPE].GetMovAvgType());
//        }

        sc.VolumeWeightedMovingAverage(sc.BaseDataIn[SC_LAST], sc.Volume, sc.Subgraph[_AUTO_SWING_SG_ATR_MA], sc.Input[_AUTO_SWING_I_VWAP_LENGTH].GetInt());
        sc.Subgraph[_AUTO_SWING_SG_ATR_TOP][sc.Index] = sc.RoundToTickSize(sc.Subgraph[_AUTO_SWING_SG_ATR_MA][sc.Index] + (sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE][sc.Index] * sc.Input[_AUTO_SWING_I_ATR_MULT].GetFloat()));
        sc.Subgraph[_AUTO_SWING_SG_ATR_BOTTOM][sc.Index] = sc.RoundToTickSize(sc.Subgraph[_AUTO_SWING_SG_ATR_MA][sc.Index] - (sc.Subgraph[_AUTO_SWING_SG_ATR_VALUE][sc.Index] * sc.Input[_AUTO_SWING_I_ATR_MULT].GetFloat()));
    }

    // Button Off
    if ((sc.MenuEventID == ButtonOFF.GetInt() && sc.PointerEventType == SC_ACS_BUTTON_ON) || last_call)
    {
        LastIndexLooped = 0;
        SwingStart.SetDateTime(0);
        SwingEnd.SetDateTime(0);
        StateButton = -1;
        sc.SetCustomStudyControlBarButtonEnable(ButtonOFF.GetInt(), 0);
        sc.FlagFullRecalculate = 1;
        return;
    }

    // New Trade Swing
    if (sc.MenuEventID == ButtonON.GetInt() || StateButton == ButtonON.GetInt()) {
        if (tool_range_selection(sc, ButtonON.GetInt(), StateButton, MouseStart, MouseEnd) == 3) {

            SwingStart.SetDateTime(sc.BaseDateTimeIn[MouseStart]);
            SwingEnd.SetDateTime(sc.BaseDateTimeIn[MouseEnd]);
            sc.FlagFullRecalculate = 1;

            /* #ifdef _CONST_DEBUG
            {
                int _date_start_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingStart.GetDateTime());
                int _date_end_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, SwingEnd.GetDateTime());

                SCString log;
                sc.AddMessageToLog(log.Format("MouseStart: %d, MouseEnd: %d, SwingStart: %d, SwingEnd: %d, converted Start: %d, converted End: %d", MouseStart, MouseEnd, SwingStart.GetDateTime().GetTime(), SwingEnd.GetDateTime().GetTime(), _date_start_index, _date_end_index ), 1);
            }
#endif */
            StateButton = -1;
        }

        return;
    }

    // Main Iteration
    if (LastIndexLooped == sc.Index)
        return;

    int prev_index = sc.Index-1;

    autoswing_main_iteration(sc, sc.Index, prev_index);
    sc.SetPersistentInt(_AUTO_SWING_P_LAST_INDEX_LOOPED, sc.Index);

}
