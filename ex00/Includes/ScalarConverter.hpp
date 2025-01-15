#ifndef SCALAR_HPP
#define SCALAR_HPP

#include <string>
#include <iostream>
#include <sstream>
#include <climits>
#include <cfloat>

class ScalarConverter
{
private:
     ScalarConverter();
public:
    ~ScalarConverter();
    static void convert (std::string str);
};

#endif