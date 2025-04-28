#pragma once

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& cpy);
		Animal& operator=(const Animal& rhs);
		virtual ~Animal();
		virtual void makeSound() = 0;
		std::string getType() const;
};
