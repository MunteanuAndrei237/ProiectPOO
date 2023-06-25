//
// Created by Andrei on 5/11/2023.
//

#include "Hud_changegamemode.h"

Hud_changegamemode::Hud_changegamemode() = default;

Hud_changegamemode::Hud_changegamemode(const Hud_changegamemode &other) = default;

Hud_changegamemode &Hud_changegamemode::operator=(const Hud_changegamemode &other) = default;

Hud_changegamemode::~Hud_changegamemode() = default;

void Hud_changegamemode::show() {
    std::cout << "hud change gamemode shown\n";
}

const std::shared_ptr<Hud> Hud_changegamemode::clone() const {
    return std::make_shared<Hud_changegamemode>(*this);
}

void Hud_changegamemode::cashout() {
    std::cout << "Money inserted:" << total_inserted << "\n";
    std::cout << "Money out:" << balance << "\n";
    std::cout << "Profit:" << balance - total_inserted << "\n";
}

void Hud_changegamemode::changegamemode(Gamemode* gh){
    std::string newgamemode;
    std::cout<<"Change gamemode(classic/book_of_ra/shining_crown):";
    std::cin>>newgamemode;
    *gh=Gamemode(newgamemode);
}