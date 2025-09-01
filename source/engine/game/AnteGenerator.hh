#pragma once

#include "engine/common/Common.hh"
#include "engine/common/Globals.hh"
#include "engine/util/Random.hh"

#include <memory>
#include <optional>
#include <unordered_map>

struct Blind {
    f64 chipRequirement;
    std::optional<TagContext> tagCtx;
    std::optional<BossContext> bossCtx;
};

struct Ante {
    Blind small;
    Blind big;
    Blind boss;
};

class AnteGenerator {
public:
    AnteGenerator();
    ~AnteGenerator() = default;

    std::unique_ptr<Ante> generate(State &roundStartParams, Random &prng);

private:
    BossContext nextBoss(State &roundStartParams, Random &prng);

    std::unordered_map<const char *, u64> m_bossesUsed;
};
