#ifndef BASE_0_H
#define BASE_0_H

#include <iostream>

class Base_0
{
public:
    Base_0()
    {
        std::cout << "class: Base_0, constructor" << std::endl;
    }

    ~Base_0()
    {
        std::cout << "class: Base_0, destructor" << std::endl;
    }

    virtual void fun_0() = 0;

    virtual void fun_1()
    {
        std::cout << "class: Base_0, fun_1" << std::endl;
    }

    virtual void fun_2()
    {
        std::cout << "class: Base_0, fun_2" << std::endl;
    }

    virtual void fun_3()
    {
        std::cout << "class: Base_0, fun_3" << std::endl;
    }

    virtual void fun_4()
    {
        std::cout << "class: Base_0, fun_4" << std::endl;
    }

protected:
    int val = 1218;
};

#endif // BASE_0_H