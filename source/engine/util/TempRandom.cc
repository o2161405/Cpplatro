#include "TempRandom.hh"

#include <array>
#include <bit>
#include <numbers>

namespace {

template <int K, int Q, int S>
void lj_tw223_gen(u64 &state, u64 &result) {
    constexpr u64 mask = static_cast<u64>(-1LL) << (64 - K);

    u64 z = state;
    z = (((z << Q) ^ z) >> (K - S)) ^ ((z & mask) << S);
    result ^= z;
    state = z;
}

} // namespace

TempRandom::TempRandom(const f64 &seed) {
    m_state[0] = 0xa0d277570a345b8c;
    m_state[1] = 0x764a296c5d4aa64f;
    m_state[2] = 0x51220704070adeaa;
    m_state[3] = 0x2a2717b5a7b7b927;
    this->seed(seed);
}

void TempRandom::seed(const f64 &seed) {
    constexpr std::array<u8, 4> SEED_MAGIC = {0x01, 0x06, 0x09, 0x11};

    f64 d = seed;

    for (int i = 0; i < 4; ++i) {
        const u32 m = 1u << SEED_MAGIC[i];

        d = d * std::numbers::pi + std::numbers::e;

        u64 val = std::bit_cast<u64>(d);
        if (val < m) {
            val += m;
        }

        m_state[i] = val;
    }

    for (int i = 0; i < 10; ++i) {
        next();
    }
}

u64 TempRandom::next() {
    u64 result = 0;
    lj_tw223_gen<63, 31, 18>(m_state[0], result);
    lj_tw223_gen<58, 19, 28>(m_state[1], result);
    lj_tw223_gen<55, 24, 7>(m_state[2], result);
    lj_tw223_gen<47, 21, 8>(m_state[3], result);
    return result;
}
