#pragma once

#include "game/tag/TagBase.hh"

class TagHolo : public TagBase {
public:
    TagHolo() : TagBase("Holographic Tag", std::nullopt) {}
};