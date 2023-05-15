//
// Created by Andrei on 5/1/2023.
//
#include <iostream>
#include <cmath>
#include "Hud_double.h"

Hud_double::Hud_double() = default;

Hud_double::Hud_double(const Hud_double &other) = default;

Hud_double &Hud_double::operator=(const Hud_double &other) = default;

Hud_double::~Hud_double() = default;

void Hud_double::show() {
    std::cout << "double hud shown\n";
}

const std::shared_ptr<Hud> Hud_double::clone() const {
    return std::make_shared<Hud_double>(*this);
}

void Hud_double::double_the_win(float amount) {
    std::string culoare;
    tries += 1;
    if (tries == 1) {
        if (balance >= amount) {
            balance -= amount;
        } else {
            std::cout << "not enough funds\n";
        }
        std::cout << "culoare(red/black):";
        std::cin >> culoare;
        if (culoare == "black") {
            int ch = rand();
            if (ch % 2 == 0) {
                std::cout << "Red.You lost" << "\n";
                amount = 0;
                tries = 0;
            } else {
                amount *= 2;
                std::cout << "Black.You won:" << amount << "\n";
                double_the_win(amount);
            }
        } else if (culoare == "red") {
            int ch = rand();
            if (ch % 2 == 0) {
                std::cout << "Black.You lost" << "\n";
                amount = 0;
                tries = 0;
            } else {
                amount *= 2;
                std::cout << "Red.You won:" << amount << "\n";
                double_the_win(amount);
            };
        }
    } else if (tries > 1 and tries <= 5) {
        std::cout << "culoare(red/black/cashout):";
        std::cin >> culoare;
        if (culoare == "black") {
            int ch = rand();
            if (ch % 2 == 0) {
                std::cout << "Red.You lost" << "\n";
                amount = 0;
                tries = 0;
            } else {
                amount *= 2;
                std::cout << "Black.You won:" << amount << "\n";
                double_the_win(amount);
            };
        } else if (culoare == "red") {
            int ch = rand();
            if (ch % 2 == 0) {
                std::cout << "Black.You lost" << "\n";
                amount = 0;
                tries = 0;
            } else {
                amount *= 2;
                std::cout << "Red.You won:" << amount << "\n";
                double_the_win(amount);
            };
        } else if (culoare == "cashout") {
            cashout();
        }
    } else if (tries == 6) {
        cashout();
    }
}

void Hud_double::cashout() {
    int amountinitiallyinserted = total_inserted - balance;
    int realtries = tries - 1;
    int totalwin = amountinitiallyinserted * pow(2, realtries);
    std::cout << "You doubled your " << amountinitiallyinserted << "$ " << realtries << " time(s) and turned it into:"
              << totalwin << "$\n";
    balance += totalwin;
    tries = 0;
}

void Hud_double::print(std::ostream &os) const {
    Hud::print(os);
    os << "Tries" << tries << "\n";
}

