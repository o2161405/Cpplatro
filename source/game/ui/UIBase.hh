#pragma once

#include "game/generators/AnteGenerator.hh"
#include "game/ui/UIChoice.hh"

class UIBase {
public:
    virtual ~UIBase() = default;

    virtual UIChoice::Action<UIChoice::BlindSelection> getBlindAction(const Ante &ante) = 0;
};
