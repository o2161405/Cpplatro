#pragma once

#include "game/tag/TagBase.hh"

class TagRare : public TagBase {
public:
    TagRare() : TagBase("Rare Tag", std::nullopt) {}
};