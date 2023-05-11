//
// Created by Andrei on 5/11/2023.
//

#ifndef OOP_HUD_EXEMPLU_H
#define OOP_HUD_EXEMPLU_H


#include "Hud.h"

class Hud_exemplu:public Hud {
public:
    Hud_exemplu();

    Hud_exemplu(const Hud_exemplu &other);

    Hud_exemplu &operator=(const Hud_exemplu &other);

    ~Hud_exemplu();

    void show() override;

    [[nodiscard]] const std::shared_ptr<Hud> clone() const override;

    void cashout() override;
};


#endif //OOP_HUD_EXEMPLU_H
