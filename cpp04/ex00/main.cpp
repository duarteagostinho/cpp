# include "Cat.hpp"
# include "Dog.hpp"
# include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << k->getType() << " " << std::endl;
	k->makeSound();

	WrongCat directWrongCat;
	directWrongCat.makeSound(); 
	wrongmeta->makeSound();

	delete meta;
	delete j;
	delete i;
	delete wrongmeta;
	delete k;
	return 0;
}