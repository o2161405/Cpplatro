#pragma once

#include "game/tag/TagBase.hh"

class TagJuggle : public TagBase {
public:
    TagJuggle() : TagBase("Juggle Tag", std::nullopt) {}
};