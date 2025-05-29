#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include "BitcoinExchange.hpp"

int isLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 0;
	return 1;
}

int is30DayMonth(int month)
{
	if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
		return 1;
	return 0;
}

int isDateValid(const Date& date, const std::map<Date, double>& DB)
{
	if (date.getMonth() < 1 || date.getMonth() > 12)
		return 1;
	if (date.getDay() < 1 || date.getDay() > 31)
		return 1;
	if (date.getMonth() == 2 && date.getDay() == 29)
		return isLeapYear(date.getYear());
	if (date.getMonth() == 2 && date.getDay() == 30)
		return false;
	if (date.getDay() == 31)
		return is30DayMonth(date.getMonth());
	if (date < DB.begin()->first)
	{
		std::cout << "Error: date is before the start of the database." << std::endl;
		return 2;
	}
	if (date > DB.rbegin()->first)
	{
		std::cout << "Error: date is after the end of the database." << std::endl;
		return 2;
	}
	return 0;
}

void printOutput(std::map<Date, double>& DB, std::ifstream& input)
{
	std::string buf;
	int year, month, day;
	double amount;
	char sep;

	while (getline(input, buf))
	{
		if (buf == "date | value")
			continue;
		std::stringstream line(buf);
		line >> year >> sep;
		if (sep != '-')
		{
			std::cout << "Error: bad input =>" << buf << std::endl;
			continue;
		}
		line >> month >> sep >> day;
		if (sep != '-')
		{
			std::cout << "Error: bad input =>" << buf << std::endl;
			continue;
		}
		line >> sep >> amount;
		if (sep != '|')
		{
			std::cout << "Error: bad input =>" << buf << std::endl;
			continue;
		}
		if (amount < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue;
		}
		if (amount > 1000)
		{
			std::cout << "Error: too large number." << std::endl;
			continue;
		}
		Date date(year, month, day);
		if (int ret = isDateValid(date, DB))
		{
			if (ret == 1)
				std::cout << "Error: bad input => " << date << std::endl;
			continue;
		}
		std::map<Date, double>::iterator it = DB.begin();
		while (it->first <= date)
			it++;
		it--;
		std::cout << date << " => " << amount << " => " << it->second * amount << std::endl;
	}
}

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc [File]" << std::endl;
		return 1;
	}
	std::ifstream istream(av[1]);
	if (!istream.good())
	{
		std::cout << "Error: could not open file." << std::endl;
		return 1;
	}
	std::string DBFile = "data.csv";
	std::ifstream DBstream(DBFile.c_str());
	std::map<Date, double> DB = createDB(DBstream);
	printOutput(DB, istream);
}
