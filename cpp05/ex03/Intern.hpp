
#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{	
	private:
		struct File
		{	
			std::string type;
			AForm* (*make)(std::string& target);
		};
		static const File filemap[];
	public:
		Intern();
		Intern(const Intern& cpy);
		Intern& operator=(const Intern& rhs);
		~Intern();
		AForm* makeForm(std::string type, std::string target);
};
#endif 