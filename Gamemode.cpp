//
// Created by Andrei on 4/30/2023.
//
#include<vector>
#include <string>
#include "Gamemode.h"
    Gamemode::Gamemode(const std::string &gs) : gamemode{gs} {
        if (gamemode == "classic") {
            weights = {0.15, 0.2, 0.2, 0.05, 0.2, 0.2};
            icons = {"cherry", "orange", "banana", "seven", "plum", "melon"};
            rows = 3;
            columns = 5;
        } else if (gamemode == "book_of_ra") {
            weights = {0.25, 0.25, 0.2, 0.05, 0.05, 0.25};
            icons = {"A", "Q", "K", "book", "pharaoh", "J"};
            rows = 3;
            columns = 5;
        } else if (gamemode == "shining_crown") {
            weights = {0.15, 0.19, 0.19, 0.05, 0.19, 0.18, 0.05};
            icons = {"cherry", "orange", "banana", "seven", "plum", "melon", "crown"};
            rows = 3;
            columns = 5;
        }
    }

        Gamemode::Gamemode(const Gamemode &other) : gamemode(other.gamemode), icons(other.icons), weights(other.weights),
                                      rows(other.rows), columns(other.columns) {}

        Gamemode &Gamemode::operator=(const Gamemode &other) {
        gamemode = other.gamemode;
        icons = other.icons;
        weights = other.weights;
        rows = other.rows;
        columns = other.columns;
        return *this;
    }

Gamemode::~Gamemode() {}

    std::ostream &operator<<(std::ostream &os, const Gamemode &gcout) {
        os << "gamemode: " << gcout.gamemode << ", icons:[";
        for (unsigned int i = 0; i < gcout.icons.size() - 1; i++)
            os << gcout.icons[i] << " ,";
        os << gcout.icons[gcout.icons.size() - 1];
        os << "], weights:[";
        for (unsigned int i = 0; i < gcout.weights.size() - 1; i++)
            os << gcout.weights[i] << " ,";
        os << gcout.weights[gcout.weights.size() - 1];
        os << "]\n";
        return os;
    }

    std::vector<std::vector<std::string>> Gamemode::generate_table() {
        std::vector <std::vector<std::string>> table(rows, std::vector<std::string>(columns));
        for (int rowindex = 0; rowindex < rows; rowindex++)
            for (int columnindex = 0; columnindex < columns; columnindex++) {
                float ch = float(rand() % 100) / 100;
                double weighttotal = 0;
                int index = 0;
                while (weighttotal <= ch) {
                    weighttotal = weighttotal + weights[index];
                    index += 1;
                }
                if (index != 0)
                    table[rowindex][columnindex] = icons[index - 1];
            }
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                std::cout << table[i][j] << " ";
            std::cout << "\n";
        }
        return table;
    }

    double Gamemode::calculate_multiplier(std::vector<std::vector<std::string>> table) {
        double multiplier = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < columns - 2; j++)
                if (table[i][j] == table[i][j + 1] && table[i][j + 1] == table[i][j + 2]) {
                    for (unsigned int k = 0; k < icons.size(); k++)
                        if (icons[k] == table[i][j])
                            multiplier += float(1 / weights[k]);
                }
        for (int i = 0; i < rows - 2; i++)
            for (int j = 0; j < columns - 2; j++)
                if (table[i][j] == table[i + 1][j + 1] && table[i + 1][j + 1] == table[i + 2][j + 2]) {
                    for (unsigned int k = 0; k < icons.size(); k++)
                        if (icons[k] == table[i][j])
                            multiplier += float(1 / weights[k]) * 1.3;
                }
        return multiplier;
    }



