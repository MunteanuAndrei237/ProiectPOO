//
// Created by Andrei on 5/17/2023.
//

#include "bet.h"

    bet::bet() = default;
    std::string bet::getteam1()
    {
        return team1;
    }
    std::string bet::getteam2()
    {
        return team2;
    }
    float bet::getbot1()
    {
        return betting_odd_team1;
    }
    float bet::getbot2()
    {
        return betting_odd_team2;
    }
