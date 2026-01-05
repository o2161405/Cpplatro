#include "Game.hh"

#include <iostream>
#include <print>

Game::Game(const std::string &seed, UIBase &ui) : m_prng(seed), m_state(G_STARTPARAMS), m_ui(ui) {
    this->run();
}

void Game::run() {
    // constexpr u8 WIN_ANTE = 8;

    // while (m_state.ante != WIN_ANTE) {

    m_currentAnte = m_anteGenerator.generate(m_state.ante, m_prng);
    
    UIChoice::Action<UIChoice::BlindSelection> action = m_ui.getBlindAction(m_currentAnte);
    
    std::visit(overloaded{[&](const UIChoice::BlindSelection &) {
                              std::println("Blind selection chosen\n");
                          },
                       [&](const UIChoice::Management::Action &) {
                           // when joker inventory and other stuff gets implemented, this needs to
                           // be another std::visit with all the Action variants
                       }},
            action);

    (void)action;

    //}
}
