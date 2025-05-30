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
	announcer announcers[4];
	std::string levels[4];
	int i;
	bool found;

	announcers[0] = &Harl::debug;
	announcers[1] = &Harl::info;
	announcers[2] = &Harl::warning;
	announcers[3] = &Harl::error;

	levels[0] = "debug";
	levels[1] = "info";
	levels[2] = "warning";
	levels[3] = "error";
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
		(this->*announcers[i])();
	else
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
