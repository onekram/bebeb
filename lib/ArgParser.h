#pragma once

#include "string"
#include "vector"
#include "map"
#include "Argument.h"

namespace ArgumentParser {
    struct Arguments {
        std::string programName;
        std::map<std::string, Argument*> listArguments;
        std::map<std::string, std::string> multiNamesParameters;
    };
    class ArgParser {
    private:

        std::string instanceName;

        Arguments arguments;

        std::string checkParameter(const std::string&);

        static int checkValueInt(const std::string &str);

        static bool isNumeric(const std::string &str);

        bool CheckAddedArguments();

    public:
        explicit ArgParser(const std::string& name);

        bool Parse(const std::vector<std::string>& args);

        Argument& AddStringArgument(const std::string & parameterNameSecond);

        Argument& AddStringArgument(char parameterNameFirst, const std::string &parameterNameSecond);

        std::string GetStringValue(const std::string& name, int index = 0);

        Argument& AddIntArgument(const std::string &parameterNameSecond);

        Argument& AddIntArgument(char parameterNameFirst, const std::string &parameterNameSecond);

        int GetIntValue(const std::string& name, int index = 0);
    };

} // namespace ArgumentParser