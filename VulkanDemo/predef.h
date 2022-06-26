//---------------------------------------------------------------
//pre define os and archive
// OS: operating system
//      OS_WINDOWS              Windows system
//          OS_WIN_64           64bit Windows
//          OS_WIN_32           32bit Windows
//      OS_MACOS                MacOS system
//      OS_IOS                  iPhone iOS system
//      OS_ANDROID              android system
//      OS_LINUX                linux system
//      OS_UNKNOWN_APPLE        undefined apple system
//      OS_UNKNOWN              undefined system
//--------------------------------------------------------------
#pragma once

//--------------------------------------------------------------
//Operating System
//--------------------------------------------------------------
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
#define OS_WINDOWS
#ifdef _WIN64
    #define OS_WIN_64
#else
    #define OS_WIN_32
#endif

#elif __APPLE__
#include <TargetConditionals.h>
#if defined(TARGET_OS_OSX)
    #define OS_MACOS
#elif TARGET_OS_IPHONE
    #define OS_ICOS
#else
    #define OS_UNDEF_APPLE
#endif

#elif __ANDROID__
#define OS_ANDROID

#elif __linux__
#define OS_LINUX

#else
#define OS_UNKNOWN
#endif