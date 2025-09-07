#pragma once

#include "game/tag/TagBase.hh"

class TagUncommon : public TagBase {
public:
    TagUncommon() : TagBase("Uncommon Tag", std::nullopt) {}
};