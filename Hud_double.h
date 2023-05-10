//
// Created by Andrei on 5/1/2023.
//

#ifndef PROIECTPOO_HUD_DOUBLE_H
#define PROIECTPOO_HUD_DOUBLE_H
#include "Hud.h"

class Hud_double : public Hud {
    int tries=0;
public:
    Hud_double() ;

    Hud_double(const Hud_double &other) ;

    Hud_double &operator=(const Hud_double &other) ;

    ~Hud_double();

    void show() override;

    [[nodiscard]] const std::shared_ptr<Hud> clone() const override ;

    void double_the_win(float amount) ;

    void cashout() override;
};


#endif //PROIECTPOO_HUD_DOUBLE_H
