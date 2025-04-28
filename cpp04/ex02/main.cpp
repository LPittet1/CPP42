#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	//Animal impossible();
	size_t size = 10;
	Animal* animals[size];

	for (size_t i = 0; i < size; i++)
	{
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	for (size_t i = 0; i < size; i++)
	{
		std::cout << animals[i]->getType() << std::endl;
		delete animals[i];
	}

	Dog *d = new Dog();
	d->getBrain()->addIdea("idea 1");
	Dog dog(*d);
	Dog a;
	dog.getBrain()->addIdea("new idea");
	a = dog;
	d->getBrain()->printIdeas();
	delete d;
	a.getBrain()->addIdea("a super idea");

	std::cout << std::endl << "dog ideas" << std::endl;
	dog.getBrain()->printIdeas();

	std::cout << std::endl << "a ideas" << std::endl;
	a.getBrain()->printIdeas();

	Dog *test = new Dog(a);
	std::cout << std::endl << "test ideas" << std::endl;
	test->getBrain()->printIdeas();

	delete test;
}