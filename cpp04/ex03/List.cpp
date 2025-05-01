
#include "List.hpp"
#include <iostream>

List::List(): mat(0)
{

}

List::~List()
{
	while (mat)
	{
		Node* tmp = mat;
		mat = mat->next;
		if (tmp)
			delete tmp;
	}
}

void List::add_back(AMateria* m)
{
	Node *n = new Node;
	n->node = m;
	n->next = 0;
	Node *tmp = mat;
	if (!tmp)
	{
		mat = n;
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = n;
}