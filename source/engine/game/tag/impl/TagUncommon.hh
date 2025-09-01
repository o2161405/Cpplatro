#pragma once

#include "engine/game/tag/TagBase.hh"

class TagUncommon : public TagBase {
public:
    TagUncommon() : TagBase("Uncommon Tag", std::nullopt, 1) {}
};