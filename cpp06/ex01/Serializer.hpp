#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <cstdint>
# include <iostream>
# include <string>

class Serializer {

    private:
        // Attributes go here
        Serializer() ;                                  // Default
        Serializer(const Serializer &src);            // Copy
        ~Serializer();                                 // Destructor
        Serializer &operator=(const Serializer &src); // Copy Assignment

    public:
	
		struct Data{
			std::string	name;
			int			age;
		};
        // Operators
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

};

#endif
