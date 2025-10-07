#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <bits/stdc++.h>


class PresidentialPardonForm : public AForm
{
	private :
		std::string target;
	public :
		PresidentialPardonForm(const std::string &target);
		~PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		void executeForm() const;
};



#endif //PRESIDENTIALPARDONFORM_HPP
