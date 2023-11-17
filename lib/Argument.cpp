//
// Created by onekram on 11/16/23.
//

#include "Argument.h"

#include <vector>
#include <string>

Argument::Argument(const std::string& parameterNameFirst) : nameSecond(parameterNameFirst) {}

Argument::Argument(const std::string& parameterNameFirst, const std::string&  parameterNameSecond) :
    nameFirst(parameterNameFirst),
    nameSecond(parameterNameSecond)
    {}

Argument& Argument::Default(const std::string& value) {
    size_t size = valueStr.size();
    if (!multiValue)
        if (size == 0)
            valueStr.push_back(value);
        else
            valueStr[0] = value;
    else
        valueStr.push_back(value);
    filled = true;

    if (stored)
        *storedValueStr[size] = value;
    return *this;
}

Argument& Argument::Default(int value) {
    size_t size = valueInt.size();
    if (!multiValue)
        if (size == 0)
            valueInt.push_back(value);
        else
            valueInt[0] = value;
    else
        valueInt.push_back(value);
    filled = true;

    if (stored)
        *storedValueInt[size] = value;
    return *this;
}

Argument& Argument::StoreValue(std::string& value) {
    stored = true;
    storedValueStr.push_back(&value);
    return *this;
}

Argument& Argument::StoreValue(int& value) {
    stored = true;
    storedValueInt.push_back(&value);
    return *this;
}

Argument &Argument::MultiValue() {
    multiValue = true;
}

