#pragma once

#include "game/boss/BossBase.hh"

class BossPillar : public BossBase {
public:
    BossPillar() : BossBase("The Pillar", 2.0, 1, 10, 5, false) {}
};
