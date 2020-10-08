// Декодировать римскую запись числа, состоящего из любого количества знаков. Правила: I-1, V-5, X-10, L-50, C-100, D-500, M-1000. Значение римской цифры не зависит от позиции, а знак –- зависит.

// I - 105, V - 118, X - 120, L - 108, C - 99, D - 100, M - 109
#include <iostream>
#include <string>
using namespace std;

int num (char x)
{
    if (x == 'I')
        return 1;
    
    if (x == 'V')
        return 5;
    
    if (x == 'X')
        return 10;
    
    if (x == 'L')
        return 50;
    
    if (x == 'C')
        return 100;
    
    if (x == 'D')
        return 500;
    
    if (x == 'M')
        return 1000;
    return -1;
}

int main()
{
    cout <<"Введите число в римской системе счисление."<<endl;
    string number;
    cin >> number;
    
    int sum = 0;
    int* array = new int[number.length()];
    
    for (int i = 0; i < number.length(); i++)
    {
        array[i] = num(number[i]);
    }
    
    for (long int j = (number.length() - 1); j > -1; j--)
    {
        if (number.length() - 1 == j)
           sum += array[j];
        else
        {
            if (array[j] < array[j+1])
                sum -= array[j];
            else
                sum += array[j];
        }
    }
    
//    cout << array[0] << " " << array[1] << array[2] << endl;
    cout <<"Число в десятичной системе счисления: "<< sum << endl;
    
    return 0;
}
