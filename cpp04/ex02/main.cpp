# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
	std::cout << std::endl << "TEST 0:" << std::endl << std::endl;
	Animal *animal_farm[100];
	
	for (int i = 0; i < 50; i++)
		animal_farm[i] = new Dog();
	for (int j = 50; j < 100; j++)
		animal_farm[j] = new Cat();
	for (int k = 0; k < 100; k++)
		delete animal_farm[k];

	std::cout << std::endl << "TEST 1:" << std::endl << std::endl;

	Dog original;
	Dog copy(original);

	std::cout << std::endl << "TEST 2:" << std::endl << std::endl;

	Dog a;
	Dog b;
	b = a;
	return 0;
}