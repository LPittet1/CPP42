
#include "Intern.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

AForm* makePresidentialPardonForm(std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm* makeRobotomyRequestForm(std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm* makeShrubberyCreationForm(std::string& target)
{
	return new ShrubberyCreationForm(target);
}

const Intern::File Intern::filemap[] = {
	{"shrubbery creation", makeShrubberyCreationForm},
	{"robotomy request", makeRobotomyRequestForm},
	{"presidential pardon", makePresidentialPardonForm}
};

Intern::Intern()
{
	
}

Intern::Intern(const Intern& cpy)
{
	(void)cpy;
}

Intern& Intern::operator=(const Intern& rhs)
{
	if (this != &rhs)
	{
		
	}
	return *this;
}

Intern::~Intern()
{
	
}

AForm* Intern::makeForm(std::string type, std::string target)
{
	for (int i = 0; !filemap[i].type.empty(); i++)
	{
		if (!filemap[i].type.compare(type))
		{
			std::cout << "Intern created " << type << " form." << std::endl;
			return filemap[i].make(target);
		}
	}
	std::cout << "Forms of that type don't exist" << std::endl;
	return 0;
}