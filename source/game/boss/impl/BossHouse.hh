#pragma once

#include "game/boss/BossBase.hh"

class BossHouse : public BossBase {
public:
    BossHouse() : BossBase("The House", 2.0, 2, 10, 5, false) {}
};
