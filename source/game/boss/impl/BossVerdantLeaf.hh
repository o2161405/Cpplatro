#pragma once

#include "game/boss/BossBase.hh"

class BossVerdantLeaf : public BossBase {
public:
    BossVerdantLeaf() : BossBase("Verdant Leaf", 2.0, 10, 10, 8, true) {}
};
