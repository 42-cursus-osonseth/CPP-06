#include "Serializer.hpp"
#include "data.hpp"
#include <iostream>

int main ()
{
    Data d = {133,'Z', "coucou"};

    Data *ptr = Serializer::deserialize(Serializer::serialize(&d));
    std::cout << ptr->i << std::endl;
    std::cout << ptr->c << std::endl;
    std::cout << ptr->str << std::endl;
    return 0;
}