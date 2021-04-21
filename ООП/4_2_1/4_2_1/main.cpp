/*
 Даны 8 классов, которые нумеруются от 1 до 8. Классы 2, 3, 4 и 5 наследованы от первого класса. Шестой класс от второго и третьего. Седьмой от четвертого и пятого. Восьмой от шестого и седьмого.
 У каждого класса есть параметризированный конструктор с одним параметром строкового типа и закрытое свойство строкового типа для наименования объекта класса.
 Значение данного свойства определяется в параметризированном конструкторе согласно шаблону:


 «значение строкового параметра»_«номер класса»


 В основной функции реализовать алгоритм:
 1.     Объявить один указатель на объект класса x (где: x - номер класса, его надо определить).
 2.     Объявить переменную строкового типа.
 3.     Ввести значение строковой переменной. Вводимое значение является идентификатором.
 4.     Создать объект класса 8 посредством параметризированного конструктора, передав в качестве аргумента строковую переменную.
 5.     Адрес созданного объекта присвоить указателю на объект класса x.
 6.     Используя только указатель на объект класса x вывести имена всех объектов в составе объекта класса 8 и имя самого объекта класса 8. Вывод выполнить построчно, упорядочивая согласно возрастанию номеров класса. Вывод реализовать в основной функции.


 Наследственность реализовать так, чтобы всего объектов было 10.
 
 Построчно (десять строк):
 идентификатор_номер класса

 Пример вывода:
 Ident_1
 Ident_1
 Ident_1
 Ident_2
 Ident_3
 Ident_4
 Ident_5
 Ident_6
 Ident_7
 Ident_8
 */
#include "AllClass.hpp"


int main(int argc, const char * argv[]) {
    Class8* p;
    string name;
    cin >> name;
    p = new Class8(name);
    for (int i = 3; i >= 0; i--)
        p->GetterName(i);
    return 0;
}
