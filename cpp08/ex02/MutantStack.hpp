#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>

template <class T>
class MutantStack: public std::stack<T>
{
	public:
		MutantStack(): std::stack<T>() {};
		~MutantStack() {};
		MutantStack(const MutantStack& cpy): std::stack<T>(cpy) {};
		MutantStack operator=(const MutantStack& rhs)
		{
			if (*this != rhs)
			{
				std::stack<T>::operator=(rhs);
			}
			return *this;
		};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void)
		{
			return std::stack<T>::c.begin();
		}
		iterator end(void)
		{
			return std::stack<T>::c.end();
		}
		typedef typename std::stack<T>::container_type::const_iterator citerator;
		citerator begin(void) const
		{
			return std::stack<T>::c.begin();
		}
		citerator end(void) const
		{
			return std::stack<T>::c.end();
		}
	
};



#endif