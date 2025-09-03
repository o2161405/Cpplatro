#include "TagBase.hh"

#include "engine/game/Game.hh"
#include "engine/common/Globals.hh"

bool TagBase::isEligible(const s8 &ante) const {
    return m_minAnte.has_value() ? ante >= m_minAnte.value() : true;
}