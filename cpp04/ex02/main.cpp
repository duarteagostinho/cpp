# include "Cat.hpp"
# include "Dog.hpp"

int main()
{
	std::cout << "--------------- TEST 0 --------------" << std::endl;
	Animal *animal_farm[100];
	
	for (int i = 0; i < 50; i++)
		animal_farm[i] = new Dog();
	for (int j = 50; j < 100; j++)
		animal_farm[j] = new Cat();
	for (int k = 0; k < 100; k++)
		delete animal_farm[k];

	std::cout << "--------------- TEST 1 --------------" << std::endl;

	Dog original;
	Dog copy(original);

	std::cout << "--------------- TEST 2 --------------" << std::endl;

	Dog a;
	Dog b;
	b = a;
	return 0;
}