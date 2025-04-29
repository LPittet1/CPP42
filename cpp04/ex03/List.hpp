
#ifndef LIST_HPP
# define LIST_HPP

# include <string>
#include "AMateria.hpp"

struct Node
{
	AMateria* node;
	Node* next;
};

struct List
{
	private:
		Node* mat;
	public:
		List();
		~List();
		void add_back(AMateria* m);
};
#endif 