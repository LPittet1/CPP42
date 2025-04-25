#pragma once
#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& cpy);
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal& rhs);
		void makeSound() const;
		std::string getType() const;
};
