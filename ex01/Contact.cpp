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
	std::cout << "[first_name]:\t" << this->first_name << std::endl;
	std::cout << "[last_name]:\t" << this->last_name << std::endl;
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

static void print_col(const std::string& str, int colSize)
{
	std::cout << std::setfill(' ') << std::setw(colSize);
	std::cout << truncat_str(str, colSize);
	std::cout << "│";
}

void Contact::printRow(int index) const
{
	static int colSize = 10;

	std::cout << "│";
	std::cout << std::setfill(' ') << std::setw(colSize);
	std::cout << index;
	std::cout << "│";
	print_col(this->first_name, colSize);
	print_col(this->last_name, colSize);
	print_col(this->nickname, colSize);
	std::cout << std::endl;
}
