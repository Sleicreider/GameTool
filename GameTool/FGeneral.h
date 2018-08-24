//
//  FGeneral.h
//
//  Created by Dominik Reisner on 21.01.16.
//
//

#ifndef FGeneral_h
#define FGeneral_h

#include <algorithm>
#include <stdint.h>

//==================================================
// Warning

// compiler_warning.h
#define STRINGISE_IMPL(x) #x
#define STRINGISE(x) STRINGISE_IMPL(x)

// Use: #pragma message WARN("My message")
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#   define FILE_LINE_LINK __FILE__ "(" STRINGISE(__LINE__) ") : "
#   define WARN(exp) (FILE_LINE_LINK "WARNING: " exp)
#else//__GNUC__ - may need other defines for different compilers
#   define WARN(exp) ("WARNING: " exp)
#endif

//==================================================
// Deprecated
// probably not needed anymore with c++14 attributes [[deprecated]]
// issue though is that deprectaed always generated errors
#ifdef __GNUC__
#define DEPRECATED(func) func __attribute__ ((deprecated))
#elif defined(_MSC_VER)
#define DEPRECATED(func) __declspec(deprecated) func
#else
#pragma message("WARNING: You need to implement DEPRECATED for this compiler")
#define DEPRECATED(func) func
#endif

#



//==================================================
// Inline

#pragma message WARN("also for assert?")
#pragma message WARN("TT SKIPBABLE ONCE ? check engine ")

#if (Q_WS_WIN )
#	 define DEBUG_BREAK DebugBreak()
#    define FORCEINLINE __forceinline
#else
#	 define DEBUG_BREAK
#    define FORCEINLINE __attribute__((always_inline)) inline
#endif


#endif
