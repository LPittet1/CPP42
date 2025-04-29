
#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource(): count(0)
{
	for (int i = 0; i < 4; i++)
	{
		templ[i] = 0;
	}
}

MateriaSource::MateriaSource(const MateriaSource& cpy): count(cpy.count)
{
	for (int i = 0; i < 4; i++)
	{
		if (i < cpy.count)
			templ[i] = cpy.templ[i]->clone();
		else
			templ[i] = 0;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& rhs)
{
	if (this != &rhs)
	{
		count = rhs.count;
		for (int i = 0; i < 4; i++)
		{
			if (rhs.templ[i])
				templ[i] = rhs.templ[i]->clone();
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			delete templ[i];
			templ[i] = 0;
		}
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	if (count < 4)
		templ[count++] = m;
	else
	{
		delete m;
		std::cout << "This MateriaSource cannot learn more Materias" << std::endl;
	}
}

AMateria* MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < count; i++)
	{
		if (type == templ[i]->getType())
			return templ[i]->clone();
	}
	std::cout << "MateriaSource does not know this type of Materia" << std::endl;
	return 0;
}