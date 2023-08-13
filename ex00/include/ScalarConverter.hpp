#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits>
# include <iostream>
# include <sstream>

enum VarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INVALID
};

class ScalarConverter{
    public:
    // Method
        static void     convert( std::string input );
        static VarType  detectVariableType(const std::string& input); 
        static char     c;
        static int      i;
        static float    f;
        static double   d;
	
    private:
    // Constructor & Destructor
		ScalarConverter( void );
		~ScalarConverter( void );
        static bool isChar( std::string input );
        static bool isInt( std::string input );
        static bool isFloat( std::string input );
        static bool isDouble( std::string input );
        static int	detectType(std::string input);

};

#endif