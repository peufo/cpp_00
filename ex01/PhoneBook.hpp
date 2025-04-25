#pragma once
#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contact_index;
	public:
		PhoneBook();
		~PhoneBook();
		void add_contact(Contact & contact);
		void add_contact();
		void search() const;
};
