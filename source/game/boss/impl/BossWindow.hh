#pragma once

#include "game/boss/BossBase.hh"

class BossWindow : public BossBase {
public:
    BossWindow() : BossBase("The Window", 2.0, 1, 10, 5, false) {}
};
