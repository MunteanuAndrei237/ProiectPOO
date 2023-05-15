//
// Created by Andrei on 4/30/2023.
//

#include "Hud.h"

    float Hud::getbalance() const {
        return balance;
    }

    Hud::Hud() {};

Hud::Hud(const Hud &other) : balance(other.balance), total_inserted(other.total_inserted) {};

    Hud &Hud::operator=(const Hud &other) {
        balance = other.balance;
        total_inserted = other.total_inserted;
        return *this;
    };

Hud::~Hud() {};

     void Hud::print(std::ostream& os) const {
        os << "Balance: " << balance << "\n"<<"Total inserted: "<<total_inserted<<"\n";
    }

     std::ostream &operator<<(std::ostream &os, const Hud &hudcout) {
         hudcout.print(os);
        return os;
    }

    void Hud::insert_balance(float amount) {
        std::cout << "You inserted " << amount << "$\n";
        balance += amount;
        total_inserted += amount;
    }

