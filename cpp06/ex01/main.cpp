#include "Serializer.hpp"
#include <cstdint>
#include <iostream>
#include <ostream>

int	main() {
	Serializer::Data data;
	
	data.age = 10;
	data.name = "Jon";

	uintptr_t raw = Serializer::serialize(&data);

	Serializer::Data* deserialized = Serializer::deserialize(raw);

	std::cout << "NAME = " << deserialized->name << "\nAGE = " << deserialized->age << std::endl;

	if (deserialized == &data)
		std::cout << "Pointers match!" << std::endl;
	else
		std::cout << "Pointers do not match!" << std::endl;
}
