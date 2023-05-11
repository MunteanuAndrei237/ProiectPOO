//
// Created by Andrei on 5/1/2023.
//

#include "Screen.h"
#include "Hud_double.h"
#include "Hud_main.h"
#include "min_dimensions_error.h"

void Screen::checkscreen() {
    if (count > 1) {
        std::cout << "One screen is already open.Close it if you want to create a new one.\n";
    }
}

Screen::Screen(int h, int w, std::shared_ptr<Hud> h_, std::string &gamemodegs) : height{h}, width{w}, h{move(h_)},
                                                                                       sgamemode{gamemodegs} {
    if (h / w > 1) {
        throw ratio_error("ratio_error\n");
    }
    if(h<300 || w<500)
    {
        throw min_dimensions_error("min_dimensions_error\n");
    }
    count += 1;
    checkscreen();
};

Screen::Screen(const Screen &other) : height{other.height}, width{other.width},h{other.h->clone()}, sgamemode{other.sgamemode} {};

void swop(Screen &s1, Screen &s2) {
    std::swap(s1.height, s2.height);
    std::swap(s1.width, s2.width);
    std::swap(s1.sgamemode, s2.sgamemode);
    std::swap(s1.h, s2.h);
}

Screen &Screen::operator=( Screen &other) {
    swop(*this, other);
    return *this;
}

Screen::~Screen() { count -= 1; };

std::ostream &operator<<(std::ostream &os, const Screen &screencout) {
    os << "height: " << screencout.height << ", width: " << screencout.width << "\n";
    return os;
}

void Screen::hinsertbalance(float amount) {
    h->insert_balance(amount);
}

void Screen::hcashout() {
    h->cashout();
}

void Screen::showscreen() {
    h->show();
    std::cout << "balance:" << h->getbalance() << "\n";
}

void Screen::hplay(float amount) {
    if (std::shared_ptr<Hud_main> hm = std::dynamic_pointer_cast<Hud_main>(h)) {
        hm->play(amount, sgamemode);
    } else {
        std::cout << "cast pointer nereușit\n";
    }
}

void Screen::hdouble_the_win(float amount) {
    if (std::shared_ptr<Hud_double> hd = std::dynamic_pointer_cast<Hud_double>(h)) {
        hd->double_the_win(amount);
    } else {
        std::cout << "cast pointer nereușit\n";
    }
}

int Screen::count = 0;