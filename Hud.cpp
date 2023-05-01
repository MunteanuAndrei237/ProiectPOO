//
// Created by Andrei on 4/30/2023.
//

#include "Hud.h"

    float Hud::getbalance() const {
        return balance;
    }

    void Hud::setbalance(float newamount) {
        balance = newamount;
    }

    Hud::Hud() {};

Hud::Hud(const Hud &other) : balance(other.balance), total_inserted(other.total_inserted) {};

    Hud &Hud::operator=(const Hud &other) {
        balance = other.balance;
        total_inserted = other.total_inserted;
        return *this;
    };

Hud::~Hud() {};

     std::ostream &operator<<(std::ostream &os, const Hud &hudcout) {
        os << "balance: " << hudcout.balance << ", total inserted: " << hudcout.total_inserted << "\n";
        return os;
    }

    void Hud::insert_balance(float amount) {
        std::cout << "You inserted " << amount << "$\n";
        balance += amount;
        total_inserted += amount;
    }

    void Hud::cashout() {
        std::cout << "Money inserted:" << total_inserted << "\n";
        std::cout << "Money out:" << balance << "\n";
        std::cout << "Profit:" << balance - total_inserted << "\n";
    }
