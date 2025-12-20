#pragma once

#include "game/boss/BossBase.hh"

class BossFish : public BossBase {
public:
    BossFish() : BossBase("The Fish", 2.0, 2, 10, 5, false) {}
};
