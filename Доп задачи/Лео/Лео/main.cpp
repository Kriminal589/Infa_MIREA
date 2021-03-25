// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <fstream>
#include <list>

using namespace std;

//Задача копирование файла
int main()
{
    int blya;
    list <int> massiv_a;
    list <int> :: iterator hui;
    string stroka;
    ifstream a ("/Users/AndreyNovikov/Desktop/Информатика/first_matrix.txt");
    while (!a.eof())
    {
        a >> blya;
        massiv_a.push_back(blya);
    }
    a.close();
    ifstream b ("/Users/AndreyNovikov/Desktop/Информатика/second_matrix.txt");
    while (!b.eof())
    {
        b >> blya;
        massiv_a.push_back(blya);
    }
    b.close();
    massiv_a.sort();
    ofstream c ("/Users/AndreyNovikov/Desktop/Информатика/lesson.txt");
    for (hui=massiv_a.begin();hui!=massiv_a.end();hui++)
    {
         c <<*hui<<" ";
    }
    c.close();
    return 0;
}
