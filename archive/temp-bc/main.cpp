#include <iostream>
#include "Base_0.h"
#include "Derived_1.h"
#include "Derived_2.h"


// #define TEST_1
// #define TEST_2
#define TEST_3

int main()
{
    #ifdef TEST_1
    std::cout << "TEST_1" << std::endl;
    Base_0 b_0;

    b_0.fun_0();
    b_0.fun_1();
    b_0.fun_2();
    b_0.fun_3();
    b_0.fun_4();
    
    #endif

    #ifdef TEST_2
    std::cout << "TEST_2" << std::endl;
    Base_0 *b_0;
    Derived_1 d_1;
    b_0 = &d_1;

    b_0->fun_0();
    b_0->fun_1();
    b_0->fun_2();
    b_0->fun_3();
    b_0->fun_4();

    #endif

    #ifdef TEST_3
    std::cout << "TEST_3" << std::endl;
    Base_0 *b_0;
    Derived_2 d_2;
    b_0 = &d_2;

    b_0->fun_0();
    b_0->fun_1();
    b_0->fun_2();
    b_0->fun_3();
    b_0->fun_4();

    #endif

    return 0;
}