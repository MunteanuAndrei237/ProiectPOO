//
// Created by Andrei on 4/30/2023.
//

#ifndef PROIECTPOO_GAMEMODE_H
#define PROIECTPOO_GAMEMODE_H

#include<vector>
#include<iostream>

class Gamemode {
    std::string gamemode;
    std::vector<std::string> icons;
    std::vector<double> weights;
    int rows;
    int columns;
public:
    Gamemode(const std::string &gs);

    Gamemode(const Gamemode &other) ;

    Gamemode &operator=(const Gamemode &other) ;

    ~Gamemode() ;

    friend std::ostream &operator<<(std::ostream &os, const Gamemode &gcout);

    std::vector<std::vector<std::string>> generate_table() ;

    double calculate_multiplier(std::vector<std::vector<std::string>> table);
};


#endif //PROIECTPOO_GAMEMODE_H
