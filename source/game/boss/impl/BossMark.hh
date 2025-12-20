#pragma once

#include "game/boss/BossBase.hh"

class BossMark : public BossBase {
public:
    BossMark() : BossBase("The Mark", 2.0, 2, 10, 5, false) {}
};
