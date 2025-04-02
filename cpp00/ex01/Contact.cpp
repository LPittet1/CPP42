#include "Contact.hpp"

Contact::Contact()
{
    std::cout << "Write first name" << std::endl;
    std::cin >> Contact::FirstName;
    std::cout << "Write last name" << std::endl;
    std::cin >> Contact::LastName;
    std::cout << "Write nickname" << std::endl;
    std::cin >> Contact::Nickname;
    std::cout << "Write phone number" << std::endl;
    std::cin >> Contact::PhoneNumber;
    std::cout << "Write secrer" << std::endl;
    std::cin >> Contact::Secret;
}

Contact::~Contact(void)
{
    return;
}

std::string Contact::GetFirstName()
{
    return FirstName;
}
