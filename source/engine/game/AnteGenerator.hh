#pragma once

#include "engine/common/Common.hh"
#include "engine/common/Globals.hh"
#include "engine/util/Random.hh"

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
    BossContext nextBoss(Game &game);
    std::shared_ptr<TagBase> nextTag(Game &game);

    std::unordered_map<const char *, u64> m_bossesUsed;
};
