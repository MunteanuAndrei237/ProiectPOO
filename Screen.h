//
// Created by Andrei on 5/1/2023.
//

#ifndef PROIECTPOO_SCREEN_H
#define PROIECTPOO_SCREEN_H

#include <memory>
#include "Hud.h"

class Screen {
    int height;
    int width;
    std::shared_ptr<Hud> h;
    Gamemode sgamemode;
    static int count;
public:

    static void checkscreen();

    Screen(int h, int w, std::shared_ptr<Hud> h_, const std::string &gamemodegs);

    Screen(const Screen &other);

    friend void swop(Screen &s1, Screen &s2);

    Screen &operator=( Screen &other);

    ~Screen();

    friend std::ostream &operator<<(std::ostream &os, const Screen &screencout);

    void hinsertbalance(float amount);

    void hcashout();

    void showscreen();

    void hplay(float amount);

    void hdouble_the_win(float amount, const std::string& color);
};


#endif //PROIECTPOO_SCREEN_H
