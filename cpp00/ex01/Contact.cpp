#include "Contact.hpp"

Contact::Contact()
{
   
}

Contact::~Contact(void)
{
    return;
}

void Contact::print_contact()
{
	std::cout << "First name :" << FirstName << std::endl;
	std::cout << "Nickname :" << Nickname << std::endl;
	std::cout << "Last name : " << LastName << std::endl;
	std::cout << "Phone number : " << PhoneNumber << std::endl;
	std::cout << "Darkest secret : " << Secret << std::endl;
}

std::string Contact::getFirstName()
{
	return FirstName;
}

std::string Contact::getLastName()
{
	return LastName;
}

std::string Contact::getNickname()
{
	return Nickname;
}

std::string Contact::getSecret()
{
	return Secret;
}

std::string Contact::getPhoneNumber()
{
	return PhoneNumber;
}

void	Contact::setFirstName()
{
	std::cout << "First name : ";
	getline(std::cin, FirstName);
	if (FirstName.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		if (!std::cin.eof())
			setFirstName();
	}
}

void	Contact::setLastName()
{
	std::cout << "Last name : ";
	getline(std::cin, LastName);
	if (LastName.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		if (!std::cin.eof())
			setLastName();
	}
}

void	Contact::setNickname()
{
	std::cout << "Nickname : ";
	getline(std::cin, Nickname);
	if (Nickname.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		if (!std::cin.eof())
			setNickname();
	}
}

void	Contact::setSecret()
{
	std::cout << "Darkest secret : ";
	getline(std::cin, Secret);
	if (Secret.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		if (!std::cin.eof())
			setSecret();
	}
}

void Contact::setPhoneNumber()
{
	std::string Number;

	std::cout << "Phone number : ";
	getline(std::cin, Number);
	if (Number.empty())
	{
		std::cout << "All fields must be filled" << std::endl;
		if (!std::cin.eof())
			setPhoneNumber();
		return ;
	}
	for (size_t i = 0; i < Number.length(); i++)
	{
		if (!isdigit(Number[i]))
		{
			std::cout << "Number requires digit only" << std::endl;
			setPhoneNumber();
			return ;
		}
	}
	PhoneNumber = Number;
}
