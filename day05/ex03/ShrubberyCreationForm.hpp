#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <bits/stdc++.h>


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

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm",145,137), target(target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm::AForm(other), target(other.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		target = other.target;
	}
	return (*this);
}

void ShrubberyCreationForm::executeForm() const
{
    std::ofstream ofs(target + "_shrubbery");
    if (!ofs)
    {
        std::cout << "Error: Could not open file " << target << "_shrubbery" << std::endl;
        return;
    }
    ofs << "       _-_\n";
    ofs << "    /~~   ~~\\\n";
    ofs << " /~~         ~~\\\n";
    ofs << "{               }\n";
    ofs << " \\  _-     -_  /\n";
    ofs << "   ~  \\\\ //  ~\n";
    ofs << "_- -   | | _- _\n";
    ofs << "  _ -  | |   -_\n";
    ofs << "      // \\\\\n";
    ofs << "     //   \\\\\n";
    ofs << "    //     \\\\\n";
    ofs << "   //       \\\\\n";
    ofs << "  //         \\\\\n";
    ofs << " //           \\\\\n";
    ofs << "//             \\\\\n";
    ofs << "       |||\n";
    ofs << "       |||\n";
    ofs << "       |||\n";
    ofs << "   ___________\n";
    ofs.close();
    std::cout << "ShrubberyCreationForm executed successfully." << std::endl;
    return;
}

#endif //SHRUBBERYCREATIONFORM_HPP
