#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>


void testPresidentialPardonForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 25);
	Bureaucrat e("Selien", 4);
	PresidentialPardonForm pf("Julien");

	e.executeForm(pf);
	weak.signForm(pf);
	s.signForm(pf);
	weak.executeForm(pf);
	s.executeForm(pf);
	e.executeForm(pf);
}

void testRobotomyRequestForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 72);
	Bureaucrat e("Selien", 45);
	RobotomyRequestForm rf("Julien");

	e.executeForm(rf);
	weak.signForm(rf);
	s.signForm(rf);
	weak.executeForm(rf);
	s.executeForm(rf);
	e.executeForm(rf);
}

void testShrubberyCreationForm()
{
	Bureaucrat weak("Etienne", 150);
	Bureaucrat s("Horace", 140);
	Bureaucrat e("Selien", 100);
	ShrubberyCreationForm sf("Julien");

	e.executeForm(sf);
	weak.signForm(sf);
	s.signForm(sf);
	weak.executeForm(sf);
	s.executeForm(sf);
	e.executeForm(sf);
}


int main()
{
	// testPresidentialPardonForm();
	// std::cout << std::endl;
	testRobotomyRequestForm();
	// std::cout << std::endl;
	// testShrubberyCreationForm();
}