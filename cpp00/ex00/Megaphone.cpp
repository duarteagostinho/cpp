#include <iostream>

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int j = 1; av[j]; j++)
	{
		for (int i = 0; av[j][i]; i++) 
			std::cout << static_cast <char>(std::toupper(av[j][i]));
		std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}
