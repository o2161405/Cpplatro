#pragma once

#include "game/boss/BossBase.hh"

class BossNeedle : public BossBase {
public:
    BossNeedle() : BossBase("The Needle", 1.0, 2, 10, 5, false) {}
};
