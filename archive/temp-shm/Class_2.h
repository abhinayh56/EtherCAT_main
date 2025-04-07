#pragma once

#include "Shm.h"
#include <iostream>

class Class_2
{
public:
    Class_2() {}
    ~Class_2() {}

    void fun_read()
    {
        std::cout << "\nClass_2 read" << std::endl;
        std::cout << "shm.left_x: " << shm.left_x << std::endl;
        std::cout << "shm.right_x: " << shm.right_x << std::endl;
        std::cout << "shm.left_y: " << shm.left_y << std::endl;
        std::cout << "shm.right_y: " << shm.right_y << std::endl;
    }

    void fun_write(int left_x_, int right_x_, int left_y_, int right_y_)
    {
        std::cout << "\nClass_2 write" << std::endl;
        shm.left_x = left_x_;
        shm.right_x = right_x_;
        shm.left_y = left_y_;
        shm.right_y = right_y_;
    }

private:
    Shm shm;
};