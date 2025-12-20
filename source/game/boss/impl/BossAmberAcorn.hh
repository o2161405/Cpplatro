#pragma once

#include "game/boss/BossBase.hh"

class BossAmberAcorn : public BossBase {
public:
    BossAmberAcorn() : BossBase("Amber Acorn", 2.0, 10, 10, 8, true) {}
};
