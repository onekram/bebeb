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
    bool storedVector = false;

    std::string* storedValueStr;
    int* storedValueInt;
    std::vector<int>* storedValueVectorInt;
    std::vector<std::string>* storedValueVectorString;


    bool multiValue = false;
    int minAmount;

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

    Argument& MultiValue(int min = 0);

    Argument &StoreValues(std::vector<int> &values);
};


