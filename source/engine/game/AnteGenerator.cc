#include "AnteGenerator.hh"

#include "engine/common/Common.hh"
#include "engine/common/Globals.hh"
#include "engine/util/Random.hh"

#include <array>
#include <limits>
#include <memory>
#include <optional>

const std::array<u64, 8> anteChipRequirements = {300, 800, 2000, 5000, 11000, 20000, 35000, 50000};

AnteGenerator::AnteGenerator() : m_bossesUsed({}) {
    for (const auto &pair : G_BLINDS) {
        m_bossesUsed.insert({pair.first, 0});
    }
}

std::unique_ptr<Ante> AnteGenerator::generate(State &roundStartParams, Random &prng) {
    constexpr f64 SMALL_BLIND_CHIP_MULT = 1.0;
    constexpr f64 BIG_BLIND_CHIP_MULT = 1.5;
    const s8 anteIndex = std::max(0, roundStartParams.ante - 1);
    const f64 anteBaseChipRequirement = anteChipRequirements[anteIndex];

    std::unique_ptr<Ante> ante = std::make_unique<Ante>(); 

    // need to implement tag selection
    ante->small = {
        anteBaseChipRequirement * SMALL_BLIND_CHIP_MULT, // chipRequirement
        std::nullopt,                                    // tagCtx
        std::nullopt                                     // bossCtx
    };

    ante->big = {
        anteBaseChipRequirement * BIG_BLIND_CHIP_MULT, // chipRequirement
        std::nullopt,                                  // tagCtx
        std::nullopt                                   // bossCtx
    };

    BossContext nextBoss = this->nextBoss(roundStartParams, prng);
    ante->boss = {
        anteBaseChipRequirement * nextBoss.mult, // chipRequirement
        std::nullopt,                            // tagCtx
        nextBoss                                 // bossCtx
    };

    return ante;
}

BossContext AnteGenerator::nextBoss(State &roundStartParams, Random &prng) {
    constexpr u8 WIN_ANTE = 8;
    const s64 currentAnte = roundStartParams.ante;
    const u32 minAnte = std::max(static_cast<s64>(1), currentAnte);

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
