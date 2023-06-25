//
// Created by Andrei on 5/17/2023.
//

#include "bet_builder.h"

bet_builder::bet_builder() = default;
    bet_builder& bet_builder::game_name(const std::string& gn) {
        b.game_name = gn;
        return *this;
    }
    bet_builder& bet_builder::betting_odd_team1(float nr) {
        b.betting_odd_team1 = nr;
        return *this;
    }
    bet_builder& bet_builder::betting_odd_team2(float nr) {
        b.betting_odd_team2 = nr;
        return *this;
    }
    bet_builder& bet_builder::team1(const std::string& t1) {
        b.team1 = t1;
        return *this;
    }
    bet_builder& bet_builder::team2(const std::string& t2) {
        b.team2 = t2;
        return *this;
    }
    bet bet_builder::build() {
        return b;
    }
