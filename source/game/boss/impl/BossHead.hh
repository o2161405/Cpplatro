#pragma once

#include "game/boss/BossBase.hh"

class BossHead : public BossBase {
public:
    BossHead() : BossBase("The Head", 2.0, 1, 10, 5, false) {}
};
