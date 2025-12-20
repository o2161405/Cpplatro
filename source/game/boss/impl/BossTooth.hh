#pragma once

#include "game/boss/BossBase.hh"

class BossTooth : public BossBase {
public:
    BossTooth() : BossBase("The Tooth", 2.0, 3, 10, 5, false) {}
};
