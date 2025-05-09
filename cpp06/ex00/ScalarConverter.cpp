
#include "ScalarConverter.hpp"
#include <iostream>
#include <climits>
#include <cstdlib>
#include <iomanip>

bool isChar(const std::string &str)
{
	return str.size() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]);
}

bool isSpecialDouble(const std::string &str)
{
	return !str.compare("nan") || !str.compare("+inf") || !str.compare("-inf");
}

bool isSpecialFloat(const std::string &str)
{
	return !str.compare("nanf") || !str.compare("+inff") || !str.compare("-inff");
}

bool isInt(const std::string &str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool isDecimal(const std::string &str, size_t size)
{
	if (str[0] == '.')
		return false;
	int dot = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (str[i] == '.')
			dot++;
		if (!(isdigit(str[i]) || str[i] == '.') || dot > 1)
			return false;
	}
	return true;
}

bool isFloat(const std::string &str)
{
	return isDecimal(str, str.size() - 1) && str[str.size() - 1] == 'f';
}

bool isDouble(const std::string &str)
{
	return isDecimal(str, str.size());
}

void printChar(char c)
{
	std::cout << "char: ";
	if (!std::isprint(c))
		std::cout << "Non displayable" << std::endl;
	else 
		std::cout << c << std::endl;
}

void convertChar(const std::string& str)
{
	printChar(str[0]);
	std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	std::cout << std::setprecision(5);
	std::cout << "float: " << static_cast<float>(str[0]) << std::endl;
	std::cout << "double: " << static_cast<double>(str[0]) << std::endl;
}

void convertInt(const std::string& str)
{
	int v = std::atoi(str.c_str());
	if (!isascii(v))
		std::cout << "char: impossible" << std::endl;
	else
		printChar(v);
	std::cout << "int: " << v << std::endl;
	std::cout << "float: " << static_cast<float>(v) << std::endl;
	std::cout << "double: " << static_cast<double>(v) << std::endl;
}

void convertFloat(const std::string& str)
{
	float f = std::atof(str.c_str());
	if (!isascii(f))
		std::cout << "char: impossible" << std::endl;
	else printChar(f);
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(const std::string& str)
{
	float d = std::strtod(str.c_str(), 0);
	if (!isascii(d))
		std::cout << "char: impossible" << std::endl;
	else printChar(d);
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}

void convertSpecialFloat(const std::string& str)
{
	float f = std::atof(str.c_str());
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << f << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertSpecialDouble(const std::string& str)
{
	float d = std::strtod(str.c_str(), 0);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(d) << std::endl;
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string& str)
{
	if (isChar(str))
		convertChar(str);
	else if (isInt(str))
		convertInt(str);
	else if (isFloat(str))
		convertFloat(str);
	else if (isDouble(str))
		convertDouble(str);
	else if (isSpecialFloat(str))
		convertSpecialFloat(str);
	else if (isSpecialDouble(str))
		convertSpecialDouble(str);
	else
		std::cout << "unrecognized type" << std::endl;
}