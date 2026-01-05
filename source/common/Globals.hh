#pragma once

#include "common/Common.hh"
#include "game/boss/BossInclude.hh"
#include "game/tag/TagInclude.hh"

#include <array>
#include <memory>

struct State {
    s8 dollars;
    u8 handSize;
    u8 discards;
    u8 hands;
    u8 rerollCost;
    u8 jokerSlots;
    u8 consumableSlots;
    s8 ante;
};

const State G_STARTPARAMS = {
        4, // dollars
        8, // handSize
        3, // discards
        4, // hands
        5, // rerollCost
        5, // jokerSlots
        2, // consumableSlots
        1  // ante
};

const std::array<std::unique_ptr<const BossBase>, 28> G_BOSSBLINDS = {{
        std::make_unique<BossArm>(),
        std::make_unique<BossClub>(),
        std::make_unique<BossEye>(),
        std::make_unique<BossAmberAcorn>(),
        std::make_unique<BossCeruleanBell>(),
        std::make_unique<BossCrimsonHeart>(),
        std::make_unique<BossVerdantLeaf>(),
        std::make_unique<BossVioletVessel>(),
        std::make_unique<BossFish>(),
        std::make_unique<BossFlint>(),
        std::make_unique<BossGoad>(),
        std::make_unique<BossHead>(),
        std::make_unique<BossHook>(),
        std::make_unique<BossHouse>(),
        std::make_unique<BossManacle>(),
        std::make_unique<BossMark>(),
        std::make_unique<BossMouth>(),
        std::make_unique<BossNeedle>(),
        std::make_unique<BossOx>(),
        std::make_unique<BossPillar>(),
        std::make_unique<BossPlant>(),
        std::make_unique<BossPsychic>(),
        std::make_unique<BossSerpent>(),
        std::make_unique<BossTooth>(),
        std::make_unique<BossWall>(),
        std::make_unique<BossWater>(),
        std::make_unique<BossWheel>(),
        std::make_unique<BossWindow>(),
}};

const std::array<std::unique_ptr<TagBase>, 24> G_TAGS = {{
        std::make_unique<TagUncommon>(),
        std::make_unique<TagRare>(),
        std::make_unique<TagNegative>(),
        std::make_unique<TagFoil>(),
        std::make_unique<TagHolo>(),
        std::make_unique<TagPolychrome>(),
        std::make_unique<TagInvestment>(),
        std::make_unique<TagVoucher>(),
        std::make_unique<TagBoss>(),
        std::make_unique<TagStandard>(),
        std::make_unique<TagCharm>(),
        std::make_unique<TagMeteor>(),
        std::make_unique<TagBuffoon>(),
        std::make_unique<TagHandy>(),
        std::make_unique<TagGarbage>(),
        std::make_unique<TagEthereal>(),
        std::make_unique<TagCoupon>(),
        std::make_unique<TagDouble>(),
        std::make_unique<TagJuggle>(),
        std::make_unique<TagD6>(),
        std::make_unique<TagTopUp>(),
        std::make_unique<TagSkip>(),
        std::make_unique<TagOrbital>(),
        std::make_unique<TagEconomy>(),
}};
