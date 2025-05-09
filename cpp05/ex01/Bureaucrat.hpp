
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& cpy);
		Bureaucrat& operator=(const Bureaucrat& rhs);
		~Bureaucrat();
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(Form& f);
		class GradeTooHighException: public std::exception
		{
			const char* what() const throw();
		};

		class GradeTooLowException: public std::exception
		{
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& b);

#endif