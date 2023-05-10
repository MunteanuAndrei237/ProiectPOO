//
// Created by Andrei on 4/30/2023.
//

#include "Hud_main.h"

Hud_main::Hud_main() = default;

Hud_main::Hud_main(const Hud_main &other) = default;

    Hud_main &Hud_main::operator=(const Hud_main &other) = default;

Hud_main::~Hud_main() = default;

    void Hud_main::show() {
        std::cout << "main hud shown\n";
    }

    const std::shared_ptr<Hud> Hud_main::clone() const {
        return std::make_shared<Hud_main>(*this);
    }

    void Hud_main::play(float amount, Gamemode g) {
        if (balance >= amount) {
            balance-=amount;
            std::vector<std::vector<std::string>> table = g.generate_table();
            double multiplier = g.calculate_multiplier(table);
            balance+= multiplier * amount;
            std::cout << "you multiplied your $" << amount << " by: " << multiplier << "\n";
        } else {
            std::cout << "not enough funds";
        }
    }
    void Hud_main::cashout() {
        std::cout << "Money inserted:" << total_inserted << "\n";
        std::cout << "Money out:" << balance << "\n";
        std::cout << "Profit:" << balance - total_inserted << "\n";
    }


