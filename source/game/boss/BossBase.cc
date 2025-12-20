#include "BossBase.hh"

bool BossBase::isEligible(const s8 &ante) const {
    constexpr u8 WIN_ANTE = 8;
    const u8 effectiveAnte = std::max(static_cast<s8>(1), ante);

    if (!m_showdown && m_minAnte <= effectiveAnte && (effectiveAnte % WIN_ANTE || ante < 2)) {
        return true;
    } else if (m_showdown && ante % WIN_ANTE == 0 && ante >= 2) {
        return true;
    }

    return false;
}
