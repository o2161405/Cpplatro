#pragma once

#include "common/Common.hh"

#include <cmath>
#include <cstdint>

class TempRandom {
public:
    TempRandom(const f64 &seed);

    f64 getDouble() {
        return (next() & (-1ULL >> 12)) * 0x1p-52;
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
