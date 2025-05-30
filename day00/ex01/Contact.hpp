#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact
{
private:
	std::string number;
	std::string name;
	std::string last_name;
	std::string nickmame;

public:
	Contact();

	Contact(std::string num, const std::string &n,
	        const std::string &ln, const std::string &nk);

	Contact(const Contact &other);

	Contact &operator=(const Contact &other);

	void	setNumber(const std::string &num);
	void	setName(const std::string &n);
	void	setLastName(const std::string &ln);
	void	setNickName(const std::string &addr);

	std::string		getNumber();
	std::string		getName();
	std::string		getLastName();
	std::string		getNickname();

	void	printContactInfo();

	~Contact();
};

#endif // CONTACT_HPP

