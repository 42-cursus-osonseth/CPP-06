#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}
void convert_char(char c)
{
    std::cout << "char   : '" << c << "'" << std::endl;
    std::cout << "int    : " << static_cast<int>(c) << std::endl;
    std::cout << "float  : " << std::fixed << static_cast<float>(c) << std::endl;
    std::cout << "double : " << std::fixed << static_cast<double>(c) << std::endl;
}
void convert_int(long int i)
{
    if (i < INT_MIN || i > INT_MAX)
    {
        std::cout << "Invalid INT" << std::endl;
        return;
    }
    if (i < 32 || i > 126)
        std::cout << "char   : Non displayable" << std::endl;
    else
        std::cout << "char   : '" << static_cast<char>(i) << "'" << std::endl;
    std::cout << "int    : " << i << std::endl;
    std::cout << "float  : " << std::fixed << static_cast<float>(i) << std::endl;
    std::cout << "double : " << std::fixed << static_cast<double>(i) << std::endl;
}
void convert_float(double f)
{
    if (f < -FLT_MAX || f > FLT_MAX)
    {
        std::cout << "Invalid FLOAT" << std::endl;
        return;
    }
    if (f < 32 || f > 127)
        std::cout << "char   : Non displayable" << std::endl;
    else
        std::cout << "char   : '" << static_cast<char>(f) << "'" << std::endl;
    if (f < static_cast<double>(INT_MIN) || f > static_cast<double>(INT_MAX))
        std::cout << "int    : Overflow" << std::endl;
    else
        std::cout << "int    : " << static_cast<int>(f) << std::endl;
    std::cout << "float  : " << std::fixed << f << std::endl;
    std::cout << "double : " << std::fixed << f << std::endl;
}
void convert_double(long double d)
{
    if (d < -DBL_MAX || d > DBL_MAX)
    {
        std::cout << "Invalid DOUBLE" << std::endl;
        return;
    }
    if (d < 32 || d > 127)
        std::cout << "char   : Non displayable" << std::endl;
    else
        std::cout << "char   : '" << static_cast<char>(d) << "'" << std::endl;
    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "int    : Overflow" << std::endl;
    else
        std::cout << "int    : " << static_cast<int>(d) << std::endl;
    if (d < -FLT_MAX || d > FLT_MAX)
        std::cout << "float  : Overflow" << std::endl;
    else
        std::cout << "float  : " << std::fixed << static_cast<float>(d) << std::endl;
    std::cout << "double : " << std::fixed << d << std::endl;
}
bool is_int(std::string str)
{
    long int integer;
    std::istringstream iss(str);

    iss >> integer;
    if (iss.fail() || !iss.eof())
        return false;
    convert_int(integer);
    return true;
}
bool is_char(std::string str)
{
    if (str.length() > 1 || str[0] < 32 || str[0] > 126)
        return false;
    char c = str[0];
    convert_char(c);
    return true;
}
bool have_point(std::string str)
{
    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            return true;
    }
    return false;
}
bool is_float(std::string str)
{
    double f;
    if (!have_point(str))
        return false;
    if (str[str.length() - 1] != 'f')
        return false;
    if (str[str.length() - 1] == 'f')
        str = str.substr(0, str.length() - 1);
    std::istringstream iss(str);
    iss >> f;
    if (iss.fail() || !iss.eof())
        return false;
    convert_float(f);
    return true;
}
bool is_double(std::string str)
{
    long double d;
    if (!have_point(str))
        return false;
    std::istringstream iss(str);
    iss >> d;
    if (iss.fail() || !iss.eof())
        return false;
    convert_double(d);
    return true;
}

void ScalarConverter::convert(std::string str)
{
    if (is_int(str))
        return;
    if (is_char(str))
        return;
    if (is_float(str))
        return;
    if (is_double(str))
        return;
    else
        std::cout << "Invalid arg : Can't be convert or overflow an double" << std::endl;
}