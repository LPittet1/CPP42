#include "whatever.hpp"
//#include <string>
#include <iostream>

int main()
{
	std::string a = "AAAAAAAAAA";
	std::string b = "BBBBBBBBBB";
	::swap(a, b);
	std::cout << "a: " << a << ", b: " << b << std::endl;

	const int ia = 10;
	const int ib = 42;
	// int ic = 10;
	// int id = 42;
	std::cout << "max: " << ::max(ia, ib) << std::endl;
	std::cout << "min: " << ::min(a, b) << std::endl;
}