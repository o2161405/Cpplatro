#pragma once

#include "game/tag/TagBase.hh"

class TagEconomy : public TagBase {
public:
    TagEconomy() : TagBase("Economy Tag", std::nullopt) {}
};