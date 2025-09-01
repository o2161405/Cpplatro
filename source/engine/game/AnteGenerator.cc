#include "AnteGenerator.hh"

#include "engine/common/Common.hh"
#include "engine/common/Globals.hh"
#include "engine/game/Game.hh"
#include "engine/util/Random.hh"

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
    constexpr f64 SMALL_BLIND_CHIP_MULT = 1.0;
    constexpr f64 BIG_BLIND_CHIP_MULT = 1.5;
    const State& state = game.getState();
    const s8 anteIndex = std::max(0, state.ante - 1);
    const f64 anteBaseChipRequirement = anteChipRequirements[anteIndex];

    std::unique_ptr<Ante> ante = std::make_unique<Ante>(); 

    ante->small = {
        anteBaseChipRequirement * SMALL_BLIND_CHIP_MULT, // chipRequirement
        this->nextTag(game),                             // tag
        std::nullopt                                     // bossCtx
    };

    ante->big = {
        anteBaseChipRequirement * BIG_BLIND_CHIP_MULT, // chipRequirement
        this->nextTag(game),                           // tag
        std::nullopt                                   // bossCtx
    };

    BossContext nextBoss = this->nextBoss(game);
    ante->boss = {
        anteBaseChipRequirement * nextBoss.mult, // chipRequirement
        std::nullopt,                            // tag
        nextBoss                                 // bossCtx
    };

    return ante;
}

BossContext AnteGenerator::nextBoss(Game &game) {
    constexpr u8 WIN_ANTE = 8;
    const State& state = game.getState();
    const s64 currentAnte = state.ante;
    const u32 minAnte = std::max(static_cast<s64>(1), currentAnte);

    Random &prng = game.getPrng();
    u32 minUses = std::numeric_limits<u32>::max();
    std::unordered_map<const char *, u32> eligibleBosses;

    for (const auto &[bossName, bossInfo] : G_BLINDS) {
        bool eligible = false;

        if (!bossInfo.showdown && bossInfo.minAnte <= minAnte &&
                (minAnte % WIN_ANTE || currentAnte < 2)) {
            eligible = true;
        } else if (bossInfo.showdown && currentAnte % WIN_ANTE == 0 && currentAnte >= 2) {
            eligible = true;
        }

        if (!eligible) {
            continue;
        }

        auto it = m_bossesUsed.find(bossName);
        u32 currentUses = (it != m_bossesUsed.end()) ? it->second : 0;

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

std::shared_ptr<TagBase> AnteGenerator::nextTag(Game &game) {
    const s8 ante = game.getState().ante;
    const std::string keyBase = "Tag" + std::to_string(ante);

    Random &prng = game.getPrng();
    std::unordered_map<std::string, std::shared_ptr<TagBase>> tags;
    u32 unavailableCount = 0;

    for (const auto &[tagName, tagPtr] : G_TAGS) {
        if (tagPtr->isEligible(ante)) {
            tags.insert({tagName, tagPtr});
        } else {
            std::string unavailableKey = "UNAVAILABLE_" + std::to_string(unavailableCount++);
            tags.insert({unavailableKey, tagPtr});
        }
    }

    u32 it = 1;
    std::pair<std::string, std::shared_ptr<TagBase>> chosenTag;

    while (true) {
        std::string key = it == 1 ? keyBase : keyBase + "_resample" + std::to_string(it);
        f64 seed = prng.pseudoSeed(key, std::nullopt);
        chosenTag = prng.pseudoRandomElement(tags, seed);

        if (!chosenTag.first.starts_with("UNAVAILABLE")) {
            break;
        }

        it++;
    }

    return chosenTag.second;
}