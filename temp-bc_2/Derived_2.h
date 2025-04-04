#ifndef DERIVED_2_H
#define DERIVED_2_H

#include "Derived_1.h"
#include <iostream>

class Derived_2 : public Derived_1
{
public:
    Derived_2()
    {
        std::cout << "class: Derived_2, constructor" << std::endl;
    }

    ~Derived_2()
    {
        std::cout << "class: Derived_2, destructor" << std::endl;
    }

    virtual void fun_1()
    {
        std::cout << "class: Derived_2, fun_1" << std::endl;
    }

    // virtual void fun_2()
    // {
    //     std::cout << "class: Derived_2, fun_2" << std::endl;
    // }

    // virtual void fun_3()
    // {
    //     std::cout << "class: Derived_2, fun_3" << std::endl;
    // }

    virtual void fun_4()
    {
        std::cout << "class: Derived_2, fun_4" << std::endl;
        std::cout << val << std::endl;
    }

    virtual void fun_5()
    {
        std::cout << "class: Derived_2, fun_5" << std::endl;
    }

    virtual void fun_6()
    {
        std::cout << "class: Derived_2, fun_6" << std::endl;
    }
};

#endif // DERIVED_2_H