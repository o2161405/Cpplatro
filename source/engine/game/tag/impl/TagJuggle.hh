#pragma once

#include "engine/game/tag/TagBase.hh"

class TagJuggle : public TagBase {
public:
    TagJuggle() : TagBase("Juggle Tag", std::nullopt, 19) {}
};