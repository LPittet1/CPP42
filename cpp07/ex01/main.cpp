#include "iter.hpp"

int main()
{
	std::string test[10];
	std::string const cotest[10] = {"a","b","c","d","e","f","g","h","i","j"};
	double testint[10];
	for (int i = 0; i < 10; i++)
	{
		test[i] = 'a' + i;
		testint[i] = i;
	}
	iter(test, 10, doub);
	iter(cotest, 10, print);
	iter(testint, 4, doub);
	iter(test, 10, print);
	iter(testint, 10, print);
}