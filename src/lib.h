#include "main.h"

#ifndef LIB_H
#define LIB_H

std::ifstream read_conf(SCStudyInterfaceRef sc, SCString chartbookname, SCString studyname);
std::ifstream read_conf(SCStudyInterfaceRef sc);
int read_conf_single_int(SCStudyInterfaceRef sc, SCString name);

SCString alert_path(SCStudyInterfaceRef sc, SCString type, SCString extra);
float calc_fib(SCStudyInterfaceRef sc, float fiblevel, float begin, float end);
float calc_fib_f(SCStudyInterfaceRef sc, float fiblevel, float begin, float end);
float calc_currency_with_position(SCStudyInterfaceRef sc, float distance, SCString& common_currency);
float calc_entry_zone_currency_with_position(SCStudyInterfaceRef sc, int max_stop, SCString common_currency);
int Draw_Update_Text(SCStudyInterfaceRef sc, COLORREF color, float currency_value, float vertical_value, int linenumber);
int Draw_RECT(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int save_cb, int extended_rectangle, int linenumber);
int Draw_FIB(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int saveChartbook, int linenumber);
int Draw_ARROW(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, float extension, int toolconfig, int as_user, int saveChartbook, int linenumber);
s_UseTool Draw_Marker(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber);
int Draw_HRray(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int save_chartbook, int linenumber);
s_UseTool Draw_HLine(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber);
s_UseTool Draw_HLine(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int saveChartBook, int locked, int linenumber, SCString text);
s_UseTool Draw_HLineNE(SCStudyInterfaceRef sc, int startindex, int endindex, float entry, int toolconfig, int as_user, int saveChartBook, int linenumber);
int process_new_mouse_zone(SCStudyInterfaceRef sc, int & IndexBegin, int &IndexEnd, float & BeginPrice, float & EndPrice, int & OrderType, int & Length, int MouseStart, int MouseEnd);
int process_new_mouse_zone(SCStudyInterfaceRef sc, int & IndexBegin, int &IndexEnd, int &ThirdIndex, float &BeginPrice, float &EndPrice, float &ThirdPrice, int & OrderType, int & Length, int MouseStart, int MouseEnd);
int process_new_drawing(SCStudyInterfaceRef sc, int & IndexBegin, int &IndexEnd, int & ThirdIndex, float &BeginPrice, float &EndPrice, float &ThirdPrice, float &GoldenMean, int & OrderType, int & Length, DrawingTypeEnum drawing_type, s_UseTool & chartDrawing, int use_fetched_drawing);
void create_clone_drawing(SCStudyInterfaceRef sc, int IndexBegin, int IndexEnd, int ThirdIndex, float BeginPrice, float EndPrice, float ThirdPrice, float GoldenMean, int OrderType, int Length, DrawingTypeEnum drawing_type, int toolconfig, int lineNumber, s_UseTool &cloneDrawing);
int tool_range_selection(SCStudyInterfaceRef sc, int BUTTON, int & ACS_BUTTON_STATE, int & MouseStart, int & MouseEnd);
void show_hide_drawings(SCStudyInterfaceRef sc, int hide);
s_UseTool Draw_OHLC_Rray(SCStudyInterfaceRef sc, int startindex, float entry, int toolconfig, int as_user, int linenumber);
int process_new_zone(SCStudyInterfaceRef sc, int & IndexBegin, int &IndexEnd, int &ThirdIndex, float &BeginPrice, float &EndPrice, float &ThirdPrice, int & OrderType, int & Length, SCDateTime Start, SCDateTime End);
int tool_index_selection(SCStudyInterfaceRef sc, int BUTTON, int& ACS_BUTTON_STATE, int& MouseStart);
#endif // LIB_H
