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
#include "Type.hpp"

void max(First_Type* a, Second_Type* b){
    int locale_max = a->n;
    if (locale_max < b->m)
        locale_max = b->m;
    if (locale_max < b->n)
        locale_max = b->n;
    cout<< "max = " << locale_max << endl;
}

int main(int argc, const char * argv[]) {
    int n; cin >> n;
    First_Type* a = new First_Type(n);
    int m, c; cin >> m >> c;
    Second_Type* b = new Second_Type();
    b->vs(m, c);
    max(a, b);
    return 0;
}
