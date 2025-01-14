#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
// bool valid_arg(std::string str)
// {
//     std::istringstream iss(str);
//     int i;
//     iss >> i;
//     return true;
// }
bool is_int(std::string str)
{
    std::istringstream iss(str);
    int i = ;
    iss >> i;
    if (iss.fail() || !iss.eof())
        return false;
    return true;
}
bool is_float (std::string str)
{
    
}
void print(char c, int i, float f, double d)
{
    std::cout
        << "char   : " << "'" << c << "'" << std::endl
        << "int    : " << i << std::endl
        << "float  : " << f << std::endl
        << "double : " << d << std::endl;
}
void ScalarConverter::convert(std::string str)
{
    if(!is_int(str))
        std::cout << "invalid type" << std::endl;
    
    // if (!valid_arg(str))
    //     std::cout << "Invalid arg" << std::endl;
}