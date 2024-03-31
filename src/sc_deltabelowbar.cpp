#include "main.h"
#include "lib.h"


/*==========================================================================*/
SCSFExport scsf_DeltaBelowBar(SCStudyInterfaceRef sc)
{
	//SCSubgraphRef DeltaValue = sc.Subgraph[0];
	//SCSubgraphRef DeltaValue2 = sc.Subgraph[1];

	int& _P_BAR_PERIOD = sc.GetPersistentInt(1);
	SCInputRef Offset = sc.Input[1];
	SCInputRef ShowCountDown = sc.Input[2];
	SCInputRef FontSize = sc.Input[3];
	SCInputRef HorizontalOffset = sc.Input[4];
	SCInputRef ShowDelta = sc.Input[5];

	//    int hspace = -5

	if (sc.SetDefaults) {
		sc.GraphName = "Bar Delta Next to Bar";

		sc.GraphRegion = 0;
		sc.ValueFormat = 0;
		sc.DrawZeros = 1;
		sc.AutoLoop = 0;
		//        sc.FreeDLL = _CONST_FREEDLL;
		sc.HideDLLAndFunctionNames = 1;

		Offset.Name = "Vertical Offset";
		Offset.SetFloat(1);

		HorizontalOffset.Name = "Horizontal Offset";
		HorizontalOffset.SetInt(-5);

		ShowCountDown.Name = "ShowCountDown";
		ShowCountDown.SetInt(1);

		FontSize.Name = "Font Size";
		FontSize.SetInt(8);

		ShowDelta.Name = "ShowDelta";
		ShowDelta.SetInt(1);

		// subgraphs
		//DeltaValue.Name = "Bar Delta";
		//DeltaValue.DrawStyle = DRAWSTYLE_CUSTOM_VALUE_AT_Y;
		//DeltaValue.PrimaryColor = COLOR_GREEN;
		//DeltaValue.SecondaryColor = COLOR_RED;
		//DeltaValue.SecondaryColorUsed = 1;
		//DeltaValue.AutoColoring = AUTOCOLOR_POSNEG;
		//DeltaValue.GraphicalDisplacement = 3;
		//DeltaValue.DrawZeros = 0;

		//DeltaValue2.Name = "Bar Delta2";
		//DeltaValue2.DrawStyle = DRAWSTYLE_CUSTOM_VALUE_AT_Y;
		//DeltaValue2.PrimaryColor = COLOR_GREEN;
		//DeltaValue2.SecondaryColor = COLOR_RED;
		//DeltaValue2.SecondaryColorUsed = 1;
		//DeltaValue2.AutoColoring = AUTOCOLOR_POSNEG;
		//DeltaValue2.GraphicalDisplacement = 3;
		//DeltaValue2.DrawZeros = 0;


		return;
	}

	if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif



		std::ifstream file = read_conf(sc);

		if (file.good()) {
			int countdown, horizontal_placement, show_delta;
			float vertical_placement;
			file >> countdown >> vertical_placement >> horizontal_placement >> show_delta;

			ShowCountDown.SetInt(countdown);
			Offset.SetFloat(vertical_placement);
			HorizontalOffset.SetInt(horizontal_placement);
			ShowDelta.SetInt(show_delta);

			file.close();
		}
	}

	if (sc.IsFullRecalculation) {
		_P_BAR_PERIOD = 0;
	}

	//int index_show = sc.ArraySize - 1;

	////DeltaValue[index_show - 1] = 0;
	//DeltaValue.Arrays[0][index_show - 1] = 0;
	//DeltaValue2.Arrays[0][index_show - 1] = 0;

	////DeltaValue2[index_show - 1] = 0;

	//DeltaValue[index_show] = sc.AskVolume[sc.Index] - sc.BidVolume[sc.Index];
	//DeltaValue.Arrays[0][index_show] = sc.Close[sc.Index] + (1 * sc.TickSize);

	//DeltaValue2[index_show] = sc.AskVolume[sc.Index] - sc.BidVolume[sc.Index];
	//DeltaValue2.Arrays[0][index_show] = sc.Close[sc.Index]; // -(1 * sc.TickSize);

	if (sc.LastCallToFunction) {
		if (sc.UserDrawnChartDrawingExists(sc.ChartNumber, SYMBOL_TEXT_DRAWING_DELTA) > 0)
			sc.DeleteUserDrawnACSDrawing(sc.ChartNumber, SYMBOL_TEXT_DRAWING_DELTA);
	}

	s_UseTool Tool;
	Tool.ChartNumber = sc.ChartNumber;
	Tool.DrawingType = DRAWING_TEXT;
	Tool.Region = sc.GraphRegion;
	Tool.LineNumber = SYMBOL_TEXT_DRAWING_DELTA;
	Tool.AddMethod = UTAM_ADD_OR_ADJUST;
	Tool.AddAsUserDrawnDrawing = 0;
	Tool.AllowSaveToChartbook = 0;
	Tool.BeginDateTime = HorizontalOffset.GetInt() + (sc.ChartBarSpacing / 3);


	int ValueIndex = sc.ArraySize - 1;
	//Tool.BeginValue = sc.Close[ValueIndex] + ((Offset.GetInt() * sc.TickSize) * ((sc.BaseGraphScaleConstRange / 100) / sc.TickSize));
	Tool.BeginValue = sc.Close[ValueIndex] + ((Offset.GetFloat()) * ((sc.BaseGraphScaleConstRange / 100)));

	float delta = sc.AskVolume[ValueIndex] - sc.BidVolume[ValueIndex];
	//    float volume = sc.Volume[ValueIndex];
	//    float prev_volume = sc.Volume[ValueIndex - 1];

	if (ShowDelta.GetInt() > 0) {
		if (delta > 0)
			Tool.Color = color_bull;
		else
			Tool.Color = color_bear;
	}
	else {
		if (sc.Open[ValueIndex] < sc.Close[ValueIndex])
			Tool.Color = color_bull;
		else
			if (sc.Open[ValueIndex] > sc.Close[ValueIndex])
				Tool.Color = color_bear;
			else
				Tool.Color = color_even;
	}

	Tool.TransparentLabelBackground = 1;
	Tool.FontFace = sc.GetChartTextFontFaceName();

	if (ShowCountDown.GetInt() == 1) {

		if (_P_BAR_PERIOD == 0) {
			n_ACSIL::s_BarPeriod v;
			sc.GetBarPeriodParameters(v);
			_P_BAR_PERIOD = v.IntradayChartBarPeriodParameter1 / 2;
		}
		if (sc.GetLatestBarCountdownAsInteger() < _P_BAR_PERIOD) {
			// if (volume > prev_volume) {
			Tool.FontSize = FontSize.GetInt();
			Tool.FontBold = true;
		}
		else {
			Tool.FontSize = FontSize.GetInt();
			Tool.FontBold = false;
		}

		if (ShowDelta.GetInt() > 0)
			Tool.Text = Tool.Text.Format("D:%-.0f\n%.0fx%.0f\nT:%d", delta, sc.BidVolume[ValueIndex], sc.AskVolume[ValueIndex], sc.GetLatestBarCountdownAsInteger());
		else
			Tool.Text = Tool.Text.Format("T:%d", sc.GetLatestBarCountdownAsInteger());
	}
	else
		if (ShowDelta.GetInt() > 0) {
			Tool.FontSize = FontSize.GetInt();
			Tool.FontBold = true;

			Tool.Text = Tool.Text.Format("D:%-.0f\n%.0fx%.0f\nT:%.0f", delta, sc.BidVolume[ValueIndex], sc.AskVolume[ValueIndex], sc.Volume[ValueIndex]);
			//Tool.Text = Tool.Text.Format("D:%-.0f\n%.0fx%.0f", delta, sc.BidVolume[ValueIndex], sc.AskVolume[ValueIndex]);
		}


	sc.UseTool(Tool);

}
