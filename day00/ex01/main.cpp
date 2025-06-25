#include "PhoneBook.hpp"
#include <string>
#include <sstream>

bool valid_input(std::string input, InputType type)
{
	for (std::string::size_type i = 0; i < input.size(); i++)
	{
		bool char_valid = false;

		if ((type & IT_Numbers) && std::isdigit(input[i]))
			char_valid = true;
		if ((type & IT_Alphabet) && std::isalpha(input[i]))
			char_valid = true;
		if (!char_valid)
			return false;
	}
	return true;
}

bool add(PhoneBook &phonebook)
{
	Contact			contact;
	std::string		number;
	std::string		name;
	std::string		last_name;
	std::string		nickname;
	std::string		darkestsecret;

	do
	{
		std::cout << "number[] : ";
		if (!std::getline(std::cin,number))
			return (false);
	} while (!valid_input(number,IT_Numbers) || number.empty());
	do
	{
	std::cout << "name : ";
	if (!std::getline(std::cin,name))
		return (false);
	}while (!valid_input(name,IT_Alphabet) || name.empty());
	do
	{
		std::cout << "last name : ";
		if (!std::getline(std::cin,last_name))
			return (false);
	}while (!valid_input(last_name,IT_Alphabet) || last_name.empty());
	do
	{
		std::cout << "nickname : ";
		if (!std::getline(std::cin,nickname))
			return (false);
	}while (!valid_input(nickname,(IT_Alphabet | IT_Numbers)) || nickname.empty());
	do
	{
		std::cout << "darkestsecret : ";
		if (!std::getline(std::cin,darkestsecret))
			return (false);
	}while (!valid_input(nickname,(IT_Alphabet | IT_Numbers)) || darkestsecret.empty());

	contact.setNumber(number);
	contact.setName(name);
	contact.setLastName(last_name);
	contact.setNickName(nickname);
	contact.setDarkestSecret(darkestsecret);
	phonebook.addContact(contact);
	return (true);
}

bool search(PhoneBook phonebook)
{
	std::string input;
	unsigned int index;

	phonebook.displayContactTable();
	do
	{
		std::cout << "enter index of the entry to display" << std::endl;
		std::cout << ">";
		if (!std::getline(std::cin,input))
			return (false);
	} while (!valid_input(input,IT_Numbers));
	std::stringstream ss(input);
	ss >> index;
	if (index > phonebook.size)
		std::cout << "non existent contact" << std::endl;
	else
		phonebook.displayContact(index);
	return (true);
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "entre command : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin,command))
			return (0);
		if (command == "add" || command == "ADD")
		{
			if (!add(phonebook))
				return (0);
		}
		else if (command == "search" || command == "SEARCH")
		{
			if (!search(phonebook))
				return (0);
		}
		else if (command == "exit" || command == "EXIT")
			return (0);
		else
			std::cout << "command not valid" << std::endl;
	}
	return (0);
}
