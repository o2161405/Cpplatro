#pragma once

#include "game/boss/BossBase.hh"

class BossWall : public BossBase {
public:
    BossWall() : BossBase("The Wall", 4.0, 2, 10, 5, false) {}
};
