#pragma once

#include "game/tag/TagBase.hh"

class TagBoss : public TagBase {
public:
    TagBoss() : TagBase("Boss Tag", std::nullopt) {}
};