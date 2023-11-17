#include <functional>
#include <lib/ArgParser.h>

#include <iostream>
#include <numeric>
#include <sstream>
#include <iterator>


std::vector<std::string> SplitString(const std::string& str) {
    std::istringstream iss(str);

    return {std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>()};
}

struct Options {
    bool sum = false;
    bool mult = false;
};

int main(int argc, char** argv) {
    Options opt;
    std::vector<int> values;


    ArgumentParser::ArgParser parser("Program");
    std::string a;
    std::string b;


    parser.AddStringArgument("param1").MultiValue();
    parser.AddStringArgument("param2").Default("veve");

    parser.Parse(SplitString("app --param1=value1 --param1=vwvg"));
    std::cout << parser.GetStringValue("param1", 1) << '\n';
    std::cout << parser.GetStringValue("param2") << '\n';


//    parser.AddIntArgument("N").MultiValue(1).Positional().StoreValues(values);
//    parser.AddFlag("sum", "add args").StoreValue(opt.sum);
//    parser.AddFlag("mult", "multiply args").StoreValue(opt.mult);
//    parser.AddHelp('h', "help", "Program accumulate arguments");

//    if(!parser.Parse(argc, argv)) {
//        std::cout << "Wrong argument" << std::endl;
//        std::cout << parser.HelpDescription() << std::endl;
//        return 1;
//    }
//
//    if(parser.Help()) {
//        std::cout << parser.HelpDescription() << std::endl;
//        return 0;
//    }
//
//    if(opt.sum) {
//        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 0) << std::endl;
//    } else if(opt.mult) {
//        std::cout << "Result: " << std::accumulate(values.begin(), values.end(), 1, std::multiplies<int>()) << std::endl;
//    } else {
//        std::cout << "No one options had chosen" << std::endl;
//        std::cout << parser.HelpDescription();
//        return 1;
//    }

    return 0;

}
