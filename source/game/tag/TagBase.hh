#pragma once

#include "common/Common.hh"

#include <optional>
#include <string_view>

struct State;

class TagBase {
public:
    virtual ~TagBase() = default;

    bool isEligible(const s8 &ante) const {
        return m_minAnte.has_value() ? ante >= m_minAnte.value() : true;
    }

    inline std::string_view getDisplay() const {
        return m_display;
    }

protected:
    TagBase(std::string_view display, std::optional<u8> minAnte)
        : m_display(display), m_minAnte(minAnte) {}

    std::string_view m_display;
    std::optional<u8> m_minAnte;
};
