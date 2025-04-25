#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "type of the dog : " << j->getType() << " " << std::endl;
	std::cout << "Type of the cat : " << i->getType() << " " << std::endl;
	std::cout << "Cat sound ";
	i->makeSound();
	std::cout << "Dog sound ";
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl << "COPY CONSTRUCTOR TESTS" << std::endl << std::endl;

	Dog t;
	const Animal* cp = new Dog(t);

	std::cout << "type of the copy dog : " << cp->getType() << " " << std::endl;
	std::cout << "Dog copy sound ";
	cp->makeSound();

	std::cout << std::endl << "WRONG ANIMAL TESTS" << std::endl << std::endl;

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();
	WrongCat tac;

	std::cout << "type of the wrong cat (animal): " << wc->getType() << " " << std::endl;
	std::cout << "type of the wrong cat : " << tac.getType() << " " << std::endl;
	std::cout << "Wrong cat (animal) sound : ";
	wc->makeSound();
	std::cout << "Wrong cat sound : ";
	tac.makeSound();
	std::cout << "Wrong animal sound : ";
	wa->makeSound();

	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete cp;
	delete wa;
	delete wc;
}