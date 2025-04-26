#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int insertIndex;
	public:
		PhoneBook();
		~PhoneBook();
		void addContact(Contact & contact);
		void addContact();
		void search() const;
};


#endif
