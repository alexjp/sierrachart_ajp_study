#include "sc_position.h"

void sc_position_hide_breakeven(SCStudyInterfaceRef sc)
{
	sc.SetPersistentInt(_P_HIDE_BREAKEVEN, 1);
	sc.Subgraph[_SG_POSITION_BREAKEVEN].DrawStyle = DRAWSTYLE_IGNORE;
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].DrawStyle = DRAWSTYLE_LINE_AT_LAST_BAR_TO_LEFT_SIDE;
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].DrawStyle = DRAWSTYLE_LINE_AT_LAST_BAR_TO_LEFT_SIDE;

}
void sc_position_show_breakeven(SCStudyInterfaceRef sc)
{
	sc.SetPersistentInt(_P_HIDE_BREAKEVEN, 0);
	sc.Subgraph[_SG_POSITION_BREAKEVEN].DrawStyle = DRAWSTYLE_LINE_AT_LAST_BAR_TO_LEFT_SIDE;
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].DrawStyle = DRAWSTYLE_IGNORE;
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].DrawStyle = DRAWSTYLE_IGNORE;
}

void sc_position_initialize_fib_based_values(SCStudyInterfaceRef sc, int index, float stop, float target, s_SCPositionData &position)
{
	float &_trail_target = sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);
	float &_trail_stop = sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);
	float &_breakeven = sc.GetPersistentFloat(_P_POSITION_BREAKEVEN);
	float &_target = sc.GetPersistentFloat(_P_POSITION_TARGET);
	float &_stop = sc.GetPersistentFloat(_P_POSITION_STOP);


	if (sc.Input[_I_POSITION_USE_EXT_ATR].GetInt() == 1) {
		SCFloatArray atrArray;
		SCInputRef i_atr = sc.Input[_I_ATR];
		if (sc.GetStudyArrayUsingID(i_atr.GetStudyID(), i_atr.GetSubgraphIndex(), atrArray)) {
			sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].SetInt((atrArray[index] * sc.Input[_I_POSITION_ATR_MULT].GetFloat()) / sc.TickSize);
		}
	}

	float _price_trail_offset = sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].GetInt() * sc.TickSize;

	_trail_target = calc_fib_f(sc, sc.Input[_I_TRAIL_TARGET_FIB].GetFloat(), stop, target);
	_trail_stop = calc_fib_f(sc, sc.Input[_I_TRAIL_STOP_FIB].GetFloat(), stop, target);
	_breakeven = calc_fib_f(sc, sc.Input[_I_BREAKEVEN_FIB].GetFloat(), stop, target);

	if (position.PositionQuantity > 0) {
		if (_breakeven < position.AveragePrice + _price_trail_offset)
			_breakeven = position.AveragePrice + _price_trail_offset;

		// if (_trail_stop < _breakeven + _price_trail_offset)
		//     _trail_stop = _breakeven + _price_trail_offset;

		// if (_trail_target < (_trail_stop + _price_trail_offset))
		//     _trail_target = _trail_stop + _price_trail_offset;
	}
	else if (position.PositionQuantity < 0) {
		if (_breakeven > position.AveragePrice - _price_trail_offset)
			_breakeven = position.AveragePrice - _price_trail_offset;

		// if (_trail_stop > _breakeven - _price_trail_offset)
		//     _trail_stop = _breakeven - _price_trail_offset;

		// if (_trail_target > (_trail_stop - _price_trail_offset))
		//     _trail_target = _trail_stop - _price_trail_offset;
	}

	_stop = stop;
	_target = target;
}

void sc_position_set_defaults(SCStudyInterfaceRef sc)
{

	sc.GraphName = "Position Management";
	sc.StudyDescription = "Position Management";

	sc.Input[_I_POSITION_REAL_SIMULATION].Name = "Real:1/Simulation trading:0";
	sc.Input[_I_POSITION_REAL_SIMULATION].SetInt(0);

	sc.Input[_I_POSITION_AUTOTRAIL].Name = "Auto Trail ON";
	sc.Input[_I_POSITION_AUTOTRAIL].SetInt(1);

	sc.Input[_I_POSITION_ENABLED].Name = "Study Enabled";
	sc.Input[_I_POSITION_ENABLED].SetInt(1);

	sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].Name = "Trail Offset in ticks";
	sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].SetInt(10);

	sc.Subgraph[_SG_POSITION_BREAKEVEN].Name = "Breakeven Style";
	sc.Subgraph[_SG_POSITION_BREAKEVEN].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
	sc.Subgraph[_SG_POSITION_BREAKEVEN].PrimaryColor = color_even;
	sc.Subgraph[_SG_POSITION_BREAKEVEN].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_POSITION_BREAKEVEN].LineWidth = 2;

	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].Name = "Trail Target Style";
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].PrimaryColor = color_success;
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_POSITION_TRAIL_TARGET].LineWidth = 2;

	sc.Subgraph[_SG_POSITION_TRAIL_STOP].Name = "Trail Stop Style";
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUE_LABELS_ONLY;
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].PrimaryColor = color_bad;
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].DisplayNameValueInWindowsFlags = 0;
	sc.Subgraph[_SG_POSITION_TRAIL_STOP].LineWidth = 2;

	sc.Input[_I_TRAIL_TARGET_FIB].Name = "Trail Target Ratio Fib";
	sc.Input[_I_TRAIL_TARGET_FIB].SetFloat(23.6);

	sc.Input[_I_TRAIL_STOP_FIB].Name = "Trail Stop Ratio Fib";
	sc.Input[_I_TRAIL_STOP_FIB].SetFloat(61.8);

	sc.Input[_I_BREAKEVEN_FIB].Name = "Breakeven Ratio Fib";
	sc.Input[_I_BREAKEVEN_FIB].SetFloat(61.8);

	sc.Input[_I_ATR].Name = "External ATR Study";
	sc.Input[_I_ATR].SetStudySubgraphValues(0, 0);

	sc.Input[_I_POSITION_ATR_MULT].Name = "ATR Multiplier";
	sc.Input[_I_POSITION_ATR_MULT].SetFloat(1);

	sc.Input[_I_POSITION_USE_EXT_ATR].Name = "USE External ATR Study for ATR Offset";
	sc.Input[_I_POSITION_USE_EXT_ATR].SetInt(0);

	sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].Name = "Ticksize Multiplier";
	sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].SetInt(1);

	sc.GraphRegion = 0;

	sc.AutoLoop = 1;
	sc.ScaleRangeType = SCALE_SAMEASREGION;
	sc.DrawStudyUnderneathMainPriceGraph = 1;

}

int sc_position_skip_iteration(SCStudyInterfaceRef sc)
{
	if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.DownloadingHistoricalData)
		return 1;
	return 0;
}

int sc_position_last_call(SCStudyInterfaceRef sc)
{
	if (!sc.LastCallToFunction)
		return 0;

	return 1;
}

void sc_position_iterate_long(SCStudyInterfaceRef sc, int index, s_SCPositionData &position, s_SCTradeOrder &stop, s_SCTradeOrder &target)
{
	float _last_price = sc.Close[index];
	float _price_trail_offset = sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].GetFloat() * sc.TickSize;

	float &_trail_target = sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);
	float &_trail_stop = sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);
	float &_breakeven = sc.GetPersistentFloat(_P_POSITION_BREAKEVEN);
	float &_target = sc.GetPersistentFloat(_P_POSITION_TARGET);
	float &_stop = sc.GetPersistentFloat(_P_POSITION_STOP);

	int _is_auto_trail = sc.Input[_I_POSITION_AUTOTRAIL].GetInt();

	if (sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0 && _breakeven != 0) {
		if (stop.Price1 < position.AveragePrice && _breakeven < _last_price) {

			std::pair <int, s_SCNewOrder> _new_stop = lib_trade_modify_stop(sc, index, position.PositionQuantity, stop, (_price_trail_offset), position.AveragePrice + _price_trail_offset, 0);

			if (_new_stop.first == 1) {
				double _rounded_new_stop = round_to_ticksize_trade(sc, _new_stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
				double _rounded_target = round_to_ticksize_trade(sc, target.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
				sc.SetPersistentFloat(_P_POSITION_STOP, _rounded_new_stop);
				sc_position_initialize_fib_based_values(sc, index, _rounded_new_stop, _rounded_target, position);
				sc_position_hide_breakeven(sc);
			}
		}
	}
	else {
		if (_target != 0 && _stop != 0) {
			float tick = (1 * sc.TickSize);

			if ((abs(target.Price1 - _last_price) < _price_trail_offset)) {
				float _proposed_new_price = target.Price1 + _price_trail_offset;
				std::pair <int, s_SCNewOrder> _new_target = lib_trade_modify_target(sc, index, position.PositionQuantity, target, _price_trail_offset, _proposed_new_price, 0);
				if (_new_target.first == 1)
					sc.SetPersistentFloat(_P_POSITION_TARGET, round_to_ticksize_trade(sc, _new_target.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()));
			}

			if (_is_auto_trail) {
				if (_last_price > _trail_target) {

					if (stop.Price1 < _trail_stop) {
						std::pair <int, s_SCNewOrder> _new_stop = lib_trade_modify_stop(sc, index, position.PositionQuantity, stop, _price_trail_offset, _trail_stop, 0);
						if (_new_stop.first == 1)
							sc.SetPersistentFloat(_P_POSITION_STOP, round_to_ticksize_trade(sc, _new_stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()));
					}

					_trail_target = round_to_ticksize_trade(sc, _trail_target + _price_trail_offset, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
					_trail_stop = round_to_ticksize_trade(sc, _trail_stop + _price_trail_offset, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
				}
			}

		}
	}

}

void sc_position_iterate_short(SCStudyInterfaceRef sc, int index, s_SCPositionData &position, s_SCTradeOrder &stop, s_SCTradeOrder &target)
{
	float _last_price = sc.Close[index];
	float _price_trail_offset = sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].GetFloat() * sc.TickSize;

	float &_trail_target = sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);
	float &_trail_stop = sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);
	float &_breakeven = sc.GetPersistentFloat(_P_POSITION_BREAKEVEN);
	float &_target = sc.GetPersistentFloat(_P_POSITION_TARGET);
	float &_stop = sc.GetPersistentFloat(_P_POSITION_STOP);

	int _is_auto_trail = sc.Input[_I_POSITION_AUTOTRAIL].GetInt();

	if (sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0 && _breakeven != 0) {
		if (stop.Price1 > position.AveragePrice && _breakeven > _last_price) {
			std::pair <int, s_SCNewOrder> _new_stop = lib_trade_modify_stop(sc, index, position.PositionQuantity, stop, (_price_trail_offset), position.AveragePrice - _price_trail_offset, 0);
			if (_new_stop.first == 1)
				sc.SetPersistentFloat(_P_POSITION_STOP, round_to_ticksize_trade(sc, _new_stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()));
			sc_position_initialize_fib_based_values(sc, index, round_to_ticksize_trade(sc, _new_stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()), round_to_ticksize_trade(sc, target.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()), position);
			sc_position_hide_breakeven(sc);
		}
	}
	else {
		if (_target != 0 && _stop != 0) {
			float tick = (1 * sc.TickSize);

			if ((abs(target.Price1 - _last_price) < _price_trail_offset)) {
				float _proposed_new_price = target.Price1 - _price_trail_offset;
				std::pair <int, s_SCNewOrder> _new_target = lib_trade_modify_target(sc, index, position.PositionQuantity, target, _price_trail_offset, _proposed_new_price, 0);
				if (_new_target.first == 1)
					sc.SetPersistentFloat(_P_POSITION_TARGET, round_to_ticksize_trade(sc, _new_target.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()));
			}

			if (_is_auto_trail) {
				if (_last_price < _trail_target) {

					if (stop.Price1 > _trail_stop) {
						std::pair <int, s_SCNewOrder> _new_stop = lib_trade_modify_stop(sc, index, position.PositionQuantity, stop, _price_trail_offset, _trail_stop, 0);
						if (_new_stop.first == 1)
							sc.SetPersistentFloat(_P_POSITION_STOP, round_to_ticksize_trade(sc, _new_stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()));
					}

					_trail_target = round_to_ticksize_trade(sc, _trail_target - _price_trail_offset, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
					_trail_stop = round_to_ticksize_trade(sc, _trail_stop - _price_trail_offset, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
				}
			}

		}
	}
}


int sc_position_iterate_position(SCStudyInterfaceRef sc, int index, s_SCPositionData &position, s_SCTradeOrder stop, s_SCTradeOrder target)
{
	float _price_trail_offset = sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].GetFloat() * sc.TickSize;

	if (position.PositionQuantity != 0) {


		if (position.PositionQuantity > 0) {
			if (position.AveragePrice <= (stop.Price1 + _price_trail_offset) && sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0)
				sc_position_hide_breakeven(sc);
			sc_position_iterate_long(sc, index, position, stop, target);
		}
		if (position.PositionQuantity < 0) {
			if (position.AveragePrice >= (stop.Price1 - _price_trail_offset) && sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0)
				sc_position_hide_breakeven(sc);
			sc_position_iterate_short(sc, index, position, stop, target);
		}
	}

	return 1;
}


void sc_position_clear_values(SCStudyInterfaceRef sc, int index)
{
	sc.SetPersistentFloat(_P_POSITION_TRAIL_TARGET, 0);
	sc.SetPersistentFloat(_P_POSITION_TRAIL_STOP, 0);
	sc.SetPersistentFloat(_P_POSITION_BREAKEVEN, 0);
	sc.SetPersistentFloat(_P_POSITION_TARGET, 0);
	sc.SetPersistentFloat(_P_POSITION_STOP, 0);

	sc.SetPersistentInt(_P_POSITION_LAST_INDEX_LOOPED, 0);
	sc.SetPersistentFloat(_P_POSITION_LAST_QUANTITY, 0);
}

void sc_position_update_values(SCStudyInterfaceRef sc, int index)
{
	sc.Subgraph[_SG_POSITION_TARGET][index] = sc.GetPersistentFloat(_P_POSITION_TARGET);
	sc.Subgraph[_SG_POSITION_STOP][index] = sc.GetPersistentFloat(_P_POSITION_STOP);

	if (sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0) {
		sc.Subgraph[_SG_POSITION_BREAKEVEN][index] = sc.GetPersistentFloat(_P_POSITION_BREAKEVEN);
	}
	else {
		sc.Subgraph[_SG_POSITION_TRAIL_TARGET][index] = sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);
		sc.Subgraph[_SG_POSITION_TRAIL_STOP][index] = sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);
	}
}


void sc_position_initialize(SCStudyInterfaceRef sc, int current_index, s_SCPositionData &position, s_SCTradeOrder stop, s_SCTradeOrder target)
{
#ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog("POSITION MANAGEMENT: Initializing!", 1);
	}
#endif

	//int index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, position.LastEntryDateTime);

	//int & LastIndexLooped = sc.GetPersistentInt(_P_POSITION_LAST_INDEX_LOOPED);

	//float _last_price = sc.Close[index];
	//float _price_trail_offset = sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].GetFloat() * sc.TickSize;

	//int _is_auto_trail = sc.Input[_I_POSITION_AUTOTRAIL].GetInt();

	sc_position_initialize_fib_based_values(sc, current_index, round_to_ticksize_trade(sc, stop.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()), round_to_ticksize_trade(sc, target.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()), position);

	sc_position_show_breakeven(sc);
	//sc.SetPersistentInt(_P_POSITION_T_S_LOCKED, 0);
}

/*==========================================================================*/
SCSFExport scsf_Position_Management(SCStudyInterfaceRef sc)
{

	sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;
	sc.SendOrdersToTradeService = sc.Input[_I_POSITION_REAL_SIMULATION].GetInt();


	// EVENTS REGION
	if (sc.SetDefaults) {
		sc_position_set_defaults(sc);
		return;
	}


	if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif



		std::ifstream file = read_conf(sc);

		if (file.good()) {
			float breakeven, trail_target, trail_stop, atr_mult;
			int use_ext_atr;
			file >> breakeven >> trail_target >> trail_stop >> atr_mult >> use_ext_atr;

			sc.Input[_I_BREAKEVEN_FIB].SetFloat(breakeven);
			sc.Input[_I_TRAIL_TARGET_FIB].SetFloat(trail_target);
			sc.Input[_I_TRAIL_STOP_FIB].SetFloat(trail_stop);
			sc.Input[_I_POSITION_ATR_MULT].SetFloat(atr_mult);
			sc.Input[_I_POSITION_USE_EXT_ATR].SetInt(use_ext_atr);

			file.close();
		}

		sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].SetInt(load_ticksize_multiplier_from_file(sc));


		if (sc.Input[_I_POSITION_USE_EXT_ATR].GetInt() == 0) {
			SCString atr_path;

			std::ifstream atr_input(atr_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "atr"));

			if (atr_input.is_open()) {
				int atr;
				atr_input >> atr;
				sc.Input[_I_POSITION_PRICE_TRAIL_OFFSET].SetInt(sc.Round(atr * sc.Input[_I_POSITION_ATR_MULT].GetFloat()));
				atr_input.close();
			}
		}


		SCString realsim_path;
		std::ifstream realsim_input(realsim_path.Format("conf/%s.conf", "realsim"));
		if (realsim_input.is_open()) {
			int realsim;
			realsim_input >> realsim;

			sc.Input[_I_POSITION_REAL_SIMULATION].SetInt(realsim);

			realsim_input.close();
		}
		else
			sc.AddMessageToLog(realsim_path + ": Error opening file", 0);
	}

	if (sc_position_skip_iteration(sc))
		return;

	// Remove Trade Management
	int last_call = sc_position_last_call(sc);
	if (last_call)
		return;

	// LOOP ITERATION REGION

	//sc_position_initialize(sc, sc.Index, _position);
	//else

	if (sc.IsFullRecalculation) {		
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Full Recalculation", 0);
#endif

		sc_position_update_values(sc, sc.Index);
		return;
	}

#ifdef _CONST_DEBUG
	SCString log;
	sc.AddMessageToLog(log.Format("%d updatestart, %d index", sc.UpdateStartIndex, sc.Index), 0);
#endif
	//if (true || sc.UpdateStartIndex < sc.Index) {
		if (sc.Input[_I_POSITION_ENABLED].GetInt() == 1) {
#ifdef _CONST_DEBUG
			sc.AddMessageToLog("Position Enabled", 0);
#endif

			s_SCPositionData _position;
			sc.GetTradePosition(_position);

			if (_position.PositionQuantity != 0.0) {
				
				

				std::pair <int, s_SCTradeOrder> stop = lib_trade_find_stop(sc);
				std::pair <int, s_SCTradeOrder> target = lib_trade_find_target(sc);

				//            float tick = 1 * sc.TickSize;

				if (stop.first == 1 && target.first == 1) {
										
					float _r_stop_price = round_to_ticksize_trade(sc, stop.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());
					float _r_target_price = round_to_ticksize_trade(sc, target.second.Price1, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());

					if (sc.GetPersistentFloat(_P_POSITION_LAST_QUANTITY) == 0 || _r_stop_price != round_to_ticksize_trade(sc, sc.GetPersistentFloat(_P_POSITION_STOP), sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()) || _r_target_price != round_to_ticksize_trade(sc, sc.GetPersistentFloat(_P_POSITION_TARGET), sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt())) {
#ifdef _CONST_DEBUG
						SCString log;
						sc.AddMessageToLog(log.Format("%f == %f, %f == %f", _r_stop_price, round_to_ticksize_trade(sc, sc.GetPersistentFloat(_P_POSITION_STOP), sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt()), _r_target_price, round_to_ticksize_trade(sc, sc.GetPersistentFloat(_P_POSITION_TARGET), sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt())), 0);
#endif
						sc_position_initialize(sc, sc.Index, _position, stop.second, target.second);
						sc.SetPersistentFloat(_P_POSITION_LAST_QUANTITY, _position.PositionQuantity);
					}
					else {
						if (sc.GetPersistentInt(_P_HIDE_BREAKEVEN) == 0) {
							if (sc.MenuEventID == ACS_BUTTON_21 && sc.PointerEventType == SC_ACS_BUTTON_ON) {

								sc.AddMessageToLog("Breakeven adjust", 0);

								float Mouse = round_to_ticksize_trade(sc, sc.ActiveToolYValue, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());

								int long_valid = _position.PositionQuantity > 0 && Mouse > _position.AveragePrice && Mouse > _r_stop_price && Mouse < _r_target_price;
								int short_valid = _position.PositionQuantity < 0 && Mouse < _position.AveragePrice && Mouse < _r_stop_price && Mouse > _r_target_price;

								if (long_valid || short_valid)
									sc.SetPersistentFloat(_P_POSITION_BREAKEVEN, Mouse);

								sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_21, 0);
							}
						}
						else {
							if (sc.MenuEventID == ACS_BUTTON_22 && sc.PointerEventType == SC_ACS_BUTTON_ON) {
								float Mouse = round_to_ticksize_trade(sc, sc.ActiveToolYValue, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());

								int long_valid = _position.PositionQuantity > 0 && Mouse > _position.AveragePrice && Mouse > _r_stop_price && Mouse < _r_target_price && Mouse < sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);
								int short_valid = _position.PositionQuantity < 0 && Mouse < _position.AveragePrice && Mouse < _r_stop_price && Mouse > _r_target_price && Mouse > sc.GetPersistentFloat(_P_POSITION_TRAIL_TARGET);

								if (long_valid || short_valid)
									sc.SetPersistentFloat(_P_POSITION_TRAIL_STOP, Mouse);

								sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_22, 0);
							}
							if (sc.MenuEventID == ACS_BUTTON_23 && sc.PointerEventType == SC_ACS_BUTTON_ON) {
								float Mouse = round_to_ticksize_trade(sc, sc.ActiveToolYValue, sc.Input[_I_POSITION_TICKSIZE_MULTIPLIER].GetInt());

								int long_valid = _position.PositionQuantity > 0 && Mouse > _position.AveragePrice && Mouse > _r_stop_price && Mouse < _r_target_price && Mouse > sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);
								int short_valid = _position.PositionQuantity < 0 && Mouse < _position.AveragePrice && Mouse < _r_stop_price && Mouse > _r_target_price && Mouse < sc.GetPersistentFloat(_P_POSITION_TRAIL_STOP);

								if (long_valid || short_valid)
									sc.SetPersistentFloat(_P_POSITION_TRAIL_TARGET, Mouse);

								sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_23, 0);
							}
						}

						if (sc.GetPersistentInt(_P_POSITION_LAST_INDEX_LOOPED) != sc.Index)
							sc_position_update_values(sc, sc.Index);
					}
					sc_position_iterate_position(sc, sc.Index, _position, stop.second, target.second);
				}
			}
			else {
				if (sc.GetPersistentFloat(_P_POSITION_LAST_QUANTITY) != 0) {
					sc_position_clear_values(sc, sc.Index);
					sc.FlagFullRecalculate = 1;
				}
			}
		}
	//}
}
