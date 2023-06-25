//
// Created by Andrei on 5/17/2023.
//

#ifndef OOP_WELCOME_SPIN_H
#define OOP_WELCOME_SPIN_H
#include "Hud.h"
//singleton
class welcome_spin {
private:
    welcome_spin();
public:
    welcome_spin(const welcome_spin&)=delete;
    welcome_spin& operator=(const welcome_spin&)=delete;
    static welcome_spin& use_spin(Hud& h);
};


#endif //OOP_WELCOME_SPIN_H
