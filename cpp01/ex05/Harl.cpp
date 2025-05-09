#include "Harl.hpp"

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4 ; i++)
	{
		if (!levels[i].compare(level))
		{
			(this->*functionlist[i])();
			return ;
		}
	}
	std::cout << "unrecognised level" << std::endl;
}

void Harl::debug()
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error()
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

Harl::Harl()
{
	functionlist[0] = &Harl::debug;
	functionlist[1] = &Harl::info;
	functionlist[2] = &Harl::warning;
	functionlist[3] = &Harl::error;
}