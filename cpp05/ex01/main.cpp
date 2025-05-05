#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void invalidForms()
{
	try
	{
		Form f("Too Low", 151, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Form f("Too Low", 0, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	invalidSign()
{
	try
	{
		Form f("random form", 130, 150);
		Bureaucrat b("weak", 140);
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void validTest()
{
	try
	{
		Form f("random form", 130, 150);
		Bureaucrat b("weak", 130);
		b.signForm(f);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main()
{
	// invalidForms();
	//invalidSign();
	validTest();
}