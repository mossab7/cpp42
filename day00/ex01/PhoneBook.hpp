#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define CONTACTS_CAP 1
#define WIDTH_ALIGNMENT 10

class PhoneBook
{
	Contact contacts[CONTACTS_CAP];
	static int n;
	public :

		unsigned int size;
		unsigned int iter;

		PhoneBook();

		PhoneBook(const PhoneBook &other);

		PhoneBook &operator=(const PhoneBook &other);

		void addContact(const Contact &contact);

		void displayContact(unsigned int index);

		void displayContactTable();

		~PhoneBook() {}
};

#endif // PHONEBOOK_HPP
