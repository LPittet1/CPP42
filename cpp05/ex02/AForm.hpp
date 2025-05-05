
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
	public:
		AForm();
		AForm(std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& cpy);
		AForm& operator=(const AForm& rhs);
		~AForm();
		std::string getName() const;
		bool		getIsSigned() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		void		beSigned(Bureaucrat& b);
		class	GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};
		class	GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, AForm& f);


#endif 