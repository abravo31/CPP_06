#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>
# include <string>
# include <iostream>
# include <limits>

struct Data
{
    std::string value;
};


class Serializer {
    public:
	
	// Assignment Operator
		Serializer& operator = ( const Serializer& src );

    // Methods
        static uintptr_t   serialize(Data* ptr);
        static Data*       deserialize(uintptr_t raw);
    
    private:
    // Constructor & Destructor
		Serializer( void );
        Serializer( const Serializer& copy );
		~Serializer( void );

};

#endif