#pragma once

#include "game/tag/TagBase.hh"

class TagGarbage : public TagBase {
public:
    TagGarbage() : TagBase("Garbage Tag", 2) {}
};