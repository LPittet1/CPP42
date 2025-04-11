#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
private:
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
	typedef void (Harl::*FunctionPtr)();
	FunctionPtr functionlist[4];
public:
	void complain(std::string level);
	void complain_switch(int level);
	Harl();
};

#endif