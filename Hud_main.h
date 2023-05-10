//
// Created by Andrei on 4/30/2023.
//

#ifndef PROIECTPOO_HUD_MAIN_H
#define PROIECTPOO_HUD_MAIN_H
#include "Hud.h"
#include "Gamemode.h"


class Hud_main : public Hud {
public:
    Hud_main();

    Hud_main(const Hud_main &other);

    Hud_main &operator=(const Hud_main &other);

    ~Hud_main();

    void show() override;

    [[nodiscard]] const std::shared_ptr<Hud> clone() const override;

    void play(float amount, Gamemode g);

    void cashout() override;
};


#endif //PROIECTPOO_HUD_MAIN_H
