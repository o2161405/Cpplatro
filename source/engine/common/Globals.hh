#pragma once

#include "engine/common/Common.hh"
#include "engine/game/tag/TagInclude.hh"

#include <unordered_map>
#include <memory>

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

const std::unordered_map<const char *, std::shared_ptr<TagBase>> G_TAGS = {
    {"tag_uncommon", std::make_shared<TagUncommon>()},
    {"tag_rare", std::make_shared<TagRare>()},
    {"tag_negative", std::make_shared<TagNegative>()},
    {"tag_foil", std::make_shared<TagFoil>()},
    {"tag_holo", std::make_shared<TagHolo>()},
    {"tag_polychrome", std::make_shared<TagPolychrome>()},
    {"tag_investment", std::make_shared<TagInvestment>()},
    {"tag_voucher", std::make_shared<TagVoucher>()},
    {"tag_boss", std::make_shared<TagBoss>()},
    {"tag_standard", std::make_shared<TagStandard>()},
    {"tag_charm", std::make_shared<TagCharm>()},
    {"tag_meteor", std::make_shared<TagMeteor>()},
    {"tag_buffoon", std::make_shared<TagBuffoon>()},
    {"tag_handy", std::make_shared<TagHandy>()},
    {"tag_garbage", std::make_shared<TagGarbage>()},
    {"tag_ethereal", std::make_shared<TagEthereal>()},
    {"tag_coupon", std::make_shared<TagCoupon>()},
    {"tag_double", std::make_shared<TagDouble>()},
    {"tag_juggle", std::make_shared<TagJuggle>()},
    {"tag_d_six", std::make_shared<TagD6>()},
    {"tag_top_up", std::make_shared<TagTopUp>()},
    {"tag_skip", std::make_shared<TagSkip>()},
    {"tag_orbital", std::make_shared<TagOrbital>()},
    {"tag_economy", std::make_shared<TagEconomy>()}};