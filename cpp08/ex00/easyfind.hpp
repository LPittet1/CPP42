#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind( T& cont, const int& target)
{
	typename T::iterator it = find(cont.begin(), cont.end(), target);
	return it;
}


#endif