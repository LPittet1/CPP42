
#include <iostream>
#include <iomanip>
#include "BitcoinExchange.hpp"

Date::Date():year(1970),month(1),day(1)
{

}
Date::Date(int year, int month, int day): year(year), month(month), day(day)
{

}

Date::Date(const Date& cpy): year(cpy.year), month(cpy.month), day(cpy.day)
{

}

Date& Date::operator=(const Date& rhs)
{
	if (*this != rhs)
	{
		year = rhs.year;
		month = rhs.month;
		day = rhs.day;
	}
	return *this;
}

Date::~Date()
{

}

bool Date::operator==(const Date& rhs) const
{
	return year == rhs.year && month == rhs.month && day == rhs.day;
}

bool Date::operator<(const Date& rhs) const
{
	if (year >= rhs.year)
	{
		if (month >= rhs.month)
		{
			if (day >= rhs.day)
			{
				return false;
			}
			return month != rhs.month;
		}
		return year != rhs.year;
	}
	return true;
}

bool Date::operator>(const Date& rhs) const
{
	if (year <= rhs.year)
	{
		if (month <= rhs.month)
		{
			if (day <= rhs.day)
			{
				return false;
			}
			return month != rhs.month;
		}
		return year != rhs.year;
	}
	return true;
}

bool Date::operator!=(const Date& rhs) const
{
	return !operator==(rhs);
}

bool Date::operator<=(const Date& rhs) const
{
	return operator==(rhs) || operator<(rhs);
}

bool Date::operator>=(const Date& rhs) const
{
	return operator==(rhs) || operator>(rhs);
}

std::map<Date, int> createDB(std::istream& input)
{
	std::string str;
	while (std::getline(input, str))
	{
		
	}
}