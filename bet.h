//
// Created by Andrei on 5/17/2023.
//

#ifndef OOP_BET_H
#define OOP_BET_H
#include <string>
//builder
class bet {
protected:
    std::string game_name;
    std::string team1;
    std::string team2;
    float betting_odd_team1;
    float betting_odd_team2;
    friend class bet_builder;
public:
    bet();
    std::string getteam1();
    std::string getteam2();
    float getbot1();
    float getbot2();
};


#endif //OOP_BET_H
