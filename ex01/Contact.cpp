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
	std::cout << std::endl;
}

static const std::string truncat_str(std::string const str, size_t len)
{
	std::string res(str);

	if (res.size() <= len)
		return (res);
	res.at(len - 1) = '.';
	res.erase(res.begin() + len, res.end());
	return (res);
}

void Contact::printRow(int index) const
{
	static int col_size = 10;

	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(col_size);
	std::cout << index;
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(col_size);
	std::cout << truncat_str(this->first_name, col_size);
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(col_size);
	std::cout << truncat_str(this->last_name, col_size);
	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(col_size);
	std::cout << truncat_str(this->nickname, col_size);
	std::cout << "│";
	std::cout << std::endl;
}
