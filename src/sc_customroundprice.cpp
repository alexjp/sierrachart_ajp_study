#include "main.h"

SCSFExport scsf_CustomRoundPriceBarsToTickSize(SCStudyInterfaceRef sc) {
    SCSubgraphRef Open = sc.Subgraph[0];
    SCSubgraphRef High = sc.Subgraph[1];
    SCSubgraphRef Low = sc.Subgraph[2];
    SCSubgraphRef Last = sc.Subgraph[3];
    SCSubgraphRef Volume = sc.Subgraph[4];
    SCSubgraphRef OpenInterest = sc.Subgraph[5];
    SCSubgraphRef OHLCAvg = sc.Subgraph[6];
    SCSubgraphRef HLCAvg = sc.Subgraph[7];
    SCSubgraphRef HLAvg = sc.Subgraph[8];
    SCSubgraphRef BidVol = sc.Subgraph[9];
    SCSubgraphRef AskVol = sc.Subgraph[10];

    SCInputRef TickSize = sc.Input[0];

    if (sc.SetDefaults) {
        sc.GraphName = "Custom Round Price Bars To Tick Size";

        sc.StudyDescription = "This study when applied to a chart will round the "
                              "bar values to the Tick Size set in Chart >> Chart "
                              "Settings.";

        sc.GraphUsesChartColors = true;

        sc.ValueFormat = VALUEFORMAT_INHERITED;
        sc.GraphRegion = 0;
        sc.DisplayAsMainPriceGraph = true;
        sc.AutoLoop = 1;
        sc.GraphDrawType = GDT_OHLCBAR;
        sc.StandardChartHeader = 1;

        Open.Name = "Open";
        Open.DrawStyle = DRAWSTYLE_LINE;
        Open.PrimaryColor = RGB(255, 255,255);

        High.Name = "High";
        High.DrawStyle = DRAWSTYLE_LINE;
        High.PrimaryColor = RGB(255, 255,255);

        Low.Name = "Low";
        Low.DrawStyle = DRAWSTYLE_LINE;
        Low.PrimaryColor = RGB(255, 255,255);

        Last.Name = "Last";
        Last.DrawStyle = DRAWSTYLE_LINE;
        Last.PrimaryColor = RGB(255, 255,255);

        Volume.Name = "Volume";
        Volume.DrawStyle = DRAWSTYLE_IGNORE;
        Volume.PrimaryColor = RGB(255,0,0);

        OpenInterest.Name = "Num Trades / OpenInterest";
        OpenInterest.DrawStyle = DRAWSTYLE_IGNORE;
        OpenInterest.PrimaryColor = RGB(0,0,255);

        OHLCAvg.Name = "OHLC Avg";
        OHLCAvg.DrawStyle = DRAWSTYLE_IGNORE;
        OHLCAvg.PrimaryColor = RGB(0,255,0);

        HLCAvg.Name = "HLC Avg";
        HLCAvg.DrawStyle = DRAWSTYLE_IGNORE;
        HLCAvg.PrimaryColor = RGB(0,255,255);

        HLAvg.Name = "HL Avg";
        HLAvg.DrawStyle = DRAWSTYLE_IGNORE;
        HLAvg.PrimaryColor = RGB(0,127,255);

        BidVol.Name = "Bid Vol";
        BidVol.DrawStyle = DRAWSTYLE_IGNORE;
        BidVol.PrimaryColor = RGB(0,255,0);

        AskVol.Name = "Ask Vol";
        AskVol.DrawStyle = DRAWSTYLE_IGNORE;
        AskVol.PrimaryColor = RGB(0,255,0);

        TickSize.Name = "Tick Size";
        TickSize.SetFloat(sc.TickSize);



        return;
    }


    if (sc.Index == 0) {

                SCString tick_path;
                std::ifstream tick_input(tick_path.Format("conf/%s/%s.conf", sc.Symbol.GetChars(), "tick"));

                if (tick_input) {
                    float tick;
                    tick_input >> tick;
                    if (tick > 0.0) {
                        TickSize.SetFloat(tick);
                    }
                    tick_input.close();
                }
                else {
                    TickSize.SetFloat(sc.TickSize);
                }

            }

    sc.Subgraph[SC_OPEN][sc.Index] = sc.RoundToTickSize(sc.BaseDataIn[SC_OPEN][sc.Index], TickSize.GetFloat());
    sc.Subgraph[SC_HIGH][sc.Index] = sc.RoundToTickSize(sc.BaseDataIn[SC_HIGH][sc.Index], TickSize.GetFloat());
    sc.Subgraph[SC_LOW][sc.Index] = sc.RoundToTickSize(sc.BaseDataIn[SC_LOW][sc.Index], TickSize.GetFloat());
    sc.Subgraph[SC_LAST][sc.Index] = sc.RoundToTickSize(sc.BaseDataIn[SC_LAST][sc.Index], TickSize.GetFloat());

    for(int SubgraphIndex =SC_VOLUME; SubgraphIndex <=SC_ASKVOL;SubgraphIndex++)
        sc.Subgraph[SubgraphIndex][sc.Index] =sc.BaseDataIn[SubgraphIndex][sc.Index];

    sc.GraphName = sc.GetStudyNameFromChart(sc.ChartNumber, 0);
}
