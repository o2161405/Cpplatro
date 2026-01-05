#pragma once

#include "game/generators/AnteGenerator.hh"

#include <string>
#include <variant>
#include <vector>

struct UIChoice {
    struct Management {
        struct JokerSell { /* joker inventory impl required */
        };
        struct JokerMove { /* joker inventory impl required */
        };

        using Action = std::variant<JokerSell, JokerMove>;
    };

    struct BlindSelection {
        enum class Small { Skip, Pick };
        enum class Big { Skip, Pick };
        enum class Boss { Pick };
        std::variant<Small, Big, Boss> selection;
    };

    struct ShopSelection {
        // tarot and joker impl required before this gets filled in
        // use std::reference_wrapper<const JokerBase>
    };

    struct CardSelection {
        // card impl required before this gets filled in
        // use std::vector<std::reference_wrapper<Card>>
    };

    template <typename T>
    using Action = std::variant<T, Management::Action>;

    using Any = std::variant<BlindSelection, ShopSelection, CardSelection, Management::Action>;
};

template <class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

namespace UIHelpers {

inline std::vector<UIChoice::BlindSelection> getBlindChoices(const Ante &ante) {
    std::vector<UIChoice::BlindSelection> choices;
    choices.reserve(2);

    if (!ante.small.completed) {
        choices.push_back({UIChoice::BlindSelection::Small::Pick});
        choices.push_back({UIChoice::BlindSelection::Small::Skip});
    }

    else if (!ante.big.completed) {
        choices.push_back({UIChoice::BlindSelection::Big::Pick});
        choices.push_back({UIChoice::BlindSelection::Big::Skip});
    }

    else if (!ante.boss.completed) {
        choices.push_back({UIChoice::BlindSelection::Boss::Pick});
    }

    return choices;
}

} // namespace UIHelpers
