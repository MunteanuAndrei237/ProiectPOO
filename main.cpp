#include <iostream>
#include <string>
#include <ctime>
#include <exception>
#include <stdexcept>
#include "Gamemode.cpp"
#include "Hud.cpp"
#include "Hud_main.cpp"
#include "Hud_double.cpp"
#include "Screen.cpp"
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
        screen2.hdouble_the_win(20, "black");
        screen2.hdouble_the_win(20, "black");
        screen2.hdouble_the_win(20, "black");
        screen2.hcashout();
        screen2.showscreen();
    }
    catch (ratio_error &err) {
        std::cout << err.what() << "\n";
    }
    catch (std::invalid_argument &err) {
        std::cout << err.what() << "\n";
    }
    catch (std::exception &err) {
        std::cout << err.what() << "\n";
    }
    return 0;
}
