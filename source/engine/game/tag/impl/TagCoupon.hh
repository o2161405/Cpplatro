#pragma once

#include "engine/game/tag/TagBase.hh"

class TagCoupon : public TagBase {
public:
    TagCoupon() : TagBase("Coupon Tag", std::nullopt, 17) {}
};