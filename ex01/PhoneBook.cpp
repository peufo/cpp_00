#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): insertIndex(0)
{
}

PhoneBook::~PhoneBook()
{
}

static void fill_field(const std::string label, std::string & field)
{
	while (field == "")
	{
		std::cout << label << ": ";
		std::getline(std::cin, field);
		if (field == "")
			std::cout << "Empty field is not allowed" << std::endl;
	}
}

void PhoneBook::addContact(Contact & contact)
{
	if (this->insertIndex >= 8)
		this->insertIndex = 0;
	this->contacts[this->insertIndex++] = contact;
}

void PhoneBook::addContact()
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone = "";
	std::string secret = "";

	fill_field("First name", first_name);
	fill_field("Last name", last_name);
	fill_field("Nickname", nickname);
	fill_field("Phone", phone);
	fill_field("Secret 🤫 ", secret);

	Contact contact(first_name, last_name, nickname, phone, secret);
	this->addContact(contact);
	std::cout << "Thanks, new contact added !\n" << std::endl;
}

static void print_frame_row(std::string corner_a, std::string col, std::string corner_b)
{
	std::cout << corner_a;
	for (int col_index = 0; col_index < 4; col_index++)
	{
		if (col_index)
			std::cout << col;
		for (int i = 0; i < 10; i++)
			std::cout << "─";
	}
	std::cout << corner_b << std::endl;
}

void PhoneBook::search() const
{
	std::string input;
	int	index;

	print_frame_row("┌", "┬", "┐");
	for (int i = 0; i < 8; i++)
		this->contacts[i].printRow(i);
	print_frame_row("└", "┴", "┘");
	std::cout << "Contact index : ";
	std::getline(std::cin, input);
	if (input[0] < '0' || input[0] > '9')
	{
		std::cout << "Please, enter a numerical value" << std::endl;
		return ;
	}
	index = std::atoi(input.c_str());
	if (index < 0 || index > 7)
	{
		std::cout << "Sorry, contact index " << index << " is out of the range (0-7)" << std::endl;
		return ;
	}
	this->contacts[index].print();
}
