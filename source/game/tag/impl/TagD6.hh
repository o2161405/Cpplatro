#pragma once

#include "game/tag/TagBase.hh"

class TagD6 : public TagBase {
public:
    TagD6() : TagBase("D6 Tag", std::nullopt) {}
};