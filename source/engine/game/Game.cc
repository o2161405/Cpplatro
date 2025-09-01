#include "Game.hh"

#include "engine/common/Globals.hh"
#include "engine/util/Random.hh"

#include <cmath>
#include <cstring>

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <numbers>
#include <vector>

Game::Game(const std::string &seed) : m_prng(seed), m_roundStartParams(G_STARTPARAMS) {
    this->init();
}

void Game::init() {
    auto ante = m_anteGenerator.generate(m_roundStartParams, m_prng);
    std::cout << ante->boss.bossCtx.value().display << std::endl;
}
