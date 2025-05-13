#include <iostream>
#include <ctime>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	std::srand(std::time(0));
	int var = std::rand();
	if (var % 3 == 0)
		return new A;
	if (var % 2 == 0)
		return new B;
	return new C;
}

void identify(Base* p)
{
	std::string type;
	if (dynamic_cast<A*>(p))
		type = "A";
	if (dynamic_cast<B*>(p))
		type = "B";
	if (dynamic_cast<C*>(p))
		type = "C";
	std::cout << type << std::endl;
}

void identify(Base& p)
{
	try 
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch(...)
	{
		try
		{
			dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch(...)
		{
			std::cout << "C" << std::endl;
		}
		
	}
}

int main()
{
	Base *test;

	test = generate();
	identify(test);
	identify(*test);
	delete test;
}