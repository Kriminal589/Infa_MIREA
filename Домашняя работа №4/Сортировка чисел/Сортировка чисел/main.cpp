#include <iostream>
using namespace std;
int main()
{
    cout<<"Программа \"Сортировка чисел\" "<<endl;
    cout<<"Количество вводимых чисел -> ";
    double count;
    cin >> count;
    double* a = new double[count];
    double z;
    for (int i = 1; i <= count; i++)
    {
        cout<<i<<" число -> "; cin >> z;
        a[i-1] = z;
    }
    double max, min;
    for (int i = 0; i < count; i++)
    {
        bool Firts_max = true; bool Firts_min = true;
        if (Firts_max == true)
        {
            Firts_max = Firts_min = false;
            max = min = a[i];
        }
        if ((Firts_min == false) &&(a[i] < min))
            min = a[i];
        if ((Firts_max == false) &&(a[i] > max))
            max = a[i];
        
        
        for (int j = 0; j < count; j++)
        {
            if(a[i] > a[i+1])
            {
                int t = a[i+1];
                a[i+1] = a[i];
                a[i] = t;
            }
        }
    }
    cout <<"Минимальное число: "<<min<<endl;
    cout <<"Максимальное число: "<<max<<endl;
    cout <<"Введенные числа в возрастающем порядке:"<<endl;
    for(int i = 0; i < count; i++)
    {
        cout<<a[i]<<", ";
    }
}
