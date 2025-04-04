#ifndef PHONEBOOK_CPP
# define PHONEBOOK_CPP

#include "Contact.hpp"
#include <ctype.h>
#include <iomanip>

class Phonebook
{
	private :
		Contact book[8];
		unsigned int	index;
	public :
		Phonebook();
		~Phonebook();
		void	add();
		void	search();
		void	print_book();
		std::string	truncate(std::string str);
};

#endif