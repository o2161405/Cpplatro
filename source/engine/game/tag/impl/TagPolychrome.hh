#pragma once

#include "engine/game/tag/TagBase.hh"

class TagPolychrome : public TagBase {
public:
    TagPolychrome() : TagBase("Polychrome Tag", std::nullopt, 6) {}
};