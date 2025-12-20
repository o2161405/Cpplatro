#pragma once

#include "game/boss/BossBase.hh"

class BossVioletVessel : public BossBase {
public:
    BossVioletVessel() : BossBase("Violet Vessel", 6.0, 10, 10, 8, true) {}
};
