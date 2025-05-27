#include <iostream>
#include <fstream>
#include <cstdlib>
#include "BitcoinExchange.hpp"

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
	std::map<std::string, int> data;
	std::pair<std::string, int> test("test", 10);
	data.insert(test);
	std::cout << data["test"] << std::endl;
	std::map<Date, int> DB = createDB(istream);

}