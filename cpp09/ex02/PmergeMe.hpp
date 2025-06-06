#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <cstdlib>
# include <algorithm>


//why vector and deque because they have accessors []


std::vector<int> PmergeVect(int ac, char **av);
std::deque<int>  PmergeDeque(int ac, char **av);
int maxNumberOfComparison(int numVal);


#endif