#include "ScalarConverter.hpp"

int main() {
    // ScalarConverter::convert("'A'");
    // ScalarConverter::convert("42");
    // ScalarConverter::convert("4.2f");
    // ScalarConverter::convert("4.2");
    // ScalarConverter::convert("-inff");
    // ScalarConverter::convert("+inff");
    // ScalarConverter::convert("nanf");
    // ScalarConverter::convert("-inf");
    // ScalarConverter::convert("+inf");
    // ScalarConverter::convert("nan");
    ScalarConverter::convert("0");
    VarType type = ScalarConverter::detectVariableType("'a'");

    switch (type) {
        case CHAR:
            std::cout << "Detected type: char" << std::endl;
            break;
        case INT:
            std::cout << "Detected type: int" << std::endl;
            break;
        case FLOAT:
            std::cout << "Detected type: float" << std::endl;
            break;
        case DOUBLE:
            std::cout << "Detected type: double" << std::endl;
            break;
        case INVALID:
            std::cout << "Invalid format or unknown type" << std::endl;
            break;

    return 0;
}
}