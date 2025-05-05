#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	try
	{
		Bureaucrat weak("Edouard", 150);
		std::cout << weak << std::endl;
		weak.incrementGrade();
		std::cout << weak << std::endl;
		weak.decrementGrade();
		std::cout << weak << std::endl;
		weak.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat tooWeak("Ed", 151);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat strong("Edouardo", 1);
		std::cout << strong << std::endl;
		strong.decrementGrade();
		std::cout << strong << std::endl;
		strong.incrementGrade();
		std::cout << strong << std::endl;
		strong.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		Bureaucrat strong("Edouarda", 0);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}