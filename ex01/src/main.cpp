#include "Serializer.hpp"

int main( int ac, char **av ) {

	Data *test = new(Data);
	if (ac == 2){
		test->value = av[1];
		uintptr_t serialized = Serializer::serialize(test);
    	Data* deserialized = Serializer::deserialize(serialized);
		std::cout << "Original value: " << test->value << std::endl;
    	std::cout << "Deserialized value: " << deserialized->value << std::endl;
    	if (deserialized == test) {
        	std::cout << "Serialization and deserialization successful." << std::endl;
    	} else {
        	std::cout << "Serialization and deserialization failed." << std::endl;
    	}
	}
	else
		std::cout << "Invalid Args." << std::endl;
	delete test;
	return 0;
}