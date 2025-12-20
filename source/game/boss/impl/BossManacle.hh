#pragma once

#include "game/boss/BossBase.hh"

class BossManacle : public BossBase {
public:
    BossManacle() : BossBase("The Manacle", 2.0, 1, 10, 5, false) {}
};
