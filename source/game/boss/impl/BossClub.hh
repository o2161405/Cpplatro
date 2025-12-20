#pragma once

#include "game/boss/BossBase.hh"

class BossClub : public BossBase {
public:
    BossClub() : BossBase("The Club", 2.0, 1, 10, 5, false) {}
};
