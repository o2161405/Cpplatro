#pragma once

#include "engine/common/Common.hh"

#include <cmath>
#include <cstdint>

#include <bit>

class TempRandom {
public:
    TempRandom(const f64 &seed);

    f64 getDouble() {
        u64 intermediate = (next() & 0x000fffffffffffffULL) | 0x3ff0000000000000ULL;
        return std::bit_cast<f64>(intermediate) - 1.0;
    }

    u64 getInteger(u64 max) {
        ASSERT(max >= 1);
        return static_cast<u64>(std::floor(getDouble() * static_cast<f64>(max))) + 1;
    }

private:
    void seed(const f64 &seed);
    u64 next();

    u64 m_state[4];
};
