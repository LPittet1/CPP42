#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>





int main()
{
	ShrubberyCreationForm f("test");
	Bureaucrat king("Jean", 1);
	Bureaucrat nul("Alex", 150);
	king.signForm(f);
	nul.executeForm(f);
}