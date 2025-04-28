#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* brain;
	public:
		Cat();
		Cat(const Cat& cpy);
		Cat& operator=(const Cat& rhs);
		~Cat();
		void makeSound() const;
		Brain* getBrain() const;
};
