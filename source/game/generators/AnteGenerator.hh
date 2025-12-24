#pragma once

#include "common/Common.hh"
#include "common/Globals.hh"
#include "game/random/Random.hh"

#include <array>
#include <functional>
#include <memory>
#include <optional>

struct Blind {
    std::optional<std::reference_wrapper<const TagBase>> tag;
    std::optional<std::reference_wrapper<const BossBase>> boss;
    bool completed;
};

struct Ante {
    Blind small;
    Blind big;
    Blind boss;
};

class AnteGenerator {
public:
    AnteGenerator() = default;
    ~AnteGenerator() = default;

    Ante generate(const s8 ante, Random &prng);

private:
    std::reference_wrapper<const BossBase> nextBoss(const s8 ante, Random &prng);
    std::reference_wrapper<const TagBase> nextTag(const s8 ante, Random &prng);

    std::array<u64, G_BOSSBLINDS.size()> m_bossesUsed = {0};
};
