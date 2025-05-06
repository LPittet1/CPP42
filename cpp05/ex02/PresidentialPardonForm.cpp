
#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string& target): AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& cpy): AForm("PresidentialPardonForm", 25, 5), target(cpy.target)
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void PresidentialPardonForm::beExecuted() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}