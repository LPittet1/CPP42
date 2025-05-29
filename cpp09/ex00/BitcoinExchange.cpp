
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
			return month == rhs.month && year == rhs.year;
		}
		return year == rhs.year;
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
			return month == rhs.month && year == rhs.year;
		}
		return year == rhs.year;
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

int Date::getYear(void) const
{
	return year;
}

int Date::getMonth(void) const
{
	return month;
}

int Date::getDay(void) const
{
	return day;
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
	os << date.getYear() << '-' << std::setw(2) << std::setfill('0') <<  date.getMonth() << '-' << std::setw(2) << std::setfill('0')<< date.getDay();
	return os;
}

std::map<Date, double> createDB(std::istream& input)
{
	std::string str;
	int year;
	int month;
	int day;
	double value;
	char separator;
	std::map<Date, double> DB;

	std::getline(input, str);
	while (std::getline(input, str))
	{
		input >> year >> separator >> month >> separator >> day;
		Date temp(year, month, day);
		input >> separator >> value;
		std::pair<Date, double> pair(temp, value);
		DB.insert(pair);
	}
	return DB;
}