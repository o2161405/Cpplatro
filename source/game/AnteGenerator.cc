#include "AnteGenerator.hh"

#include "common/Common.hh"
#include "common/Globals.hh"
#include "game/Game.hh"
#include "util/Random.hh"

#include <array>
#include <limits>
#include <memory>
#include <optional>
#include <iostream>

const std::array<u64, 8> anteChipRequirements = {300, 800, 2000, 5000, 11000, 20000, 35000, 50000};

AnteGenerator::AnteGenerator() : m_bossesUsed({}) {
    for (const auto &pair : G_BLINDS) {
        m_bossesUsed.insert({pair.first, 0});
    }
}

std::unique_ptr<Ante> AnteGenerator::generate(Game &game) {
    const State& state = game.getState();
    const f64 anteChipRequirement = anteChipRequirements[std::max(0, state.ante - 1)];

    std::unique_ptr<Ante> ante = std::make_unique<Ante>(); 
    Random& prng = game.getPrng();

    ante->small = {
        anteChipRequirement * 1.0,
        this->nextTag(state.ante, prng),
        std::nullopt
    };

    ante->big = {
        anteChipRequirement * 1.5,
        this->nextTag(state.ante, prng),
        std::nullopt
    };

    BossContext nextBoss = this->nextBoss(state.ante, prng);
    ante->boss = {
        anteChipRequirement * nextBoss.mult,
        std::nullopt,
        nextBoss
    };

    return ante;
}

BossContext AnteGenerator::nextBoss(const s8 ante, Random &prng) {
    constexpr u8 WIN_ANTE = 8;
    const u32 minAnte = std::max(static_cast<s8>(1), ante);

    std::unordered_map<const char *, u32> eligibleBosses;

    for (const auto &[bossName, bossInfo] : G_BLINDS) {
        bool eligible = false;

        if (!bossInfo.showdown && bossInfo.minAnte <= minAnte &&
                (minAnte % WIN_ANTE || ante < 2)) {
            eligible = true;
        } else if (bossInfo.showdown && ante % WIN_ANTE == 0 && ante >= 2) {
            eligible = true;
        }

        if (!eligible) {
            continue;
        }

        auto it = m_bossesUsed.find(bossName);
        u32 currentUses = (it != m_bossesUsed.end()) ? it->second : 0;
        u32 minUses = std::numeric_limits<u32>::max();

        if (currentUses < minUses) {
            minUses = currentUses;
            eligibleBosses.clear();
            eligibleBosses.insert({bossName, currentUses});
        } else if (currentUses == minUses) {
            eligibleBosses.insert({bossName, currentUses});
        }
    }

    f64 seed = prng.pseudoSeed("boss", std::nullopt);
    const char *chosenBoss = prng.pseudoRandomElement(eligibleBosses, seed).first;
    m_bossesUsed[chosenBoss] += 1;

    return G_BLINDS.at(chosenBoss);
}

std::shared_ptr<TagBase> AnteGenerator::nextTag(const s8 ante, Random &prng) {
    const std::string keyBase = "Tag" + std::to_string(ante);

    for (u32 i = 1; ; ++i) {
        std::string key = (i == 1) ? keyBase : keyBase + "_resample" + std::to_string(i);
        f64 seed = prng.pseudoSeed(key, std::nullopt);
        
        TempRandom tprng(seed);
        u64 tagIndex = tprng.getInteger(std::size(G_TAGS)) - 1;
        
        const std::shared_ptr<TagBase>& chosenTag = G_TAGS[tagIndex];

        if (chosenTag->isEligible(ante)) {
            return chosenTag;
        }
    }
}