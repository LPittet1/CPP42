#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string* stringPTR = &brain;
	std::string& stringREF = brain;

	std::cout << "brain address is : " << &brain << std::endl;
	std::cout << "stringPTR address is : " << &brain << std::endl;
	std::cout << "stringREF address is : " << &brain << std::endl << std::endl;

	std::cout << "brain content is : " << brain << std::endl;
	std::cout << "stringPTR content is : " << *stringPTR << std::endl;
	std::cout << "stringREF content is : " << stringREF << std::endl;
 }