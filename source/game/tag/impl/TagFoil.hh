#pragma once

#include "game/tag/TagBase.hh"

class TagFoil : public TagBase {
public:
    TagFoil() : TagBase("Foil Tag", std::nullopt) {}
};