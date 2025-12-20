#pragma once

#include "game/boss/BossBase.hh"

class BossWheel : public BossBase {
public:
    BossWheel() : BossBase("The Wheel", 2.0, 2, 10, 5, false) {}
};
