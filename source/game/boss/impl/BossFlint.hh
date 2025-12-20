#pragma once

#include "game/boss/BossBase.hh"

class BossFlint : public BossBase {
public:
    BossFlint() : BossBase("The Flint", 2.0, 2, 10, 5, false) {}
};
