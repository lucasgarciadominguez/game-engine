//Copyright (c) 2023+ Lucas
//this code is released under public domain

#pragma once

#if not defined __cplusplus
    
    #error "This engine requires a C++ compiler"

#endif

#if __cplusplus >=201103L
    #define ENGINE_CPP_11_AVAILABLE
    #if  __cplusplus >=201402L
        #define ENGINE_CPP_14_AVAILABLE
        #if  __cplusplus >=201703L
            #define ENGINE_CPP_17_AVAILABLE
        #endif
    #endif
#endif

#if defined _MSC_VER

    #define ENGINE_MICROSOFT_COMPILER   //ENGINE es por el nombre del proyecto del motor, si fuese superengine seria SUPERENGINE

#elif defined __clang__

    #define ENGINE_CLANG_COMPILER

#endif  // _MSC_VER


//------------------------------//
#if defined ENGINE_MICROSOFT_COMPILER

    #if defined _M_ARM || defined _M_ARM64

        #define ENGINE_ARCHITECTURE_ARM
    #else
        #define ENGINE_ARCHITECTURE_INTEL


    #endif

#elif ENGINE_CLANG_COMPILER   //ENGINE es por el nombre del proyecto del motor, si fuese superengine seria SUPERENGINE

#endif


