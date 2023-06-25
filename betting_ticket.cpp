//
// Created by Andrei on 5/17/2023.
//

#include "betting_ticket.h"
betting_ticket::betting_ticket()=default;
void betting_ticket::placeticket(float amount,Hud& h){
    h.setbalance(h.getbalance()-amount);
    float chance=rand()%int(totalbettingodds);
    if (chance==0)
    {
        std::cout<<"Winning ticket;you won: "<<amount*totalbettingodds;
        h.setbalance(h.getbalance()+amount*totalbettingodds);
    }
    else
        std::cout<<"Losing ticket:(.";
}