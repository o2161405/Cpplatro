#include "AnteGenerator.hh"

#include "game/random/TempRandom.hh"

#include <limits>
#include <memory>
#include <optional>
#include <vector>

Ante AnteGenerator::generate(const s8 ante, Random &prng) {
    Ante generated;
    generated.small = {this->nextTag(ante, prng), std::nullopt, false};
    generated.big = {this->nextTag(ante, prng), std::nullopt, false};
    generated.boss = {std::nullopt, this->nextBoss(ante, prng), false};
    return generated;
}

std::reference_wrapper<const BossBase> AnteGenerator::nextBoss(const s8 ante, Random &prng) {
    u64 minUses = std::numeric_limits<u64>::max();
    std::vector<u32> eligibleBossIndices;

    for (u32 i = 0; i < G_BOSSBLINDS.size(); ++i) {
        if (!G_BOSSBLINDS[i]->isEligible(ante)) {
            continue;
        }

        u64 currentUses = m_bossesUsed[i];

        if (currentUses < minUses) {
            minUses = currentUses;
            eligibleBossIndices.clear();
            eligibleBossIndices.push_back(i);
        } else if (currentUses == minUses) {
            eligibleBossIndices.push_back(i);
        }
    }

    f64 seed = prng.pseudoSeed("boss", std::nullopt);
    TempRandom tprng(seed);

    u64 bossIndex = tprng.getInteger(eligibleBossIndices.size()) - 1;
    u32 chosenBossIndex = eligibleBossIndices[bossIndex];
    m_bossesUsed[chosenBossIndex]++;

    return *G_BOSSBLINDS[chosenBossIndex];
}

std::reference_wrapper<const TagBase> AnteGenerator::nextTag(const s8 ante, Random &prng) {
    const std::string keyBase = "Tag" + std::to_string(ante);

    for (u32 i = 1;; ++i) {
        std::string key = (i == 1) ? keyBase : keyBase + "_resample" + std::to_string(i);
        f64 seed = prng.pseudoSeed(key, std::nullopt);

        TempRandom tprng(seed);
        u64 tagIndex = tprng.getInteger(std::size(G_TAGS)) - 1;
        const TagBase &chosenTag = *G_TAGS[tagIndex];

        if (!chosenTag.isEligible(ante)) {
            continue;
        }

        return chosenTag;
    }
}
