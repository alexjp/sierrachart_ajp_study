#include "main.h"
#include "lib.h"

SCSFExport scsf_VwapATRBands(SCStudyGraphRef sc)
{
    // Section 1 - Set the configuration variables

    if (sc.SetDefaults) {
        // Set the configuration and defaults

        sc.GraphName = "VWap ATRBands";

        sc.StudyDescription = "VWap ATRBands";

        sc.AutoLoop = 1;  // true

        sc.GraphRegion = 0;
        sc.ValueFormat = VALUEFORMAT_INHERITED;

        sc.Input[0].Name = "ATR/MA Length";
        sc.Input[0].SetInt(21);
        sc.Input[0].SetIntLimits(1, 500);
        sc.Input[0].SetDescription("MA Length.<br>\
                                    Displays as the Mid-Band and used to calculate ATR value.");

        sc.Input[1].Name = "ATR/MA Type";
        sc.Input[1].SetMovAvgType(MOVAVGTYPE_SIMPLE);
        sc.Input[1].SetDescription("MA Type.<br>\
                                   Displays as the Mid-Band and used to calculate ATR value.");

        sc.Input[2].Name = "Bands Multiplier ... 1 = 100%";
        sc.Input[2].SetFloat(1.5f);
        sc.Input[2].SetFloatLimits(0.1f, 10.0f);
        sc.Input[2].SetDescription("Upper Band = MA + (ATR * MULTIPLIER)<br>\
                                   Lower Band = MA - (ATR * MULTIPLIER<br>\
                                   Band calculations are rounded to nearest tick size.<br>\
                                   Accepts values 0.1 (10%) to 10.0 (1000%)<br>\
                                   ATR Value is available in the chart/tool windows only.");

        sc.Subgraph[0].Name = "ATR/MA";
        sc.Subgraph[0].PrimaryColor = COLOR_RED;
        sc.Subgraph[0].DrawStyle = DRAWSTYLE_LINE;
        sc.Subgraph[0].LineWidth = 2;

        // Named but ignored. For tool value window only.
        // This study draws on the main price graph, not a region.
        // Unless ATR value is similar to price scale, chart will distort, as it should.
        sc.Subgraph[1].Name = "ATR Value";
        sc.Subgraph[1].DrawStyle = DRAWSTYLE_IGNORE;

        sc.Subgraph[2].Name = "Upper Band";
        sc.Subgraph[2].PrimaryColor = COLOR_MEDIUMPURPLE;
        sc.Subgraph[2].DrawStyle = DRAWSTYLE_LINE;
        sc.Subgraph[2].LineStyle = LINESTYLE_DASH;
        sc.Subgraph[2].LineWidth = 2;

        sc.Subgraph[3].Name = "Lower Band";
        sc.Subgraph[3].PrimaryColor = COLOR_MEDIUMPURPLE;
        sc.Subgraph[3].DrawStyle = DRAWSTYLE_LINE;
        sc.Subgraph[3].LineStyle = LINESTYLE_DASH;
        sc.Subgraph[3].LineWidth = 2;

        return;
    }

    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif



        std::ifstream file = read_conf(sc);

        if (file.good()) {
            int ma_length, ma_type, show_study;
            float multiplier;
            file>> ma_length >> ma_type >> multiplier >> show_study;

            sc.Input[0].SetInt(ma_length);
            sc.Input[1].SetInt(ma_type);
            sc.Input[2].SetFloat(multiplier);


            if (show_study == 1)
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 1);
            else
                sc.SetStudyVisibilityState(sc.StudyGraphInstanceID, 0);

            file.close();
        }
    }

    // Section 2 - Do data processing

    sc.VolumeWeightedMovingAverage(sc.BaseDataIn[SC_LAST], sc.Volume, sc.Subgraph[0], sc.Input[0].GetInt());

    sc.ATR(sc.BaseDataIn, sc.Subgraph[1], sc.Input[0].GetInt(), sc.Input[1].GetMovAvgType());

    //upper band
    sc.Subgraph[2][sc.Index] = sc.RoundToTickSize(sc.Subgraph[0][sc.Index] + (sc.Subgraph[1][sc.Index] * sc.Input[2].GetFloat()), sc.TickSize);
    //lower band
    sc.Subgraph[3][sc.Index] = sc.RoundToTickSize(sc.Subgraph[0][sc.Index] - (sc.Subgraph[1][sc.Index] * sc.Input[2].GetFloat()), sc.TickSize);


}
