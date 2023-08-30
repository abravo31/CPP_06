#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter( void ){}

ScalarConverter::~ScalarConverter( void ){}

VarType	ScalarConverter::detectVariableType(const std::string& input){

    size_t length = input.length();
    if (length == 3 && input[0] == '\'' && input[2] == '\'') {
        return CHAR;
    }

    size_t dotPos = input.find('.');
    size_t fPos = input.find('f');
    if (dotPos != std::string::npos) {
        if (fPos != std::string::npos && fPos == length - 1) {
            return FLOAT;
        } else {
            return DOUBLE;
        }
    }

    if ( input == "inf" || input == "+inf" || input == "-inf" || input == "nan")
        return INF_NAN;
    
    char* endptr;
    std::strtol(input.c_str(), &endptr, 10);
    if (*endptr == '\0') {
        return INT;
    }

    return INVALID;
} 

void    ScalarConverter::putChar( long double input ){

	ScalarConverter::c = static_cast<char>(input);
	if (std::isnan(input) || std::isinf(input) || input < 0 || input > 127)
		std::cout << "char: impossible\n";
	else if (ScalarConverter::c <= 32 || ScalarConverter::c == 127)
		std::cout << "char: Non displayable\n";
	else
		std::cout << "char: \'" << ScalarConverter::c << "\'" << std::endl;
}

void    ScalarConverter::putInt( long double input ){

    ScalarConverter::i = static_cast<int>(input);
    if (std::isnan(input) || input > std::numeric_limits<int>::max() || input < std::numeric_limits<int>::min())
        std::cout << "int: impossible\n";
    else
        std::cout << "int: " << ScalarConverter::i << std::endl;
}

void    ScalarConverter::putFloat( long double input ){

    long double intPart;
    ScalarConverter::f = static_cast<float>(input);
	if (std::isnan(input))
		ScalarConverter::f = std::numeric_limits<float>::quiet_NaN();
	std::cout << "float: " << ScalarConverter::f;
    if (std::modf(input, &intPart) == 0.0L)
        std::cout << ".0";
    std::cout << "f" << std::endl;
}

void    ScalarConverter::putDouble( long double input ){

    long double intPart;
    ScalarConverter::d = static_cast<double>(input);
	if (std::isnan(input))
		ScalarConverter::d = std::numeric_limits<double>::quiet_NaN();
	std::cout << "double: " << ScalarConverter::d;
    if (std::modf(input, &intPart) == 0.0L)
        std::cout << ".0";
    std::cout << std::endl;
}

void    ScalarConverter::displayResults( long double input ){

    //std::cout << "Original input: " << input << std::endl;
    ScalarConverter::putChar(input);
	ScalarConverter::putInt(input);
	ScalarConverter::putFloat(input);
	ScalarConverter::putDouble(input);
}

void    ScalarConverter::toChar( std::string input ){

    ScalarConverter::c = input[1];
    if (ScalarConverter::c > std::numeric_limits<char>::max() || ScalarConverter::c < std::numeric_limits<char>::min())
        throw std::overflow_error("Char Overflow!");
    if (ScalarConverter::c <= 32 || ScalarConverter::c == 127)
        throw std::overflow_error("Non Displayable Character!");
    ScalarConverter::displayResults( ScalarConverter::c );
}

void    ScalarConverter::toInt( std::string input ){
    
    long double convert;
    convert = std::atof(input.c_str());
    if (convert > std::numeric_limits<int>::max() || convert < std::numeric_limits<int>::min())
        throw std::overflow_error("Integer Overflow!");
    ScalarConverter::displayResults( convert );
}

void    ScalarConverter::toFloat( std::string input ){

    long double convert;
    convert = static_cast<float>(std::atof(input.c_str()));
    ScalarConverter::displayResults( convert );
}

void    ScalarConverter::toDouble( std::string input ){

    long double convert;
    convert = std::atof(input.c_str());
    ScalarConverter::displayResults( convert );
}

void    ScalarConverter::nanInf( std::string input ){

    float _f;
    if (input == "inf" || input == "+inf"){
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        _f = std::numeric_limits<float>::infinity();
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _f << std::endl;
    } else if (input == "-inf"){
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        _f = -std::numeric_limits<float>::infinity();
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _f << std::endl;        
    } else {
        std::cout << "char: " << "impossible" << std::endl;
        std::cout << "int: " << "impossible" << std::endl;
        _f = std::numeric_limits<float>::quiet_NaN();
        std::cout << "float: " << _f << "f" << std::endl;
        std::cout << "double: " << _f << std::endl;
    }        
}

void    ScalarConverter::undefined( std::string input ){
	
    (void)input;
	throw std::overflow_error("Invalid Number!");
}

void    ScalarConverter::convert( std::string input ){
    
    typedef	void(*fPointer)(std::string);
	fPointer	fconv[6] = { &ScalarConverter::toChar, &ScalarConverter::toInt,
	&ScalarConverter::toFloat, &ScalarConverter::toDouble, &ScalarConverter::nanInf, &ScalarConverter::undefined };
	try{
		fconv[ScalarConverter::detectVariableType(input)](input);
	} catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
}