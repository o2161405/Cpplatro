#pragma once

#include "game/boss/BossBase.hh"

class BossWater : public BossBase {
public:
    BossWater() : BossBase("The Water", 2.0, 2, 10, 5, false) {}
};
