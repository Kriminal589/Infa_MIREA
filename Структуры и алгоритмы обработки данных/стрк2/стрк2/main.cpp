/*
 "   1. Разработать структуру узла списка, структура информационной части узла определена вариантом. Для определения структуры узла списка, используйте тип struct. Сохраните определение структуры узла прототипы функций в заголовочном файле.    "
 "   2. Разработайте функции для выполнения операции над линейным двунаправленным динамическим списком:
    - вывод списка в двух направлениях (слева направо и справа налево).
    - поиск узла с заданным значением (операция должна возвращать указатель на узел с заданным значением).   "
    3. Вставка нового узла перед первым узлом.
 
 
 
 4. Удаление сведений по счету (всех узлов), у которого общая сумма вклада равна нулю ( сумма по приходу, минус сумма по расходу).
 
 Номер счета в банке, дата, вид операции (приход или расход), сумма вклада.
 */

#include <iostream>
#include "Header.h"
using namespace std;

// Функция для заполнения узла с клиентом
void plenum (Users *&q){
    q = new Users; // Создаю нового клиента
    cout << "Введите номер банковского счета: ";
    cin >> q->AccountNumber;
    cout << "Сколько операций будет проведено? (Максимум 10) ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "Введите дату операции: ";
        cin >> q->data;
        q->datas[i] = q->data; // Запоминаю дату операции
        cout << "Введите тип операции: Приход/Расход  ";
        cin >> q->operation;
        if (q->operation != "Приход" && q->operation != "Расход"){
            cout << "Неизвестный тип операции. Проверьте, возможно операция начинается не с заглавной буквы."<<endl;
            exit(1);
        }
        q->operations[i] = q->operation; // Запоминаю тип операции
        int k;
        cout << "Сумма валюты, участвующей в операции? "; cin >> k;
        q->money[i] = k;
        if (q->operation == "Приход"){
            q->sum += k;
        }
        if (q->operation == "Расход"){
            q->sum -= k;
        }
        cout << "Операция завершена."<<endl;
        cout << endl;
    }
}

// Создание нового списка
void new_list(Users *&L){
    Users *q, *q1;
    bool First = true; // Переменная, с помощью которой будем отлавливать первый элемент
    cout << "Введите количество банковских клиентов: ";
    int x; cin >> x;
    for (int i = 0; i<x; i++){
        plenum(q); // Заполяем узел с клиентом
        if (First == true){
            q->prev = NULL;
            L = q;
            First = false;
        }
        else{
            q1->next = q;
            q->prev = q1;
        }
        q->next = NULL;
        q1 = q;
    }
}

// Функция удаления узлов, у которых поле sum == 0
void DeleteNode(Users *&L){
    bool First = true; // Переменная, с помощью которой будем отлавливать первый элемент
    Users *q = L;
    Users *q1;
    while (q){
        if (First == true){
            if (q->sum == 0){
                q1 = q;
                if (q1->next != NULL){
                    q = q1->next;
                    q->prev = NULL;
                    L = q;
                    delete q1;
                    continue;
                }else{
                    cout << "Ошибка. Были удалены все пользователи банковской системы."<<endl;
                    exit(2);
                }
            }
            First = false;
        }
        if (q->sum == 0){
            q1 = q;
            q = q1->prev;
            q->next = q1->next;
            if (q1->next != NULL){
                q = q1->next;
                q->prev = q1->prev;
            }
                delete q1;
        }
        q = q->next;
    }
}

// Функиция для вставки нового узла в начало списки
void add(Users *&L){
    Users *q;
    cout << "Перед добавления пользователя его нужно заполнить." <<endl;
    plenum(q);
    Users *q1 = L;
    q->next = q1;
    q1->prev = q;
    L = q;
}

// Вывод списка слева направо или справа налево
void outList(Users* L){
    Users* q = L;
    cout << "Вывести массив слева направо или справа налево? L/R : ";
    string y; cin >> y;
    // Вывод списка слева направо
    if (y == "L"){
        while (q){
            cout <<"Номер банковского счета: "<< q->AccountNumber << endl;
            cout << "Дата последней операции: " << q->data << "   Тип операции: " << q->operation<<endl;
            cout << "Сумма вклада: "<<q->sum;
            cout<<endl;
            cout<<endl;
            
            q = q->next;
        }
    }
    // Вывод списка справа налево
    if (y == "R"){
        while (q->next != NULL){
            q=q->next;
        }
        while (q){
            cout <<"Номер банковского счета: "<< q->AccountNumber << endl;
            cout << "Дата последней операции: " << q->data << "   Тип операции: " << q->operation<<endl;
            cout << "Сумма вклада: "<<q->sum;
            cout<<endl;
            cout<<endl;
            q = q->prev;
        }
    }
}

int main()
{
    Users* L;
    new_list(L);
    cout<<endl;
    outList(L);
    cout<<endl;
    cout << "Производится удаление."<<endl;
    DeleteNode(L);
    cout << "Удаление произведено."<<endl;
    cout<<endl;
    cout << "Добавим новый узел."<<endl;
    add(L);
    cout << "Узел добавлен."<<endl;
    outList(L);
    return 0;
}


