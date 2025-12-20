#pragma once

#include "game/boss/BossBase.hh"

class BossArm : public BossBase {
public:
    BossArm() : BossBase("The Arm", 2.0, 2, 10, 5, false) {}
};
