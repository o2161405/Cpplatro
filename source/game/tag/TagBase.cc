#include "TagBase.hh"

#include "game/Game.hh"
#include "common/Globals.hh"

bool TagBase::isEligible(const s8 &ante) const {
    return m_minAnte.has_value() ? ante >= m_minAnte.value() : true;
}