#pragma once

#include "game/tag/TagBase.hh"

class TagCharm : public TagBase {
public:
    TagCharm() : TagBase("Charm Tag", std::nullopt) {}
};