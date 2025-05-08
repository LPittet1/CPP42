#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <iostream>


void testPresidentialPardonForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 25);
	Bureaucrat e("Selien", 4);
	Intern inter;
	AForm* form;

	form = inter.makeForm("wrong form", "Julien");
	form = inter.makeForm("presidential pardon", "Julien");
	e.executeForm(*form);
	weak.signForm(*form);
	s.signForm(*form);
	weak.executeForm(*form);
	s.executeForm(*form);
	e.executeForm(*form);
}

void testRobotomyRequestForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 25);
	Bureaucrat e("Selien", 4);
	Intern inter;
	AForm* form;

	form = inter.makeForm("wrong form", "Julien");
	form = inter.makeForm("robotomy request", "Julien");
	e.executeForm(*form);
	weak.signForm(*form);
	s.signForm(*form);
	weak.executeForm(*form);
	s.executeForm(*form);
	e.executeForm(*form);
}

void testShrubberyCreationForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 25);
	Bureaucrat e("Selien", 4);
	Intern inter;
	AForm* form;

	form = inter.makeForm("wrong form", "Julien");
	form = inter.makeForm("shrubbery creation", "Julien");
	e.executeForm(*form);
	weak.signForm(*form);
	s.signForm(*form);
	weak.executeForm(*form);
	s.executeForm(*form);
	e.executeForm(*form);
}


int main()
{
	// testPresidentialPardonForm();
	// std::cout << std::endl;
	// testRobotomyRequestForm();
	// std::cout << std::endl;
	testShrubberyCreationForm();
}