//
// Created by onekram on 11/16/23.
//
#pragma once
#include <vector>
#include <string>
class Argument {
private:
    std::string nameFirst;
    std::string nameSecond;
    std::string description;
    bool filled = false;
    bool stored = false;

    std::vector<std::string*> storedValueStr;
    std::vector<int*> storedValueInt;

    bool multiValue = false;

public:
    std::vector<std::string> valueStr;
    std::vector<int> valueInt;

    explicit Argument(const std::string& parameterNameFirst);
    explicit Argument(const std::string& parameterNameFirst, const std::string& parameterNameSecond);

    [[nodiscard]] bool isFilled() const { return filled;}

    Argument& Default(const std::string& value);
    Argument& Default(int value);

    Argument& StoreValue(std::string& value);

    Argument& StoreValue(int &value);

    Argument& MultiValue();

};


