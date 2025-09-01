#pragma once

#include "engine/common/Common.hh"

#include <optional>

class Game;
struct State;

class TagBase {
public:
    virtual ~TagBase() = default;

    bool isEligible(const s8 &ante) const;

    inline const char* getDisplay() const { return m_display; }
    inline u8 getSortId() const { return m_sortId; }

protected:
    TagBase(const char* display, std::optional<u8> minAnte, u8 sortId)
            : m_display(display), m_minAnte(minAnte), m_sortId(sortId) {}

    const char* m_display;
    std::optional<u8> m_minAnte;
    u8 m_sortId;
};