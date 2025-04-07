#ifndef DERIVED_1_H
#define DERIVED_1_H

#include "Base_0.h"
#include <iostream>

class Derived_1 : public Base_0
{
public:
    Derived_1()
    {
        std::cout << "class: Derived_1, constructor" << std::endl;
    }

    ~Derived_1()
    {
        std::cout << "class: Derived_1, destructor" << std::endl;
    }

    // virtual void fun_1()
    // {
    //     std::cout << "class: Derived_1, fun_1" << std::endl;
    // }

    virtual void fun_2()
    {
        std::cout << "class: Derived_1, fun_2" << std::endl;
        std::cout << val << std::endl;
        val = val*2;
        std::cout << val << std::endl;
    }

    // virtual void fun_3()
    // {
    //     std::cout << "class: Derived_1, fun_3" << std::endl;
    // }

    // virtual void fun_4()
    // {
    //     std::cout << "class: Derived_1, fun_4" << std::endl;
    // }

    virtual void fun_5()
    {
        std::cout << "class: Derived_1, fun_5" << std::endl;
    }

    virtual void fun_6()
    {
        std::cout << "class: Derived_1, fun_6" << std::endl;
    }
};

#endif // DERIVED_1_H
