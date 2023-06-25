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
#include "bet.h"
#include "bet_builder.h"
#include "betting_ticket.h"
#include "betting_ticket_builder.h"
#include "welcome_spin.h"
int main() {
    srand(time(nullptr));
    Hud_double hd;
    welcome_spin::use_spin(hd);
    bet_builder b;
    bet fcsb_rapid = b.game_name("Fotbal Liga 1").team1("FCSB").team2("Rapid").betting_odd_team1(1.83).betting_odd_team2(2.2).build();
    bet magnus_hikaru = b.game_name("Chess").team1("Magnus Carlsen").team2("Hikaru Nakamura").betting_odd_team1(1.12).betting_odd_team2(8.2).build();
    bet farul_cfr = b.game_name("Fotbal Liga 1").team1("farul constanta").team2("CFR").betting_odd_team1(1.46).betting_odd_team2(2.83).build();
    betting_ticket_builder bt;
    betting_ticket lucky_ticket=bt.bet1(fcsb_rapid,"FCSB").bet2(magnus_hikaru,"Magnus Carlsen").build();
    lucky_ticket.placeticket(10,hd);
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
    Gamemode* p=&g1;
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
