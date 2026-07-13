#include "Serializer.hpp"
#include <cstdint>

/*
** ------------------------------- CONSTRUCTORS --------------------------------
*/

Serializer::Serializer() {
    // std::cout << "Default Constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &src) {
    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Serializer::~Serializer() {
    // std::cout << "Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOADS ---------------------------------
*/

Serializer &Serializer::operator=(const Serializer &src) {
    if (this != &src) {
        // Copy attributes here
    }
    return *this;
}

std::ostream &operator<<(std::ostream &o, const Serializer &i) {
    (void)i; // Evita erro de 'unused parameter' até adicionares lógica
    o << "Type: Serializer";
    return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

uintptr_t	Serializer::serialize(Data *raw) {
	uintptr_t ptr = reinterpret_cast<uintptr_t>(raw);
	return ptr;
}

Serializer::Data*	Serializer::deserialize(uintptr_t ptr) {
	return reinterpret_cast<Data*>(ptr);
}

// Add methods here...
