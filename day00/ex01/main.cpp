#include "PhoneBook.hpp"

void add(PhoneBook &phonebook)
{
	Contact			contact;
	std::string		number;
	std::string		name;
	std::string		last_name;
	std::string		nickname;

	std::cout << "number[] :";
	std::cin >> number;
	std::cout << "name :";
	std::cin >> name;
	std::cout << "last name :";
	std::cin >> last_name;
	std::cout << "nickname :";
	std::cin >> nickname;

	contact.setNumber(number);
	contact.setName(name);
	contact.setLastName(last_name);
	contact.setNickName(nickname);
	phonebook.addContact(contact);
}

void search(PhoneBook phonebook)
{
	unsigned int index;

	phonebook.displayContactTable();
	std::cout << "enter index of the entry to display" << std::endl;
	std::cout << ">";
	std::cin >> index;
	if (std::cin.fail())
	{
		std::cout << "invalid index" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		return;
	}
	if (index > phonebook.size)
		std::cout << "non existent contact" << std::endl;
	else
		phonebook.displayContact(index);
}

int main(void)
{
	PhoneBook phonebook;
	std::string command;

	while (true)
	{
		std::cout << "entre command : ADD, SEARCH, EXIT" << std::endl;
		std::cout << "> ";
		std::cin >> command;

		if (std::cin.eof())
			return (0);
		if (command == "add" || command == "ADD")
			add(phonebook);
		else if (command == "search" || command == "SEARCH")
			search(phonebook);
		else if (command == "exit" || command == "EXIT")
			return (0);
		else
			std::cout << "command not valid" << std::endl;
	}
	return (0);
}
