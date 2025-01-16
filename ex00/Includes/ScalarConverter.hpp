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
     ScalarConverter(ScalarConverter const &other);
     ScalarConverter &operator=(ScalarConverter const &other);
public:
    ~ScalarConverter();
    static void convert (std::string str);
};

#endif