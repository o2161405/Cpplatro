#pragma once

#include "common/Common.hh"

#include <optional>

class Game;
struct State;

class TagBase {
public:
    virtual ~TagBase() = default;

    bool isEligible(const s8 &ante) const;

    inline const char* getDisplay() const { return m_display; }

protected:
    TagBase(const char* display, std::optional<u8> minAnte)
            : m_display(display), m_minAnte(minAnte) {}

    const char* m_display;
    std::optional<u8> m_minAnte;
};