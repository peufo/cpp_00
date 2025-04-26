#pragma once
#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone;
		std::string secret;
	public:
		Contact();
		Contact(
			std::string first_name,
			std::string last_name,
			std::string nickname,
			std::string phone,
			std::string secret);
		~Contact();
		void print() const;
		void printRow(int index) const;
};
