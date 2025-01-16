#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "A single argument is required" << std::endl;
        return 0;
    }
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}