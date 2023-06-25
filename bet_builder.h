//
// Created by Andrei on 5/17/2023.
//

#ifndef OOP_BET_BUILDER_H
#define OOP_BET_BUILDER_H
#include "bet.h"
//builder
class bet_builder {
private:
    bet b;
public:
    bet_builder();
    bet_builder& game_name(const std::string& gn) ;
    bet_builder& betting_odd_team1(float nr);
    bet_builder& betting_odd_team2(float nr);
    bet_builder& team1(const std::string& t1);
    bet_builder& team2(const std::string& t2);
    bet build();
};


#endif //OOP_BET_BUILDER_H
