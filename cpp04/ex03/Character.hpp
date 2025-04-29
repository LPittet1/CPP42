
#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include "AMateria.hpp"
# include "List.hpp"


class Character: public ICharacter
{
	private:
		AMateria* inventory[4];
		List droppedItems;
		std::string name;
	public:
		Character();
		Character(const std::string& name);
		Character(const Character& cpy);
		Character& operator=(const Character& rhs);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};
#endif 