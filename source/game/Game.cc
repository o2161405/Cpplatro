#include "Game.hh"

#include <iostream>

Game::Game(const std::string &seed) : m_prng(seed), m_state(G_STARTPARAMS) {
    this->init();
}

void Game::init() {
    auto ante = m_anteGenerator.generate(*this);
    std::cout << ante->small.tag.value()->getDisplay() << std::endl;
    std::cout << ante->big.tag.value()->getDisplay() << std::endl;
}
