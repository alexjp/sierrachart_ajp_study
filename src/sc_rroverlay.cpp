#include "sc_rroverlay.h"


int rr_skip_iteration(SCStudyInterfaceRef sc)
{
    if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.DownloadingHistoricalData)
        return 1;
    return 0;
}



SCSFExport scsf_ProfitStopRROverlay(SCStudyInterfaceRef sc)
{
    int& LastAlertIndex = sc.GetPersistentInt(1);

    SCInputRef I_Profit = sc.Input[0];
    SCInputRef I_Stop = sc.Input[1];
    SCInputRef I_RR = sc.Input[2];
    SCInputRef I_DIR = sc.Input[3];
    SCInputRef I_LT = sc.Input[4];
    SCInputRef I_ST = sc.Input[5];


    SCInputRef OffsetProfit = sc.Input[6];
    SCInputRef OffsetStop = sc.Input[7];
    SCInputRef OffsetRR = sc.Input[8];

    SCInputRef MinRR = sc.Input[9];

    SCInputRef FontSize = sc.Input[10];


    if (sc.SetDefaults)
    {
        sc.GraphName = "Stop/Profit/RR overlay";

        sc.GraphRegion = 0;
        sc.ValueFormat = 0;
        sc.DrawZeros = 0;
        sc.AutoLoop = 0;
//        sc.FreeDLL = _CONST_FREEDLL;

        OffsetProfit.Name = "Vertical Placement";
        OffsetProfit.SetInt(1);

        OffsetStop.Name = "Horizontal Placement";
        OffsetStop.SetInt(1);

        OffsetRR.Name = "Alert";
        OffsetRR.SetInt(1);

        MinRR.Name = "Minimum RR";
        MinRR.SetFloat(1.618);

        I_Profit.Name = "Profit study";
        I_Profit.SetStudySubgraphValues(1, 16);

        I_Stop.Name = "Stop study";
        I_Stop.SetStudySubgraphValues(1, 15);

        I_RR.Name = "RR study";
        I_RR.SetStudySubgraphValues(1, 17);

        I_DIR.Name = "Long or Short Trade study";
        I_DIR.SetStudySubgraphValues(1, 12);

        I_LT.Name = "Long Trade study";
        I_LT.SetStudySubgraphValues(1, 1);

        I_ST.Name = "Short Trade study";
        I_ST.SetStudySubgraphValues(1, 2);

        FontSize.Name = "Font Size";
        FontSize.SetInt(8);

        sc.AlertOnlyOncePerBar = 1;
        return;
    }


    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif


        std::ifstream file = read_conf(sc);

        if (file.good()) {
            int vertical_placement,horizontal_placement;
            file >> vertical_placement >> horizontal_placement;

            OffsetProfit.SetInt(vertical_placement);
            OffsetStop.SetInt(horizontal_placement);

            file.close();
        }

        SCString path;
        std::ifstream alert_input(path.Format("conf/%s/%d-%s.conf", sc.ChartbookName().GetChars(),  sc.ChartNumber, "Alert"));
        if (alert_input.is_open()) {
            int alert;
            alert_input >> alert;

            OffsetRR.SetInt(alert);

            alert_input.close();
        }
        else
            sc.AddMessageToLog(path + ": Error opening file", 0);

    }

    if (rr_skip_iteration(sc))
        return;

    int hspace = OffsetStop.GetInt();

    int ValueIndex = sc.ArraySize - 1;



    s_UseTool Tool;


    SCFloatArray profitArray;
    sc.GetStudyArrayUsingID(I_Profit.GetStudyID(), I_Profit.GetSubgraphIndex(), profitArray);

    SCFloatArray stopArray;
    sc.GetStudyArrayUsingID(I_Stop.GetStudyID(), I_Stop.GetSubgraphIndex(), stopArray);

    SCFloatArray rrArray;
    sc.GetStudyArrayUsingID(I_RR.GetStudyID(), I_RR.GetSubgraphIndex(), rrArray);

    SCFloatArray directionArray;
    sc.GetStudyArrayUsingID(I_DIR.GetStudyID(), I_DIR.GetSubgraphIndex(), directionArray);

    SCFloatArray longArray;
    sc.GetStudyArrayUsingID(I_LT.GetStudyID(), I_LT.GetSubgraphIndex(), longArray);

    SCFloatArray shortArray;
    sc.GetStudyArrayUsingID(I_ST.GetStudyID(), I_ST.GetSubgraphIndex(), shortArray);

    s_SCPositionData position;

    if (sc.LastCallToFunction || (profitArray[ValueIndex] == 0 && stopArray[ValueIndex] == 0) || position.PositionQuantity != 0) {
        if (sc.GetACSDrawingByLineNumber(sc.ChartNumber, SYMBOL_TEXT_DRAWING_PROFIT,  Tool) > 0) {
            sc.DeleteACSChartDrawing(sc.ChartNumber, TOOL_DELETE_CHARTDRAWING, SYMBOL_TEXT_DRAWING_PROFIT);
        }
        return;
    }

    if (rrArray[ValueIndex] > MinRR.GetFloat()) {

        if (directionArray[ValueIndex] == 0) {
            Tool.Color = color_even;
        }

        else {
            int previousCandle = ValueIndex - 1;
            if (directionArray[ValueIndex] > 0) {
                Tool.Color = color_bull;
                int _candle_reversal = (sc.Open[previousCandle] < sc.Close[previousCandle]) && (sc.Open[previousCandle -1] > sc.Close[previousCandle -1]);

                if (LastAlertIndex != ValueIndex && OffsetRR.GetInt() > 0 && _candle_reversal && longArray[previousCandle] > 0) {
                    SCString log;
                    sc.SetAlert(OffsetRR.GetInt(), ValueIndex, log.Format("Possible Long trade"));
                    LastAlertIndex = ValueIndex;
                }
            }
            if (directionArray[ValueIndex] < 0) {
                Tool.Color = color_bear;
                int _candle_reversal = (sc.Open[previousCandle] > sc.Close[previousCandle]) && (sc.Open[previousCandle -1] < sc.Close[previousCandle -1]);

                if (LastAlertIndex != ValueIndex && OffsetRR.GetInt() > 0 && _candle_reversal && shortArray[previousCandle] > 0) {
                    SCString log;
                    sc.SetAlert(OffsetRR.GetInt(), ValueIndex, log.Format("Possible Short trade"));
                    LastAlertIndex = ValueIndex;
                }
            }
        }


        Tool.FontSize = FontSize.GetInt();
        Tool.FontBold = true;
    }
    else {
        Tool.FontSize = FontSize.GetInt();
        Tool.FontBold = false;
        Tool.Color = color_even;
    }

    float profit = profitArray[ValueIndex];
    if (profitArray[ValueIndex] > 0 && stopArray[ValueIndex] > 0 && rrArray[ValueIndex] > 0) {

        Tool.ChartNumber = sc.ChartNumber;
        Tool.DrawingType = DRAWING_TEXT;
        Tool.Region = sc.GraphRegion;
        Tool.LineNumber = SYMBOL_TEXT_DRAWING_PROFIT;
        Tool.AddMethod = UTAM_ADD_OR_ADJUST;
        Tool.AddAsUserDrawnDrawing = 0;
        Tool.AllowSaveToChartbook = 0;
        Tool.BeginDateTime = hspace;

        Tool.BeginValue = sc.Close[ValueIndex] + ((OffsetProfit.GetInt()) * ((sc.BaseGraphScaleConstRange / 100)));
        //Tool.UseRelativeVerticalValues = 0;


        Tool.TransparentLabelBackground = 1;
        Tool.FontFace = sc.GetChartTextFontFaceName();

        Tool.Text = Tool.Text.Format("P:%.1f\nS:%.1f\nR:%.1f", profitArray[ValueIndex], stopArray[ValueIndex], rrArray[ValueIndex]);

        sc.UseTool(Tool);
    }
}
