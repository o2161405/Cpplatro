#pragma once

#include "game/tag/TagBase.hh"

class TagInvestment : public TagBase {
public:
    TagInvestment() : TagBase("Investment Tag", std::nullopt) {}
};