#include "Serializer.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>

int	main() {
	Serializer::Data data;
	
	data.age = 10;
	data.name = "Jon";

	uintptr_t	raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;

	Serializer::Data*	deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized: " << deserialized << "\nNAME = " << deserialized->name << "\nAGE = " << deserialized->age << "\n";

	std::cout << "Serialized = " << raw << "\nDeserialized = " << deserialized << std::endl;


}
