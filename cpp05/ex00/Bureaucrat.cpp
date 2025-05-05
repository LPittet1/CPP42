
#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(): name("John Doe"), grade(150)
{
	
}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name), grade(grade)
{
		if (grade < 1)
			throw GradeTooHighException();
		if (grade > 150)
			throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& cpy): name(cpy.name), grade(cpy.grade)
{
	
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		grade = rhs.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	
}

int Bureaucrat::getGrade() const
{
	return grade;
}

std::string Bureaucrat::getName() const
{
	return name;
}

void Bureaucrat::incrementGrade()
{
	if (grade == 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade()
{
	if (grade == 150)
		throw GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat& b)
{
	os << b.getName() << ", bureacrat grade " << b.getGrade();
	return os;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade too low";
}