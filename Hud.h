//
// Created by Andrei on 4/30/2023.
//

#ifndef PROIECTPOO_HUD_H
#define PROIECTPOO_HUD_H
#include <iostream>
#include <memory>
class Hud {
protected:
    float balance = 0;
    float total_inserted = 0;
public:
    [[nodiscard]] virtual const std::shared_ptr<Hud> clone() const=0;

    virtual void show()=0;

    [[nodiscard]] float getbalance() const;

    Hud();

    Hud(const Hud &other);

    Hud &operator=(const Hud &other) ;

    virtual ~Hud();

    friend std::ostream &operator<<(std::ostream &os, const Hud &hudcout);

    void insert_balance(float amount);

    virtual void cashout()=0;

    virtual void print(std::ostream& os) const ;
};


#endif //PROIECTPOO_HUD_H
