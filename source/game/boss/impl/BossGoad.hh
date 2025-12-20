#pragma once

#include "game/boss/BossBase.hh"

class BossGoad : public BossBase {
public:
    BossGoad() : BossBase("The Goad", 2.0, 1, 10, 5, false) {}
};
