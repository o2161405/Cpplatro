#pragma once

#include "game/boss/BossBase.hh"

class BossCeruleanBell : public BossBase {
public:
    BossCeruleanBell() : BossBase("Cerulean Bell", 2.0, 10, 10, 8, true) {}
};
