
#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure& cpy);
		Cure& operator=(const Cure& rhs);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};
#endif 