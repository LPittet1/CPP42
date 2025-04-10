#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "wrong number of arguments" << std::endl;
		return 1;
	}
	struct stat s;
	stat(av[1], &s);
	if (S_ISDIR(s.st_mode))
	{
		std::cout << "File is a directory" << std::endl;
		return 1;
	}
	std::string ifile = av[1];
	std::ifstream istream(av[1]);
	if (!istream)
	{
		std::cout << "Error  : " << ifile << std::endl;
		return 1;
	}
	std::string ofile = ifile.append(".replace");
	std::ofstream ostream(ofile.c_str());
	if (!ostream)
	{
		std::cout << "Error : " << ofile << std::endl;
		return 1;
	}
	std::string line;
	std::string toFind = av[2];
	std::string replacement = av[3];
	while (std::getline(istream, line))
	{
		std::string::size_type pos = 0;
		while ((pos = line.find(toFind)) != std::string::npos)
		{
			line.erase(pos, toFind.length());
			line.insert(pos, replacement);
		}
		ostream << line << std::endl;
	}
	istream.close();
	ostream.close();
}