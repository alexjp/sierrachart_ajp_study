#! /bin/sh

    echo "building...64bit"
    x86_64-w64-mingw32-g++ -march=x86-64 -O2 -shared -static -static-libgcc -static-libstdc++ -s -fno-rtti -fno-exceptions -fpermissive -std=gnu++11 \
	    -I /home/alex/.sierracharts_source \
	    -w src/main.cpp \
	    -w src/lib.cpp \
	    -w src/lib_trade.cpp \
	    -w src/sc_position.cpp \
	    -o ajp_study_position_64.dll 
