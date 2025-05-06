
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& cpy): AForm("ShrubberyCreationForm", 145, 137), target(cpy.target)
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		target = rhs.target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void ShrubberyCreationForm::beExecuted() const
{
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file)
		throw FileCreationException();
	for (int i = 0; i < 3; i++)
	{
			file << "\n\
				     .{{}}}}}}.									 .{{}}}}}}.\n\
				    {{{{{{(`)}}}.								{{{{{{(`)}}}.\n\
				   {{{(`)}}}}}}}}}					   {{{(`)}}}}}}}}}\n\
				  }}}}}}}}}{{(`){{{				  	}}}}}}}}}{{(`){{{\n\
				  }}}}{{{{(`)}}{{{{				  	}}}}{{{{(`)}}{{{{\n\
 				 {{{(`)}}}}}}}{}}}}} 				 {{{(`)}}}}}}}{}}}}}\n\
				{{{{{{{{(`)}}}}}}}}}}				{{{{{{{{(`)}}}}}}}}}}\n\
				{{{{{{{}{{{{(`)}}}}}}				{{{{{{{}{{{{(`)}}}}}}\n\
				 {{{{{(`)   {{{{(`)}'				 {{{{{(`)   {{{{(`)}'\n\
				  `\"\"'\" |   | \"'\"'`				 	  `\"\"'\" |   | \"'\"'`\n\
				  (`)  /     \\				  		  (`)  /     \\\n\
 				 ~~~~~~~~~~~~~~~~~~~ 				 ~~~~~~~~~~~~~~~~~~~";
	}
	file.close();
}

const char* ShrubberyCreationForm::FileCreationException::what() const throw()
{
	return "Error creating file";
}