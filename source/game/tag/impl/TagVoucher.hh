#pragma once

#include "game/tag/TagBase.hh"

class TagVoucher : public TagBase {
public:
    TagVoucher() : TagBase("Voucher Tag", std::nullopt) {}
};