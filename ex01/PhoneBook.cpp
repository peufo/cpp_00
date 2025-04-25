#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contact_index(0)
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

void PhoneBook::add_contact(Contact & contact)
{
	if (this->contact_index >= 8)
		this->contact_index = 0;
	this->contacts[this->contact_index++] = contact;
}

void PhoneBook::add_contact()
{
	std::string first_name = "";
	std::string last_name = "";
	std::string nickname = "";
	std::string phone = "";
	std::string secret = "";

	std::cin.ignore();
	fill_field("First name", first_name);
	fill_field("Last name", last_name);
	fill_field("Nickname", nickname);
	fill_field("Phone", phone);
	fill_field("Secret 🤫 ", secret);

	Contact contact(first_name, last_name, nickname, phone, secret);
	this->add_contact(contact);
	std::cout << "Thanks, new contact added !" << std::endl << std::endl;
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
	int index;

	print_frame_row("┌", "┬", "┐");
	for (int i = 0; i < 8; i++)
		this->contacts[i].print_row(i);
	print_frame_row("└", "┴", "┘");
	std::cout << "Contact index : ";
	std::cin >> index;
	if (index < 0 || index > 7)
	{
		std::cout << "Sorry, contact index " << index << " is out of the range" << std::endl;
		return ;
	}
	this->contacts[index].print();
}
