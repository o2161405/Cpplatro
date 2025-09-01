#pragma once

#include "engine/game/tag/TagBase.hh"

class TagDouble : public TagBase {
public:
    TagDouble() : TagBase("Double Tag", std::nullopt, 18) {}
};