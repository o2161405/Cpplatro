#pragma once

#include "engine/game/tag/TagBase.hh"

class TagHolo : public TagBase {
public:
    TagHolo() : TagBase("Holographic Tag", std::nullopt, 5) {}
};