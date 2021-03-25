/*
Объект обладает следующей функциональностью:
- считывает элементы массива;
- выводит элементы массива;
- разворачивает последовательность элементов массива.
 */

#ifndef massive_hpp
#define massive_hpp

#include <stdio.h>

class massive{
private:
    int x[10];
    int N;
public:
    massive(int x);
    void get_length();
    void set_massive();
    void get_massive();
    void ReMassive();
};

#endif
