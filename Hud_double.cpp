//
// Created by Andrei on 5/1/2023.
//
#include "Hud_double.h"

Hud_double::Hud_double() = default;

Hud_double::Hud_double(const Hud_double &other) = default;

Hud_double &Hud_double::operator=(const Hud_double &other) = default;

Hud_double::~Hud_double() = default;

    void Hud_double::show() {
        std::cout << "double hud shown\n";
    }

    const std::shared_ptr<Hud> Hud_double::clone() const  {
        return std::make_shared<Hud_double>(*this);
    }

    void Hud_double::double_the_win(float amount, const std::string &culoare) {
        if (getbalance() >= amount) {
            setbalance(getbalance() - amount);
            int ch = rand();
            if (ch % 2 == 0) {
                if (culoare == "black")
                    std::cout << "Black.";
                else
                    std::cout << "Red.";
                std::cout << "You won:" << amount << "\n";
                amount *= 2;
            } else {
                if (culoare == "black")
                    std::cout << "Red.";
                else
                    std::cout << "Black.";
                std::cout << "You lost:" << amount << "\n";
                amount = 0;
            }
            setbalance(getbalance() + amount);
        } else {
            std::cout << "not enough funds\n";
        }
    }

