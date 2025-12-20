#pragma once

#include <cstdint>
#include <cstdio>
#include <cstdlib>

typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

#define TOSTRINGIMPL(x) #x
#define TOSTRING(x) TOSTRINGIMPL(x)

#ifdef __FILE_NAME__
#define FILE_NAME __FILE_NAME__
#else
#define FILE_NAME __FILE__
#endif

#define STATIC_ASSERT(e) static_assert(e, "[" FILE_NAME ":" TOSTRING(__LINE__) "] ASSERT: " #e)

#define RUNTIME_ASSERT(e) \
    do { \
        if (!(e)) { \
            printf("[" FILE_NAME ":" TOSTRING(__LINE__) "] ASSERT: " #e "\n"); \
            abort(); \
        } \
    } while (0)

#define ASSERT(e) RUNTIME_ASSERT(e)
