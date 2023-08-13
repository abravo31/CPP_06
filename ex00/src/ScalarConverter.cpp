#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}

ScalarConverter::~ScalarConverter( void ){}

bool ScalarConverter::isChar( std::string input ){

    return (input.size() == 3 && input[0] == '\'' && input[2] == '\'');
}

VarType	ScalarConverter::detectVariableType(const std::string& input){
    std::istringstream ss(input);
    char c;
    int i;
    float f;
    double d;

    if (ss >> c && ss.eof()) {
        return CHAR;
    } else if (ss.clear(), ss.str() == "0" && input != "0") {
        return INVALID;  // Avoid "0" being classified as an int
    } else if (ss.clear(), ss >> i && ss.eof()) {
        return INT;
    } else if (ss.clear(), ss >> f && ss.eof()) {
        return FLOAT;
    } else if (ss.clear(), ss >> d && ss.eof()) {
        return DOUBLE;
    }
    return INVALID;
} 

bool ScalarConverter::isInt( std::string input ){

    try{
        std::stoi(input);
        return true;
    } catch (...){
        return false;
    }
}

bool ScalarConverter::isFloat( std::string input ){

    try{
        std::stof(input);
        return true;
    } catch (...){
        return false;
    }
}

bool ScalarConverter::isDouble( std::string input ){

    try{
        std::stod(input);
        return true;
    } catch (...){
        return false;
    }
}

void    displayResults( std::string input ){

    std::cout << "Original input: " << input << std::endl;
    std::cout << "As char: " << ScalarConverter::c << std::endl;
    std::cout << "As int: " << ScalarConverter::i << std::endl;
    std::cout << "As float: " << ScalarConverter::f << std::endl;
    std::cout << "As double: " << ScalarConverter::d << std::endl;
}

void    ScalarConverter::convert( std::string input ){
    
    if (isChar(input)){
        ScalarConverter::c = input[1];
        ScalarConverter::i = static_cast<int>(c);
        ScalarConverter::f = static_cast<float>(c);
        ScalarConverter::d = static_cast<double>(c);
    } else if (isInt(input)){
        ScalarConverter::i = std::stoi(input);
        ScalarConverter::c = static_cast<char>(i);
        ScalarConverter::f = static_cast<float>(i);
        ScalarConverter::d = static_cast<double>(i);
    } else if (isFloat(input)){
        ScalarConverter::f = std::stof(input);
        ScalarConverter::c = static_cast<char>(f);
        ScalarConverter::i = static_cast<int>(f);
        ScalarConverter::d = static_cast<double>(f);
    } else if (isDouble(input)){
        ScalarConverter::d = std::stod(input);
        ScalarConverter::c = static_cast<char>(d);
        ScalarConverter::i = static_cast<int>(d);
        ScalarConverter::f = static_cast<float>(d);
    } else  {
        std::cerr << "Invalid input format." << std::endl;
        return;
    }
    displayResults(input);
}