#pragma once

#include "game/boss/BossBase.hh"

class BossSerpent : public BossBase {
public:
    BossSerpent() : BossBase("The Serpent", 2.0, 5, 10, 5, false) {}
};
