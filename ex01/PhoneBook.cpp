#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): contact_index(0)
{
}

PhoneBook::~PhoneBook()
{
}

static void fill_field(const std::string label, std::string & field)
{
	std::cout << label << ": ";
	std::cin >> field;
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

	fill_field("First name", first_name);
	fill_field("Last name", last_name);
	fill_field("Nickname", nickname);
	fill_field("Phone", phone);
	fill_field("Secret 🤫 ", secret);

	Contact contact(first_name, last_name, nickname, phone, secret);
	this->add_contact(contact);
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
	print_frame_row("┌", "┬", "┐");
	for (int i = 0; i < 8; i++)
		this->contacts[i].print_row(i);
	print_frame_row("└", "┴", "┘");
}
