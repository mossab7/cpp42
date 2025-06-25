#include "Contact.hpp"

Contact::Contact()
{
	name = "";
	number = "";
	last_name = "";
	nickmame = "";
	darkestsecret = "";
}

Contact::Contact(std::string num, const std::string &n,
			const std::string &ln, const std::string &nk,
			const std::string &ds)
{
	number = num;
	name = n;
	last_name = ln;
	nickmame = nk;
	darkestsecret = ds;
}

Contact::Contact(const Contact &other)
{
	number = other.number;
	name = other.name;
	last_name = other.last_name;
	nickmame = other.nickmame;
	darkestsecret = other.darkestsecret;
}

Contact& Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		number = other.number;
		name = other.name;
		last_name = other.last_name;
		nickmame = other.nickmame;
		darkestsecret = other.darkestsecret;
	}
	return *this;
}

Contact::~Contact()
{

}

void	Contact::printContactInfo()
{
	std::cout << "Number: " << number << std::endl;
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "nickmame: " << nickmame << std::endl;
	std::cout << "darkestsecret: " << darkestsecret << std::endl;
}

void	Contact::setNumber(const std::string &num)
{
	number = num;
}

void	Contact::setName(const std::string &n)
{
	name = n;
}

void	Contact::setLastName(const std::string &ln)
{
	last_name = ln;
}

void	Contact::setNickName(const std::string &nk)
{
	nickmame = nk;
}

void	Contact::setDarkestSecret(const std::string &ds)
{
	darkestsecret = ds;
}

std::string		Contact::getNumber()
{
	return (number);
}

std::string		Contact::getName()
{
	return (name);
}

std::string		Contact::getLastName()
{
	return (last_name);
}

std::string		Contact::getNickname()
{
	return (nickmame);
}

std::string		Contact::getDarkestSecret()
{
	return (darkestsecret);
}
