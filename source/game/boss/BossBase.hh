#pragma once

#include "common/Common.hh"

#include <string_view>

class BossBase {
public:
    virtual ~BossBase() = default;

    bool isEligible(const s8 &ante) const;

    inline std::string_view getDisplay() const {
        return m_display;
    }

    inline f64 getMult() const {
        return m_mult;
    }

    inline u8 getReward() const {
        return m_reward;
    }

    inline bool isShowdown() const {
        return m_showdown;
    }

protected:
    BossBase(std::string_view display, f64 mult, u8 minAnte, u8 maxAnte, u8 reward, bool showdown)
        : m_display(display), m_mult(mult), m_minAnte(minAnte), m_maxAnte(maxAnte),
          m_reward(reward), m_showdown(showdown) {}

    std::string_view m_display;
    f64 m_mult;
    u8 m_minAnte;
    u8 m_maxAnte;
    u8 m_reward;
    bool m_showdown;
};
