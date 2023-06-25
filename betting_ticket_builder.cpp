//
// Created by Andrei on 5/17/2023.
//

#include "betting_ticket_builder.h"

    betting_ticket_builder:: betting_ticket_builder() = default;
    betting_ticket_builder&  betting_ticket_builder:: bet1(bet& x,const std::string &teamname) {
        bt.bet1 = x;
        if(teamname==x.getteam1())
            bt.totalbettingodds*=x.getbot1();
        else if (teamname==x.getteam2())
            bt.totalbettingodds*=x.getbot2();
        return *this;
    }
    betting_ticket_builder&  betting_ticket_builder:: bet2(bet& x,const std::string &teamname) {
        bt.bet2 = x;
        if(teamname==x.getteam1())
            bt.totalbettingodds*=x.getbot1();
        else if (teamname==x.getteam2())
            bt.totalbettingodds*=x.getbot2();
        return *this;
    }
[[maybe_unused]] betting_ticket_builder&  betting_ticket_builder:: bet3(bet& x,const std::string &teamname) {
         bt.bet3 = x;
        if(teamname==x.getteam1())
            bt.totalbettingodds*=x.getbot1();
        else if (teamname==x.getteam2())
            bt.totalbettingodds*=x.getbot2();
        return *this;
    }
    betting_ticket  betting_ticket_builder:: build() {
        std::cout<<"Ticket created.Betting odds: "<<bt.totalbettingodds<<"\n";
        return bt;
    }
