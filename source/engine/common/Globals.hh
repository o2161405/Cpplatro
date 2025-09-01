#pragma once

#include "engine/common/Common.hh"

#include <unordered_map>

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

// TO DO: IMPLEMENT
struct TagContext {};

// Tag unordered_map here
