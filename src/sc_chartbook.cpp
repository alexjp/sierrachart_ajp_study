#include "main.h"
#include "lib.h"
std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
// f(n){n=n<2?:f(n-1)+f(n-2);}i,j,k;g(n){for(;k<n;j=k,k=f(i++));n=k-n<n-j?k:j;}

int fib(int n)
{
	return n = n < 2 ? n : fib(n - 1) + fib(n - 2);
}

int gib(int n)
{
	int i = 0, j = 0, k = 0;
	for (; k < n; j = k, k = fib(i++));
	return n = k - n < n - j ? k : j;
}

SCString conf_folder_name(SCStudyInterfaceRef sc) {
	SCString conf_name = sc.Input[6].GetString();
	if (conf_name.IsEmpty())
		return sc.Symbol.GetChars();
	return conf_name;
}

/*==========================================================================*/
SCSFExport scsf_Chartbook_Manager(SCStudyInterfaceRef sc) {
	// SCInputRef ChartBookNameRegEx = sc.Input[1];
	SCInputRef CBM_use_external_atr = sc.Input[1];
	SCInputRef CBM_external_atr = sc.Input[2];
	SCInputRef CBM_atr_mult = sc.Input[3];
	SCInputRef CBM_external_nt = sc.Input[4];
	SCInputRef CBM_normalize_nt = sc.Input[5];
	SCInputRef CBM_custom_name = sc.Input[6];
  	SCInputRef CBM_use_external_volume = sc.Input[7];
	SCInputRef CBM_external_volume = sc.Input[8];

	SCSubgraphRef SG_TF = sc.Subgraph[0];

	if (sc.SetDefaults) {

		sc.GraphName = "ChartBook Manager";
		sc.StudyDescription = "ChartBook Manager";

		CBM_use_external_atr.Name = "Use External ATR";
		CBM_use_external_atr.SetInt(0);
		CBM_external_atr.Name = "External ATR";
		CBM_external_atr.SetStudySubgraphValues(1, 1);
		CBM_external_nt.Name = "External NT";
		CBM_external_nt.SetStudySubgraphValues(1, 1);
		CBM_normalize_nt.Name = "Normalize Fib Trades Number";
		CBM_normalize_nt.SetInt(0);

		CBM_atr_mult.Name = "ATR Multiplier";
		CBM_atr_mult.SetFloat(1);

		CBM_custom_name.Name = "Custom configuration folder Name";
		CBM_custom_name.SetString("");

		SG_TF.Name = "TimeFrame";
		SG_TF.DrawStyle = DRAWSTYLE_SUBGRAPH_NAME_AND_VALUES_ONLY;
		SG_TF.DrawZeros = false;

   		CBM_use_external_volume.Name = "Use External Volume";
		CBM_use_external_volume.SetInt(0);
		CBM_external_volume.Name = "External Volume";
		CBM_external_volume.SetStudySubgraphValues(1, 1);

        
		sc.GraphRegion = 0;
		sc.AutoLoop = 1;

		return;
	}

	if (SG_TF[sc.Index] == 0 && SG_TF[sc.Index - 1] > 0) {
		SG_TF[sc.Index] = SG_TF[sc.Index - 1];
		SG_TF[sc.Index + 1] = SG_TF[sc.Index];
	}

	if (sc.UpdateStartIndex == 0) {
#ifdef _CONST_DEBUG
		sc.AddMessageToLog("Doing Initial Load", 0);
#endif



		sc.SetPersistentInt(1, 0);
		std::ifstream file = read_conf(sc);

		if (file.good()) {
			float atr_mult;
			file >> atr_mult;

			CBM_atr_mult.SetFloat(atr_mult);

			file.close();
		}
		return;
	}

	if ((sc.Index == sc.ArraySize - 1) && (sc.GetPersistentInt(1) == 0)) {

		//sc.AddMessageToLog("Preparing writting atr file", 1);
		if (CBM_use_external_atr.GetInt() == 1) {
			SCFloatArray atrArray;
			sc.GetStudyArrayFromChartUsingID(sc.ChartNumber, static_cast<int>(CBM_external_atr.GetStudyID()), static_cast<int>(CBM_external_atr.GetSubgraphIndex()), atrArray);
			float atr = atrArray[sc.Index] * CBM_atr_mult.GetFloat();
			if (atrArray.GetArraySize() > 0 && atr > 0.0) {
				SCString atr_path;
				SCString _folder_name = conf_folder_name(sc);
				SCString _path = atr_path.Format("conf/%s", _folder_name.GetChars());
				std::wstring stemp = s2ws(_path.GetChars());
				LPCWSTR result = stemp.c_str();
				//				if (GetFileAttributes(result) == INVALID_FILE_ATTRIBUTES) {
				//					CreateDirectory(result, NULL);
				//				}
				std::ofstream atr_output_check(atr_path.Format("conf/%s/%s.conf", _folder_name.GetChars(), "atr"));
				if (!atr_output_check.is_open()) {
  					//CreateDirectory(result, NULL);
					CreateDirectory(_path.GetChars(), NULL);
				}
				std::ofstream atr_output(atr_path.Format("conf/%s/%s.conf", _folder_name.GetChars(), "atr"));
				if (atr_output.is_open()) {
					float scale = sc.Round(atr / sc.TickSize);
					atr_output << scale << std::endl << atr;
					atr_output.close();
				}
			}
		}
		
		if (CBM_use_external_volume.GetInt() == 1) {
			SCFloatArray volumeArray;
			sc.GetStudyArrayFromChartUsingID(sc.ChartNumber, static_cast<int>(CBM_external_volume.GetStudyID()), static_cast<int>(CBM_external_volume.GetSubgraphIndex()), volumeArray);
			float volume = volumeArray[sc.Index];
			if (volumeArray.GetArraySize() > 0 && volume > 0.0) {
				SCString volume_path;
				SCString _folder_name = conf_folder_name(sc);
				SCString _path = volume_path.Format("conf/%s", _folder_name.GetChars());
				std::wstring stemp = s2ws(_path.GetChars());
				LPCWSTR result = stemp.c_str();
				//				if (GetFileAttributes(result) == INVALID_FILE_ATTRIBUTES) {
				//					CreateDirectory(result, NULL);
				//				}
				std::ofstream atr_output_check(volume_path.Format("conf/%s/%s.conf", _folder_name.GetChars(), "volume"));
				if (!atr_output_check.is_open()) {
  					//CreateDirectory(result, NULL);
					CreateDirectory(_path.GetChars(), NULL);
				}
				std::ofstream volume_output(volume_path.Format("conf/%s/%s.conf", _folder_name.GetChars(), "volume"));
				if (volume_output.is_open()) {
					volume_output << volume;
					volume_output.close();
				}
			}
		}
		//
		sc.SetPersistentInt(1, 1);
		return;
	}

	//SCString log;
	//sc.AddMessageToLog(log.Format("%d, %d",sc.GetPersistentInt(1), sc.Index == (sc.ArraySize-1)), 1);
	if (sc.ChartIsDownloadingHistoricalData(sc.ChartNumber) || sc.IsFullRecalculation || sc.DownloadingHistoricalData)
		return;

	if (sc.LastCallToFunction)
		return;

	if (sc.MenuEventID == ACS_BUTTON_7 && sc.PointerEventType == SC_ACS_BUTTON_ON) {
		sc.SetCustomStudyControlBarButtonEnable(ACS_BUTTON_8, 0);
		SCString _name = conf_folder_name(sc);
		sc.OpenChartbook(_name);
		// sc.OpenChartbook(sc.Symbol + ".cht");
		return;
	}



	//if ((sc.Index == sc.ArraySize - 1) &&
	//	(sc.GetPersistentInt(2) < sc.Index)){

	if (SG_TF[sc.Index] == 0 && sc.Index == sc.ArraySize - 1) {

		SCFloatArray ntArray;
		sc.GetStudyArrayFromChartUsingID(sc.ChartNumber, static_cast<int>(CBM_external_nt.GetStudyID()), static_cast<int>(CBM_external_nt.GetSubgraphIndex()), ntArray);
		if (ntArray.GetArraySize() > sc.ArraySize - 2) {
			float tf = ntArray[sc.Index - 1];
			int gtf = gib(static_cast<int>(tf));
			//SCString log;
			//sc.AddMessageToLog(log.Format("tf: %f, gtf: %d", tf, gtf), 1);
			if (gtf > 0) {
				SG_TF[sc.Index] = gtf;
				SCString _timeframe_path;
				SCString _folder_name = conf_folder_name(sc);
				SCString _path = _timeframe_path.Format("conf/%s", _folder_name.GetChars());

				std::ofstream output(_timeframe_path.Format("conf/%s/%s.conf", _folder_name.GetChars(), "timeframe"));
				if (output.is_open()) {
                    float tf_gtf_ratio = 1;
                    
					int timeframe_file = 0;

					if (CBM_normalize_nt.GetInt() == 1) {
						timeframe_file = gtf;
                        tf_gtf_ratio = gtf / tf;
                    }
					else {
						n_ACSIL::s_BarPeriod BarPeriod;
						sc.GetBarPeriodParameters(BarPeriod);
						if (BarPeriod.IntradayChartBarPeriodType == IBPT_NUM_TRADES_PER_BAR)
							timeframe_file = BarPeriod.IntradayChartBarPeriodParameter1;
						else timeframe_file = tf;
					}

					output << timeframe_file << std::endl << tf_gtf_ratio;
					output.close();
				}
			}


			return;
		}
		//}
		//else if (SG_TF[sc.Index] == 0)
		//
	}
}
