#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {

    private :
        std::string FirstName;
        std::string LastName;
        std::string Nickname;
        int PhoneNumber;
        std::string Secret;

    public :
        Contact(void);
        ~Contact(void);
        std::string   GetFirstName();
        std::string   GetLastName();
        std::string   GetNickname();
        int           GetPhoneNumber();
        std::string   GetSecret();

};

#endif