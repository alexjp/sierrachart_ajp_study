#include "main.h"
#include "lib.h"

int const _I_TOOL_ATR = 0;
int const _I_TOOL_ATR_MULT = 1;
int const _I_TOOL_SWING_START = 2;
int const _I_TOOL_SWING_START_ALT = 3;
int const _I_TOOL_SWING_REMOVE = 4;
int const _I_TOOL_CLEAN = 5;
int const _I_TOOL_AUTO = 6;
int const _I_TOOL_VBP_NAME = 7;
int const _I_TOOL_SWING_START_END = 8;
int const _I_TOOL_LVTI_NAME = 9;
int const _I_TOOL_VOL = 10;
int const _I_TOOL_VOL_MULT = 11;

void zone_swing_set_defaults(SCStudyInterfaceRef sc)
{

	sc.GraphName = "Swing Zone Trade Zone";
	sc.StudyDescription = "Swing Zone Trade Zone";

	sc.Input[_I_TOOL_SWING_START].Name = "Key Start Drawing Swing";
	sc.Input[_I_TOOL_SWING_START].SetInt(3);

	sc.Input[_I_TOOL_SWING_REMOVE].Name = "Key Remove Drawing Swing";
	sc.Input[_I_TOOL_SWING_REMOVE].SetInt(16);

	sc.Input[_I_TOOL_SWING_START_END].Name = "Key Change End Drawing Swing";
	sc.Input[_I_TOOL_SWING_START_END].SetInt(4);

	sc.Input[_I_TOOL_CLEAN].Name = "Key Clean Drawings";
	sc.Input[_I_TOOL_CLEAN].SetInt(4);

	sc.Input[_I_TOOL_AUTO].Name = "Key Auto Drawing";
	sc.Input[_I_TOOL_AUTO].SetInt(1);

	sc.Input[_I_TOOL_VBP_NAME].Name = "VbP study short name";
	sc.Input[_I_TOOL_VBP_NAME].SetString("volumebyprice");

	sc.Input[_I_TOOL_ATR].Name = "ATR";
	sc.Input[_I_TOOL_ATR].SetInt(0);

	sc.Input[_I_TOOL_ATR_MULT].Name = "ATR Mult";
	sc.Input[_I_TOOL_ATR_MULT].SetFloat(0);

    sc.Input[_I_TOOL_LVTI_NAME].Name = "Large Volume Trade I. study short name";
    sc.Input[_I_TOOL_LVTI_NAME].SetString("lvti");

    sc.Input[_I_TOOL_VOL].Name = "Volume";
    sc.Input[_I_TOOL_VOL].SetInt(0);

    sc.Input[_I_TOOL_VOL_MULT].Name = "Volume Mult";
    sc.Input[_I_TOOL_VOL_MULT].SetFloat(0);

	sc.GraphRegion = 0;
	//    sc.FreeDLL = _CONST_FREEDLL;
	sc.AutoLoop = 0;
	sc.ScaleRangeType = SCALE_SAMEASREGION;
	sc.DrawStudyUnderneathMainPriceGraph = 1;

}

int zone_swing_skip_iteration(SCStudyInterfaceRef sc)
{
	if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.IsFullRecalculation || sc.DownloadingHistoricalData)
		return 1;

	return 0;
}

int zone_swing_last_call(SCStudyInterfaceRef sc)
{
	if (!sc.LastCallToFunction)
		return 0;
	return 1;
}

void zone_swing_clear(SCStudyInterfaceRef sc, int IndexBegin, int IndexEnd) {
	int _max = 50; //sc.GetACSDrawingsCount(sc.ChartNumber, 0);

#ifdef _CONST_DEBUG
	SCString log;
	sc.AddMessageToLog(log.Format("_max: %d", _max), 1);
#endif
	s_UseTool _chart;
	for (int _index = 0; _index <= _max; _index++) {
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog(log.Format("_max: %d, _index: %d", _max, _index), 1);
#endif

		if (sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_UNKNOWN, _chart, _index) > 0) {
#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog(log.Format("Locked: %d, IndexBegin: %d, IndexEnd: %d      BeginIndex: %d", _chart.LockDrawing, IndexBegin, IndexEnd, _chart.BeginIndex), 1);
#endif
			if (_chart.BeginIndex >= IndexBegin && _chart.BeginIndex <= IndexEnd && _chart.LockDrawing == 0) {
				sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, _chart.LineNumber);
				_index = -1;
				//_max = 20; //sc.GetACSDrawingsCount(sc.ChartNumber, 0);
			}
		}
		else _index = _max + 1;
	}
}

void zone_swing_tool_remove(SCStudyInterfaceRef sc) {

	//    if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TOOL_DRAWING_RETM) > 0) {
	//        sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TOOL_DRAWING_RETM);
	//    }
	//    if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TOOL_DRAWING_RETG) > 0) {
	//        sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TOOL_DRAWING_RETG);
	//    }
	if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TOOL_DRAWING_BEGIN) > 0) {
		sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TOOL_DRAWING_BEGIN);
	}
	if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TOOL_DRAWING_END) > 0) {
		sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TOOL_DRAWING_END);
	}
	//    if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TOOL_DRAWING_ARROW) > 0) {
	//        sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TOOL_DRAWING_ARROW);
	//    }

	SCString study_name;


		int study = sc.GetStudyIDByName(sc.ChartNumber, study_name.Format("%s", sc.Input[_I_TOOL_VBP_NAME].GetString()), 1);
		if (study > 0) {			
			//sc.SetChartStudyInputInt(sc.ChartNumber, study, 43, 10);
			//sc.SetChartStudyInputInt(sc.ChartNumber, study, 42, 1);
			sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 9);
			sc.SetChartStudyInputFloat(sc.ChartNumber, study, 35, 1);
			sc.SetStudyVisibilityState(study, 0);
		}
		sc.RecalculateChart(sc.ChartNumber);

}


/*==========================================================================*/
SCSFExport scsf_SwingZone_Zone(SCStudyInterfaceRef sc)
{

	int& OrderType = sc.GetPersistentInt(1);
	float& BeginPrice = sc.GetPersistentFloat(2);
	float& EndPrice = sc.GetPersistentFloat(3);
	int& IndexBegin = sc.GetPersistentInt(4);
	int& IndexEnd = sc.GetPersistentInt(5);
	int& Length = sc.GetPersistentInt(6);
	float& GoldenMean = sc.GetPersistentFloat(7);
	int& ThirdIndex = sc.GetPersistentInt(8);
	float& ThirdPrice = sc.GetPersistentFloat(9);
	SCInputRef ATR = sc.Input[_I_TOOL_ATR];
	SCInputRef ATRMult = sc.Input[_I_TOOL_ATR_MULT];

    SCInputRef VOL = sc.Input[_I_TOOL_VOL];
    SCInputRef VOLMult = sc.Input[_I_TOOL_VOL_MULT];

	int& ACS_BUTTON_ZONE_STATE_3 = sc.GetPersistentInt(40);
	int& ACS_BUTTON_ZONE_STATE = sc.GetPersistentInt(41);
	int& MouseStart = sc.GetPersistentInt(33);
	int& MouseEnd = sc.GetPersistentInt(34);

	sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;

	if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif



		SCString atr_path;

		std::ifstream atr_input(atr_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "atr"));

		if (atr_input.is_open()) {
			int atr;
			atr_input >> atr;
			ATR.SetInt(atr);
			atr_input.close();
		}

        SCString vol_path;

        std::ifstream vol_input(vol_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "volume"));

        if (vol_input.is_open()) {
            int vol;
            vol_input >> vol;
            VOL.SetInt(vol);
            vol_input.close();
        }

        int study = 0;
        SCString study_name;

        study_name = study_name.Format("%s", sc.Input[_I_TOOL_LVTI_NAME].GetString());
        study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);

        int volume = static_cast<int>(VOL.GetInt() * VOLMult.GetFloat());

        if (study > 0 && volume > 0) {
            int old_volume = 0;
            sc.GetChartStudyInputInt(sc.ChartNumber, study, 0, old_volume);
#ifdef _CONST_DEBUG
            SCString log;
            sc.AddMessageToLog(log.Format("Volume LVTI => Old: %d, New: %d", old_volume, volume), 0);
#endif
            if (volume != old_volume)
            {
#ifdef _CONST_DEBUG
                SCString log;
                sc.AddMessageToLog(log.Format("Applying volume: %d", volume), 0);
#endif
                sc.SetChartStudyInputInt(sc.ChartNumber, study, 0, volume);
            }
        }
	}


	if (sc.SetDefaults) {
		zone_swing_set_defaults(sc);
		return;
	}

	if (zone_swing_last_call(sc))
		return;

	if (zone_swing_skip_iteration(sc))
		return;

	// Clear Swing tools suite
	if (sc.MenuEventID == sc.Input[_I_TOOL_SWING_REMOVE].GetInt() && sc.PointerEventType == SC_ACS_BUTTON_ON)
	{
#ifdef _CONST_DEBUG
		{
			SCString log;
			sc.AddMessageToLog(log.Format("Removing Swing Tool Drawings"), 0);
		}
#endif
		zone_swing_tool_remove(sc);
		sc.SetCustomStudyControlBarButtonEnable(sc.Input[_I_TOOL_SWING_REMOVE].GetInt(), 0);


	}

	if (sc.Input[_I_TOOL_SWING_START_END].GetInt() != 0 && (sc.MenuEventID == sc.Input[_I_TOOL_SWING_START_END].GetInt() || ACS_BUTTON_ZONE_STATE_3 == sc.Input[_I_TOOL_SWING_START_END].GetInt())) {
		if (sc.PointerEventType == SC_ACS_BUTTON_ON) {
			MouseEnd = -1;
		}
		if (tool_index_selection(sc, sc.MenuEventID, ACS_BUTTON_ZONE_STATE_3, MouseEnd) == 3) {

            int study = 0;
			double date, time;
			SCString study_name;

//			int study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);

//			if (study <= 0) {
				study_name = study_name.Format("%s", sc.Input[_I_TOOL_VBP_NAME].GetString());
				study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);
//			}

			if (study > 0) {
				int _end = 0;
				_end = MouseEnd;
				//sc.SetChartStudyInputInt(sc.ChartNumber, study, 42, 1);
				//sc.SetChartStudyInputInt(sc.ChartNumber, study, 43, 10);

                time = std::modf(sc.GetEndingDateTimeForBarIndex(_end).GetAsDouble(), &date);

                sc.SetChartStudyInputFloat(sc.ChartNumber, study, 39, date);
				sc.SetChartStudyInputFloat(sc.ChartNumber, study, 40, time);


				if (MouseEnd > sc.ArraySize || MouseEnd == MouseStart) {
					sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 5);
				}
				else {
					sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 8);
				}

				sc.SetStudyVisibilityState(study, 1);
				sc.RecalculateChart(sc.ChartNumber);
			}
			ACS_BUTTON_ZONE_STATE_3 = -1;
		}
		return;
	}



	// Draw Swing tools suite
	if (sc.Input[_I_TOOL_SWING_START].GetInt() != 0 && (sc.MenuEventID == sc.Input[_I_TOOL_SWING_START].GetInt() || ACS_BUTTON_ZONE_STATE_3 == sc.Input[_I_TOOL_SWING_START].GetInt())) {
		if (sc.PointerEventType == SC_ACS_BUTTON_ON) {
			MouseStart = -1;
			MouseEnd = -1;
		}

		if (tool_range_selection(sc, sc.MenuEventID, ACS_BUTTON_ZONE_STATE_3, MouseStart, MouseEnd) == 3) {

			double date, time;
			SCString study_name;

			int study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);

			if (study <= 0) {
				study_name = study_name.Format("%s", sc.Input[_I_TOOL_VBP_NAME].GetString());
				study = sc.GetStudyIDByName(sc.ChartNumber, study_name, 1);
			}

			if (study > 0) {
				int _begin, _end = 0;			
				_begin = MouseStart;
				_end = MouseEnd;
				//sc.SetChartStudyInputInt(sc.ChartNumber, study, 42, 1);
				//sc.SetChartStudyInputInt(sc.ChartNumber, study, 43, 10);

				time = std::modf(sc.GetEndingDateTimeForBarIndex(_begin).GetAsDouble(), &date);
				sc.SetChartStudyInputFloat(sc.ChartNumber, study, 36, date);
				sc.SetChartStudyInputFloat(sc.ChartNumber, study, 38, time);

				time = std::modf(sc.GetEndingDateTimeForBarIndex(_end).GetAsDouble(), &date);
                sc.SetChartStudyInputFloat(sc.ChartNumber, study, 39, date);
				sc.SetChartStudyInputFloat(sc.ChartNumber, study, 40, time);

                if (MouseEnd > sc.ArraySize || MouseEnd == MouseStart) {
					sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 5);
				}
				else {
					sc.SetChartStudyInputFloat(sc.ChartNumber, study, 32, 8);
				}

				sc.SetStudyVisibilityState(study, 1);
				sc.RecalculateChart(sc.ChartNumber);
			}
			ACS_BUTTON_ZONE_STATE_3 = -1;
		}
		return;
	}

	// Clear Selected tools
	if (sc.MenuEventID == sc.Input[_I_TOOL_CLEAN].GetInt() || ACS_BUTTON_ZONE_STATE == sc.Input[_I_TOOL_CLEAN].GetInt()) {
		if (sc.PointerEventType == SC_ACS_BUTTON_ON) {
			MouseStart = -1;
			MouseEnd = -1;
		}
		if (tool_range_selection(sc, sc.MenuEventID, ACS_BUTTON_ZONE_STATE, MouseStart, MouseEnd) == 3) {
			//if (tool_range_selection(sc, sc.Input[_I_TOOL_CLEAN].GetInt(), ACS_BUTTON_ZONE_STATE, MouseStart, MouseEnd) == 3) {
			//process_new_mouse_zone(sc, IndexBegin, IndexEnd, BeginPrice, EndPrice, GoldenMean, OrderType, Length, MouseStart, MouseEnd);
			zone_swing_clear(sc, MouseStart, MouseEnd);
			ACS_BUTTON_ZONE_STATE = -1;
		}
		return;
	}

	// Update tool to highest and lowest swing values
	if (sc.MenuEventID == sc.Input[_I_TOOL_AUTO].GetInt() && sc.PointerEventType == SC_ACS_BUTTON_ON)
	{
		sc.SetCustomStudyControlBarButtonEnable(sc.Input[_I_TOOL_AUTO].GetInt(), 0);

		s_UseTool _chartDrawing;
		int drawing = sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_UNKNOWN, _chartDrawing, -1);

		if (drawing && _chartDrawing.Color == color_select_tool && (_chartDrawing.DrawingType == DRAWING_RETRACEMENT || _chartDrawing.DrawingType == DRAWING_PRICE_EXPANSION || _chartDrawing.DrawingType == DRAWING_PRICE_PROJECTION || _chartDrawing.DrawingType == DRAWING_ARROW || _chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT || _chartDrawing.DrawingType == DRAWING_CALCULATOR || _chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT))
			//if (drawing && (_chartDrawing.DrawingType == DRAWING_RETRACEMENT || _chartDrawing.DrawingType == DRAWING_PRICE_EXPANSION || _chartDrawing.DrawingType == DRAWING_PRICE_PROJECTION || _chartDrawing.DrawingType == DRAWING_ARROW || _chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT || _chartDrawing.DrawingType == DRAWING_CALCULATOR))
		{

			drawing = process_new_drawing(sc, IndexBegin, IndexEnd, ThirdIndex, BeginPrice, EndPrice, ThirdPrice, GoldenMean, OrderType, Length, _chartDrawing.DrawingType, _chartDrawing, 1);

			if (drawing)
			{
				float _last_price = sc.Close[sc.Index];

				s_UseTool _clonedDrawing;
				int toolconfig = OrderType == 1 ? 2 : OrderType == -1 ? 3 : 0;
				int line_number = _chartDrawing.LineNumber;
				int _updown = toolconfig + OrderType;

				if (_chartDrawing.DrawingType == DRAWING_ARROW || _chartDrawing.DrawingType == DRAWING_CALCULATOR || _chartDrawing.DrawingType == DRAWING_RETRACEMENT) {
					if (_chartDrawing.LineWidth == 1)
						toolconfig = toolconfig + 5;
				}

				if (_chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT)
				{
					float start_point = 0;
					float end_point = 0;

					if (ATR.GetInt() > 0 && ATRMult.GetFloat() > 0) {
						float price_change = ((ATR.GetInt() * ATRMult.GetFloat()) * sc.TickSize);
						start_point = BeginPrice;
						end_point = BeginPrice + ((OrderType * 1) * price_change);
						//_updown = toolconfig;
						_updown = (_last_price < end_point) ? 3 : (_last_price > start_point) ? 2 : _updown;
					}
					else {
						start_point = calc_fib(sc, 23.6, EndPrice, BeginPrice);
						end_point = calc_fib(sc, 78.6, EndPrice, BeginPrice);
						_updown = (_last_price < end_point) ? 3 : (_last_price > start_point) ? 2 : _updown;
					}


					create_clone_drawing(sc, IndexBegin, IndexEnd + 1, ThirdIndex, start_point, end_point, ThirdPrice, GoldenMean, OrderType, Length, _chartDrawing.DrawingType, _updown, line_number, _clonedDrawing);

					//create_clone_drawing(sc, ThirdIndex, IndexEnd, IndexBegin, calc_fib(sc, 100, ThirdPrice, EndPrice), calc_fib(sc, 61.8, BeginPrice, EndPrice), BeginPrice, GoldenMean, OrderType, Length, _chartDrawing.DrawingType, toolconfig, line_number, _clonedDrawing);

					//create_clone_drawing(sc, IndexBegin + 1, IndexEnd + 3, ThirdIndex, calc_fib(sc, 78.6, BeginPrice, EndPrice), calc_fib(sc, 113, BeginPrice, EndPrice), ThirdPrice, GoldenMean, OrderType, Length, _chartDrawing.DrawingType, toolconfig, line_number, _clonedDrawing);

				}
				else {
					create_clone_drawing(sc, IndexBegin, IndexEnd, ThirdIndex, BeginPrice, EndPrice, ThirdPrice, GoldenMean, OrderType, Length, _chartDrawing.DrawingType, toolconfig, line_number, _clonedDrawing);
				}

				sc.UseTool(_clonedDrawing);

			}
		}
		return;
	}

}
