#pragma once

#include "common/Common.hh"
#include "common/Globals.hh"
#include "util/Random.hh"

#include <array>
#include <functional>
#include <memory>
#include <optional>

class Game;

struct Blind {
    std::optional<std::reference_wrapper<const TagBase>> tag;
    std::optional<std::reference_wrapper<const BossBase>> boss;
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

    std::unique_ptr<Ante> generate(Game &game);

private:
    std::reference_wrapper<const BossBase> nextBoss(const s8 ante, Random &prng);
    std::reference_wrapper<const TagBase> nextTag(const s8 ante, Random &prng);

    std::array<u64, G_BOSSBLINDS.size()> m_bossesUsed = {0};
};
