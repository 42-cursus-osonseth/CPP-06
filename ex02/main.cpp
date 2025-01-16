#include <ctime>
#include <cstdlib>
#include <exception>
#include <stdexcept>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void);
void identify(Base *p);
void identify(Base &p);

Base *generate(void)
{
    int random_number = std::rand() % 3;
    if (random_number == 0)
        return new A();
    else if (random_number == 1)
        return new B();
    else
        return new C();
}
void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "type A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "type B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "type C" << std::endl;
}
void identify(Base &p)
{
    try
    {
        dynamic_cast<A &>(p);
        std::cout << "type A" << std::endl;
        return;
    }
    catch (std::exception &e) {}
    try
    {
        dynamic_cast<B &>(p);
        std::cout << "type B" << std::endl;
        return;
    }
    catch (std::exception &e) {}
    try
    {
        dynamic_cast<C &>(p);
        std::cout << "type C" << std::endl;
        return;
    }
    catch (std::exception &e) {}
}
int main()
{
    std::srand(std::time(0));
    Base *ptr = generate();
    identify(ptr);
    identify(*ptr);
    return 0;
}