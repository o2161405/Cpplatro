#pragma once

#include "engine/game/tag/TagBase.hh"

class TagSkip : public TagBase {
public:
    TagSkip() : TagBase("Skip Tag", std::nullopt, 22) {}
};