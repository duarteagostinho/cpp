#include <iostream>
#include <cstring>
#include <cctype>

char	*toUpperCase(char *str)
{
	size_t len = strlen(str);
	char *result = new char[len + 1];

	for (size_t i = 0; i < len; ++i)
	{
		result[i] = toupper(str[i]);
	}
	result[len] = '\0';
	return result;
}

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; ++i)
	{
		char *uppercase = toUpperCase(av[i]);
		std::cout << uppercase;
		delete[] uppercase;
	}
	std::cout << std::endl;
	return 0;
}
