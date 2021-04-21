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
 */

#ifndef AllClass_hpp
#define AllClass_hpp


#include <iostream>
using namespace std;

class Class1 {
private:
    string name;
public:
    void GetterName(int n);
    Class1(string name);
};

class Class2:public Class1 {
private:
    string name;
public:
    void GetterName(int n);
    Class2(string name);
};

class Class3:public Class1 {
private:
    string name;
public:
    Class3(string name);
    void GetterName(int n);
};

class Class4:public Class1 {
private:
    string name;
public:
    void GetterName(int n);
    Class4(string name);
};

class Class5:public Class1 {
private:
    string name;
public:
    void GetterName(int n);
    Class5(string name);
};

class Class6:public Class2, public Class3 {
private:
    string name;
public:
    void GetterName(int n);
    Class6(string name);
};

class Class7:public Class4, public Class5 {
private:
    string name;
public:
    void GetterName(int n);
    Class7(string name);
};

class Class8:public Class6, public Class7 {
private:
    string name;
public:
    void GetterName(int n);
    Class8(string name);
};


#endif /* AllClass_hpp */
