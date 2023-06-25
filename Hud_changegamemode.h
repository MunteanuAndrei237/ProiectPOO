//
// Created by Andrei on 5/11/2023.
//

#ifndef OOP_HUD_CHANGEGAMEMODE_H
#define OOP_HUD_CHANGEGAMEMODE_H


#include "Hud.h"
#include "Gamemode.h"
class Hud_changegamemode: public Hud {

public:
    Hud_changegamemode();

    Hud_changegamemode(const Hud_changegamemode &other);

    Hud_changegamemode &operator=(const Hud_changegamemode &other);

    ~Hud_changegamemode();

    void show() override;

    [[nodiscard]] const std::shared_ptr<Hud> clone() const override;

    void cashout() override;

    void changegamemode(Gamemode* gh);
};


#endif //OOP_HUD_CHANGEGAMEMODE_H