set(MAIN_FILES main.cpp main.h)
set(LIB_FILES lib.cpp lib.h lib_trade.cpp lib_trade.h)
set(POSITION_FILES sc_position.cpp sc_position.h)
set(SWING_FILES sc_swing.cpp sc_swing.h)
set(OVERLAY_FILES sc_rroverlay.cpp sc_rroverlay.h)
set(TOOL_FILES sc_tool.cpp)
set(ZOOM_FILES sc_zoom.cpp)
set(CHARTBOOK_FILES sc_chartbook.cpp)
set(VWAP_FILES sc_vwap.cpp)
set(ROUNDPRICE_FILES sc_customroundprice.cpp)
set(DELTA_FILES sc_deltabelowbar.cpp)
set(AUTOSWING_FILES sc_autoswing_fib.cpp sc_autoswing_fib.h)
set(TIMEFRAME_FILES sc_timeframe_tick.cpp sc_timeframe_range.cpp sc_timeframe_renko.cpp)
set(TRADEWINDOW_FILES sc_tradewindow.cpp)
#set(AUTOSWING_FILES sc_autoswing_fib.cpp sc_autoswing_fib.h sc_autoswing_pa.cpp sc_autoswing_pa.h)

add_library(ajp_study SHARED ${MAIN_FILES} ${LIB_FILES}
    ${POSITION_FILES} ${SWING_FILES} ${OVERLAY_FILES}
    ${TOOL_FILES} ${ZOOM_FILES} ${CHARTBOOK_FILES} ${VWAP_FILES}
    ${ROUNDPRICE_FILES} ${DELTA_FILES} ${TIMEFRAME_FILES} ${TRADEWINDOW_FILES})
