#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat& cpy);
		~WrongCat();
		WrongCat& operator=(const WrongCat& rhs);
		void makeSound();
};
