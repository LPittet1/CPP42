#include "Phonebook.hpp"

int main()
{
    Phonebook book;

	while (1)
	{
		std::cout << "Enter a command : ADD, SEARCH, EXIT : ";
		std::string cmd;
		getline(std::cin, cmd);
		if (std::cin.eof())
		{
			std::cout << std::endl << "Stop trying to mess with the phonebook!" << std::endl;
			break;
		}
		else if (!cmd.compare("ADD"))
			book.add();
		else if (!cmd.compare("SEARCH"))
			book.search();
		else if (!cmd.compare("EXIT"))
			return 0;
		else
			std::cout << "wrong input, possible commands are ADD, SEARCH and EXIT" << std::endl;
	}
}