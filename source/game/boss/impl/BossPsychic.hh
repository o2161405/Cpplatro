#pragma once

#include "game/boss/BossBase.hh"

class BossPsychic : public BossBase {
public:
    BossPsychic() : BossBase("The Psychic", 2.0, 1, 10, 5, false) {}
};
