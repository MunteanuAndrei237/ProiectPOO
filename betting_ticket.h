//
// Created by Andrei on 5/17/2023.
//

#ifndef OOP_BETTING_TICKET_H
#define OOP_BETTING_TICKET_H
#include "bet.h"
#include "Hud.h"
#include <iostream>
//builder
//max 3 bets per ticket,min one
class betting_ticket{
    bet bet1;
    bet bet2;
    bet bet3;
    float totalbettingodds=1;
    friend class betting_ticket_builder;
public:
    betting_ticket();
    void placeticket(float amount,Hud& h);
};


#endif //OOP_BETTING_TICKET_H
