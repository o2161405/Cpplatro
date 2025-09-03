#pragma once

#include "engine/game/tag/TagBase.hh"

class TagVoucher : public TagBase {
public:
    TagVoucher() : TagBase("Voucher Tag", std::nullopt, 8) {}
};