
#include "AForm.hpp"
#include <iostream>

AForm::AForm(): name("default form"), isSigned(false), gradeSign(150), gradeExec(150)
{
	
}

AForm::AForm(std::string name, int gradeSign, int gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& cpy): name(cpy.name), isSigned(cpy.isSigned), gradeSign(cpy.gradeSign), gradeExec(cpy.gradeExec)
{
	
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getIsSigned() const
{
	return isSigned;
}

int AForm::getGradeSign() const
{
	return gradeSign;
}

int AForm::getGradeExec() const
{
	return gradeExec;
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw AForm::GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}