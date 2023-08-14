#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <limits>
# include <iostream>
# include <sstream>
# include <cstdlib>
# include <cmath>

enum VarType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    INF_NAN,
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
        static void toChar( std::string input );
        static void toInt( std::string input );
        static void toFloat( std::string input );
        static void toDouble( std::string input );
        static void undefined( std::string input );
        static void nanInf( std::string input );
        static void putChar( long double input );
        static void putInt( long double input );
        static void putFloat( long double input );
        static void putDouble( long double input );
        static void displayResults( long double input );

};

#endif