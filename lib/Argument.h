//
// Created by onekram on 11/16/23.
//
#pragma once

#include <string>

class Argument {
private:
    std::string nameFirst;
    std::string nameSecond;
    bool filled = false;

public:
    std::string valueStr;
    int valueInt{};

    explicit Argument(std::string  parameterNameFirst);
    explicit Argument(std::string parameterNameFirst, std::string parameterNameSecond);

    [[nodiscard]] bool isFilled() const { return filled;}

    Argument& Default(const std::string& valueName);

    Argument& Default(int value);
};


