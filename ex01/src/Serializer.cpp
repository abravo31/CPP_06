#include "Serializer.hpp"

// Constructor & Destructor
Serializer::Serializer( void ){
    
    std::cout << "Serializer Constructor called" << std::endl;
}

Serializer::Serializer( const Serializer& copy ){
    
    std::cout << "Serializer Copy Constructor called" << std::endl;
    *this = copy;
}

Serializer::~Serializer( void ){

    std::cout << "Serializer Destructor called" << std::endl;
}
	
// Assignment Operator
Serializer& Serializer::operator = ( const Serializer& src ){
    
    std::cout << "Serializer Assignement operator called" << std::endl;
    if ( this == &src )
        return *this;
    return *this;
}

// Methods
uintptr_t   Serializer::serialize(Data* ptr){
    return reinterpret_cast<uintptr_t>(ptr);
}

Data*       Serializer::deserialize(uintptr_t raw){
    return reinterpret_cast<Data*>(raw);
}