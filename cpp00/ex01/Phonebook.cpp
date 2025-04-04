#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	index = 0;
}

Phonebook::~Phonebook()
{
	return ;
}

void	Phonebook::add()
{
	int i;

	i = index % 8;
	book[i].setFirstName();
	book[i].setLastName();
	book[i].setNickname();
	book[i].setPhoneNumber();
	book[i].setSecret();
	index++;
}


void	Phonebook::search()
{
	std::string i;

	print_book();
	std::cout << "Which contact do you want to see?  ";
	getline(std::cin, i);
	int j = 0;
	if (std::cin.eof())
		return ;
	while (i[j])
	{
		if (!isdigit(i[j]))
		{
			std::cout << "invalid index" << std::endl;
			search();
			return ;
		}
		j++;
	}
	int ind = std::atoi(i.c_str());
	if (ind < 0 || ind > 7 || book[ind].getFirstName().empty())
			std::cout << "invalid index" << std::endl;
	else
		book[ind].print_contact();
}

void	Phonebook::print_book()
{
	if (!book[0].getFirstName().empty())
	{
		std::cout << std::setw(10) << "index"; 
		std::cout << "|";
		std::cout << std::setw(10) << "First name";
		std::cout << "|";
		std::cout << std::setw(10) << "Last name";
		std::cout << "|";
		std::cout << std::setw(10) << "Nickname";
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < 8; i++)
	{
		if (book[i].getFirstName().empty())
			break;
		std::cout << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::setw(10) << truncate(book[i].getFirstName());
		std::cout << "|";
		std::cout << std::setw(10) << truncate(book[i].getLastName());
		std::cout << "|";
		std::cout << std::setw(10) << truncate(book[i].getNickname());
		std::cout << "|" << std::endl;
	}
}

std::string Phonebook::truncate(std::string str)
{
	if (str.length() <= 10)
		return str;
	return str.substr(0,9) + ".";
}