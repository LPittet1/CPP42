
#include "Form.hpp"
#include <iostream>

Form::Form(): name("default form"), isSigned(false), gradeSign(150), gradeExec(150)
{
	
}

Form::Form(std::string name, int gradeSign, int gradeExec): name(name), isSigned(false), gradeSign(gradeSign), gradeExec(gradeExec)
{
	if (gradeExec < 1 || gradeSign < 1)
		throw GradeTooHighException();
	if (gradeExec > 150 || gradeSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& cpy): name(cpy.name), isSigned(cpy.isSigned), gradeSign(cpy.gradeSign), gradeExec(cpy.gradeExec)
{
	
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
	{
		isSigned = rhs.isSigned;
	}
	return *this;
}

Form::~Form()
{
	
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getGradeSign() const
{
	return gradeSign;
}

int Form::getGradeExec() const
{
	return gradeExec;
}

void Form::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > gradeSign)
		throw Form::GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}