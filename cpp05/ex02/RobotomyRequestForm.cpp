
#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45), target("default")
{
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string& target): AForm("RobotomyRequestForm", 72, 45), target(target)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& cpy): AForm("RobotomyRequestForm", 72, 45), target(cpy.target)
{
	
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm::beExecuted() const
{
	if (std::rand() % 2)
	{
		std::cout << "bbzzzzzzzzzzzz bbrrrrrrr" << std::endl;
		std::cout << target << " has been robotomized" << std::endl;
	}
	else
		std::cout << "Failed to robotomize " << target << std::endl;
}