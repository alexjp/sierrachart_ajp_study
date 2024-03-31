cmake_minimum_required(VERSION 3.13)

SET(CMAKE_CXX_COMPILER "/usr/bin/x86_64-w64-mingw32-g++")

project(ajp_study)

SET(CMAKE_SYSTEM_NAME Win32)
SET(CMAKE_CROSSCOMPILING 1)
SET(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "-fno-exceptions -fpermissive")
SET(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "-fno-exceptions -fpermissive")
SET_PROPERTY(GLOBAL PROPERTY TARGET_SUPPORTS_SHARED_LIBS TRUE)
SET(CMAKE_SHARED_LIBRARY_PREFIX "")

MESSAGE( "64 bits compiler detected" )
SET(CMAKE_SYSTEM_PROCESSOR x86_64)
SET(CMAKE_CXX_FLAGS "-march=x86-64 -O2 -shared -static -static-libgcc -static-libstdc++ -s -fno-rtti -fno-exceptions -fpermissive -std=gnu++11")
SET(CMAKE_SHARED_LIBRARY_SUFFIX "_64.dll")

add_subdirectory(src)
#subdirs(src)

#calculate linux
#target_include_directories(ajp_study PUBLIC /home/alex/.sierracharts_source /usr/x86_64-w64-mingw32/mingw/include/)
#opensuse
target_include_directories(ajp_study PUBLIC sierrachart_source mingw)


target_compile_options(ajp_study PUBLIC -fno-rtti -fno-exceptions -fpermissive -Wno-deprecated -Wno-ignored-attributes -fms-extensions)


install(TARGETS ajp_study RUNTIME DESTINATION "/home/alex/.amp" LIBRARY	DESTINATION "/home/alex/.amp")
install(TARGETS ajp_study RUNTIME DESTINATION "/home/alex/.amp2" LIBRARY	DESTINATION "/home/alex/.amp2")
install(TARGETS ajp_study RUNTIME DESTINATION "/home/alex/.dd" LIBRARY DESTINATION "/home/alex/.dd")

#install(TARGETS autoswing RUNTIME DESTINATION "/home/alex/" LIBRARY DESTINATION "/home/alex/")
