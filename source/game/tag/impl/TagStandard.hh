#pragma once

#include "game/tag/TagBase.hh"

class TagStandard : public TagBase {
public:
    TagStandard() : TagBase("Standard Tag", 2) {}
};