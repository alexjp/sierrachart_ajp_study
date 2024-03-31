#! /bin/sh

    echo "building...64bit"
    x86_64-w64-mingw32-g++ -march=x86-64 -O2 -shared -static -static-libgcc -static-libstdc++ -s -fno-rtti -fno-exceptions -fpermissive -std=gnu++11 \
	    -I /home/alex/.sierracharts_source \
	    -w src/main.cpp \
	    -w src/lib.cpp \
	    -w src/lib_trade.cpp \
	    -w src/sc_position.cpp \
	    -w src/sc_swing.cpp \
	    -w src/sc_rroverlay.cpp \
	    -w src/sc_tool.cpp \
	    -w src/sc_zoom.cpp \
	    -w src/sc_chartbook.cpp \
	    -w src/sc_vwap.cpp \
	    -w src/sc_customroundprice.cpp \
	    -w src/sc_deltabelowbar.cpp \
	    -w src/sc_timeframe_tick.cpp \
	    -w src/sc_timeframe_range.cpp \
	    -w src/sc_timeframe_renko.cpp \
	    -w src/sc_tradewindow.cpp \
	    -o ajp_study_64.dll 


#	    -w src/sc_autoswing_fib.cpp \
#	    -w src/sc_vwap.cpp \
#	    -w src/sc_customroundprice.cpp \
