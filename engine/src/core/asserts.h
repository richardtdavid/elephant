#pragma once

#include "defines.h"

// disable assertions by commenting out the below line.
#define EPHASSERTIONS_ENABLED

#ifdef EPHASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

EPHAPI void report_assertion_failure(const char* expression, const char* message, const char* file, i32 line);

#define EPHASSERT(expr)                                                \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define EPHASSERT_MSG(expr, message)                                        \
    {                                                                     \
        if (expr) {                                                       \
        } else {                                                          \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifdef _DEBUG
#define EPHASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr) {                                                  \
        } else {                                                     \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define EPHASSERT_DEBUG(expr)  // Does nothing at all
#endif

#else
#define EPHASSERT(expr)               // Does nothing at all
#define EPHASSERT_MSG(expr, message)  // Does nothing at all
#define EPHASSERT_DEBUG(expr)         // Does nothing at all
#endif