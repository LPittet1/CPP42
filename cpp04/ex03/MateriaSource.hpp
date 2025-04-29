
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* templ[4];
		int count;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& cpy);
		MateriaSource& operator=(const MateriaSource& rhs);
		~MateriaSource();
		void learnMateria(AMateria* m);
		AMateria* createMateria(const std::string& type);
};
#endif 