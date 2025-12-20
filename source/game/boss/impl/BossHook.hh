#pragma once

#include "game/boss/BossBase.hh"

class BossHook : public BossBase {
public:
    BossHook() : BossBase("The Hook", 2.0, 1, 10, 5, false) {}
};
