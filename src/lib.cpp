#include "lib.h"

std::ifstream read_conf(SCStudyInterfaceRef sc, SCString chartbookname, SCString studyname) {
	SCString path;

	std::ifstream input_number(path.Format("conf/%s/%d-%s.conf", chartbookname.GetChars(), sc.ChartNumber, studyname.GetChars()));
	if (input_number.good())
		return input_number;

	std::ifstream input(path.Format("conf/%s/%s.conf", chartbookname.GetChars(), studyname.GetChars()));
	if (input.good())
		return input;

	std::ifstream input_global_number(path.Format("conf/%d-%s.conf", sc.ChartNumber, studyname.GetChars()));
	if (input_global_number.good())
		return input_global_number;

	std::ifstream input_global(path.Format("conf/%s.conf", studyname.GetChars()));
	if (input_global.good())
		return input_global;

	return input_global;
	// #ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog(path + ": Error opening file", 0);
	}
	// #endif
}

std::ifstream read_conf(SCStudyInterfaceRef sc) {
	return read_conf(sc, sc.ChartbookName().GetChars(), sc.GraphShortName);
}


int read_conf_single_int(SCStudyInterfaceRef sc, SCString name) {
	SCString file_path;

	std::ifstream file_input(file_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), name.GetChars()));

	if (file_input.is_open()) {
		int value;
		file_input >> value;
		file_input.close();
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog(log.Format("Value for %s: %d", name, value), 1);
#endif
		return value;
	}
    return -1;
}

SCString alert_path(SCStudyInterfaceRef sc, SCString type, SCString extra) {
	SCString path;
	path.Format("alert/%s/%s-%s.wav", sc.ChartbookName().GetChars(), type.GetChars(), extra.GetChars());

#ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog(path + " Sound file", 0);
	}
#endif

	return path;
}
float calc_fib(SCStudyInterfaceRef sc, float fiblevel, float begin, float end)
{
	float price = begin - (begin - end) * ((100 - fiblevel) / 100);
	return sc.RoundToTickSize(price, sc.TickSize);
}
float calc_fib_f(SCStudyInterfaceRef sc, float fiblevel, float begin, float end)
{
	float price = begin - (begin - end) * ((100 - fiblevel) / 100);
	return sc.RoundToTickSize(price, sc.TickSize);
}
float calc_currency_with_position(SCStudyInterfaceRef sc, float distance, SCString& common_currency)
{
	s_SCPositionData position;
	sc.GetTradePosition(position);

	float c = sc.ConvertCurrencyValueToCommonCurrency(sc.CurrencyValuePerTick, sc.GetTradeSymbol(), common_currency) * (sc.TradeWindowOrderQuantity + abs(position.PositionQuantity));

	return ((c * distance) / sc.TickSize);
}
float calc_entry_zone_currency_with_position(SCStudyInterfaceRef sc, int max_stop, SCString common_currency) {
	s_SCPositionData position;
	sc.GetTradePosition(position);

	float currency_value = sc.ConvertCurrencyValueToCommonCurrency(sc.CurrencyValuePerTick, sc.GetTradeSymbol(), common_currency);

	//if (currency_value > 1)
	//	return (max_stop / (currency_value * (sc.TradeWindowOrderQuantity + abs(position.PositionQuantity)))) * sc.TickSize;
	//else
	return (max_stop / (currency_value * (sc.TradeWindowOrderQuantity + abs(position.PositionQuantity)))) * sc.TickSize;
}
int Draw_Update_Text(SCStudyInterfaceRef sc, COLORREF color, float currency_value, float vertical_value, int linenumber)
{
	s_UseTool Tool;

	SCString text;
	Tool.Text = text.Format("%.1f", currency_value);
	Tool.Color = color;
	Tool.BeginDateTime = -10;
	Tool.BeginValue = vertical_value;

	if (linenumber)
	{
		Tool.LineNumber = linenumber;
		Tool.AddMethod = UTAM_ADD_OR_ADJUST;
		sc.UseTool(Tool);
		return linenumber;
	}
	else {
		Tool.ChartNumber = sc.ChartNumber;
		Tool.Region = 0;
		Tool.AddAsUserDrawnDrawing = 0;
		Tool.AddMethod = UTAM_ADD_OR_ADJUST;
		Tool.DrawingType = DRAWING_TEXT;
		Tool.UseRelativeVerticalValues = false;
		Tool.Color = color;
		Tool.FontSize = 8;
		Tool.ReverseTextColor = 1;
		Tool.FontBold = 1;
		Tool.TextAlignment = 1;
		sc.UseTool(Tool);
		return Tool.LineNumber;
	}

}
int Draw_RECT(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int save_cb, int extended_rectangle, int linenumber)
{
	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;

	if (!as_user && linenumber != 0)
		Tool.LineNumber = linenumber;

	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = save_cb;
	Tool.LockDrawing = 1;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;

	if (extended_rectangle)
		Tool.DrawingType = DRAWING_RECTANGLE_EXT_HIGHLIGHT;
	else
		Tool.DrawingType = DRAWING_RECTANGLEHIGHLIGHT;

	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = endindex;

	Tool.BeginValue = entry;
	Tool.EndValue = extension;

	sc.UseTool(Tool);
#ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog(log.Format("Rect Line Number: %d", Tool.LineNumber), 0);
	}
#endif
	return Tool.LineNumber;

}
int Draw_FIB(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int saveChartbook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;

	if (!as_user && linenumber != 0)
		Tool.LineNumber = linenumber;

	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartbook;
	Tool.DrawingType = DRAWING_RETRACEMENT;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = endindex;

	Tool.BeginValue = entry;
	Tool.EndValue = extension;

	sc.UseTool(Tool);
	return Tool.LineNumber;
}
int Draw_ARROW(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int saveChartbook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;

	if (linenumber != 0)
		Tool.LineNumber = linenumber;

	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartbook;
	Tool.DrawingType = DRAWING_ARROW;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = endindex;

	Tool.BeginValue = entry;
	Tool.EndValue = extension;

	sc.UseTool(Tool);
	return Tool.LineNumber;
}
int Draw_HRray(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int save_chartbook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = save_chartbook;
	Tool.DrawingType = DRAWING_HORIZONTAL_RAY;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = startindex + 1;

	Tool.BeginValue = entry;
	Tool.EndValue = entry;

	sc.UseTool(Tool);

#ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog(log.Format("HRray Number: %d", Tool.LineNumber), 0);
	}
#endif

	return Tool.LineNumber;
}
s_UseTool Draw_OHLC_Rray(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = as_user;
	Tool.DrawingType = DRAWING_OHLC_RAY;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	//    Tool.EndIndex = startindex + 1;

	Tool.BeginValue = entry;
	//    Tool.EndValue = entry;

	sc.UseTool(Tool);
	return Tool;
}
s_UseTool Draw_HLine(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartBook;
	Tool.DrawingType = DRAWING_HORIZONTALLINE;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = startindex + 1;

	Tool.BeginValue = entry;
	Tool.EndValue = entry;

	sc.UseTool(Tool);
	return Tool;
}
s_UseTool Draw_HLine(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int locked, int linenumber, SCString text)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartBook;
	Tool.DrawingType = DRAWING_HORIZONTALLINE;
	Tool.UseToolConfigNum = toolconfig;
	Tool.LockDrawing = locked;
	Tool.Text = text;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = startindex + 1;

	Tool.BeginValue = entry;
	Tool.EndValue = entry;

	sc.UseTool(Tool);
	return Tool;
}
s_UseTool Draw_HLineNE(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartBook;
	Tool.DrawingType = DRAWING_HORIZONTAL_LINE_NON_EXTENDED;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = endindex;

	Tool.BeginValue = entry;
	Tool.EndValue = entry;

	sc.UseTool(Tool);
	return Tool;
}
s_UseTool Draw_Marker(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber)
{

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	if (linenumber)
		Tool.LineNumber = linenumber;
	Tool.Region = 0;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = as_user;
	Tool.AllowSaveToChartbook = saveChartBook;
	Tool.DrawingType = DRAWING_MARKER;
	Tool.UseToolConfigNum = toolconfig;

	Tool.BeginIndex = startindex;
	Tool.EndIndex = startindex;

	Tool.BeginValue = entry;
	Tool.EndValue = entry;

	sc.UseTool(Tool);
	return Tool;
}
int process_new_mouse_zone(SCStudyInterfaceRef sc, int& IndexBegin, int& IndexEnd, float& BeginPrice, float& EndPrice, int& OrderType, int& Length, int MouseStart, int MouseEnd)
{
	int success = 0;
	if (MouseStart != 0 && MouseEnd != 0)
	{
		int _length = abs(MouseStart - MouseEnd) + 1;
		int _endindex = MouseEnd;


		int _low_index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, _length);
		int _high_index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, _length);

#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog(log.Format("_low_index: %d, _high_index_: %d, size: %d", _low_index, _high_index, sc.ArraySize), 1);
#endif

		if (_low_index < _high_index)
		{
			IndexBegin = _low_index;
			IndexEnd = _high_index;
			OrderType = 1;
			BeginPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);
			EndPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);
		}

		if (_low_index > _high_index)
		{
			IndexBegin = _high_index;
			IndexEnd = _low_index;
			OrderType = -1;
			BeginPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);
			EndPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);
		}

		success = 1;
	}

	Length = abs(IndexBegin - IndexEnd);

#ifdef _CONST_DEBUG
	SCString log;
	sc.AddMessageToLog(log.Format("IndexBegin: %d, IndexEnd: %d, BeginPrice: %f, EndPrice: %f, OrderType: %d, Length: %d, MouseStart: %d, MouseEnd: %d", IndexBegin, IndexEnd, BeginPrice, EndPrice, OrderType, Length, MouseStart, MouseEnd), 1);
#endif


	return success;
}
//vbp
int process_new_mouse_zone(SCStudyInterfaceRef sc, int& IndexBegin, int& IndexEnd, int& ThirdIndex, float& BeginPrice, float& EndPrice, float& ThirdPrice, int& OrderType, int& Length, int MouseStart, int MouseEnd)
{
	int success = 0;

#ifdef _CONST_DEBUG
	{
		SCString log;
		sc.AddMessageToLog(log.Format("Processing new mouse zone: %d - %d", MouseStart, MouseEnd), 1);
	}
#endif

	if (MouseStart != 0 && MouseEnd != 0)
	{
		int _length = abs(MouseStart - MouseEnd) + 1;
		int _endindex = MouseEnd;


		int _low_index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, _length);
		int _high_index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, _length);

#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog(log.Format("_low_index: %d, _high_index_: %d, size: %d", _low_index, _high_index, sc.ArraySize), 1);
#endif

		if (_low_index < _high_index)
		{
			IndexBegin = _low_index;
			IndexEnd = _high_index;
			OrderType = 1;
			BeginPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);
			EndPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);

			//            int _third_length = abs(_endindex - _high_index);
			int _third_length = abs(_low_index - MouseStart);
			if (_third_length == 0) {
				ThirdIndex = _low_index;
				ThirdPrice = BeginPrice;
			}
			//            else {
			//                ThirdIndex = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, _third_length);
			//                ThirdPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _third_length);
			//            }
			else {
				ThirdIndex = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _low_index, _third_length + 1);
				ThirdPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _low_index, _third_length + 1);
			}


		}

		if (_low_index > _high_index)
		{
			IndexBegin = _high_index;
			IndexEnd = _low_index;
			OrderType = -1;
			BeginPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);
			EndPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);

			//            int _third_length = abs(_endindex - _low_index);
			int _third_length = abs(_high_index - MouseStart);
			if (_third_length == 0) {
				ThirdIndex = _high_index;
				ThirdPrice = BeginPrice;
			}
			//            else {
			//                ThirdIndex = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, _third_length);
			//                ThirdPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _third_length);
			//            }
			else {
				ThirdIndex = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _high_index, _third_length + 1);
				ThirdPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _high_index, _third_length + 1);
			}

		}

		success = 1;
	}

	Length = abs(IndexBegin - IndexEnd);

#ifdef _CONST_DEBUG
	SCString log;
	sc.AddMessageToLog(log.Format("IndexBegin: %d, IndexEnd: %d, BeginPrice: %f, EndPrice: %f, OrderType: %d, Length: %d, MouseStart: %d, MouseEnd: %d", IndexBegin, IndexEnd, BeginPrice, EndPrice, OrderType, Length, MouseStart, MouseEnd), 1);
#endif

	return success;
}
int process_new_drawing(SCStudyInterfaceRef sc, int& IndexBegin, int& IndexEnd, int& ThirdIndex, float& BeginPrice, float& EndPrice, float& ThirdPrice, float& GoldenMean, int& OrderType, int& Length, DrawingTypeEnum drawing_type, s_UseTool& chartDrawing, int use_fetched_drawing)
{
	int success = 0;
	int chart_drawing_found = use_fetched_drawing;
	if (!use_fetched_drawing)
	{
		chart_drawing_found = sc.GetUserDrawnChartDrawing(sc.ChartNumber, drawing_type, chartDrawing, -1);
	}
	if (chart_drawing_found > 0)
	{
		Length = (chartDrawing.EndIndex - chartDrawing.BeginIndex) + 1;
		int _endindex = chartDrawing.EndIndex;


		int _low_index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, Length);
		int _high_index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, Length);

		ThirdIndex = chartDrawing.ThirdIndex;
		ThirdPrice = chartDrawing.ThirdValue;

		if (_low_index < _high_index)
		{
			IndexBegin = _low_index;
			IndexEnd = _high_index;
			OrderType = 1;
			BeginPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, Length);
			EndPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, Length);
			if (chartDrawing.DrawingType == DRAWING_PRICE_PROJECTION)
			{
				int _third_index = ThirdIndex;
				int _third_length = abs(ThirdIndex - IndexEnd);
				ThirdIndex = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _third_index, _third_length);
				ThirdPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _third_index, _third_length);
			}
			else if (chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT)
			{
				int _third_index = 0;
				int _third_length = (_low_index - chartDrawing.BeginIndex) + 1;
				ThirdIndex = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _low_index, _third_length);
				ThirdPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _low_index, _third_length);
			}

		}

		if (_low_index > _high_index)
		{
			IndexBegin = _high_index;
			IndexEnd = _low_index;
			OrderType = -1;
			BeginPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, Length);
			EndPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, Length);
			if (chartDrawing.DrawingType == DRAWING_PRICE_PROJECTION)
			{
				int _third_index = ThirdIndex;
				int _third_length = abs(ThirdIndex - IndexEnd);
				ThirdIndex = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _third_index, _third_length);
				ThirdPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _third_index, _third_length);
			}
			else if (chartDrawing.DrawingType == DRAWING_RECTANGLE_EXT_HIGHLIGHT)
			{
				int _third_index = 0;
				int _third_length = (_high_index - chartDrawing.BeginIndex) + 1;
				ThirdIndex = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _high_index, _third_length);
				ThirdPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _high_index, _third_length);
			}

		}


		GoldenMean = calc_fib(sc, 61.8, BeginPrice, EndPrice);
		success = 1;
	}

	return success;
}
void create_clone_drawing(SCStudyInterfaceRef sc, int IndexBegin, int IndexEnd, int ThirdIndex, float BeginPrice, float EndPrice, float ThirdPrice, float GoldenMean, int OrderType, int Length, DrawingTypeEnum drawing_type, int toolconfig, int lineNumber, s_UseTool& cloneDrawing)
{

	cloneDrawing.BeginIndex = IndexBegin;
	cloneDrawing.BeginValue = BeginPrice;
	cloneDrawing.EndIndex = IndexEnd;
	cloneDrawing.EndValue = EndPrice;
	cloneDrawing.UseToolConfigNum = toolconfig;
	cloneDrawing.AddMethod = UTAM_ADD_OR_ADJUST;
	cloneDrawing.AddAsUserDrawnDrawing = 1;
	cloneDrawing.AllowSaveToChartbook = 1;
	cloneDrawing.HideDrawing = 0;
	cloneDrawing.DrawingType = drawing_type;
	cloneDrawing.ThirdIndex = ThirdIndex;
	cloneDrawing.ThirdValue = ThirdPrice;
	if (lineNumber)
		cloneDrawing.LineNumber = lineNumber;

}
int tool_range_selection(SCStudyInterfaceRef sc, int BUTTON, int& ACS_BUTTON_STATE, int& MouseStart, int& MouseEnd) {
	int& MouseStartDrawing = sc.GetPersistentInt(131);
	int& MouseMoveDrawing = sc.GetPersistentInt(132);

	if (sc.PointerEventType == SC_ACS_BUTTON_ON)
	{
		ACS_BUTTON_STATE = BUTTON;
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 ON", 1);
#endif

		s_UseTool vline1;
		vline1.DrawingType = DRAWING_VERTICALLINE;
		//vline1.DrawingType = DRAWING_HORIZONTALLINE;
		vline1.BeginIndex = sc.ActiveToolIndex;
		//vline1.BeginValue = sc.ActiveToolYValue;
		vline1.AddMethod = UTAM_ADD_OR_ADJUST;
		vline1.UseToolConfigNum = 7;
		sc.UseTool(vline1);
		MouseMoveDrawing = vline1.LineNumber;
		return 1;
	}

	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_ACS_BUTTON_OFF)
	{
		ACS_BUTTON_STATE = 0;
		MouseStart = -1;
		MouseEnd = -1;
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseStartDrawing);
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseMoveDrawing);
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 OFF", 1);
#endif

		return -1;
	}

	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_POINTER_MOVE) {
		if (MouseStart < 0) {
			s_UseTool vline1;
			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, MouseMoveDrawing, vline1) != 0) {
				vline1.BeginIndex = sc.ActiveToolIndex;
				//vline1.BeginValue = sc.ActiveToolYValue;				
				vline1.AddMethod = UTAM_ADD_OR_ADJUST;
				sc.UseTool(vline1);
			}
		}
		if (MouseStart >= 0) {
			s_UseTool vline2;
			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, MouseMoveDrawing, vline2) != 0) {
				vline2.BeginIndex = sc.ActiveToolIndex;
				vline2.AddMethod = UTAM_ADD_OR_ADJUST;
				sc.UseTool(vline2);
			}
		}
		return 0;
	}
	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_POINTER_BUTTON_DOWN) {
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 Mouse Down", 1);
		sc.AddMessageToLog(log.Format("Index: %d", sc.ActiveToolIndex), 1);

#endif

		if (MouseStart < 0) {
			MouseStart = sc.ActiveToolIndex;
			s_UseTool vline2;
			vline2.DrawingType = DRAWING_VERTICALLINE;
			vline2.BeginIndex = sc.ActiveToolIndex;
			vline2.AddMethod = UTAM_ADD_OR_ADJUST;
			vline2.UseToolConfigNum = 8;
			sc.UseTool(vline2);
			MouseStartDrawing = vline2.LineNumber;
			return 2;
		}
		else if (MouseEnd < 0)
			MouseEnd = sc.ActiveToolIndex;

		if (MouseStart >= 0 && MouseEnd >= 0) {
#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog("Trade Coordinates aquired", 1);
#endif

			if (MouseStart > MouseEnd) {
				int temp;
				temp = MouseEnd;
				MouseEnd = MouseStart;
				MouseStart = temp;
			}
			return 3;
		}
	}

	if (ACS_BUTTON_STATE == -1) {
		sc.SetCustomStudyControlBarButtonEnable(BUTTON, 0);
		ACS_BUTTON_STATE = 0;
		MouseStart = 0;
		MouseEnd = 0;
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseStartDrawing);
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseMoveDrawing);
		return -2;
	}

	return 0;
}
void show_hide_drawings(SCStudyInterfaceRef sc, int hide) {
	s_UseTool _hide_drawing;
	/*int _chart_count = sc.GetACSDrawingsCount(sc.ChartNumber, 0);
	for (int _index = 0; _index < _chart_count; _index++) {
		if (sc.GetACSDrawingByIndex(sc.ChartNumber, _index, _hide_drawing, 0) != 0)
		{
			_hide_drawing.HideDrawing = hide;
			_hide_drawing.AddMethod = UTAM_ADD_OR_ADJUST;
			sc.UseTool(_hide_drawing);
		}
		else
			_index = -1;
	}*/

	int _index = 0;
	while (sc.GetUserDrawnChartDrawing(sc.ChartNumber, DRAWING_UNKNOWN, _hide_drawing, _index) != 0)
	{
		if (_hide_drawing.HideDrawing != hide) {
			_hide_drawing.HideDrawing = hide;
			_hide_drawing.AddMethod = UTAM_ADD_OR_ADJUST;
			sc.UseTool(_hide_drawing);
		}
		_index++;
	}

}
int process_new_zone(SCStudyInterfaceRef sc, int& IndexBegin, int& IndexEnd, int& ThirdIndex, float& BeginPrice, float& EndPrice, float& ThirdPrice, int& OrderType, int& Length, SCDateTime Start, SCDateTime End)
{
	int success = 0;
	int _date_start_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, Start);
	int _date_end_index = sc.GetContainingIndexForSCDateTime(sc.ChartNumber, End);


	if (_date_start_index > 0 && _date_end_index > _date_start_index)
	{
#ifdef _CONST_DEBUG
		{
			SCString log;
			sc.AddMessageToLog(log.Format("Processing new zone: %d - %d", _date_start_index, _date_end_index), 1);
		}
#endif

		int _length = abs(_date_start_index - _date_end_index) + 1;
		int _endindex = _date_end_index;


		int _low_index = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, _length);
		int _high_index = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, _length);

#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog(log.Format("_low_index: %d, _high_index_: %d, size: %d", _low_index, _high_index, sc.ArraySize), 1);
#endif

		if (_low_index < _high_index)
		{
			IndexBegin = _low_index;
			IndexEnd = _high_index;
			OrderType = 1;
			BeginPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);
			EndPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);

			int _third_length = abs(_endindex - _high_index);
			if (_third_length == 0) {
				ThirdIndex = _high_index;
				ThirdPrice = EndPrice;
			}
			else {
				ThirdIndex = sc.GetIndexOfLowestValue(sc.BaseDataIn[SC_LOW], _endindex, _third_length);
				ThirdPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _third_length);
			}
		}

		if (_low_index > _high_index)
		{
			IndexBegin = _high_index;
			IndexEnd = _low_index;
			OrderType = -1;
			BeginPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _length);
			EndPrice = sc.GetLowest(sc.BaseDataIn[SC_LOW], _endindex, _length);

			int _third_length = abs(_endindex - _low_index);
			if (_third_length == 0) {
				ThirdIndex = _low_index;
				ThirdPrice = EndPrice;
			}
			else {
				ThirdIndex = sc.GetIndexOfHighestValue(sc.BaseDataIn[SC_HIGH], _endindex, _third_length);
				ThirdPrice = sc.GetHighest(sc.BaseDataIn[SC_HIGH], _endindex, _third_length);
			}
		}

		success = 1;
	}
	else return success;
	Length = abs(IndexBegin - IndexEnd);

#ifdef _CONST_DEBUG
	SCString log;
	sc.AddMessageToLog(log.Format("IndexBegin: %d, IndexEnd: %d, BeginPrice: %f, EndPrice: %f, OrderType: %d, Length: %d, Start: %s, End: %s", IndexBegin, IndexEnd, BeginPrice, EndPrice, OrderType, Length, sc.DateTimeToString(Start, 0), sc.DateTimeToString(End, 0)), 1);
#endif

	return success;
}


int tool_index_selection(SCStudyInterfaceRef sc, int BUTTON, int& ACS_BUTTON_STATE, int& MouseStart) {
	int& MouseStartDrawing = sc.GetPersistentInt(133);
	int& MouseMoveDrawing = sc.GetPersistentInt(134);

	if (sc.PointerEventType == SC_ACS_BUTTON_ON)
	{
		ACS_BUTTON_STATE = BUTTON;
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 ON", 1);
#endif

		s_UseTool vline1;
		vline1.DrawingType = DRAWING_VERTICALLINE;
		//vline1.DrawingType = DRAWING_HORIZONTALLINE;
		vline1.BeginIndex = sc.ActiveToolIndex;
		//vline1.BeginValue = sc.ActiveToolYValue;
		vline1.AddMethod = UTAM_ADD_OR_ADJUST;
		vline1.UseToolConfigNum = 7;
		sc.UseTool(vline1);
		MouseMoveDrawing = vline1.LineNumber;
		return 1;
	}

	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_ACS_BUTTON_OFF)
	{
		ACS_BUTTON_STATE = 0;
		MouseStart = -1;
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseStartDrawing);
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseMoveDrawing);
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 OFF", 1);
#endif

		return -1;
	}

	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_POINTER_MOVE) {
		if (MouseStart < 0) {
			s_UseTool vline1;
			if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, MouseMoveDrawing, vline1) != 0) {
				vline1.BeginIndex = sc.ActiveToolIndex;
				vline1.AddMethod = UTAM_ADD_OR_ADJUST;
				sc.UseTool(vline1);
			}
		}
		return 0;
	}

	if (ACS_BUTTON_STATE == BUTTON && sc.PointerEventType == SC_POINTER_BUTTON_DOWN) {
#ifdef _CONST_DEBUG
		SCString log;
		sc.AddMessageToLog("Button 2 Mouse Down", 1);
#endif
		if (MouseStart < 0) {
			MouseStart = sc.ActiveToolIndex;		
#ifdef _CONST_DEBUG
			SCString log;
			sc.AddMessageToLog("Trade Coordinates aquired", 1);
#endif

			return 3;
		}
	}

	if (ACS_BUTTON_STATE == -1) {
		sc.SetCustomStudyControlBarButtonEnable(BUTTON, 0);
		ACS_BUTTON_STATE = 0;
		MouseStart = -1;
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseStartDrawing);
		sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, MouseMoveDrawing);
		return -2;
	}

	return 0;
}
