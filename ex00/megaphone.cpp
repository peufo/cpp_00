#include <iostream>

static std::string toUpper(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if ('a' <= *it && *it <= 'z')
			*it -= 32;
	return (str);
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	std::cout << toUpper(av[1]);
	for (int i = 2; i < ac; i++)
		std::cout << " " << toUpper(av[i]);
	std::cout << std::endl;
	return (0);
}
