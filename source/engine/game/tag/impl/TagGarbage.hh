#pragma once

#include "engine/game/tag/TagBase.hh"

class TagGarbage : public TagBase {
public:
    TagGarbage() : TagBase("Garbage Tag", 2, 15) {}
};