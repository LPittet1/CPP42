
#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	name;
		bool				isSigned;
		const int			gradeSign;
		const int			gradeExec;
	public:
		Form();
		Form(std::string name, int gradeSign, int gradeExec);
		Form(const Form& cpy);
		Form& operator=(const Form& rhs);
		~Form();
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

std::ostream& operator<<(std::ostream& os, Form& f);


#endif 