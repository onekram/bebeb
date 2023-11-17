
#include "vector"
#include "iostream"
#include "ArgParser.h"

#include <utility>
#include "Argument.h"

ArgumentParser::ArgParser::ArgParser(std::string  name) : instanceName(std::move(name)) {}

std::string ArgumentParser::ArgParser::checkParameter(const std::string& str) {
    auto pos = str.rfind('-');
    if (pos == std::string::npos) {
        std::cout << "Error: Invalid parameter " << str << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string param = str.substr(pos + 1);
    if (param.length() == 1)
        return arguments.multiNamesParameters.find(param)->second;
    return param;
}

int ArgumentParser::ArgParser::checkValueInt(const std::string& str) {
    try {
        return std::stoi(str);
    } catch (const std::invalid_argument& ex) {
        std::cout << "Error: Invalid argument " << str << std::endl;
        exit(EXIT_FAILURE);
    } catch (const std::out_of_range& ex) {
        std::cout << "Error: Invalid argument " << str << " dont match int 32 bits" << std::endl;
        exit(EXIT_FAILURE);
    }
}

bool ArgumentParser::ArgParser::isNumeric(const std::string& str) {
    for (char ch : str)
        if (!('0' <= ch && '9' >= ch))
            return false;
    return true;
}

bool ArgumentParser::ArgParser::CheckAddedArguments() {
    for (auto & arg : arguments.listArguments) {
        if (!arg.second->isFilled()) return false;
    }
    return true;
}

bool ArgumentParser::ArgParser::Parse(const std::vector<std::string> &args) {
    if (args.empty()) {
        std::cout << "Error: Invalid number of currentArguments" << std::endl;
        exit(EXIT_FAILURE);
    }

    arguments.programName = args[0];

    int i = 1;
    while(i < args.size()) {
        const std::string& el = args[i];
        auto pos = el.find('=');
        std::string key = checkParameter(el.substr(0, pos));
        std::string value = el.substr(pos + 1);
        int valueInt;
        std::string valueStr;
        if (isNumeric(value)) {
            valueInt = checkValueInt(value);
//            currentArguments.listArguments.insert({key, Argument(key).Default(valueInt)});
            arguments.listArguments.find(key)->second->Default(valueInt);

        } else {
            valueStr = value;
//            currentArguments.listArguments.insert({key, Argument(key).Default(valueStr)});
            arguments.listArguments.find(key)->second->Default(valueStr);

        }
        ++i;
    }
    return CheckAddedArguments();
}

Argument& ArgumentParser::ArgParser::AddStringArgument(const std::string& parameterNameSecond) {

    auto* arg = new Argument(parameterNameSecond);
    arguments.listArguments.insert({parameterNameSecond, arg});

    return *arg;
}

Argument& ArgumentParser::ArgParser::AddStringArgument(char parameterNameFirst,
                                                        const std::string& parameterNameSecond) {

    auto* arg = new Argument(parameterNameSecond);
    std::string s {parameterNameFirst};
    arguments.multiNamesParameters.insert({s, parameterNameSecond});

    arguments.listArguments.insert({parameterNameSecond, arg});
    return *arg;
}

std::string ArgumentParser::ArgParser::GetStringValue(const std::string &name) {
    return arguments.listArguments.find(name)->second->valueStr;
}
