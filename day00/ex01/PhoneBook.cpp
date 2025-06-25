#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	iter = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	size = other.size;
	for (int i = 0; i < CONTACTS_CAP; ++i)
		contacts[i] = other.contacts[i];
}

PhoneBook& PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
		size = other.size;
		for (int i = 0; i < CONTACTS_CAP; i++)
			contacts[i] = other.contacts[i];
	}
	return *this;
}

void PhoneBook::displayContact(unsigned int index)
{
	if (index < size)
		contacts[index].printContactInfo();
	else
		std::cout << "Invalid index.\n";
}

void PhoneBook::addContact(const Contact &contact)
{
	contacts[iter] = contact;
	++size;
	++iter;
	if (iter > CONTACTS_CAP - 1)
		iter = 0;
	if (size > CONTACTS_CAP)
		size = CONTACTS_CAP;
}

void print_column_field(const std::string &str)
{
	if (str.length() > WIDTH_ALIGNMENT)
		std::cout << str.substr(0, WIDTH_ALIGNMENT - 1) << ".";
	else
		std::cout << std::setw(WIDTH_ALIGNMENT) << str;
	std::cout << "|";
}

void PhoneBook::displayContactTable()
{
	std::cout << "|" << std::setw(WIDTH_ALIGNMENT) << "Index"
			  << "|" << std::setw(WIDTH_ALIGNMENT) << "First Name"
			  << "|" << std::setw(WIDTH_ALIGNMENT) << "Last Name"
			  << "|" << std::setw(WIDTH_ALIGNMENT) << "Nickname"
			  << "|" << std::setw(WIDTH_ALIGNMENT) << "DarkestSe."
			  << "|\n";


	for (unsigned int i = 0; i < size; ++i)
	{
		std::cout << "|";
		std::cout << std::setw(WIDTH_ALIGNMENT) << i << "|";
		print_column_field(contacts[i].getName());
		print_column_field(contacts[i].getLastName());
		print_column_field(contacts[i].getNickname());
		print_column_field(contacts[i].getDarkestSecret());
		std::cout << "\n";
	}
}

InputType operator|(InputType a, InputType b)
{
	return static_cast<InputType>(static_cast<int>(a) | static_cast<int>(b));
}

bool operator&(InputType a, InputType b)
{
	return (static_cast<int>(a) & static_cast<int>(b)) != 0;
}
