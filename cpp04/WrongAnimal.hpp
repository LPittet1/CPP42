#pragma once
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& cpy);
		~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& rhs);
		void makeSound();
		std::string getType();
};
