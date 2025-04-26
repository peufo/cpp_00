#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

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
		void addContact(Contact & contact);
		void addContact();
		void search() const;
};


#endif
