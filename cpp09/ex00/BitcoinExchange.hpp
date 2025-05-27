
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class Date
{
	private:
		int year;
		int month;
		int day;
	public:
		Date();
		Date(int year, int month, int day);
		Date(const Date& cpy);
		Date& operator=(const Date& rhs);
		~Date();
		bool operator<(const Date& rhs) const;
		bool operator<=(const Date& rhs) const;
		bool operator>(const Date& rhs) const;
		bool operator>=(const Date& rhs) const;
		bool operator==(const Date& rhs) const;
		bool operator!=(const Date& rhs) const;
};

std::map<Date, int> createDB(std::istream& input);

#endif 