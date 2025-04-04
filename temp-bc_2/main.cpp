#include <iostream>
#include "Base_0.h"
#include "Derived_1.h"
#include "Derived_2.h"

int main()
{
    Derived_1 *d_1;
    Derived_2 d_2;
    d_1 = &d_2;

    d_1->fun_1();
    d_1->fun_2();
    d_1->fun_3();
    d_1->fun_4();
    d_1->fun_5();
    d_1->fun_6();

    return 0;
}