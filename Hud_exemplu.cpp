//
// Created by Andrei on 5/11/2023.
//

#include "Hud_exemplu.h"

Hud_exemplu::Hud_exemplu() = default;

Hud_exemplu::Hud_exemplu(const Hud_exemplu &other) = default;

Hud_exemplu &Hud_exemplu::operator=(const Hud_exemplu &other) = default;

Hud_exemplu::~Hud_exemplu() = default;

void Hud_exemplu::show() {
    std::cout << "HUD EXEMPLU SHOW\n";
}

const std::shared_ptr<Hud> Hud_exemplu::clone() const {
    return std::make_shared<Hud_exemplu>(*this);
}

void Hud_exemplu::cashout() {
    std::cout << "HUD EXEMPLU CASHOUT"<<"\n";
}
