#pragma once

#include "game/ui/UIBase.hh"
#include "game/ui/UIChoice.hh"

#include <iostream>
#include <print>
#include <ranges>
#include <variant>

namespace UIHelpers {

inline std::string getDisplay(const UIChoice::Any &selection) {
    return std::visit(
            overloaded{
                    [](const UIChoice::BlindSelection &s) {
                        return std::string(std::visit(
                                overloaded{[](UIChoice::BlindSelection::Small s) {
                                               return (s == UIChoice::BlindSelection::Small::Pick) ?
                                                       "Pick Small Blind" :
                                                       "Skip Small Blind";
                                           },
                                        [](UIChoice::BlindSelection::Big b) {
                                            return (b == UIChoice::BlindSelection::Big::Pick) ?
                                                    "Pick Big Blind" :
                                                    "Skip Big Blind";
                                        },
                                        [](UIChoice::BlindSelection::Boss) {
                                            return "Pick Boss Blind";
                                        }},
                                s.selection));
                    },
                    [](const UIChoice::ShopSelection &) { return std::string("Shop Selection"); },
                    [](const UIChoice::CardSelection &) { return std::string("Card Selection"); },
                    [](const UIChoice::Management::Action &) {
                        // when joker inventory and other stuff gets implemented, this needs to
                        // be another std::visit with all the Action variants
                        return std::string("Some other action");
                    }},
            selection);
}

} // namespace UIHelpers

class UICommandLine : public UIBase {
public:
    UIChoice::Action<UIChoice::BlindSelection> getBlindAction(const Ante &ante) override {
        std::print("Blinds:\n  Small: {}\n  Big: {}\n  Boss: {}\n\n",
                ante.small.tag.value().get().getDisplay(), ante.big.tag.value().get().getDisplay(),
                ante.boss.boss.value().get().getDisplay());

        // Needs to be UIChoice::Action<UIChoice::BlindSelection> when management cases are added
        std::vector<UIChoice::BlindSelection> choices = UIHelpers::getBlindChoices(ante);

        std::print("Available Choices:\n");
        for (auto [i, choice] : std::views::enumerate(choices)) {
            std::print("  {}: {}\n", i, UIHelpers::getDisplay(choice));
        }

        // Management cases get added here

        int selection;
        while (true) {
            std::print("Enter choice: ");

            std::cin >> selection;
            if (!std::cin.fail() && selection >= 0 && selection <= choices.size() - 1) {
                break;
            }
        }

        return choices[selection];
    }
};
