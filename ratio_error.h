//
// Created by Andrei on 5/1/2023.
//
#pragma once
#include <stdexcept>
#include <exception>
class ratio_error : public std::exception {
    using exception::exception;
};
