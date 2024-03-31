#include "main.h"
#include "lib.h"

float zoom_atr_update(SCStudyInterfaceRef sc, float atr, float divider)
{
    if (atr > 0.0) {
        float _scale = atr * 100;
        return (_scale * divider);
    }
    return 0;
}

float zoom_volume_update(SCStudyInterfaceRef sc, float volume, float divider)
{
    if (volume > 0.0) {
        float _scale = volume;
        return (_scale * divider);
    }
    return 0;
}

float zoom_atr_update(SCStudyInterfaceRef sc, unsigned int atr_id, unsigned int atr_subid, float divider)
{
    SCFloatArray atrArray;
    sc.GetStudyArrayFromChartUsingID(sc.ChartNumber, static_cast<int>(atr_id), static_cast<int>(atr_subid), atrArray);
    return zoom_atr_update(sc, atrArray[sc.Index], divider);
}

SCSFExport scsf_Zoom_Manager(SCStudyInterfaceRef sc)
{

    SCInputRef Zoom_default = sc.Input[1];
    SCInputRef Zoom_default_scale = sc.Input[2];

    SCInputRef Zoom_right_space = sc.Input[3];
    SCInputRef Zoom_out_constant_level = sc.Input[4];
    SCInputRef Zoom_in_constant_level = sc.Input[5];

    SCInputRef ZoomOutLevel1 = sc.Input[6];
    SCInputRef ZoomOutLevel2 = sc.Input[7];
    SCInputRef ZoomInOutMiddle = sc.Input[12];
    SCInputRef ZoomInLevel1 = sc.Input[8];
    SCInputRef ZoomInLevel2 = sc.Input[9];

    SCInputRef Zoom_default_scale_divider = sc.Input[10];
    SCInputRef Zoom_use_ticksize_file = sc.Input[11];
    SCInputRef Zoom_external_atr = sc.Input[13];

    SCInputRef Zoom_use_external_atr_file = sc.Input[14];

    SCInputRef Zoom_right_zoom_divider = sc.Input[16];

    SCInputRef Zoom_graph_region = sc.Input[17];
    SCInputRef Zoom_Volume = sc.Input[18];


    int &OldZoom = sc.GetPersistentInt(1);
    //    int& UpdatedIndex = sc.GetPersistentInt(2);

    sc.GraphRegion = Zoom_graph_region.GetInt();


    if (Zoom_graph_region.GetInt() == 0)
        sc.ReceivePointerEvents = ACS_RECEIVE_POINTER_EVENTS_WHEN_ACS_BUTTON_ENABLED;
    else
        sc.ReceivePointerEvents = ACS_RECEIVE_NO_POINTER_EVENTS;

    if (sc.SetDefaults) {

        sc.GraphName = "Zoom Manager";
        sc.StudyDescription = "Zoom Manager";

        sc.GraphUsesChartColors = true;

        sc.ValueFormat = VALUEFORMAT_INHERITED;
        sc.DisplayAsMainPriceGraph = false;
        sc.AutoLoop = 0;

        sc.GraphDrawType = GDT_OHLCBAR;
        sc.StandardChartHeader = 1;

        Zoom_default.Name = "Zoom Ratio";
        Zoom_default.SetInt(5);
        Zoom_default_scale.Name = "Zoom Ratio Scale";
        Zoom_default_scale.SetFloat(300);

        Zoom_default_scale_divider.Name = "Zoom Ratio Scale Multiplier";
        Zoom_default_scale_divider.SetFloat(1);

        Zoom_right_space.Name = "Right Space Fill Space";
        Zoom_right_space.SetInt(10);

        Zoom_out_constant_level.Name = "How many levels before Zooming Out below default";
        Zoom_out_constant_level.SetFloat(1);

        Zoom_in_constant_level.Name = "How many levels before Zooming In above default";
        Zoom_in_constant_level.SetFloat(1);

        ZoomOutLevel1.Name = "Zoom Out Level 1";
        ZoomOutLevel1.SetInt(3);
        ZoomOutLevel2.Name = "Zoom Out Level 2";
        ZoomOutLevel2.SetInt(1);
        ZoomInOutMiddle.Name = "Zoom Middle Level";
        ZoomInOutMiddle.SetInt(5);
        ZoomInLevel1.Name = "Zoom In Level 1";
        ZoomInLevel1.SetInt(5);
        ZoomInLevel2.Name = "Zoom In Level 2";
        ZoomInLevel2.SetInt(7);

        Zoom_external_atr.Name = "External ATR";
        Zoom_external_atr.SetStudySubgraphValues(1, 1);

        Zoom_use_ticksize_file.Name = "Use Tick (file)";
        Zoom_use_ticksize_file.SetInt(0);

        Zoom_use_external_atr_file.Name = "Use ATR (file)";
        Zoom_use_external_atr_file.SetInt(0);

        Zoom_right_zoom_divider.Name = "Right Space Fill Space Divider";
        Zoom_right_zoom_divider.SetInt(1);

        Zoom_graph_region.Name = "Graph Region";
        Zoom_graph_region.SetInt(0);

        Zoom_Volume.Name = "Use Volume instead of ATR";
        Zoom_Volume.SetInt(0);

//         sc.GraphRegion = Zoom_graph_region.GetInt();

        return;
    }



    if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
        sc.AddMessageToLog("Doing Initial Load", 0);
#endif

        int _read_divider = 1;


        std::ifstream file = read_conf(sc);
        if (file.good()) {
            int zoom_default, right_space, out1, out2, middle, in1, in2, use_ext_scale, use_ext_atr_study, graph_region;
            float divider, constant_out, constant_in, use_volume;
            file >> zoom_default >> right_space >> out1 >> out2 >> middle >> in1 >> in2 >> constant_out >> constant_in >> divider >> use_ext_scale >> use_ext_atr_study >> graph_region >> use_volume;

            Zoom_default.SetInt(zoom_default);
            Zoom_right_space.SetInt(right_space);
            ZoomOutLevel1.SetInt(out1);
            ZoomOutLevel2.SetInt(out2);
            ZoomInOutMiddle.SetInt(middle);
            ZoomInLevel1.SetInt(in1);
            ZoomInLevel2.SetInt(in2);
            Zoom_out_constant_level.SetFloat(constant_out);
            Zoom_in_constant_level.SetFloat(constant_in);
            Zoom_graph_region.SetInt(graph_region);
            Zoom_Volume.SetFloat(use_volume);


            {
                SCString divider_path;
                std::ifstream divider_input(divider_path.Format("conf/%s/%d-%s.conf", sc.ChartbookName().GetChars(), sc.ChartNumber, "scale_ratio"));
                if (divider_input) {
                    float scale_input = 0;
                    divider_input >> scale_input;
                    if (scale_input > 0) {
                        //Zoom_default_scale_divider.SetFloat(scale_input);
                        //_read_divider = 0;
                        divider = divider * scale_input;
                        divider_input.close();
                    }
                } else {
                    std::ifstream divider_input(divider_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "scale_ratio"));
                    if (divider_input) {
                        float scale_input = 0;
                        divider_input >> scale_input;
                        if (scale_input > 0) {
                            //Zoom_default_scale_divider.SetFloat(scale_input);
                            //_read_divider = 0;
                            divider = divider * scale_input;
                            divider_input.close();
                        }
                    }
                }
            }

            {
                n_ACSIL::s_BarPeriod BarPeriod;
                sc.GetBarPeriodParameters(BarPeriod);
                if (BarPeriod.IntradayChartBarPeriodType == IBPT_NUM_TRADES_PER_BAR) {
                    SCString timeframe_path;
                    std::ifstream time_input(timeframe_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "timeframe"));
                    if (time_input) {
                        int timeframe = 0;
                        float tf_scale_ratio = 0;
                        time_input >> timeframe >> tf_scale_ratio;
                        if (tf_scale_ratio > 0) {
                            divider = divider * tf_scale_ratio;
                            time_input.close();
                        }
                    }
                }
            }

            Zoom_default_scale_divider.SetFloat(divider);

            Zoom_use_ticksize_file.SetInt(use_ext_scale);
            Zoom_use_external_atr_file.SetInt(use_ext_atr_study);

            file.close();
        }

        int use_ticksize_setting = Zoom_use_ticksize_file.GetInt();
        if (use_ticksize_setting >= 1) {
            SCString tick_path;
            std::ifstream tick_input(tick_path.Format("conf/%s/%s.conf", sc.ChartbookName().GetChars(), "tick"));

            float tick = sc.TickSize;
            if (tick_input) {
                tick_input >> tick;
                if (tick <= 0.0) {
                    tick = sc.TickSize;
                }
                tick_input.close();
            }
            float scale = (tick * 100) * use_ticksize_setting;
            Zoom_default_scale.SetFloat(scale * Zoom_default_scale_divider.GetFloat());
            SCString increment_path;
            std::ifstream increment_input(increment_path.Format("conf/%s/%d-%s.conf", sc.ChartbookName().GetChars(), sc.ChartNumber, "increment"));
            if (increment_input) {
                float increment;
                increment_input >> increment;
                if (increment > 0)
                    sc.BaseGraphScaleIncrement = sc.TickSize * (increment);
                else
                    sc.BaseGraphScaleIncrement = 0;
//					sc.BaseGraphScaleIncrement = (sc.TickSize * use_ticksize_setting);
            }
        } else {
            int atr_file_setting = Zoom_use_external_atr_file.GetInt();
            if (atr_file_setting > 0) {
                SCString atr_path;
                SCString studyname = "atr";
                std::ifstream atr_input = read_conf(sc, sc.ChartbookName().GetChars(), studyname);
                if (atr_input.good()) {
                    float atr_tick;
                    float atr;
                    atr_input >> atr_tick >> atr;
// SCString log;
// sc.AddMessageToLog(log.Format("ATR: %f, ATR_TICK: %f", atr, atr_tick),0);
                    if (atr_tick > 0 && Zoom_default_scale_divider.GetFloat() > 0.0) {
                        //float _scale = zoom_atr_update(sc, atr_tick * sc.TickSize, Zoom_default_scale_divider.GetFloat());
                        float _scale = zoom_atr_update(sc, atr, Zoom_default_scale_divider.GetFloat());
                        Zoom_default_scale.SetFloat(_scale);
                        SCString increment_path;
                        std::ifstream increment_input(increment_path.Format("conf/%s/%d-%s.conf", sc.ChartbookName().GetChars(), sc.ChartNumber, "increment"));
                        if (increment_input) {
                            float increment;
                            increment_input >> increment;
                            if (increment > 0)
                                sc.BaseGraphScaleIncrement = sc.TickSize * (increment);
                            else
                                sc.BaseGraphScaleIncrement = 0;
                        } else
                            sc.BaseGraphScaleIncrement = 0;
//							sc.BaseGraphScaleIncrement = sc.TickSize * (atr_file_setting);
                    }
                    atr_input.close();
                }
            }
        }

        {
            int volume_file_setting = Zoom_Volume.GetInt();
            if (volume_file_setting > 0) {
                SCString volume_path;
                SCString studyname = "volume";
                std::ifstream volume_input = read_conf(sc, sc.ChartbookName().GetChars(), studyname);
                if (volume_input.good()) {
                    float volume;
                    volume_input >> volume;
                    if (volume > 0 && Zoom_default_scale_divider.GetFloat() > 0.0) {
                        float _scale = zoom_volume_update(sc, volume, Zoom_default_scale_divider.GetFloat());
                        Zoom_default_scale.SetFloat(_scale);
                        sc.BaseGraphScaleIncrement = 0;
                    }
                    volume_input.close();
                }
            }
        }

    }
    if (sc.UpdateStartIndex == sc.ArraySize - 1) {

        if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.IsFullRecalculation || sc.DownloadingHistoricalData)
            return;

        if (sc.LastCallToFunction)
            return;

        if (Zoom_graph_region.GetInt() == 0) {
            if (sc.MenuEventID == ACS_BUTTON_5 && sc.PointerEventType == SC_ACS_BUTTON_ON) {
                int _chart_bar_spacing = 0;
                if (sc.ChartBarSpacing > ZoomInLevel2.GetInt())
                    _chart_bar_spacing = ZoomInLevel2.GetInt();
                else if (sc.ChartBarSpacing > ZoomInLevel1.GetInt())
                    _chart_bar_spacing = ZoomInLevel1.GetInt();
                else if (sc.ChartBarSpacing > ZoomInOutMiddle.GetInt())
                    _chart_bar_spacing = ZoomInOutMiddle.GetInt();
                else if (sc.ChartBarSpacing > ZoomOutLevel1.GetInt())
                    _chart_bar_spacing = ZoomOutLevel1.GetInt();
                else if (sc.ChartBarSpacing > ZoomOutLevel2.GetInt())
                    _chart_bar_spacing = ZoomOutLevel2.GetInt();

                else if (sc.ChartBarSpacing <= ZoomOutLevel2.GetInt() && sc.ChartBarSpacing > 0)
                    _chart_bar_spacing = sc.ChartBarSpacing - 1;

                sc.ChartBarSpacing = static_cast<short>(_chart_bar_spacing);

                sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_5, 0);
            }

            if (sc.MenuEventID == ACS_BUTTON_6 && sc.PointerEventType == SC_ACS_BUTTON_ON) {
                int _chart_bar_spacing = 0;
                if (sc.ChartBarSpacing < ZoomOutLevel2.GetInt())
                    _chart_bar_spacing = ZoomOutLevel2.GetInt();
                else if (sc.ChartBarSpacing < ZoomOutLevel1.GetInt())
                    _chart_bar_spacing = ZoomOutLevel1.GetInt();
                else if (sc.ChartBarSpacing < ZoomInOutMiddle.GetInt())
                    _chart_bar_spacing = ZoomInOutMiddle.GetInt();
                else if (sc.ChartBarSpacing < ZoomInLevel1.GetInt())
                    _chart_bar_spacing = ZoomInLevel1.GetInt();
                else if (sc.ChartBarSpacing < ZoomInLevel2.GetInt())
                    _chart_bar_spacing = ZoomInLevel2.GetInt();

                else if (sc.ChartBarSpacing >= ZoomInLevel2.GetInt())
                    _chart_bar_spacing = sc.ChartBarSpacing + 1;

                sc.ChartBarSpacing = static_cast<short>(_chart_bar_spacing);

                sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_6, 0);
            }

            if ((sc.MenuEventID == ACS_BUTTON_7 && sc.PointerEventType == SC_ACS_BUTTON_ON)) {
                //        SCFloatArray trArray;
                //        SCFloatArray atrArray;
                //        sc.ATR(sc.BaseDataIn, trArray, atrArray, sc.Index-1, 100, MOVAVGTYPE_SIMPLE);
                //        float _scale = atrArray[sc.Index] * 100;

                if ((Zoom_use_external_atr_file.GetInt() == 0) && (Zoom_use_ticksize_file.GetInt() == 0) && (Zoom_Volume.GetInt() == 0)) {
                    float _scale = zoom_atr_update(sc, Zoom_external_atr.GetStudyID(), Zoom_external_atr.GetSubgraphIndex(), Zoom_default_scale_divider.GetFloat());
                    if (_scale > 0)
                        Zoom_default_scale.SetFloat(_scale);
                    sc.BaseGraphScaleIncrement = 0;
                }

                sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_7, 0);
                sc.ChartBarSpacing = static_cast<short>(ZoomInOutMiddle.GetInt());
                OldZoom = -1;
            }
        }
        
        if (OldZoom != sc.ChartBarSpacing) {
            OldZoom = sc.ChartBarSpacing;
            int zoom_right_space = static_cast<unsigned int>(Zoom_right_space.GetInt());
            int right_div = Zoom_right_zoom_divider.GetInt();
            if (right_div > 0 && sc.ChartBarSpacing > 0)
                zoom_right_space = zoom_right_space / (sc.ChartBarSpacing * right_div);



            if (sc.NumFillSpaceBars != zoom_right_space)
                sc.NumFillSpaceBars = zoom_right_space;

            float _zoom_level = sc.ChartBarSpacing;
            float _zoom_diff = abs(_zoom_level - Zoom_default.GetInt());

            if (sc.ChartBarSpacing < Zoom_default.GetInt()) {
                //            int _chart_zoom_out_plus_constant = (sc.ChartBarSpacing + Zoom_out_constant_level.GetFloat());
                //            if (_chart_zoom_out_plus_constant < Zoom_default.GetInt())
                //                _zoom_level = _chart_zoom_out_plus_constant;
                //            else
                //                _zoom_level = Zoom_default.GetInt();

                _zoom_level = Zoom_default.GetInt() - (_zoom_diff / Zoom_out_constant_level.GetFloat());

                //            SCString log;
                //            sc.AddMessageToLog(log.Format("Zoom Level: %f", _zoom_level),0);
            }
            if (sc.ChartBarSpacing > Zoom_default.GetInt()) {
                //            int _chart_zoom_in_plus_constant = (sc.ChartBarSpacing - Zoom_in_constant_level.GetFloat());
                //            if (_chart_zoom_in_plus_constant > Zoom_default.GetInt())
                //                _zoom_level = _chart_zoom_in_plus_constant;
                //            else
                //                _zoom_level = Zoom_default.GetInt();

                _zoom_level = Zoom_default.GetInt() + (_zoom_diff / Zoom_in_constant_level.GetFloat());

                //            SCString log;
                //            sc.AddMessageToLog(log.Format("Zoom Level: %f", _zoom_level),0);
            }

            if (_zoom_level <= 0)
                _zoom_level = 1;
            float ratio = ((Zoom_default.GetInt() * 10000) / (_zoom_level));
            sc.BaseGraphScaleConstRange = (ratio / 10000) * Zoom_default_scale.GetFloat();

        }
    }
}
