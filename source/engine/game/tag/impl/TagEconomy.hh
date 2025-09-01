#pragma once

#include "engine/game/tag/TagBase.hh"

class TagEconomy : public TagBase {
public:
    TagEconomy() : TagBase("Economy Tag", std::nullopt, 24) {}
};