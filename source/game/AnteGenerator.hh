#pragma once

#include "common/Common.hh"
#include "common/Globals.hh"
#include "util/Random.hh"

#include <memory>
#include <optional>
#include <unordered_map>

class Game;

struct Blind {
    f64 chipRequirement;
    std::optional<std::shared_ptr<TagBase>> tag;
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

    std::unique_ptr<Ante> generate(Game &game);

private:
    BossContext nextBoss(const s8 ante, Random &prng);
    std::shared_ptr<TagBase> nextTag(const s8 ante, Random &prng);

    std::unordered_map<const char *, u32> m_bossesUsed;
};
