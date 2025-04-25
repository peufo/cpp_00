#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->phone = "";
	this->secret = "";
}

Contact::Contact(
	std::string first_name,
	std::string last_name,
	std::string nickname,
	std::string phone,
	std::string secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone = phone;
	this->secret = secret;
}

Contact::~Contact()
{
}

void Contact::print() const
{
	std::cout << "[name]:\t\t" << this->first_name << " " << this->last_name << std::endl;
	std::cout << "[nickname]:\t" << this->nickname << std::endl;
	std::cout << "[phone]:\t" << this->phone << std::endl;
	std::cout << "[secret]:\t" << this->secret << std::endl;
}

static const std::string ensure_width(std::string const str)
{
	std::string res(str);

	if (res.size() <= 10)
		return (res);
	res.at(9) = '.';
	res.erase(res.begin() + 10, res.end());
	return (res);
}

void Contact::print_row(int index) const
{
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << index;
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << ensure_width(this->first_name);
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << ensure_width(this->last_name);
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(10);
	std::cout << ensure_width(this->nickname);
	std::cout << "│";
	std::cout << std::endl;
}
