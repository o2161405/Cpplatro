#pragma once

#include "common/Common.hh"
#include "util/TempRandom.hh"

#include <cstring>

#include <algorithm>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>

class Random {
public:
    Random(const std::string &seed);
    ~Random() = default;

    f64 pseudoHash(const std::string &seed) const;
    f64 pseudoSeed(const std::string &key, const std::optional<std::string> &predictSeed);

    template <typename K, typename V>
    std::pair<K, V> pseudoRandomElement(const std::unordered_map<K, V> &table, f64 seed) const {
        const size_t elementCount = table.size();

        std::vector<std::pair<K, V>> sortedTable;
        sortedTable.reserve(elementCount);
        for (const auto &pair : table) {
            sortedTable.push_back(pair);
        }

        if constexpr (requires(V v) { v->getSortId(); }) {
            std::sort(sortedTable.begin(), sortedTable.end(),
                    [](const auto &a, const auto &b) { return a.second->getSortId() < b.second->getSortId(); });
        } else {
            std::sort(sortedTable.begin(), sortedTable.end(),
                    [](const auto &a, const auto &b) { return std::strcmp(a.first, b.first) < 0; });
        }

        TempRandom tprng(seed);
        return sortedTable[tprng.getInteger(elementCount) - 1];
    }

private:
    std::string m_seed;
    f64 m_pseudoHash;
    std::unordered_map<std::string, f64> m_rngStates;
};
