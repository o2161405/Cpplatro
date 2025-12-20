#pragma once

#include "game/boss/BossBase.hh"

class BossEye : public BossBase {
public:
    BossEye() : BossBase("The Eye", 2.0, 3, 10, 5, false) {}
};
