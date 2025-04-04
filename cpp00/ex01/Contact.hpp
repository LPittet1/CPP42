#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

    private :
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        std::string PhoneNumber;
        std::string Secret;

    public :
        Contact(void);
        ~Contact(void);
		void		  print_contact();
		std::string getFirstName();
		std::string getLastName();
		std::string getNickname();
		std::string	getPhoneNumber();
		std::string getSecret();
		void setFirstName();
		void setLastName();
		void setNickname();
		void setPhoneNumber();
		void setSecret();
};

#endif