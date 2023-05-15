#include <iostream>
#include <string>
#include <ctime>
#include "Gamemode.h"
#include "Hud.h"
#include "Hud_main.h"
#include "Hud_double.h"
#include "Hud_changegamemode.h"
#include "Screen.h"
#include "ratio_error.h"

int main() {
    srand(time(nullptr));
    Gamemode g1("classic");
    Gamemode g2 = g1;
    Gamemode g3(g1);
    Gamemode g4("shining_crown");
    std::cout << g1;
    g1.generate_table();
    Hud_main h1;
    std::cout << h1;
    h1.play(20, g1);
    h1.insert_balance(300);
    h1.play(50, g2);
    Hud_changegamemode hcg;
    Gamemode* p=&g1;
    std::cout << g1;
    hcg.changegamemode(p);
    std::cout << g1;
    Hud_double hprint;
    std::cout<<hprint;
    try {
        Hud_main hm;
        Hud_double hd;
        Screen screen1(1080, 1920, hm.clone(), {"classic"});
        std::cout << screen1;
        screen1.hinsertbalance(300);
        screen1.hplay(20);
        screen1.hplay(20);
        screen1.hplay(40);
        screen1.hcashout();
        screen1.showscreen();
        Screen screen2(1080, 1920, hd.clone(), {"classic"});
        std::cout << screen2;
        screen2.hinsertbalance(300);
        screen2.hdouble_the_win(20);
        screen2.showscreen();
    }
    catch (ratio_error &err) {
        std::cout << err.what() <<"Please create a screen with a different height and width.\n";
    }
    return 0;
}
