#include <iostream>
#include"Class_1.h"
#include"Class_2.h"

Class_1 class_1;
Class_2 class_2;

Shm shm_n;

int main()
{
    class_1.fun_read();
    class_2.fun_read();

    class_1.fun_write(4, 5, 8, 12);
    class_1.fun_read();
    class_2.fun_read();

    class_2.fun_write(42, 45, 788, 6512);
    class_2.fun_read();
    class_1.fun_read();

    std::cout << "\n---\n";

    shm_n.left_x = 7777;
    shm_n.left_y = 555;

    class_1.fun_read();
    class_2.fun_read();

    return 0;
}