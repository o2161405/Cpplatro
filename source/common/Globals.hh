#pragma once

#include "common/Common.hh"
#include "game/tag/TagInclude.hh"

#include <unordered_map>
#include <memory>
#include <array>

struct BossContext {
    const char *display;
    f64 mult;
    u8 minAnte;
    u8 maxAnte;
    u8 reward;
    bool showdown;
};

const std::unordered_map<const char *, BossContext> G_BLINDS = {
        {"bl_ox", {"The Ox", 2.0, 6, 10, 5, false}},
        {"bl_hook", {"The Hook", 2.0, 1, 10, 5, false}},
        {"bl_mouth", {"The Mouth", 2.0, 2, 10, 5, false}},
        {"bl_fish", {"The Fish", 2.0, 2, 10, 5, false}},
        {"bl_club", {"The Club", 2.0, 1, 10, 5, false}},
        {"bl_manacle", {"The Manacle", 2.0, 1, 10, 5, false}},
        {"bl_tooth", {"The Tooth", 2.0, 3, 10, 5, false}},
        {"bl_wall", {"The Wall", 4.0, 2, 10, 5, false}},
        {"bl_house", {"The House", 2.0, 2, 10, 5, false}},
        {"bl_mark", {"The Mark", 2.0, 2, 10, 5, false}},
        {"bl_window", {"The Window", 2.0, 1, 10, 5, false}},
        {"bl_serpent", {"The Serpent", 2.0, 5, 10, 5, false}},
        {"bl_pillar", {"The Pillar", 2.0, 1, 10, 5, false}},
        {"bl_flint", {"The Flint", 2.0, 2, 10, 5, false}},
        {"bl_wheel", {"The Wheel", 2.0, 2, 10, 5, false}},
        {"bl_arm", {"The Arm", 2.0, 2, 10, 5, false}},
        {"bl_psychic", {"The Psychic", 2.0, 1, 10, 5, false}},
        {"bl_goad", {"The Goad", 2.0, 1, 10, 5, false}},
        {"bl_water", {"The Water", 2.0, 2, 10, 5, false}},
        {"bl_eye", {"The Eye", 2.0, 3, 10, 5, false}},
        {"bl_plant", {"The Plant", 2.0, 4, 10, 5, false}},
        {"bl_needle", {"The Needle", 1.0, 2, 10, 5, false}},
        {"bl_head", {"The Head", 2.0, 1, 10, 5, false}},
        {"bl_final_bell", {"Cerulean Bell", 2.0, 10, 10, 8, true}},
        {"bl_final_leaf", {"Verdant Leaf", 2.0, 10, 10, 8, true}},
        {"bl_final_vessel", {"Violet Vessel", 6.0, 10, 10, 8, true}},
        {"bl_final_acorn", {"Amber Acorn", 2.0, 10, 10, 8, true}},
        {"bl_final_heart", {"Crimson Heart", 2.0, 10, 10, 8, true}}};

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

// sorted by the "order" parameter in the base game
const std::array<std::shared_ptr<TagBase>, 24> G_TAGS = {{
    std::make_shared<TagUncommon>(),
    std::make_shared<TagRare>(),
    std::make_shared<TagNegative>(),
    std::make_shared<TagFoil>(),
    std::make_shared<TagHolo>(),
    std::make_shared<TagPolychrome>(),
    std::make_shared<TagInvestment>(),
    std::make_shared<TagVoucher>(),
    std::make_shared<TagBoss>(),
    std::make_shared<TagStandard>(),
    std::make_shared<TagCharm>(),
    std::make_shared<TagMeteor>(),
    std::make_shared<TagBuffoon>(),
    std::make_shared<TagHandy>(),
    std::make_shared<TagGarbage>(),
    std::make_shared<TagEthereal>(),
    std::make_shared<TagCoupon>(),
    std::make_shared<TagDouble>(),
    std::make_shared<TagJuggle>(),
    std::make_shared<TagD6>(),
    std::make_shared<TagTopUp>(),
    std::make_shared<TagSkip>(),
    std::make_shared<TagOrbital>(),
    std::make_shared<TagEconomy>()
}};