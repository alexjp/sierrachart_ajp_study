#include "sc_swing.h"

void swing_set_defaults(SCStudyInterfaceRef sc) {

	sc.GraphName = "Swing Management";
	sc.StudyDescription = "Swing Management";

	sc.Input[_MAX_STOP_DISTANCE].Name = "Maximum Stop Distance in Currency";
	sc.Input[_MAX_STOP_DISTANCE].SetInt(10);

	sc.Input[_CURRENCY].Name = "Currency";
	sc.Input[_CURRENCY].SetString("EUR");

	sc.Input[_ENTRY_FIB].Name = "Entry Fib";
	sc.Input[_ENTRY_FIB].SetFloat(61.8);

	sc.Input[_TARGET_FIB].Name = "Target Fib";
	sc.Input[_TARGET_FIB].SetFloat(-27.2);

	sc.Input[_STOP_FIB_LEVEL].Name = "Stop Fib level";
	sc.Input[_STOP_FIB_LEVEL].SetFloat(100);

	sc.Input[_STOP_OFFSET].Name = "Stop Offset in Ticks";
	sc.Input[_STOP_OFFSET].SetInt(10);

	sc.Input[_HSPACE].Name = "Horizontal Space";
	sc.Input[_HSPACE].SetInt(-10);

	sc.Input[_VSPACE].Name = "Vertical Align";
	sc.Input[_VSPACE].SetInt(-2);

	sc.Input[_MIN_RR].Name = "Minimum RR";
	sc.Input[_MIN_RR].SetFloat(1.618);

	sc.Input[_FONT_SIZE].Name = "Font Size";
	sc.Input[_FONT_SIZE].SetInt(10);

	sc.Subgraph[_LONG_TRADE].Name = "Trade Long Possivel";
	sc.Subgraph[_LONG_TRADE].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_SHORT_TRADE].Name = "Trade Short Possivel";
	sc.Subgraph[_SHORT_TRADE].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_INDEX_BEGIN].Name = "_INDEX_BEGIN";
	sc.Subgraph[_INDEX_BEGIN].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_INDEX_END].Name = "_INDEX_END";
	sc.Subgraph[_INDEX_END].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_SG_PRICE_BEGIN].Name = "_PRICE_BEGIN";
	sc.Subgraph[_SG_PRICE_BEGIN].DrawStyle = DRAWSTYLE_DASH;
	sc.Subgraph[_SG_PRICE_BEGIN].PrimaryColor = color_bear;
	sc.Subgraph[_SG_PRICE_BEGIN].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_PRICE_BEGIN].LineWidth = 2;
	sc.Subgraph[_SG_PRICE_BEGIN].ShortName = "Swing Start";

	sc.Subgraph[_SG_PRICE_END].Name = "_PRICE_END";
	sc.Subgraph[_SG_PRICE_END].DrawStyle = DRAWSTYLE_DASH;
	sc.Subgraph[_SG_PRICE_END].PrimaryColor = color_success;
	sc.Subgraph[_SG_PRICE_END].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_PRICE_END].LineWidth = 2;
	sc.Subgraph[_SG_PRICE_END].ShortName = "Swing End";

	sc.Subgraph[_SG_PRICE_THIRD].Name = "_PRICE_THIRD";
	sc.Subgraph[_SG_PRICE_THIRD].DrawStyle = DRAWSTYLE_DASH;
	sc.Subgraph[_SG_PRICE_THIRD].PrimaryColor = color_success;
	sc.Subgraph[_SG_PRICE_THIRD].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_PRICE_THIRD].LineWidth = 2;
	sc.Subgraph[_SG_PRICE_THIRD].ShortName = "Swing End";

	sc.Subgraph[_STOP_PRICE].Name = "_STOP_PRICE";
	sc.Subgraph[_STOP_PRICE].DrawStyle = DRAWSTYLE_DASH;
	sc.Subgraph[_STOP_PRICE].PrimaryColor = color_bull;
	sc.Subgraph[_STOP_PRICE].DisplayNameValueInWindowsFlags = 1;
	sc.Subgraph[_STOP_PRICE].LineWidth = 2;
	sc.Subgraph[_STOP_PRICE].ShortName = "Stop";

	sc.Subgraph[_TARGET_PRICE].Name = "_TARGET_PRICE";
	sc.Subgraph[_TARGET_PRICE].DrawStyle = DRAWSTYLE_DASH;
	sc.Subgraph[_TARGET_PRICE].PrimaryColor = color_success;
	sc.Subgraph[_TARGET_PRICE].DisplayNameValueInWindowsFlags = 1;
	sc.Subgraph[_TARGET_PRICE].LineWidth = 2;
	sc.Subgraph[_TARGET_PRICE].ShortName = "Target";

	sc.Subgraph[_CURRENCY_STOP].Name = "Stop Distance in Currency";
	sc.Subgraph[_CURRENCY_STOP].DrawStyle =
		DRAWSTYLE_SUBGRAPH_NAME_AND_VALUES_ONLY;
	sc.Subgraph[_CURRENCY_STOP].PrimaryColor = color_bad;
	// sc.Subgraph[_CURRENCY_STOP].DisplayNameValueInWindowsFlags = 1;
	sc.Subgraph[_CURRENCY_STOP].ShortName = "StopLoss";
	// sc.Subgraph[_CURRENCY_STOP].LineWidth = 11;
	// sc.Subgraph[_CURRENCY_STOP].GraphicalDisplacement = 10;

	sc.Subgraph[_CURRENCY_TARGET].Name = "Target Distance in Currency";
	sc.Subgraph[_CURRENCY_TARGET].DrawStyle =
		DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
	sc.Subgraph[_CURRENCY_TARGET].PrimaryColor = color_success;
	// sc.Subgraph[_CURRENCY_TARGET].DisplayNameValueInWindowsFlags = 1;
	sc.Subgraph[_CURRENCY_TARGET].ShortName = "Profit";
	// sc.Subgraph[_CURRENCY_TARGET].LineWidth = 11;
	// sc.Subgraph[_CURRENCY_TARGET].GraphicalDisplacement = 10;

	sc.Subgraph[_RR].Name = "Risk/Reward";
	sc.Subgraph[_RR].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
	sc.Subgraph[_RR].PrimaryColor = color_success;
	// sc.Subgraph[_RR].DisplayNameValueInWindowsFlags = 1;
	sc.Subgraph[_RR].ShortName = "R/R";
	// sc.Subgraph[_RR].LineWidth = 11;
	// sc.Subgraph[_RR].GraphicalDisplacement = 10;

	sc.Subgraph[_FIB_ENTRY].Name = "_FIB_ENTRY";
	sc.Subgraph[_FIB_ENTRY].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_ACTIVE].Name = "_ACTIVE";
	sc.Subgraph[_ACTIVE].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_DIRECTION].Name = "_DIRECTION";
	sc.Subgraph[_DIRECTION].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_LENGTH].Name = "_LENGTH";
	sc.Subgraph[_LENGTH].DrawStyle = DRAWSTYLE_IGNORE;

	sc.Subgraph[_AREA_TOP].Name = "_AREA_TOP";
	sc.Subgraph[_AREA_TOP].DrawStyle = DRAWSTYLE_FILLRECTTOP_TRANSPARENT;
	sc.Subgraph[_AREA_TOP].PrimaryColor = color_bull;
	sc.Subgraph[_AREA_TOP].DisplayNameValueInWindowsFlags = 0;
	// sc.Subgraph[_AREA_TOP].SecondaryColor = color_bear;
	// sc.Subgraph[_AREA_TOP].SecondaryColorUsed = true;
	// sc.Subgraph[_AREA_TOP].AutoColoring = true;

	sc.Subgraph[_AREA_BOTTOM].Name = "_AREA_BOTTOM";
	sc.Subgraph[_AREA_BOTTOM].DrawStyle = DRAWSTYLE_FILLRECTBOTTOM_TRANSPARENT;
	sc.Subgraph[_AREA_BOTTOM].PrimaryColor = color_bear;
	sc.Subgraph[_AREA_BOTTOM].DisplayNameValueInWindowsFlags = 0;
	// sc.Subgraph[_AREA_BOTTOM].SecondaryColor = color_bear;
	// sc.Subgraph[_AREA_BOTTOM].SecondaryColorUsed = true;
	// sc.Subgraph[_AREA_BOTTOM].AutoColoring = true;

	sc.Input[_I_SWING_REAL_SIMULATION].Name = "Real=1/ Sim=0 Account";
	sc.Input[_I_SWING_REAL_SIMULATION].SetInt(1);

	sc.Input[_I_BUTTON_ON].Name = "Button Activate";
	sc.Input[_I_BUTTON_ON].SetInt(0);

	sc.Input[_I_BUTTON_ON_ALT].Name = "Button Activate (alternative by drawing)";
	sc.Input[_I_BUTTON_ON_ALT].SetInt(0);

	sc.Input[_I_BUTTON_TOOGLE_HIDE].Name = "Button RR Tool Visibility";
	sc.Input[_I_BUTTON_TOOGLE_HIDE].SetInt(0);

	sc.Input[_I_BUTTON_OFF].Name = "Button Deactivate";
	sc.Input[_I_BUTTON_OFF].SetInt(10);

	sc.Input[_I_ATR].Name = "External ATR";
	sc.Input[_I_ATR].SetStudySubgraphValues(1, 16);

	sc.Input[_I_ATR_MULT].Name = "ATR Multiplier";
	sc.Input[_I_ATR_MULT].SetFloat(1);

	sc.Input[_I_PREV_SWING_HL_STOP_FIB].Name = "Stop Fib for Previous Swing HL";
	sc.Input[_I_PREV_SWING_HL_STOP_FIB].SetFloat(38.2);

	sc.Input[_I_SWING_USE_EXT_ATR].Name = "Use External ATR Study";
	sc.Input[_I_SWING_USE_EXT_ATR].SetInt(1);

	sc.Input[_I_TICKSIZE_MULTIPLIER].Name = "Ticksize Multiplier";
	sc.Input[_I_TICKSIZE_MULTIPLIER].SetInt(1);

	sc.Input[_I_SWING_PREVIOUS_SWING_HIGH_LOW].Name = "Use Previous Swing High/Low";
	sc.Input[_I_SWING_PREVIOUS_SWING_HIGH_LOW].SetInt(0);

	sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].Name = "Use Previous Swing High/Low ATR Detector offset Multiplier";
	sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].SetFloat(1);

	sc.GraphRegion = 0;
	sc.AutoLoop = 1;
	sc.ScaleRangeType = SCALE_SAMEASREGION;
	sc.DrawStudyUnderneathMainPriceGraph = 1;
	sc.DisplayStudyInputValues = 0;
	sc.DisplayStudyName = 0;
	sc.TransparencyLevel = 90;


}

int swing_skip_iteration(SCStudyInterfaceRef sc) {
	if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) ||
		sc.DownloadingHistoricalData)
		return 1;
	return 0;
}

int swing_last_call(SCStudyInterfaceRef sc) {
	if (!sc.LastCallToFunction)
		return 0;

	return 1;
}

int broke_stop(SCStudyInterfaceRef sc, int index) {
	if (sc.GetPersistentInt(_P_DIRECTION) == 1 &&
		sc.Low[index] < sc.GetPersistentFloat(_P_STOP_PRICE))
		return 1;
	if (sc.GetPersistentInt(_P_DIRECTION) == -1 &&
		sc.High[index] > sc.GetPersistentFloat(_P_STOP_PRICE))
		return 1;
	return 0;
}

int long_trade(SCStudyInterfaceRef sc, int index) {
	if (sc.GetPersistentInt(_P_INDEX_END) < index &&
		sc.GetPersistentInt(_P_DIRECTION) == 1 &&
		sc.Close[index] < sc.GetPersistentFloat(_P_FIB_ENTRY))
		return 1;
	return 0;
}

int short_trade(SCStudyInterfaceRef sc, int index) {
	if (sc.GetPersistentInt(_P_INDEX_END) < index &&
		sc.GetPersistentInt(_P_DIRECTION) == -1 &&
		sc.Close[index] > sc.GetPersistentFloat(_P_FIB_ENTRY))
		return 1;
	return 0;
}

void update_empty_index_values(SCStudyInterfaceRef sc, int index) {
	sc.Subgraph[_INDEX_BEGIN][index] = 0;
	sc.Subgraph[_INDEX_END][index] = 0;
	sc.Subgraph[_SG_PRICE_BEGIN][index] = 0;
	sc.Subgraph[_SG_PRICE_END][index] = 0;
	sc.Subgraph[_SG_PRICE_THIRD][index] = 0;
	sc.Subgraph[_DIRECTION][index] = 0;
	sc.Subgraph[_LENGTH][index] = 0;
	sc.Subgraph[_ACTIVE][index] = 0;
	sc.Subgraph[_STOP_PRICE][index] = 0;
	sc.Subgraph[_TARGET_PRICE][index] = 0;
	sc.Subgraph[_AREA_TOP][index] = 0;
	sc.Subgraph[_AREA_BOTTOM][index] = 0;
	sc.Subgraph[_FIB_ENTRY][index] = 0;
	sc.Subgraph[_LONG_TRADE][index] = 0;
	sc.Subgraph[_SHORT_TRADE][index] = 0;
	sc.Subgraph[_CURRENCY_STOP][index] = 0;

	sc.Subgraph[_CURRENCY_TARGET][index] = 0;
	sc.Subgraph[_CURRENCY_STOP][index] = 0;
	sc.Subgraph[_RR][index] = 0;
}

void update_index_values(SCStudyInterfaceRef sc, int index) {
	sc.Subgraph[_INDEX_BEGIN][index] = sc.GetPersistentInt(_P_INDEX_BEGIN);
	sc.Subgraph[_INDEX_END][index] = sc.GetPersistentInt(_P_INDEX_END);
	sc.Subgraph[_SG_PRICE_BEGIN][index] = sc.GetPersistentFloat(_P_PRICE_BEGIN);
	sc.Subgraph[_SG_PRICE_END][index] = sc.GetPersistentFloat(_P_PRICE_END);
	sc.Subgraph[_SG_PRICE_THIRD][index] = sc.GetPersistentFloat(_P_PRICE_THIRD);
	sc.Subgraph[_DIRECTION][index] = sc.GetPersistentInt(_P_DIRECTION);
	sc.Subgraph[_LENGTH][index] = sc.GetPersistentInt(_P_LENGTH);
	sc.Subgraph[_ACTIVE][index] = sc.GetPersistentInt(_P_ACTIVE);
	sc.Subgraph[_STOP_PRICE][index] = sc.GetPersistentFloat(_P_STOP_PRICE);
	sc.Subgraph[_TARGET_PRICE][index] = sc.GetPersistentFloat(_P_TARGET_PRICE);
	sc.Subgraph[_AREA_TOP][index] = sc.GetPersistentFloat(_P_AREA_TOP);
	sc.Subgraph[_AREA_BOTTOM][index] = sc.GetPersistentFloat(_P_AREA_BOTTOM);
	sc.Subgraph[_FIB_ENTRY][index] = sc.GetPersistentFloat(_P_FIB_ENTRY);
	sc.Subgraph[_LONG_TRADE][index] = long_trade(sc, index);
	sc.Subgraph[_SHORT_TRADE][index] = short_trade(sc, index);
}

void sc_swing_update_orders(SCStudyInterfaceRef sc, int index, s_SCPositionData &position) {
	float tick = sc.TickSize;
	//    float _last_price = sc.Close[index];
	int &StopInit = sc.GetPersistentInt(_P_STOP_INITIAL);
	int &TargetInit = sc.GetPersistentInt(_P_TARGET_INITIAL);

	std::pair<int, s_SCTradeOrder> find_stop = lib_trade_find_stop(sc);
	if (find_stop.first == 1) {
		s_SCTradeOrder _stop = find_stop.second;
		float _stop_price = sc.GetPersistentFloat(_P_STOP_PRICE);

		if (StopInit == 1 || ((position.PositionQuantity > 0 && _stop.Price1 < (_stop_price - tick)) || (position.PositionQuantity < 0 && _stop.Price1 >(_stop_price + tick)))) {

#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog(log.Format("Trying to move Stop from: %f to %f", _stop.Price1, _stop_price), 1);
#endif
			std::pair<int, s_SCNewOrder> modify_order = lib_trade_modify_stop(sc, index, position.PositionQuantity, _stop, tick, _stop_price, StopInit);
			//            if (modify_order.first == 1 && StopInit == 1)
			if (StopInit == 1)
				StopInit = 0;
		}
}

	std::pair<int, s_SCTradeOrder> find_target = lib_trade_find_target(sc);
	if (find_target.first == 1) {
		s_SCTradeOrder _target = find_target.second;
		float _target_price = sc.GetPersistentFloat(_P_TARGET_PRICE);

		if (TargetInit == 1 || ((position.PositionQuantity > 0 && _target.Price1 < (_target_price - tick)) || (position.PositionQuantity < 0 && _target.Price1 >(_target_price + tick)))) {
#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog(log.Format("Trying to move Target from: %f to %f",
				_target.Price1, _target_price),
				1);
#endif
			std::pair<int, s_SCNewOrder> modify_order = lib_trade_modify_target(sc, index, position.PositionQuantity, _target, tick, _target_price, TargetInit);
			//            if (modify_order.first == 1 && TargetInit == 1)
			if (TargetInit == 1)
				TargetInit = 0;
		}
	}
}

void main_iteration(SCStudyInterfaceRef sc, int index, int last_iterated_index) {

	sc.SetPersistentInt(_P_LAST_INDEX_LOOPED, index);

	if (last_iterated_index != sc.Index) {
		int _min_index = sc.GetPersistentInt(_P_INDEX_END);

		if (index == _min_index && _min_index > 0)
			sc.SetPersistentInt(_P_ACTIVE, 1);

		if (_min_index <= 0 || index < _min_index ||
			sc.GetPersistentInt(_P_ACTIVE) == 0 || broke_stop(sc, index) == 1) {
			sc.SetPersistentInt(_P_ACTIVE, 0);
			update_empty_index_values(sc, index);
			s_UseTool Tool;
			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, SYMBOL_TEXT_DRAWING_PROFIT, Tool) > 0) {
				sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, SYMBOL_TEXT_DRAWING_PROFIT);
			}
			return;
		}

		if (sc.Input[_TARGET_FIB].GetFloat() == 0) {
			int &direction = sc.GetPersistentInt(_P_DIRECTION);
			int &index_third = sc.GetPersistentInt(_P_INDEX_THIRD);
			float &price_third = sc.GetPersistentFloat(_P_PRICE_THIRD);
			float &price_begin = sc.GetPersistentFloat(_P_PRICE_BEGIN);
			float &price_end = sc.GetPersistentFloat(_P_PRICE_END);
			float &target_price = sc.GetPersistentFloat(_P_TARGET_PRICE);
			//			float & area_top =
			//sc.GetPersistentFloat(_P_AREA_TOP);
			float _price_diff = abs(price_begin - price_end);
			float tick = sc.TickSize;
			float &_p_fib_entry = sc.GetPersistentFloat(_P_FIB_ENTRY);
			/* Updating price_third to be the lowest value inside swing after retreacement
			if (index > index_third) {
				if (direction == 1) {
					float _latest_pivot_price = sc.Low[index - 1];
					if (price_third > _latest_pivot_price) {
						index_third = index - 1;
						price_third = _latest_pivot_price;

						if (price_third > _p_fib_entry)
							target_price = _p_fib_entry + _price_diff;
						else
							target_price = price_third + _price_diff;

						if (target_price <= price_end)
							target_price = price_end + tick;
						//                        if (area_top > price_third && price_third
						//                        > price_begin)
						//							area_top =
						//price_third;
					}
				}
				if (direction == -1) {
					float _latest_pivot_price = sc.High[index - 1];
					if (price_third < _latest_pivot_price) {
						index_third = index - 1;
						price_third = _latest_pivot_price;
						if (price_third < _p_fib_entry)
							target_price = _p_fib_entry - _price_diff;
						else
							target_price = price_third - _price_diff;

						if (target_price >= price_end)
							target_price = price_end - tick;
						//                        if (area_top < price_third && price_third
						//                        < price_begin)
						//							area_top =
						//price_third;
					}
				}
			}
			*/
		}

		update_index_values(sc, index);
	}

	if (sc.GetPersistentInt(_P_ACTIVE) == 1) {
		s_SCPositionData _position;
		sc.GetTradePosition(_position);
		if ((_position.PositionQuantity > 0 && sc.GetPersistentInt(_P_DIRECTION) == 1) || (_position.PositionQuantity < 0 && sc.GetPersistentInt(_P_DIRECTION) == -1)) {
			sc_swing_update_orders(sc, sc.Index, _position);

			s_UseTool Tool;

			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, SYMBOL_TEXT_DRAWING_PROFIT, Tool) > 0) {
				sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, SYMBOL_TEXT_DRAWING_PROFIT);
			}
		}

		else {

			SCString currency = sc.Input[_CURRENCY].GetString();
			float target_value = calc_currency_with_position(sc, abs(sc.Subgraph[_TARGET_PRICE][index] - sc.Close[index]), currency);
			float stop_value = calc_currency_with_position(sc, abs(sc.Subgraph[_STOP_PRICE][index] - sc.Close[index]), currency);
			float _rr = 0;
			if (stop_value > 0.0)
				_rr = target_value / stop_value;
			sc.Subgraph[_CURRENCY_STOP][sc.Index] = stop_value;
			sc.Subgraph[_CURRENCY_TARGET][sc.Index] = target_value;
			sc.Subgraph[_RR][sc.Index] = _rr;

			if (_rr > 0.0)
			{
				s_UseTool Tool;
				float _scale_const = sc.BaseGraphScaleConstRange / 100;
				Tool.ChartNumber = sc.ChartNumber;
				Tool.DrawingType = DRAWING_TEXT;
				Tool.Region = sc.GraphRegion;
				Tool.LineNumber = SYMBOL_TEXT_DRAWING_PROFIT;
				Tool.AddMethod = UTAM_ADD_OR_ADJUST;
				Tool.AddAsUserDrawnDrawing = 0;
				Tool.AllowSaveToChartbook = 0;
				Tool.BeginDateTime = sc.Input[_HSPACE].GetInt() + (sc.ChartBarSpacing / 3);

				Tool.BeginValue = sc.Close[sc.Index] + (sc.Input[_VSPACE].GetInt() * _scale_const);

				Tool.TransparentLabelBackground = 1;
				Tool.FontFace = sc.GetChartTextFontFaceName();



				if (_rr > sc.Input[_MIN_RR].GetFloat()) {
					Tool.FontSize = sc.Input[_FONT_SIZE].GetInt();
					Tool.FontBold = true;
					if (sc.GetPersistentInt(_P_DIRECTION) == 1) {
						Tool.Color = sc.Subgraph[_LONG_TRADE].PrimaryColor;
					}
					else if (sc.GetPersistentInt(_P_DIRECTION) == -1) {
						Tool.Color = sc.Subgraph[_SHORT_TRADE].PrimaryColor;
					}
				}
				else {
					Tool.FontSize = sc.Input[_FONT_SIZE].GetInt() - 1;
					Tool.FontBold = false;
					Tool.Color = color_even;
				}

				Tool.Text = Tool.Text.Format("P:%.1f\nS:%.1f\nR:%.1f", target_value, stop_value, _rr);
				sc.UseTool(Tool);
			}

		}
	}
}

float get_stop_offset(SCStudyInterfaceRef sc) {
	return (sc.Input[_STOP_OFFSET].GetInt() * sc.TickSize);
}

float get_stop_offset_multiplied(SCStudyInterfaceRef sc) {
	return (get_stop_offset(sc) * sc.Input[_I_ATR_MULT].GetFloat());
}
float get_stop_offset_multiplied_alt(SCStudyInterfaceRef sc) {
	return (get_stop_offset(sc) * sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].GetFloat());
}
//float get_stop_offset_prev_swing_hl_stop_fib(SCStudyInterfaceRef sc) {
//	return (get_stop_offset(sc) * sc.Input[_I_PREV_SWING_HL_STOP_FIB].GetFloat());
//}
float get_stop_offset_prev_swing_hl_detector(SCStudyInterfaceRef sc) {
	if (sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].GetFloat() > 0.0)
		return (get_stop_offset(sc) * sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].GetFloat());
	//return abs(get_stop_offset_multiplied(sc) - get_stop_offset_prev_swing_hl_multiplied(sc));
	return get_stop_offset_multiplied(sc);
}

void initialize_values_calculations(SCStudyInterfaceRef sc, int index, int use_prev_swing) {
	int &index_begin = sc.GetPersistentInt(_P_INDEX_BEGIN);
	int &index_end = sc.GetPersistentInt(_P_INDEX_END);
	int &index_third = sc.GetPersistentInt(_P_INDEX_THIRD);
	float &price_begin = sc.GetPersistentFloat(_P_PRICE_BEGIN);
	float &price_end = sc.GetPersistentFloat(_P_PRICE_END);
	float &price_third = sc.GetPersistentFloat(_P_PRICE_THIRD);
	int &direction = sc.GetPersistentInt(_P_DIRECTION);
	int &length = sc.GetPersistentInt(_P_LENGTH);
	int &active = sc.GetPersistentInt(_P_ACTIVE);
	int _prev_swing_hl = sc.Input[_I_SWING_PREVIOUS_SWING_HIGH_LOW].GetInt();

	float &_p_stop_price = sc.GetPersistentFloat(_P_STOP_PRICE);
	float &_p_target_price = sc.GetPersistentFloat(_P_TARGET_PRICE);
	float &_p_fib_entry = sc.GetPersistentFloat(_P_FIB_ENTRY);
	float &_p_area_top = sc.GetPersistentFloat(_P_AREA_TOP);
	float &_p_area_bottom = sc.GetPersistentFloat(_P_AREA_BOTTOM);

	float _stop = 0, _target_price = 0, _area_top = 0, _area_bottom = 0;
	float _fib_entry = 0;

	float _offset = get_stop_offset(sc);
	float _stop_atr_offset = get_stop_offset_multiplied(sc);
	//float _prev_swing_hl_offset = get_stop_offset_prev_swing_hl_multiplied(sc);
	float _swing_hl_detector = get_stop_offset_prev_swing_hl_detector(sc);

	// TODO: CLEANUP
	float max_stop_currency_value = 0;
	float entry_zone;

	float _target_fib = sc.Input[_TARGET_FIB].GetFloat();
	int _using_prev_hl = 0;

	//SCString log;
	//sc.AddMessageToLog(log.Format("atr: %f, abs: %f and %f", _prev_swing_hl_offset, abs(price_third - price_begin), abs(price_third - price_end)), 0);
	if ((_prev_swing_hl > 1) || ((use_prev_swing == 1) && (_prev_swing_hl == 1) && (_swing_hl_detector < (abs(price_third - price_end))) && (_swing_hl_detector < (abs(price_third - price_begin))))) {
		_stop_atr_offset = get_stop_offset_multiplied_alt(sc);
		_stop = calc_fib(sc, sc.Input[_I_PREV_SWING_HL_STOP_FIB].GetFloat(), price_begin, price_third);
		_using_prev_hl = 1;
		sc.Subgraph[_SG_PRICE_THIRD].DrawStyle = sc.Subgraph[_SG_PRICE_BEGIN].DrawStyle;
	}
	else {
		_stop = calc_fib(sc, sc.Input[_STOP_FIB_LEVEL].GetFloat(), price_begin, price_end);
		sc.Subgraph[_SG_PRICE_THIRD].DrawStyle = DRAWSTYLE_IGNORE;
	}

	if (active == 1) {
		max_stop_currency_value = calc_entry_zone_currency_with_position(sc, sc.Input[_MAX_STOP_DISTANCE].GetInt(), sc.Input[_CURRENCY].GetString());

		if (_target_fib != 0.0)
			_target_price = calc_fib(sc, sc.Input[_TARGET_FIB].GetFloat(), price_begin, price_end);

		if (_using_prev_hl == 1)
			_fib_entry = price_third;
		else
			_fib_entry = calc_fib(sc, sc.Input[_ENTRY_FIB].GetFloat(), price_begin, price_end);

		if (direction == 1) {
			_stop = _stop - _stop_atr_offset;
			//if (_using_prev_hl == 1 && _stop < price_begin)
			//	_stop = price_begin;
			entry_zone = round_to_ticksize_trade(sc, _stop + max_stop_currency_value, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
			if (entry_zone > _fib_entry)
				entry_zone = _fib_entry;
			if (entry_zone < price_begin)
				entry_zone = price_begin;
			if (_target_fib == 0.0) {
				_target_price = price_end + abs(_offset);
				//_target_price = price_end + abs(price_end - price_third);

				//if (price_third > _fib_entry)
				//	_target_price = _fib_entry + abs(price_begin - price_end);
				//else
				//	_target_price = price_third + abs(price_begin - price_end);
			}
		}
		if (direction == -1) {
			_stop = _stop + _stop_atr_offset;
			//if (_using_prev_hl == 1 && _stop > price_begin)
			//	_stop = price_begin;
			entry_zone = round_to_ticksize_trade(sc, _stop - max_stop_currency_value, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
			if (entry_zone < _fib_entry)
				entry_zone = _fib_entry;
			if (entry_zone > price_begin)
				entry_zone = price_begin;
			if (_target_fib == 0.0) {
				_target_price = price_end - abs(_offset);
				//_target_price = price_end - abs(price_end - price_third);

				//if (price_third < _fib_entry)
				//	_target_price = _fib_entry - abs(price_begin - price_end);
				//else
				//	_target_price = price_third - abs(price_begin - price_end);
				////                if (entry_zone < price_third)
				////                    entry_zone = price_third;
			}
			//if (_prev_swing_hl > 0) {
			//	if (entry_zone < _price_begin_strategy)
			//		entry_zone = _price_begin_strategy;
			//}

		}

		//_area_top = calc_fib_f(sc, 61.8, price_begin, price_end);
		//_area_bottom = calc_fib_f(sc, 88.6, price_begin, price_end);
	}

	_p_stop_price = round_to_ticksize_trade(sc, _stop, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_p_target_price = round_to_ticksize_trade(sc, _target_price, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_p_fib_entry = round_to_ticksize_trade(sc, _fib_entry, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_p_area_top = round_to_ticksize_trade(sc, entry_zone, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	//if (_using_prev_hl == 1)
	//	_p_area_bottom = round_to_ticksize_trade(sc, (price_third);
	//else
	_p_area_bottom = round_to_ticksize_trade(sc, price_begin, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());

	sc.Subgraph[_LONG_TRADE][index] = 0;
	sc.Subgraph[_SHORT_TRADE][index] = 0;

	sc.SetPersistentFloat(_P_TRADE_QUANTITY, sc.TradeWindowOrderQuantity);
	sc.SetPersistentInt(_P_STOP_INITIAL, 1);
	sc.SetPersistentInt(_P_TARGET_INITIAL, 1);

	sc.SetPersistentInt(_P_SWING_INITIALIZED, 1);
}

void swing_set_atr_tick_offset(SCStudyInterfaceRef sc, int index_end) {

	if (index_end > 0 && sc.Input[_I_SWING_USE_EXT_ATR].GetInt() > 0) {
		SCFloatArray atrArray;
		SCInputRef i_atr = sc.Input[_I_ATR];
		if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
			float _result = (atrArray[index_end]) / sc.TickSize;
			sc.Input[_STOP_OFFSET].SetInt(sc.Round(_result));

		}
	}
}

void initialize_values(SCStudyInterfaceRef sc, int index, int index_begin, int index_end, int third_index, float price_begin, float price_end, float third_price, int direction, int length, int active, int use_prev_swing) {
	int &_index_begin = sc.GetPersistentInt(_P_INDEX_BEGIN);
	int &_index_end = sc.GetPersistentInt(_P_INDEX_END);
	int &_index_third = sc.GetPersistentInt(_P_INDEX_THIRD);
	float &_price_begin = sc.GetPersistentFloat(_P_PRICE_BEGIN);
	float &_price_end = sc.GetPersistentFloat(_P_PRICE_END);
	float &_price_third = sc.GetPersistentFloat(_P_PRICE_THIRD);
	int &_direction = sc.GetPersistentInt(_P_DIRECTION);
	int &_length = sc.GetPersistentInt(_P_LENGTH);
	int &_active = sc.GetPersistentInt(_P_ACTIVE);

	_active = active;
	_direction = direction;
	_index_begin = index_begin;
	_index_end = index_end;
	_index_third = third_index;
	_price_begin = round_to_ticksize_trade(sc, price_begin, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_price_end = round_to_ticksize_trade(sc, price_end, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_price_third = round_to_ticksize_trade(sc, third_price, sc.Input[_I_TICKSIZE_MULTIPLIER].GetInt());
	_length = length;

	//	if (length > 0) {
	//		SCFloatArray atrArray;
	//		//        SCFloatArray trArray;
	//		//        sc.ATR(sc.BaseDataIn, trArray, atrArray, index_end, length+1,
	//		//        MOVAVGTYPE_LINEARREGRESSION);
	//		SCInputRef i_atr = sc.Input[_I_ATR];
	//		SCInputRef i_atr_mult = sc.Input[_I_ATR_MULT];
	//		if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
	//			sc.Input[_STOP_OFFSET].SetInt((atrArray[index_end] * i_atr_mult.GetFloat()) / sc.TickSize);
	//		}
	//	}
	//	else {
	//		sc.Input[_STOP_OFFSET].SetInt(0);
	//	}

	swing_set_atr_tick_offset(sc, index_end);

	if (_direction == 1) {
		sc.Subgraph[_STOP_PRICE].PrimaryColor = sc.Subgraph[_LONG_TRADE].PrimaryColor;
		sc.Subgraph[_TARGET_PRICE].PrimaryColor = sc.Subgraph[_LONG_TRADE].PrimaryColor;
		sc.Subgraph[_AREA_TOP].PrimaryColor = sc.Subgraph[_LONG_TRADE].PrimaryColor;
	}
	else     if (_direction == -1) {
		sc.Subgraph[_STOP_PRICE].PrimaryColor = sc.Subgraph[_SHORT_TRADE].PrimaryColor;
		sc.Subgraph[_TARGET_PRICE].PrimaryColor = sc.Subgraph[_SHORT_TRADE].PrimaryColor;
		sc.Subgraph[_AREA_TOP].PrimaryColor = sc.Subgraph[_SHORT_TRADE].PrimaryColor;
	}


	initialize_values_calculations(sc, index, use_prev_swing);
}
/*==========================================================================*/
SCSFExport scsf_SwingZone_Swing(SCStudyInterfaceRef sc) {

	/*SCInputRef EntryFib = sc.Input[_ENTRY_FIB];
	SCInputRef TargetFib = sc.Input[_TARGET_FIB];
	SCInputRef MaxStopDistance = sc.Input[_MAX_STOP_DISTANCE];
	SCInputRef ATRMult = sc.Input[_I_ATR_MULT];
	SCInputRef StopFibLevel = sc.Input[_STOP_FIB_LEVEL];
	SCInputRef StopOffset = sc.Input[_STOP_OFFSET];
	SCInputRef ButtonON = sc.Input[_I_BUTTON_ON];
	SCInputRef ButtonOFF = sc.Input[_I_BUTTON_OFF];
*/
	int &STATE_ACS_BUTTON_2 = sc.GetPersistentInt(_STATE_ACS_BUTTON);
	int &MouseStart = sc.GetPersistentInt(_MOUSE_START);
	int &MouseEnd = sc.GetPersistentInt(_MOUSE_END);
	int &LastIndexLooped = sc.GetPersistentInt(_P_LAST_INDEX_LOOPED);

	
	sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;
	sc.SendOrdersToTradeService = sc.Input[_I_SWING_REAL_SIMULATION].GetInt();

	if (sc.SetDefaults) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Loading Defaults", 0);
#endif
		swing_set_defaults(sc);
		return;
	}

	if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif

		std::ifstream file = read_conf(sc);

		if (file.good()) {
			float entry_fib, target_fib, stop_fib_level, atr_mult, min_rr, atr_mult_prev_swing_hl, atr_mult_prev_swing_hl_detect_offset;
			int max_stop_distance, vertical_placement, horizontal_placement, font_size, use_atr, previous_swing_hl;
			file >> entry_fib >> target_fib >> stop_fib_level >> max_stop_distance >> atr_mult >> min_rr >> vertical_placement >> horizontal_placement >> font_size >> use_atr >> previous_swing_hl >> atr_mult_prev_swing_hl >> atr_mult_prev_swing_hl_detect_offset;

			sc.Input[_ENTRY_FIB].SetFloat(entry_fib);
			sc.Input[_TARGET_FIB].SetFloat(target_fib);
			sc.Input[_STOP_FIB_LEVEL].SetFloat(stop_fib_level);
			sc.Input[_MAX_STOP_DISTANCE].SetInt(max_stop_distance);
			sc.Input[_I_ATR_MULT].SetFloat(atr_mult);
			sc.Input[_MIN_RR].SetFloat(min_rr);
			sc.Input[_VSPACE].SetInt(vertical_placement);
			sc.Input[_HSPACE].SetInt(horizontal_placement);
			sc.Input[_FONT_SIZE].SetInt(font_size);
			sc.Input[_I_SWING_USE_EXT_ATR].SetInt(use_atr);
			sc.Input[_I_SWING_PREVIOUS_SWING_HIGH_LOW].SetInt(previous_swing_hl);
			sc.Input[_I_PREV_SWING_HL_STOP_FIB].SetFloat(atr_mult_prev_swing_hl);
			sc.Input[_I_USE_PREV_SWING_HL_STOP_ATR_DETECT_OFFSET].SetFloat(atr_mult_prev_swing_hl_detect_offset);
			file.close();
		}
		
		int atr = read_conf_single_int(sc, "atr");
        if (atr != -1)
			sc.Input[_STOP_OFFSET].SetInt(atr);
		
		int max = read_conf_single_int(sc, "maxstopdistance");
        if (max != -1)
				sc.Input[_MAX_STOP_DISTANCE].SetInt(max);

		sc.Input[_I_TICKSIZE_MULTIPLIER].SetInt(load_ticksize_multiplier_from_file(sc));


		SCString realsim_path;
		std::ifstream realsim_input(realsim_path.Format("conf/%s.conf", "realsim"));
		if (realsim_input.is_open()) {

			int realsim;

			realsim_input >> realsim;

			sc.Input[_I_SWING_REAL_SIMULATION].SetInt(realsim);

			realsim_input.close();

		}
	}

	if (swing_skip_iteration(sc))
		return;

	int last_call = swing_last_call(sc);
	if ((sc.MenuEventID == sc.Input[_I_BUTTON_OFF].GetInt() && sc.PointerEventType == SC_ACS_BUTTON_ON) || last_call) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Remove Trade Management", 0);
#endif

		if (LastIndexLooped != 0) {
			LastIndexLooped = 0;
			initialize_values(sc, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
			sc.SetPersistentInt(_P_STOP_INITIAL, 0);
			sc.SetPersistentInt(_P_TARGET_INITIAL, 0);
			sc.FlagFullRecalculate = 1;
			s_UseTool Tool;
			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, SYMBOL_TEXT_DRAWING_PROFIT, Tool) > 0) {
				sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, SYMBOL_TEXT_DRAWING_PROFIT);
			}

#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog("Clear: Recalculate", 1);
#endif
			STATE_ACS_BUTTON_2 = -1;
			sc.SetCustomStudyControlBarButtonEnable(sc.Input[_I_BUTTON_OFF].GetInt(), 0);
		}
		sc.SetPersistentInt(_P_SWING_INITIALIZED, 0);
		return;
	}

	if (sc.IsFullRecalculation) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Full Recalculation", 0);
#endif
		main_iteration(sc, sc.Index, LastIndexLooped);
		return;
	}

	if (sc.Input[_I_BUTTON_ON].GetInt() > 0 && (sc.MenuEventID == sc.Input[_I_BUTTON_ON].GetInt() || STATE_ACS_BUTTON_2 == sc.Input[_I_BUTTON_ON].GetInt())) {

#ifdef _CONST_DEBUG
		sc.AddMessageToLog("New Trade Swing", 0);
#endif
		if (tool_range_selection(sc, sc.MenuEventID, STATE_ACS_BUTTON_2, MouseStart, MouseEnd) == 3) {
			int _index_begin, _index_end, _third_index, _direction, _length;
			float _price_begin, _price_end, _third_price;

			if (process_new_mouse_zone(sc, _index_begin, _index_end, _third_index,
				_price_begin, _price_end, _third_price,
				_direction, _length, MouseStart, MouseEnd)) {

				initialize_values(sc, _index_begin, _index_begin, _index_end, _third_index, _price_begin, _price_end, _third_price, _direction, _length, 1, 0);
#ifdef _CONST_DEBUG
				SCString log;
				sc.AddMessageToLog("Initialize: Recalculate", 1);
#endif
				sc.FlagFullRecalculate = 1;
			}

			STATE_ACS_BUTTON_2 = -1;
		}
		return;
	}

	if (sc.Input[_I_BUTTON_ON_ALT].GetInt() > 0 && sc.MenuEventID == sc.Input[_I_BUTTON_ON_ALT].GetInt()) {

		sc.SetCustomStudyControlBarButtonEnable(sc.Input[_I_BUTTON_ON_ALT].GetInt(), 0);
		int _selected = sc.GetLineNumberOfSelectedUserDrawnDrawing();
		s_UseTool _tool;
		if (_selected == 1) {
			int i = 1, max = 10;
			while (_tool.IsSelected == 0 || i == max) {
				sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_REWARD_RISK, _tool, i * -1);
				i++;

#ifdef _CONST_DEBUG
				SCString log;
				sc.AddMessageToLog(log.Format("Initialize: selected %d and exists %d", _tool.LineNumber, _tool.IsSelected), 0);
#endif
			}
			_selected = _tool.IsSelected;
#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog(log.Format("Initialize: selected %d and exists %d", _selected, sc.UserDrawnChartDrawingExists(sc.ChartNumber, _selected)), 0);
#endif
		}
		else {
			_selected = sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_REWARD_RISK, _tool, -1);
		}
		if (_selected == 1 && _tool.LineNumber != 0) {
			//_selected = _tool.LineNumber;
			//if (_selected != 0 && sc.UserDrawnChartDrawingExists(sc.ChartNumber, _selected) == 1) {
			//	s_UseTool _tool;
			//if (sc.GetUserDrawnDrawingByLineNumber(sc.ChartNumber, _selected, _tool) == 1) {
			//	if (_tool.DrawingType == DRAWING_REWARD_RISK) {
			int _index_begin, _index_end, _third_index, _direction, _length;
			float _price_begin, _price_end, _third_price;

			_index_begin = _tool.BeginIndex;
			_price_begin = _tool.BeginValue;

			_index_end = _tool.ThirdIndex;
			_price_end = _tool.ThirdValue;

			//if (_tool.LevelStyle[2] == MARKER_POINT) {
			//	_third_index = _index_begin;
			//	_third_price = _price_begin;
			//}
			//else {
			_third_index = _tool.EndIndex;
			_third_price = _tool.EndValue;
			//}

			if (_price_begin < _price_end)
				_direction = 1;
			else
				if (_price_begin > _price_end)
					_direction = -1;
				else
					return;
			_length = abs(_index_begin - _index_end);

#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog(log.Format("price: %f, %f, %f", _price_begin, _price_end, _third_price), 0);
			sc.AddMessageToLog(log.Format("index: %d, %d, %d", _index_begin, _index_end, _third_index), 0);
			sc.AddMessageToLog(log.Format("length: %d, direction: %d", _length, _direction), 0);
#endif
			initialize_values(sc, _index_begin, _index_begin, _index_end, _third_index, _price_begin, _price_end, _third_price, _direction, _length, 1, 1);
			sc.FlagFullRecalculate = 1;
			//STATE_ACS_BUTTON_2 = -1;
/*
			if (_tool.LockDrawing == 0) {
				_tool.LockDrawing = 1;
				_tool.HideDrawing = 1;
				_tool.AddMethod = UTAM_ADD_OR_ADJUST;
				sc.UseTool(_tool);
			}*/

			for (int i = 1; i < 20; i++) {
				if (sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_REWARD_RISK, _tool, i * -1)) {
					_tool.HideDrawing = 1;
					_tool.LockDrawing = 1;
					_tool.AddMethod = UTAM_ADD_OR_ADJUST;
					sc.UseTool(_tool);
				}
			}

			//}
		/*	}
		}*/
		}

		return;
	}

	if (sc.Input[_I_BUTTON_TOOGLE_HIDE].GetInt() > 0 && sc.MenuEventID == sc.Input[_I_BUTTON_TOOGLE_HIDE].GetInt()) {
		sc.SetCustomStudyControlBarButtonEnable(sc.Input[_I_BUTTON_TOOGLE_HIDE].GetInt(), 0);
		s_UseTool _tool;
		for (int i = 1; i < 20; i++) {
			if (sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_REWARD_RISK, _tool, i * -1)) {
				if (_tool.HideDrawing == 0)
					_tool.HideDrawing = 1;
				else
					_tool.HideDrawing = 0;
				_tool.AddMethod = UTAM_ADD_OR_ADJUST;
				sc.UseTool(_tool);
			}
			else
				return;
		}
		return;
	}

	if (sc.TradeWindowOrderQuantity != sc.GetPersistentFloat(_P_TRADE_QUANTITY)) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Trade Quantity changed", 0);
#endif
		s_UseTool Tool;
		if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, SYMBOL_TEXT_DRAWING_PROFIT, Tool) > 0) {
			sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, SYMBOL_TEXT_DRAWING_PROFIT);
		}

		initialize_values_calculations(sc, sc.GetPersistentInt(_P_INDEX_BEGIN), 1);
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Trade Quantity: Recalculate", 1);
#endif
		sc.FlagFullRecalculate = 1;
		return;
	}

	// LOOP ITERATION REGION
	if (sc.GetPersistentInt(_P_SWING_INITIALIZED) == 1) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Main Iteration Loop", 0);
#endif
		main_iteration(sc, sc.Index, LastIndexLooped);
	}
}
