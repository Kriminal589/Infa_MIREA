/*
 Создать объект первого типа, у которого одно целочисленное свойство. Значение данного свойства определяется посредством параметризированного конструктора.
 Создать объект второго типа, у которого две целочисленных свойства. Значение данных свойств определяется посредством метода объекта.
 Реализовать дружественную функцию, которая находит максимальное значение полей объекта первого типа и полей объекта второго типа.


 Написать программу:
 1. Вводит значение для поля объекта первого типа.
 2. Создает объект первого типа.
 3. Вводит значения полей для полей объекта второго типа.
 4. Создает объект второго типа.
 5. Определяет значения полей объекта второго типа.
 6. Определяет максимальное значение полей, созданных двух объектов разного типа посредством дружественной функции.
 7. Выводит полученный результат.
 */
#ifndef Type_hpp
#define Type_hpp

#include <iostream>
using namespace std;

class First_Type{
public:
    int n;
    First_Type(int n);
};

class Second_Type{
public:
    int n,m;
    void vs (int n, int m);
};

#endif
