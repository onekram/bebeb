//
// Created by onekram on 11/16/23.
//

#include "Argument.h"

#include <utility>
#include "string"

Argument::Argument(std::string  parameterNameFirst) : nameSecond(std::move(parameterNameFirst)) {}

Argument::Argument(std::string  parameterNameFirst, std::string  parameterNameSecond) :
    nameFirst(std::move(parameterNameFirst)),
    nameSecond(std::move(parameterNameSecond))
    {}


Argument& Argument::Default(const std::string& value) {
    valueStr = value;
    filled = true;
    return *this;
}

Argument& Argument::Default(int value) {
    valueInt = value;
    filled = true;
    return *this;
}
