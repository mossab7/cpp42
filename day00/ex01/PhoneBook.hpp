#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

#define CONTACTS_CAP 2
#define WIDTH_ALIGNMENT 10

enum InputType
{
	IT_None = 0,
	IT_Alphabet = 1 << 0,
	IT_Numbers = 1 << 1
};

InputType operator|(InputType a, InputType b);
bool operator&(InputType a, InputType b);

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

bool search(PhoneBook phonebook);
bool add(PhoneBook &phonebook);
void print_column_field(const std::string &str);

#endif // PHONEBOOK_HPP
