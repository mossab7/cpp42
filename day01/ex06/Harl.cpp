#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t putenough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for	years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
	std::string levels[4] = {"debug", "info", "warning", "error"};
	int i;
	bool found;

	found = false;
	for (i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			found = true;
			break;
		}
	}
	if (found)
	{
		switch (i)
		{
			case (0):
				debug();
			case (1):
				info();
			case (2):
				warning();
			case (3):
				error();
			default:
				break;
		}
	}
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
