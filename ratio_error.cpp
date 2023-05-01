//
// Created by Andrei on 5/1/2023.
//
#include <stdexcept>

class ratio_error : public std::invalid_argument {
    using invalid_argument::invalid_argument;
};
