#pragma once

#include "game/tag/TagBase.hh"

class TagTopUp : public TagBase {
public:
    TagTopUp() : TagBase("Top-Up Tag", 2) {}
};