#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "data.hpp"

typedef unsigned long uintptr_t;
class Serializer
{
private:
    Serializer();
public:
    ~Serializer();
    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);
};

#endif