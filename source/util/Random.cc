#include "Random.hh"

#include "common/Common.hh"
#include "util/TempRandom.hh"

#include <cstring>
#include <cmath>

#include <iomanip>
#include <string>
#include <vector>

Random::Random(const std::string &seed)
    : m_seed(seed), m_pseudoHash(pseudoHash(seed)), m_rngStates({}) {}

f64 Random::pseudoHash(const std::string &seed) const {
    constexpr f64 HASH_NUMERATOR = 1.1239285023;

    f64 output = 1.0;

    for (size_t i = seed.length(); i > 0; --i) {
        unsigned char c = static_cast<u8>(seed[i - 1]);
        f64 result = ((HASH_NUMERATOR / output) * c * std::numbers::pi + std::numbers::pi * i);

        output = std::fmod(result, 1.0);
        if (output < 0.0) {
            output += 1.0;
        }
    }

    return output;
}

f64 Random::pseudoSeed(const std::string &key, const std::optional<std::string> &predictSeed) {
    constexpr f64 HASH_BASE = 2.134453429141;
    constexpr f64 HASH_MULTI = 1.72431234;
    constexpr f64 FLOAT_TRUNCATION_MULT = 1e13;

    if (predictSeed) {
        f64 predictHash = pseudoHash(key + *predictSeed);
        predictHash = std::fmod(HASH_BASE + predictHash * HASH_MULTI, 1.0);
        predictHash = std::round(std::abs(predictHash) * FLOAT_TRUNCATION_MULT) / FLOAT_TRUNCATION_MULT;
        return (predictHash + pseudoHash(*predictSeed)) / 2.0;
    } else {
        if (m_rngStates.find(key) == m_rngStates.end()) {
            m_rngStates[key] = pseudoHash(key + m_seed);
        }

        f64 cachedState = m_rngStates[key];
        cachedState = std::fmod(HASH_BASE + cachedState * HASH_MULTI, 1.0);
        cachedState = std::round(std::abs(cachedState) * FLOAT_TRUNCATION_MULT) / FLOAT_TRUNCATION_MULT;

        m_rngStates[key] = cachedState;

        return (cachedState + m_pseudoHash) / 2.0;
    }
}
