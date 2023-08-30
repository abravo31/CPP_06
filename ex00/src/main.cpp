#include "ScalarConverter.hpp"

char ScalarConverter::c;
int ScalarConverter::i;
float ScalarConverter::f;
double ScalarConverter::d;

int main( int ac, char **av ) {

	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "Invalid Args." << std::endl;
	return 0;
}