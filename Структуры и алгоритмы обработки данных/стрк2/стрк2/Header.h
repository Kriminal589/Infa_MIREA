//
//  Header.h
//  стрк2
//
//  Created by Andrey Novikov on 18.04.2021.
//

#ifndef Header_h
#define Header_h
using namespace std;

struct Users
{
    Users* next; // Ссылка на след. клиента
    Users* prev; // Ссылка на предыдущего клиента
    string data;// Дата операции
    string operation;// Тип последней операции
    int AccountNumber; // Номер банковского счета
    string operations[10]; // История всех операций
    string datas[10]; // Даты всех операций
    int money[10]; // История сумм всех операций
    int sum = 0; // Вклад банка
};

#endif /* Header_h */
