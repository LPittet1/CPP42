
#include "Character.hpp"
#include <iostream>

Character::Character(): inventory(), name("defaultName")
{
	
}

Character::Character(const std::string& name): inventory(), name(name)
{

}

Character::Character(const Character& cpy): inventory(), name(cpy.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (cpy.inventory[i])
			inventory[i] = cpy.inventory[i]->clone();
	}
}

Character& Character::operator=(const Character& rhs)
{
	if (this != &rhs)
	{
		this->name = rhs.name;
		for (int i = 0; i < 4; i++)
		{
			if (this->inventory[i])
			{
				delete this->inventory[i];
				this->inventory[i] = 0;
			}
			if (rhs.inventory[i])
				inventory[i] = rhs.inventory[i]->clone();
		}
	}
	return *this;
}

Character::~Character()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
		{
			std::cout << inventory[i] << std::endl;
			delete inventory[i];
			inventory[i] = 0;
		}
	}
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (!inventory[i])
		{
			inventory[i] = m;
			return;
		}
	}
	std::cout << "Inventory is full" << std::endl;
}

void Character::unequip(int idx)
{
	if (!inventory[idx])
		return;
	droppedItems.add_back(inventory[idx]);
	delete inventory[idx];
	inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target)
{
	if (!inventory[idx])
		std::cout << "No spell in this slot" << std::endl;
	if (inventory[idx])
		inventory[idx]->use(target);
}

void Character::printInvAdrr()
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			std::cout << name << " : " << inventory[i] << std::endl;
	}
}