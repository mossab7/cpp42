#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <bits/stdc++.h>

#define SC_SIGN_GRADE 145
#define SC_EXEC_GRADE 137

class ShrubberyCreationForm : public AForm
{
	private :
		std::string target;
	public :
		ShrubberyCreationForm(const std::string &target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		void executeForm() const;
};

#endif //SHRUBBERYCREATIONFORM_HPP
