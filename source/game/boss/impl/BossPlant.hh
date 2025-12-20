#pragma once

#include "game/boss/BossBase.hh"

class BossPlant : public BossBase {
public:
    BossPlant() : BossBase("The Plant", 2.0, 4, 10, 5, false) {}
};
