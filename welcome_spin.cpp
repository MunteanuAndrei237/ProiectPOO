//
// Created by Andrei on 5/17/2023.
//

#include "welcome_spin.h"
    welcome_spin::welcome_spin() = default;


      welcome_spin& welcome_spin::use_spin(Hud& h) {
        int chance=rand() % 100;
        std::cout<<"You won:";
        if(chance<80)
        {
            std::cout<<"nothing";
        }
        else if(chance<95)
        {
            std::cout<<"10$";
            h.setbalance(h.getbalance()+10);
        }
        else if(chance<99)
        {
            std::cout<<"100$";
            h.setbalance(h.getbalance()+100);
        }
        else if(chance<99)
        {
            std::cout<<"1000$";
            h.setbalance(h.getbalance()+1000);
        }
        std::cout<<"\n";
        static welcome_spin ws;
        return ws;
    }