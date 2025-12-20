#pragma once

#include "common/Common.hh"

#include <optional>
#include <string>
#include <unordered_map>

class Random {
public:
    Random(const std::string &seed);
    ~Random() = default;

    f64 pseudoHash(const std::string &seed) const;
    f64 pseudoSeed(const std::string &key, const std::optional<std::string> &predictSeed);

private:
    std::string m_seed;
    f64 m_pseudoHash;
    std::unordered_map<std::string, f64> m_rngStates;
};
