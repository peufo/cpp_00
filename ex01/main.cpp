#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

static void print_usage()
{
	std::cout << "Usage:" << std::endl;
	std::cout << "ADD\tsave new contact" << std::endl;
	std::cout << "SEARCH\tdisplay a specific contact" << std::endl;
	std::cout << "EXIT\texit this awesome programme" << std::endl;
	std::cout << std::endl;
}

int main()
{
	PhoneBook book;
	std::string command;

	std::cout << "Welcome to your awesome PHONEBOOK !\n" << std::endl;
	print_usage();
	while (true)
	{
		std::cout << "PHONEBOOK> ";
		getline(std::cin, command);
		if (command == "ADD")
		{
			book.addContact();
			continue ;
		}
		if (command == "SEARCH")
		{
			book.search();
			continue ;
		}
		if (command == "EXIT")
			break;
		std::cout << "Command not found: `" << command << "'" << std::endl;
		print_usage();
	}
	std::cout << "Bye 👋 " << std::endl;
	return (0);
}
