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

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm("PresidentialPardonForm",25,5), target(target)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
	AForm::AForm(other), target(other.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void PresidentialPardonForm::executeForm() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
    return;
}

#endif //PRESIDENTIALPARDONFORM_HPP
