#pragma once

#include "game/boss/BossBase.hh"

class BossOx : public BossBase {
public:
    BossOx() : BossBase("The Ox", 2.0, 6, 10, 5, false) {}
};
