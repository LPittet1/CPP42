#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data test;
    test.name = "test name";
    test.value = 42;
    std::cout << "data pointer: " << &test << std::endl;
    uintptr_t seria = Serializer::serialize(&test);
    std::cout << "seria value: " << seria << std::endl;
    Data* deseria = Serializer::deserialize(seria);
    std::cout << "name: " << test.name << ", value: " << test.value << std::endl;
    std::cout << "deseria name: " << deseria->name << ", deseria value: " << deseria->value << std::endl;
}