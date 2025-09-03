#pragma once

#include "engine/game/tag/TagBase.hh"

class TagRare : public TagBase {
public:
    TagRare() : TagBase("Rare Tag", std::nullopt, 2) {}
};