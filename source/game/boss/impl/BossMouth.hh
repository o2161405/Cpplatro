#pragma once

#include "game/boss/BossBase.hh"

class BossMouth : public BossBase {
public:
    BossMouth() : BossBase("The Mouth", 2.0, 2, 10, 5, false) {}
};
