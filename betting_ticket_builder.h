//
// Created by Andrei on 5/17/2023.
//

#ifndef OOP_BETTING_TICKET_BUILDER_H
#define OOP_BETTING_TICKET_BUILDER_H
#include "betting_ticket.h"
//builder
class betting_ticket_builder {
private:
    betting_ticket bt;
public:
    betting_ticket_builder();
    betting_ticket_builder& bet1(bet& x,const std::string &teamname);
    betting_ticket_builder& bet2(bet& x,const std::string &teamname);
    [[maybe_unused]]  betting_ticket_builder& bet3(bet& x,const std::string &teamname);
    betting_ticket build();
};

#endif //OOP_BETTING_TICKET_BUILDER_H
