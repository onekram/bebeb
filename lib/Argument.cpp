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
    if (!multiValue) {
        if (size == 0)
            valueStr.push_back(value);
        else
            valueStr[0] = value;
        filled = true;
    } else {
        valueStr.push_back(value);
        if (valueInt.size() >= minAmount)
            filled = true;
    }

    if (stored)
        *storedValueStr = value;
    if (storedVector)
        storedValueVectorString->push_back(value);
    return *this;
}

Argument& Argument::Default(int value) {
    size_t size = valueInt.size();
    if (!multiValue) {
        if (size == 0)
            valueInt.push_back(value);
        else
            valueInt[0] = value;
        filled = true;
    } else {
        valueInt.push_back(value);
        if (valueInt.size() >= minAmount)
            filled = true;
    }

    if (stored)
        *storedValueInt = value;
    if (storedVector)
        storedValueVectorInt->push_back(value);
    return *this;
}

Argument& Argument::StoreValue(std::string& value) {
    stored = true;
    storedValueStr = &value;
    return *this;
}

Argument& Argument::StoreValue(int& value) {
    stored = true;
    storedValueInt = &value;
    return *this;
}

Argument& Argument::StoreValues(std::vector<int>& values) {
    storedVector = true;
    storedValueVectorInt = &values;
    return *this;
}

Argument &Argument::MultiValue(int min) {
    multiValue = true;
    minAmount = min;
}

